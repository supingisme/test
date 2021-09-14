#!/bin/bash

#SELINUX=/etc/sysconf/selinux
SELINUX=selinux

sed -i 's/SELINUX=enforcing/SELINUX=disabled/g' $SELINUX
echo "the /etc/sysconfig/selinux file has changed to "
grep 'SELINUX' $SELINUX | grep -v '^#'
