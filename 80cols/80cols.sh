#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

if [ ! -f "$1" ]; then
    exit 1
fi

while IFS= read -r line; do
    var=$(echo -n "$line" | wc -c)
    if [ "$var" -ge 80 ]; then
        echo -E "$line"
    fi
done < "$1"

