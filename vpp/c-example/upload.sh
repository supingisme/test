#!/bin/bash
# 上传代码到 服务器

dst=10.170.6.66
path=/root/workspace/test/vpp/c-example
user=root

scp -r * $user@$dst:$path

