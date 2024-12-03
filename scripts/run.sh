#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <Number Of AOC Day>"
    exit 1
fi

cp -r daily-template "day-$1"
echo "day-$1 initialised"