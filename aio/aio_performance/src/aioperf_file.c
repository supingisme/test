
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "aioperf_manager.h"
#include "aioperf_file.h"
#include "aioperf_eventfd.h"
#include "aioperf_general.h"

int
aioperf_files_init(aioperf_manager_t *mgr)
{
    aioperf_repository_t    *read_repo = NULL;
    aioperf_repository_t    *write_repo = NULL;
    int                      read_files_ret = 0;
    int                      write_files_ret = 0;
    
    if (!mgr) {
        printf("mgr null\n");
        return AIOPERF_ERROR;
    }
    
    read_repo = &mgr->read_repository;
    write_repo = &mgr->write_repository;

    read_files_ret = aioperf_files_read_init(read_repo);
    write_files_ret = aioperf_files_write_init(write_repo);
    
    if (read_files_ret != AIOPERF_OK && write_files_ret!= AIOPERF_OK) {
        printf("no files init\n");
        return AIOPERF_ERROR;
    }

    return AIOPERF_OK;
}


void
aioperf_files_release(aioperf_manager_t *mgr)
{
    aioperf_files_read_release(&mgr->read_repository);
    aioperf_files_write_release(&mgr->write_repository);
}


int
aioperf_files_read_init(aioperf_repository_t *repository)
{
    unsigned long         files_pool_size = 0;
    aioperf_pool_t       *pool = NULL;

    files_pool_size = repository->conf_info->file_num * 10 * 
        sizeof(aioperf_io_task_t);

    if (files_pool_size <= 0) {
        printf("READ: FILES NOT INIT (pool size 0)\n");
        return AIOPERF_ERROR;
    }
    
    if (!(pool = aioperf_memory_pool_create(files_pool_size, SYSPAGE_SIZE))) {
        printf("pool create error\n");
        return AIOPERF_ERROR;
    }

    aioperf_files_create_folder(AIOPERF_READ_FOLDER);

    repository->pool = pool;
    
    if (aioperf_files_create(repository, repository->pool, 
        AIOPERF_READ_FOLDER, AIOPERF_READ) != AIOPERF_OK) {
        printf("read files create error\n");
        goto fuck_pool_release;
    }

    return AIOPERF_OK;

fuck_pool_release:
    aioperf_files_destroy(repository);
    return AIOPERF_ERROR;
}

int
aioperf_files_write_init(aioperf_repository_t *repository)
{
    unsigned long         files_pool_size = 0;    
    aioperf_pool_t       *pool = NULL;
    
    files_pool_size = repository->conf_info->file_num * 10 * 
        sizeof(aioperf_io_task_t);

    if (files_pool_size <= 0) {
        printf("WRITE: FILES NOT INIT (pool size 0)\n");
        return AIOPERF_ERROR;
    }
    
    if (!(pool = aioperf_memory_pool_create(files_pool_size, SYSPAGE_SIZE))) {
        printf("pool create error\n");
        return AIOPERF_ERROR;
    }

    aioperf_files_create_folder(AIOPERF_WRITE_FOLDER);

    repository->pool = pool;
    
    if (aioperf_files_create(repository, repository->pool,
        AIOPERF_WRITE_FOLDER, AIOPERF_WRITE) != AIOPERF_OK) {
        printf("write files create error\n");
        goto fuck_pool_release;
    }

    return AIOPERF_OK;

fuck_pool_release:
    aioperf_files_destroy(repository);
    return AIOPERF_ERROR;
}

void
aioperf_files_read_release(aioperf_repository_t *repository)
{
    aioperf_files_destroy(repository);
    printf("READ: close file num is %d\n", repository->conf_info->file_num);
    aioperf_memory_pool_release(repository->pool);
}

void
aioperf_files_write_release(aioperf_repository_t *repository)
{
    aioperf_files_destroy(repository);
    printf("WRITE: close file num is %d\n", repository->conf_info->file_num);
    aioperf_memory_pool_release(repository->pool);
}

