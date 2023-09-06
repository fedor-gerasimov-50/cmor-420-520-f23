#!/bin/bash

# this checks if there is a directory with the same name as the command line argument $1 
if [ ! -d "$1" ]; then
    echo "$1 is a directory that does not already exist."
fi

