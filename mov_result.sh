#!/bin/bash
MODULE=template
SRC=./"$MODULE".ko
TARGET=/home/zhao/linux/nfs/rootfs/module

cp -f "$SRC" "$TARGET"
if [ $? -eq 0 ]; then
    echo "cp success"
else
    echo "cp failed"
fi