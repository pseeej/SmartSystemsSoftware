#!/bin/bash

number=1

while [ $number -le $1 ]
do
    echo "hello world"
    ((number++))
done