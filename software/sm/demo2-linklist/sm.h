/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:06:45 CST. */
#pragma once

typedef struct key_t {
	int key;
	struct key_t *sub;
}sm_key_t;

enum {E_1,E_2,E_3,E_4,E_5,E_6,E_7,E_8,E_9};

enum {s11,s12,s13,};
enum {s21,s22,s23,};
enum {s31,s32,s33,};

typedef int (*sm_handler_f)(int id, void *arg);

struct sm_node_t {
	sm_key_t state;
	sm_key_t event;
	sm_handler_f handler;
};

int insert_sm_table(const char *fmt, int s1, ...) __attribute__((format(printf, 1,3)));

