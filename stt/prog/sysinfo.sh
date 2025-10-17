#!/bin/bash

outputfile="sysinfo.txt"

{
	echo -n -e "\e[1;34mDate & Time    : \e[0m"
	date +"%A, %d %B %Y %I:%M:%S %p" # displaying date and time in formated manner

	echo -n -e "\e[1;34mLogged-in User : \e[0m"
	whoami # displaying username

	echo -n -e "\e[1;34mSystem uptime  : \e[0m"
	uptime -p # displaying uptime of system in formatted manner

	echo -n -e "\e[1;34mDisk usage (/) : \e[0m"
	df -h / | awk 'NR==2 {print "Used : " $3 " (" $5 ") | Avilable : " $4 " | Total : " $2 " | Mount point : " $6}' # displaying disuage in formatted manner
} > "$outputfile"

echo "System information saved in file $utputfile"