int
aioperf_files_create(aioperf_repository_t *repository, aioperf_pool_t *pool,
    char *folder_name, int handle_type)
{
    int                  folder_name_len = 0;
    char                 file_name[AIOPERF_FILE_NAME_SIZE] = "\0";
    int                  i = 0;
    int                  j = 0;
    aioperf_conf_file_t *file_t;
    aioperf_io_task_t  **files = NULL;
    unsigned int         files_num = 0;
    char                *folder;
    int                  percent = 0;

    
    if (!folder_name || !pool || !repository) {
        printf("aioperf_files_init param error\n");
        return AIOPERF_ERROR;
    }

    if (!(folder = aioperf_memory_pool_alloc(pool, strlen(folder_name) + 1))) {
        printf("alloc error\n");
        return AIOPERF_ERROR;
    }
    
    strcpy(folder, folder_name);

    files_num = repository->conf_info->file_num;
       
    if (!(files = (aioperf_io_task_t **)aioperf_memory_pool_alloc(pool, 
        files_num * sizeof(aioperf_io_task_t *)))) {
        printf("pool alloc error\n");
        return AIOPERF_ERROR;
    }

    repository->files = files;

    file_t = repository->conf_info->conf_file;

    //set file name
    folder_name_len = strlen(folder);
    if (folder[folder_name_len - 1] == '/') {
        folder[folder_name_len - 1] = '\0';
        folder_name_len = strlen(folder);
    }

    percent = file_t->percent;
    
    for (i = 0; i < files_num; i++) {
        j++;
        snprintf(file_name, AIOPERF_FILE_NAME_SIZE, "%s/%06d", folder, i);
        if (aioperf_files_open(pool, &files[i], file_name, handle_type) 
            != AIOPERF_OK) {
            goto fuck_files_release;
        }

        files[i]->repository = repository;
        files[i]->file_size = file_t->file_size;
        files[i]->offset = 0;
        
        if (j * 100 >= files_num * percent) {
            if (!file_t->next) {
                percent = 100;
            } else {
                file_t = file_t->next;
                percent = file_t->percent;
                j = 0;
            }
        }
    }

    if (handle_type == AIOPERF_READ) {
        printf("READ: open file num is %d\n", repository->conf_info->file_num);
    } else if (handle_type == AIOPERF_WRITE) {
        printf("WRITE: open file num is %d\n", repository->conf_info->file_num);
    }
    
    return AIOPERF_OK;
    
fuck_files_release:
    for (i = 0; i < files_num; i++) {
        if (files[i]) {
            if (files[i]->fd > 0) {
                if (close(files[i]->fd) < 0) {
                    printf("close file %d error\n", files[i]->fd);
                }
            }
        }
    }
    
    return AIOPERF_ERROR;
}

void
aioperf_files_destroy(aioperf_repository_t *repository)
{
    unsigned int        i = 0;
    unsigned int        files_num = 0;
    aioperf_io_task_t **files = NULL;
    unsigned int        close_num = 0;

    files = repository->files;
    files_num = repository->conf_info->file_num;
    
    for (i = 0; i < files_num; i++) {
        if (files[i] && files[i]->fd) {
            if (close(files[i]->fd) < 0) {
                    printf("close file %d error\n", files[i]->fd);
            }
            close_num++;
        }
    }
}

int
aioperf_files_open(aioperf_pool_t *pool, aioperf_io_task_t **file, 
    char *name, int handle_type)
{
    if (!(*file = aioperf_memory_pool_alloc(pool, sizeof(aioperf_io_task_t)))) {
        printf("pool alloc error\n");
        return AIOPERF_ERROR;
    }
    
    if (handle_type == AIOPERF_READ) {
        if (((*file)->fd = open(name, O_RDONLY, 0444)) < 0) {
            printf("open %s error\n", name);
            return AIOPERF_ERROR;
        }
    
    } else if (handle_type == AIOPERF_WRITE) {
        if (((*file)->fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0444)) < 0) {
            printf("open %s error\n", name);
            return AIOPERF_ERROR;
        }
        
    } else {
        printf("handle type error\n");
        return AIOPERF_ERROR;
    }

    return AIOPERF_OK;
}




