#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

if [ ! -f "$1" ]; then
    exit 1
fi

while IFS= read line; do
    var=$(echo -n "$line" | wc -c)
    if [ "$var" -ge 80 ]; then
        echo "$line"
    fi
done < "$1"

