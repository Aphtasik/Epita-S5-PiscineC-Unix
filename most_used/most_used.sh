#!/bin/sh

history | tr -s ' ' | cut -d ' ' -f3 | sort | uniq -c | sort -r | head >&1
