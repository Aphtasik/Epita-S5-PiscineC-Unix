#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

if [ ! -f "$1" ]; then
    exit 1
fi

while IFS=read line; do
    var=$(echo -n "$line" | wc -c)
    [ "$var" -ge 80 ] && echo -n "$line" && echo ""
done < "$1"

