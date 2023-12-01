
#! /bin/bash

#Test if file can be opened, if yes then print it out

if [ -r ./testfile.txt ];
then
    content=$(cat ./testfile.txt)
    echo $content
elif [ -f ./testfile.txt ];
then
    echo "File could not be opened"
fi 
