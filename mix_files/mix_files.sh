#!/bin/sh

while IFS=$'\t' read -r f1 f2
do
  printf '%s\n' "$f1"
  printf '%s\n' "$f2"
done < <(paste $1 $2)
