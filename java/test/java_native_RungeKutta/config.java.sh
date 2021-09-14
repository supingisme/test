#!/bin/bash

javac RungeKutta.java

javah -d ./lib/ RungeKutta

sh config.library.sh

java -Djava.library.path=lib/ RungeKutta
