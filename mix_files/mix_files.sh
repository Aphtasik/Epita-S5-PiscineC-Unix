#!/bin/sh

if [ $# -ne 3 ]; then

if 
while IFS=$'\t' read -r f1 f2
do
  printf '%s\n' "$f1"
  printf '%s\n' "$f2"
done < <(paste $1 $2)
