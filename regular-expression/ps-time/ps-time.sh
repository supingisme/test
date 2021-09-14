#!/bin/bash

ps -eo pid,etime,cmd | grep $* | awk '{print $2}'
