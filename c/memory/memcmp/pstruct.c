/* Copyright (C) Rong Tao @Sylincom Beijing, 2020年 03月 05日 星期四 14:41:42 CST. */
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct id_struct {
	int id;
}__attribute__((packed)) ID_t;
typedef struct long_id_struct {
	long id;
}__attribute__((packed)) LID_t;


//extern int MY_MEMCMP(const void *s1, const void *s2, size_t len);

void demo1(int argc, char *argv[])
{
    if(argc<3)
	{
		printf("usage: a.out 1 2\n");
		exit(1);
	}
	int i;
	for(i=0;i<argc;i++)
		printf("%s\n", argv[i]);

	ID_t id1, id2;

	id1.id = atoi(argv[1]);
	id2.id = atoi(argv[2]);
	
	printf("%d:%d\n", id1.id, id2.id);

	int ret;
    
	ret = memcmp(&id1, &id2, sizeof(ID_t)); //这里输出结果不对，数组比较不可这样用
	printf("ret = %d, %d:%d\n", id1.id, id2.id);
    
}
void demo2(int argc, char *argv[])
{
    if(argc<3)
	{
		printf("usage: a.out 1 2\n");
		exit(1);
	}
	ID_t *id1 = malloc(sizeof(ID_t));
    ID_t *id2 = malloc(sizeof(ID_t));

    memset(id1, 0, sizeof(ID_t));
    memset(id2, 0, sizeof(ID_t));
    
	id1->id = atoi(argv[1]);
	id2->id = atoi(argv[2]);
	
	printf("%d:%d\n", id1->id, id2->id);

	int ret;
    
	ret = memcmp(id1, id2, sizeof(ID_t)); //这里输出结果不对，数组比较不可这样用
	printf("ret = %d, %d:%d\n", id1->id, id2->id);
    
}

void demo3(int argc, char *argv[])
{
    if(argc<3)
	{
		printf("usage: a.out 1 2\n");
		exit(1);
	}
	LID_t *id1 = malloc(sizeof(LID_t));
    LID_t *id2 = malloc(sizeof(LID_t));

    memset(id1, 0, sizeof(LID_t));
    memset(id2, 0, sizeof(LID_t));
    
	id1->id = atol(argv[1]);
	id2->id = atol(argv[2]);
	
	printf("%ld:%ld\n", id1->id, id2->id);

	int ret;
    
	ret = memcmp(id1, id2, sizeof(LID_t)); //这里输出结果不对，数组比较不可这样用
	printf("ret = %d, %ld:%ld\n", id1->id, id2->id);
    
}

int main(int argc, char *argv[])
{
	demo1(argc, argv);
	demo2(argc, argv);
	demo3(argc, argv);

	return 0;
}