int
aioperf_files_write(aioperf_worker_t *worker, aioperf_repository_t *repository, 
    aioperf_pool_t *pool)
{
    unsigned int             file_num = 0;
    unsigned int             sel_file = 0;
    aioperf_io_task_t      **files = NULL;
    aioperf_io_task_t       *new_task = NULL;
    aioperf_conf_info_t     *conf_info = NULL;


    files = repository->files;
    conf_info = repository->conf_info;
    file_num = conf_info->file_num;

    srand((unsigned)time(NULL));
    
    while (file_num) {
        sel_file = rand() % file_num;

        if (aioperf_general_write(files[sel_file]) != AIOPERF_OK) {
            repository->io_error_num++;
            
        } else {
            repository->io_req_num++;
            
            if (files[sel_file]->offset + conf_info->buf_size >= 
                files[sel_file]->file_size) {
                aioperf_files_move_to_end(&files[sel_file], &files[file_num - 1]);
                file_num--;
            } else {
                new_task = aioperf_memory_pool_alloc(pool, 
                    sizeof(aioperf_io_task_t));
                if (!new_task) {
                    printf("alloc task error\n");
                    return AIOPERF_ERROR;
                } else {
                    *new_task = *files[sel_file];
                    new_task->file_next = files[sel_file];
                    files[sel_file] = new_task;
                    files[sel_file]->offset += conf_info->buf_size;
                }
            }
        }

        if (worker->worker_release_start) {
            printf("send release\n");
            return AIOPERF_ERROR;
        }
    }

    if (aioperf_eventfd_write(repository->over_evfd) != AIOPERF_OK) {
        printf("send eventfd error\n");
    }
    
    return AIOPERF_OK;
}


int
aioperf_files_read(aioperf_worker_t *worker, aioperf_repository_t *repository, 
    aioperf_pool_t *pool)
{
    unsigned int             file_num = 0;
    unsigned int             sel_file = 0;
    aioperf_io_task_t      **files = NULL;
    aioperf_io_task_t       *new_task = NULL;
    aioperf_conf_info_t     *conf_info = NULL;

    files = repository->files;
    conf_info = repository->conf_info;
    file_num = conf_info->file_num;

    srand((unsigned)time(NULL));
    
    while (file_num) {
        sel_file = rand() % file_num;

        if (aioperf_general_read(files[sel_file]) != AIOPERF_OK) {
            repository->io_error_num++;
            
        } else {
            repository->io_req_num++;
            
            if (files[sel_file]->offset + conf_info->buf_size >= 
                files[sel_file]->file_size) {
                aioperf_files_move_to_end(&files[sel_file], &files[file_num - 1]);
                file_num--;
            } else {
                new_task = aioperf_memory_pool_alloc(pool, 
                    sizeof(aioperf_io_task_t));
                if (!new_task) {
                    printf("alloc task error\n");
                    return AIOPERF_ERROR;
                } else {
                    *new_task = *files[sel_file];
                    new_task->file_next = files[sel_file];
                    files[sel_file] = new_task;
                    files[sel_file]->offset += conf_info->buf_size;
                }
            }
        }

        if (worker->worker_release_start) {
            return AIOPERF_ERROR;
        }
    }

    if (aioperf_eventfd_write(repository->over_evfd) != AIOPERF_OK) {
        printf("send eventfd error\n");
    }
    
    return AIOPERF_OK;
}


void
aioperf_files_move_to_end(aioperf_io_task_t **this, aioperf_io_task_t **end)
{
    aioperf_io_task_t *temp = NULL;

    temp = *this;

    *this = *end;

    *end = temp;
}

int 
aioperf_files_create_folder(const char *path)
{
    int i, len;

    len = strlen(path);
    char dir_path[len+1];
    dir_path[len] = '\0';

    strncpy(dir_path, path, len);

    for (i=0; i<len; i++)
    {
        if (dir_path[i] == '/' && i > 0)
        {
            dir_path[i]='\0';
            if (access(dir_path, F_OK) < 0)
            {
                if (mkdir(dir_path, 0755) < 0)
                {
                        printf("mkdir=%s:msg=%s\n", dir_path, strerror(errno));
                        return AIOPERF_ERROR;
                }
            }
            dir_path[i]='/';
        }
    }

    return AIOPERF_OK;
}

