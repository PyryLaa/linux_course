#! /bin/bash

a=10
b=15

if [[ "$a" -gt 5 && "$b" -le 15 ]];
then
    echo "And successful"
fi

if [[ "$a" -gt 5 || "$b" -gt 20 ]];
then
    echo "Or successful"
fi

