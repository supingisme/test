#!/bin/bash

gcc src/client/client.c -o client -lssl -lcrypto

gcc src/server/server.c -o server -lssl -lcrypto

