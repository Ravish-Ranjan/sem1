#!/bin/bash

number=$1

if [ -z "$number" ]; then
	read -p "Enter a number : " number
fi

if ! [[ "$number" =~ ^[0-9]+$ ]]; then
	echo -e "\e[1;31mError:\e[0m Not a valid number" >&2
	exit 2
fi

if (( $number % 2 == 0 )); then
	echo -e "$number is \e[1;34mEven"
else
	echo -e "$number is \e[1;34mOdd"
fi
