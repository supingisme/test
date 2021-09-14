#!/bin/bash
#rongtao

for oid in `cat $1`; do
	echo "\"$oid\","
done
