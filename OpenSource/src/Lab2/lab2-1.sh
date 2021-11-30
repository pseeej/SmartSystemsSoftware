#!/bin/sh

a=0

while [ $a -lt $1 ]
do
   echo Hello, World
   a=`expr $a + 1`
done