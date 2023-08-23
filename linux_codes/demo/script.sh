#!/bin/bash

grep "Applied" journals.txt > applied.txt
grep "Shark" films.txt > shark.txt
cat applied.txt shark.txt | sort > merged.txt

# this checks if the "tmp" directory exists.
# note that if/else blocks in shell scripts end with "fi"
if [ -d "tmp" ]
then
    echo "tmp dir already exists"
else
    mkdir tmp
fi

mv applied.txt shark.txt tmp
cowsay "Merged on date $(date)" >> merged.txt
