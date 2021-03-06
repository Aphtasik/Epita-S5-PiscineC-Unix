#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

if [ ! -f "$1" ]; then
    exit 1
fi

while IFS= read -r line; do
    var=$(($(printf %s $line | wc -c)))
    if [ "$var" -ge 80 ]; then
        echo $line
    fi
done < "$1"

