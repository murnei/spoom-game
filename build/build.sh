#!/bin/bash

rm -f *.o

clang -I../inc ../src/*.c -o program.o
./program.o
