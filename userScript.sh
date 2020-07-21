#!/bin/bash


awk '{print $1, $2}' ./users.txt

# takes 3 arguments.  Input filename of users, group name and operation flag
# for example: sudo userScript.sh ./users.txt newUsers -a

# pseudo code 
if args !3  do
	echo "Please enter 3 arguments"
exit
else

IFS=" "
	for each line[i] read
		first string=user
		second string=password
		assign user to $user[i] variable
		assign password to $pass[i] variable
		assign groupName to $groupName
	exit



	while file has line
		if operation flag= -a
			adduser $user[i] with password $pass[i] to group $groupName
			create  home directory for $user[i]	
 			echo "User " $user[i] "Has been created"
        		echo "User " $user[i] "has been added to group " $groupName

		else
			removeuser $user[i] from system
			removeuser from group $groupName
			delete $user[i] home directory
	
fi
