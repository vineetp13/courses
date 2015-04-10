#!/bin/bash

# Generate the file if it doesn't exist.
if [ ! -f $1 ]; then
	dd if=/dev/urandom of=./$1 bs=4096 count=1
fi
