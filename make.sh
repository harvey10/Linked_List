#!/bin/bash
echo -e "Please enter file name"
read file
if [ -e $file.cpp ]; then
    clear
    g++ -Wall -Wextra $file.cpp -o $file.o 2> error.txt
    if [ -e $file.o ]; then
	./$file.o
    fi
else
    echo "File does not exist"
fi
