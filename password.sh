#!/bin/bash

pass=$1

if [ $# -eq 0 ]
then
	echo "Too many script arguments"
	exit 1
fi


regex1="^.{8,}$"
#check password for min length
if ! [[ $pass =~ $regex1 ]] 
then
	echo "Password is too weak! Must be 8 or more characters"
	exit 1
fi
#check password for at least one numeric character
regex2="^.*[0-9].*$"
if ! [[ $pass =~ $regex2 ]]
then 
	echo "Password is too weak! Must have at least one number"
	exit 1
fi
#check password for at least one non alpha-numeric character
regex3=".*[^@#$%&*+-=].*$"
if ! [[ $pass =~ $regex3 ]] 
then
		echo "Password is too weak! Must contain at least one of the following:"
		echo "@, #, $, %, &, *, +, -, ="
		exit 1
fi

echo "You have a strong password, good job!"
#print out failed tests or all good message if it passes the test 

#use regex

#use newer syntax [[]]

