#!/bin/bash

eval "mkdir $1"
eval "cd $1"
for i in 1 2 3 4 5
do
    eval "mkdir file$i"
    eval "touch file$i.txt"
    eval "cd file$i"
    eval "touch file$i.txt"
    eval "ln -s file$i.txt ../file$i.txt"
    eval "cd ../"
done
    
    
exit 0