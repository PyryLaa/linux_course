#! /bin/bash

array=("First" "Second" "Third" "Fourth" "Fifth" "Sixth")

echo "Printing all members of the array"
echo "${array[@]}"

echo "Printing first member of the array"
echo "${array[0]}"

echo "Printing members from the second index"
echo "${array[@]:1}"

echo "Printing members from 2nd index to 6th index"
echo "${array[@]:1:6}"
