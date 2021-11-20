#!/bin/sh

cut -d ' ' -f 1 ~/.bash_history | sort | uniq -c | sort -nr | head  -n 10 | tr -s " "

