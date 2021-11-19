#!/bin/sh

if [ $# -ne 2 ]
then
    echo "Usage: mix_files file1 file2" >&2
    exit 1
fi

if [ ! -f "$1" ] && [ ! -f "$2" ]
then
    exit 1
fi

nb1=$(cat "$1" | wc -l )
min=$nb1
nb2=$(cat "$2" | wc -l )
max=$nb2
maxfile=$2
i=1

if [ $nb1 -gt $nb2 ]
then
    min=$nb2
    max=$nb1
    maxfile=$1
fi

while [ $((min + 1)) -ne $i ]
do
    head -n $i "$1" | tail -n 1
    head -n $i "$2" | tail -n 1
    i=$((i + 1))
done

tail -n $((max - i + 1)) $maxfile

exit 0
