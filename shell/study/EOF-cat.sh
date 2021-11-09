#!/bin/bash 

# demo 1
cat<<'EOF'
Line 1
This is a pen;
Hello world.
EOF

# demo2
cat > hello.c << EOF
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  printf("Hello world!\n");
    sleep(999999999);
}
EOF
