#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

if [ ! -f "$1" ]; then
    exit 1
fi

filename=$1
while read line; do
    var="$($(echo "$line" | wc -m))"
    if [ "$var" -ge 80 ]; then
        echo "$line"
    fi
done < "$filename"

