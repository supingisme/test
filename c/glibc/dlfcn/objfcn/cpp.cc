#include "cpp.h"

#include <stdio.h>

#ifndef thread_local
#define thread_local
# warning 编译时候 提示 ‘thread_local’不是一个类型名
#endif

namespace {
thread_local int g_tls_var = 19;
thread_local int g_tls_var2 = 120;
thread_local int g_tls_bss;
thread_local int g_tls_bss2;
}

__attribute__((constructor))
static void init() {
  ++g_tls_bss;
}

extern "C" {
  int func(int x) {
    g_tls_var++;
    g_tls_bss -= 3;
    g_tls_bss2 += 3;
    return x + g_tls_var + g_tls_var2 + g_tls_bss + g_tls_bss2;
  }
}

class BaseImpl : public Base {
public:
  int vf() override {
    return 1234;
  }
};

Base* MakeBase() {
  return new BaseImpl();
}
