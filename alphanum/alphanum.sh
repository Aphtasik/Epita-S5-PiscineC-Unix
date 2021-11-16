#!/bin/sh

for var in "$@"
do
    echo "it is empty"
    if grep -q ' \*' $var
    then
        echo "it is empty"
    fi
done
