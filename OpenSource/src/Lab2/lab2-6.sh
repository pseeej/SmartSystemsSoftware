#!/bin/bash

eval "mkdir $1"
eval "cd $1"
for i in 1 2 3 4 5
do
    eval "touch file$i.txt"
done

eval "tar -cvf files.tar file1.txt file2.txt file3.txt file4.txt file5.txt"

eval "mkdir files"

eval "mv files.tar files"
eval "cd files"
eval "tar -xf files.tar"
    
    
exit 0