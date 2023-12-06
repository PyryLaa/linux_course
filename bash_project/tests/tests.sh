#! /bin/bash

str="This is a string"

test -n str && echo 'String length is >0' || echo 'String length is = 0'
