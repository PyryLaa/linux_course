#! /bin/bash

#Creates a directory, name specified by user from cli
#Also creates a .sh file with the same name and gives
#execute privileges for the user for that file
#Lastly opens the file in emacs for edit

dir_name=$1
file_name="${dir_name}.sh"
mkdir "${dir_name}";cd "${dir_name}";touch "${file_name}";chmod 755 "${file_name}";emacs -nw "${file_name}";
