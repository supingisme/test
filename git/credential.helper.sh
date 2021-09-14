#!/bin/bash
# git永久保存账号密码，免去git重复输入账号密码操作
# 直接在git bash 中执行命令：git config --global credential.helper store
# 在输入一次账号密码就可以保存了

git config --global credential.helper store
