#!/bin/bash 

# 如果没有add 和 commit，
# 清除修改的文件，但是不能清除 添加的文件
git checkout .

# 如果需要清除 没有add 和 commit 的添加的文件
git clean -df

# 对于 add 的部分，先要撤销add
git reset .
# 在进行 清理即可
git checkout .

# 清除已经 commit 的文件
git reset --hard <commit_id>
