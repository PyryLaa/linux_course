#! /bin/bash

#Brace expansion, creates three directories
#/tmp/t1 /tmp/t2 and /tmp/t3
#then changes into tmp directory
#and prints the created directories info
#then remove the directories

str="removed"

mkdir /tmp/{t1,t2,t3};cd /tmp/;ls -l t*;rm -r /tmp/{t1,t2,t3};

if [[ ! -d /tmp/{t1,t2,t3} ]];
then
    echo "Directories $str" #Just to give an example of paratmeter expansion
fi



