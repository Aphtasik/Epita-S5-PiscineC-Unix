#!/bin/sh

if [ $# -ne 2 ]; then
    exit 1
fi

if [ ! -f "$1" ]; then
    exit 1
fi

i=1
while IFS=";" read -r column1 column2 column3 column4
do

    if [ $i -eq $2 ]; then
        echo "$column2 is $column3"
    fi
    i=$((i + 1))
done < $1
