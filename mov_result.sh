#!/bin/bash
MODULE=chrdev
SRC=./"$MODULE".ko
TARGET=/home/nfs/module

cp -f "$SRC" "$TARGET"
if [ $? -eq 0 ]; then
    echo "cp success"
else
    echo "cp failed"
fi