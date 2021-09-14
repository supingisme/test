#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/msg.h>



struct mcpy_struct {
    unsigned int size;
    char *memory;
};

char *str = {"rongtao Memory test"};


#define memshow(m) printf("\t%s \t%p \t%s\n", #m, m, m)

#define memshow_prefix(prefix, m) printf("[%s] \t%s \t%p \t%s\n", prefix, #m, m, m)

int my_malloc(unsigned int size, char **buf)
{
    *buf = malloc(size);
    memshow(*buf);
    strcpy(*buf, str);
    memshow(*buf);
}


int my_malloc_ulong(unsigned int size, unsigned long addr)
{
    void *buf = malloc(size);
    memcpy(&addr, buf, sizeof(addr));
    memshow(buf);
    strcpy(buf, str);
    memshow(buf);
}

#define MSG_TYPE 888

#define MSG_FILE "/dev/mqueue/memory"

pthread_t task1_id, task2_id;

/*消息结构*/
struct msg_form
{
	long mtype;
	struct mcpy_struct data;
};

void *taks1(void *arg)
{
	int msqid;
	key_t key;
    
	if((key = ftok(MSG_FILE, 123)) < 0)
	{
		perror("ftok error");
		exit(1);
	}
    
	if((msqid = msgget(key, IPC_CREAT|0777)) == -1)
	{
		perror("msgget error");
		exit(1);
	}
    
	struct msg_form msg = {MSG_TYPE, {0, NULL}};
    
    memshow_prefix("Recv Before", msg.data);

    msgrcv(msqid, &msg, sizeof(msg), msg.mtype, 0);
    
    memshow_prefix("Recv After ", msg.data);
    
    return NULL;
}

void *taks2(void *arg)
{
	int msqid;
	key_t key;

    
	if((key = ftok(MSG_FILE, 123)) < 0)
	{
		perror("ftok error");
		exit(1);
	}
    
	if((msqid = msgget(key, IPC_CREAT|0777)) == -1)
	{
		perror("msgget error");
		exit(1);
	}
    
	struct msg_form msg = {MSG_TYPE, {0, NULL}};
    
    msg.data.size = strlen(str);
    my_malloc(msg.data.size, &msg.data.memory);
    
    memshow_prefix("Send Before", msg.data.memory);
    msgsnd(msqid, &msg, sizeof(msg), 0);
    memshow_prefix("Send After ", msg.data.memory);
    
    return NULL;
}


int demo2_msgq()
{
    pthread_create(&task1_id, NULL, &taks1, NULL);
    pthread_create(&task2_id, NULL, &taks2, NULL);

    while(1)
    {
        sleep(1);
    }
}


int main()
{

//    demo1_easy();
    demo2_msgq();
    

    return 0;
}

