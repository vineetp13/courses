#!/bin/bash
NUM_PROCESSES=25600

i=1

while [ $i -le $NUM_PROCESSES ]; do
	./generate_rand_file.sh "$i.dat" 1
	let i=i+1
done

j=1
while [ $j -le $NUM_PROCESSES ]; do
#while [ 1 ]; do
	./file_contention $j &
	let j=j+1
done


