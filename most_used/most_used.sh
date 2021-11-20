#!/bin/sh

echo "$(<~/.bash_history)" | tr -s ' ' | cut -d ' ' -f3 | sort | uniq -c | sort -r | head | tr -s " " 

