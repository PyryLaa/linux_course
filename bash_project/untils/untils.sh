#! /bin/bash

i=0

until [ $i -eq 5 ];
do
    echo "Iterator is now $i"
    ((i++))
done    
