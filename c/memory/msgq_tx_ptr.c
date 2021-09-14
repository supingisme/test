#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/msg.h>



struct mcpy_struct {
    unsigned int size;
    void    *memory;
};

char *str = {"rongtao Memory test"};


#define memshow(m) printf("\t%s \t%p \t%s\n", #m, m, m)

#define memshow_prefix(prefix, m) printf("[%s] \t%s \t%p \t%s\n", prefix, #m, m, m)


int my_malloc_pp(unsigned int size, void **buf)
{
    *buf = malloc(size);
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
	key_t key = ftok(MSG_FILE, 123);
	int msqid = msgget(key, IPC_CREAT|0777);

        
	struct msg_form msg = {MSG_TYPE, 0};
    
    msgrcv(msqid, &msg, sizeof(msg), msg.mtype, 0);

   char *recv_str = (void*)msg.data.memory;
    
    memshow_prefix("Recv After ", recv_str);
    
    return NULL;
}

void *taks2(void *arg)
{
	key_t key = ftok(MSG_FILE, 123);
	int msqid = msgget(key, IPC_CREAT|0777);
    
	struct msg_form msg =  {MSG_TYPE, 0};
    
    msg.data.size = strlen(str);

    my_malloc_pp(msg.data.size, (void**)&msg.data.memory);
    
    
    strcpy(msg.data.memory, str);
    
    msgsnd(msqid, &msg, sizeof(msg), 0);
    memshow_prefix("Send After ", msg.data.memory);


    return NULL;
}

int main()
{
    pthread_create(&task1_id, NULL, &taks1, NULL);
    pthread_create(&task2_id, NULL, &taks2, NULL);

    while(1)
    {
        sleep(1);
    }
    

    return 0;
}


