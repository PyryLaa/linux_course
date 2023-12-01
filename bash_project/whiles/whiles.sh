#! /bin/bash

file=testirivit.txt

while read -r line;
do
    echo $line
done < "$file"
