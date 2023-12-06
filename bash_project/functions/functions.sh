#! /bin/bash

var=1

echo "Value before function is: ${var}"

addition(){
    val=$1
    val=$((val+1))
    return $val
}
addition var
var=$?

echo "Value after function is: ${var}"
