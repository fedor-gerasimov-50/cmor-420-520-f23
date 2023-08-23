#!/bin/bash
fname=$1
ext=$2
cat *$ext > $fname
date >> $fname 
echo "Wrote all files ending in $ext to a file named $fname on $(date)."
