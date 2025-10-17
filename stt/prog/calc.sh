#!/bin/bash

firstnum=$1 # getting first number from file call args
operation=$2 # getting operation from file call args
secondnum=$3 # getting second number from file call args

# getting first number if not provided
if [ -z "$firstnum" ]; then
	read -p "Enter first number : " firstnum
fi

# validating first input
if ! [[ $firstnum =~ ^[0-9]+$ ]]; then
	echo -e "\e[1;31mError:\e[0m Not a valid number" >&2 # printing error
	exit 2 # exiting with error code 2
fi

# getting operation to perform if not provided
if [ -z "$operation" ]; then
	read -p "Enter operation (+ - * /) : " operation
fi
operation="$(echo "$operation" | tr -d '\r' | xargs)"

# valudating operation
if ! [[ "$operation" == "+" || "$operation" == "-" || "$operation" == "*" || "$operation" == "/" ]]; then
	echo -e "\e[1;31mError:\e[0m Not a valid operation" >&2 # printing error
	exit 2 # exiting with error code 2
fi

# getting second number if not provided
if [ -z "$secondnum" ]; then
	read -p "Enter second number : " secondnum
fi

# validating second input
if ! [[ $secondnum =~ ^[0-9]+$ ]]; then
	echo -e "\e[1;31mError:\e[0m Not a valid number" >&2 # printing error
	exit 2 # exiting with error code 2
fi

# catching if divide by zero opeation is given
if [[ "$operation" == "/" && "$secondnum" -eq 0 ]];then
	echo -e "\e[1;31mError:\e[0m Division by zero" >&2
	exit 2
fi

res=$(( firstnum $operation secondnum )) # calculating result
echo -e "\e[1;34mResult :\e[0m $res" # displaying result
