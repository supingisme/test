/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:04 CST. */
/* Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. */
#include <stdio.h>

extern char __start_bindata;
extern char __stop_bindata;

int main() {
  char *p;
  for (p = &__start_bindata; p < &__stop_bindata; p++) {
    putchar(*p);
  }
  return 0;
}
