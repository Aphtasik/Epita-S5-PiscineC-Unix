#!/bin/sh

for var in "$@" 
do
    echo "$var" | tr -d 'rR'
done
