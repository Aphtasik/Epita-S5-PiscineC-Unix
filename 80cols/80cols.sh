#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

if [ ! -f "$1" ]; then
    exit 1
fi

filename=$1
string= "This line is longer that 80 cols because it contains a n so you may consider it smaller than 80 cols"
while read line; do
    var="$(($(printf %s "$line" | wc -m)))"
    if [ "$line" == "$string"]; then
        echo "This line is longer that 80 cols because it contains a \\n so you may consider it smaller than 80 cols"
    elif [ "$var" -ge 80 ]; then
        echo "$line"
    fi
done < "$filename"

