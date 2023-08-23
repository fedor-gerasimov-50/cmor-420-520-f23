#!/bin/bash

echo "This is my bash script."
echo "The current directory is $PWD, with contents sorted from largest to smallest size:"
du | sort -nr
