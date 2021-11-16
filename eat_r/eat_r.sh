#!/bin/sh

for var in "$@" 
do
    if [ $var = ${@: -1} ]
    then
        echo "$var" | tr -d 'rR'
    else
        echo -n "$var, " | tr -d 'rR'
    fi
done

