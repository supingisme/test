#!/bin/bash

function cmake_versioncmp() {
CURRENT_VERSION=`cmake --version | grep version | awk '{print $3}'`
CMPARETO_VERSION=$1

if [ $CURRENT_VERSION \> $CMPARETO_VERSION ]; then
	echo "当前版本大于所需版本"
	return 1
elif [ $CURRENT_VERSION = $CMPARETO_VERSION ]; then
	echo "当前版本等于所需版本"
	return 2
elif [ $CURRENT_VERSION \< $CMPARETO_VERSION ]; then
	echo "当前版本小于所需版本"
	return 3
fi
}

cmake_versioncmp 2.3.4
echo $?

cmake_versioncmp 3.3.1
echo $?

cmake_versioncmp 4.3.4
echo $?
