/* SPDX-License-Identifier: MIT */
/*
 * Very basic proof-of-concept for doing a copy with linked SQEs. Needs a
 * bit of error handling and short read love.
 */
#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "liburing.h"

#define QD    64         // io_uring 队列长度
#define BS    (32*1024)

struct io_data {
    size_t offset;
    int index;
    struct iovec iov;
};

static int infd, outfd;
static unsigned inflight;

// 创建一个 read->write SQE chain
static void queue_rw_pair(struct io_uring *ring, off_t size, off_t offset) {
    struct io_uring_sqe *sqe;
    struct io_data *data;
    void *ptr;

    ptr = malloc(size + sizeof(*data));
    data = ptr + size;
    data->index = 0;
    data->offset = offset;
    data->iov.iov_base = ptr;
    data->iov.iov_len = size;

    sqe = io_uring_get_sqe(ring);                            // 获取可用 SQE
    io_uring_prep_readv(sqe, infd, &data->iov, 1, offset);   // 准备 read 请求
    sqe->flags |= IOSQE_IO_LINK;                             // 设置为 LINK 模式
    io_uring_sqe_set_data(sqe, data);                        // 设置 data

    sqe = io_uring_get_sqe(ring);                            // 获取另一个可用 SQE
    io_uring_prep_writev(sqe, outfd, &data->iov, 1, offset); // 准备 write 请求
    io_uring_sqe_set_data(sqe, data);                        // 设置 data
}

// 处理完成（completion）事件：释放 SQE 的内存缓冲区，通知内核已经消费了 CQE。
static int handle_cqe(struct io_uring *ring, struct io_uring_cqe *cqe) {
    struct io_data *data = io_uring_cqe_get_data(cqe);       // 获取 CQE
    data->index++;
	int ret = -1;

    if (cqe->res < 0) {
        if (cqe->res == -ECANCELED) {
            queue_rw_pair(ring, BS, data->offset);
            inflight += 2;
        } else {
            printf("cqe error: %s\n", strerror(cqe->res));
            ret = 1;
        }
    }

    if (data->index == 2) {        // read->write chain 完成，释放缓冲区内存
        void *ptr = (void *) data - data->iov.iov_len;
        free(ptr);
    }

    io_uring_cqe_seen(ring, cqe);  // 通知内核已经消费了 CQE 事件
    return ret;
}

static int copy_file(struct io_uring *ring, off_t insize) {
    struct io_uring_cqe *cqe;
    size_t this_size;
    off_t offset;

    offset = 0;
    while (insize) {                      // 数据还没处理完
        int has_inflight = inflight;      // 当前正在进行中的 SQE 数量
        int depth;  // SQE 阈值，当前进行中的 SQE 数量（inflight）超过这个值之后，需要阻塞等待 CQE 完成

        while (insize && inflight < QD) { // 数据还没处理完，io_uring 队列也还没用完
            this_size = BS;
            if (this_size > insize)       // 最后一段数据不足 BS 大小
                this_size = insize;

            queue_rw_pair(ring, this_size, offset); // 创建一个 read->write chain，占用两个 SQE
            offset += this_size;
            insize -= this_size;
            inflight += 2;                // 正在进行中的 SQE 数量 +2
        }

        if (has_inflight != inflight)     // 如果有新创建的 SQE，
            io_uring_submit(ring);        // 就提交给内核

        if (insize)                       // 如果还有 data 等待处理，
            depth = QD;                   // 阈值设置 SQ 的队列长度，即 SQ 队列用完才开始阻塞等待 CQE；
        else                              // data 处理已经全部提交，
            depth = 1;                    // 阈值设置为 1，即只要还有 SQE 未完成，就阻塞等待 CQE

        // 下面这个 while 只有 SQ 队列用完或 data 全部提交之后才会执行到
        while (inflight >= depth) {       // 如果所有 SQE 都已经用完，或者所有 data read->write 请求都已经提交
            io_uring_wait_cqe(ring, &cqe);// 等待内核 completion 事件
            handle_cqe(ring, cqe);        // 处理 completion 事件：释放 SQE 内存缓冲区，通知内核 CQE 已消费
            inflight--;                   // 正在进行中的 SQE 数量 -1
        }
    }

    return 0;
}

static int setup_context(unsigned entries, struct io_uring *ring) {
    io_uring_queue_init(entries, ring, 0);
    return 0;
}

static int get_file_size(int fd, off_t *size) {
    struct stat st;

    if (fstat(fd, &st) < 0)
        return -1;
    if (S_ISREG(st.st_mode)) {
        *size = st.st_size;
        return 0;
    } else if (S_ISBLK(st.st_mode)) {
        unsigned long long bytes;

        if (ioctl(fd, BLKGETSIZE64, &bytes) != 0)
            return -1;

        *size = bytes;
        return 0;
    }

    return -1;
}

int main(int argc, char *argv[]) {
    struct io_uring ring;
    off_t insize;
    int ret;

    infd = open(argv[1], O_RDONLY);
    outfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (setup_context(QD, &ring))
        return 1;
    if (get_file_size(infd, &insize))
        return 1;

    ret = copy_file(&ring, insize);

    close(infd);
    close(outfd);
    io_uring_queue_exit(&ring);
    return ret;
}
