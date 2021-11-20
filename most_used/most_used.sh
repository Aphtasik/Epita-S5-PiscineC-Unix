#!/bin/sh

# history | tr -s ' ' | cut -d ' ' -f3 | sort | uniq -c | sort -r | head
echo "$(<~/.bash_history)" | tr -s ' ' | cut -d ' ' -f3 | sort | uniq -c | sort -r | head

