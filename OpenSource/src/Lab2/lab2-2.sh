#!/bin/bash

if [ $2 == "+" ]; then
    res=$(($1 + $3))
fi

if [ $2 == '-' ]; then
    res=$(($1 - $3))
fi

echo $res