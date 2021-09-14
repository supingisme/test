#!/bin/bash

#终止占用/home进程
fuser -m -w -i -k /home
