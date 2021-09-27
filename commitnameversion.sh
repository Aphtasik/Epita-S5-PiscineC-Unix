#!/bin/sh

rm -rf a.out
git add .
git commit -m "$1"
git tag -a "exercises-$2-$3" -m "$3"
git push --follow-tag
