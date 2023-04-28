#!/bin/bash

echo "Enter first number: "
read num1

echo "Enter second number: "
read num2

echo "Select an operation:"
echo "1. Maximum"
echo "2. Minimum"
read choice

case $choice in
    1) 
        if [ $num1 -gt $num2 ]
        then
            echo "Maximum is: $num1"
        else
            echo "Maximum is: $num2"
        fi
        ;;
    2) 
        if [ $num1 -lt $num2 ]
        then
            echo "Minimum is: $num1"
        else
            echo "Minimum is: $num2"
        fi
        ;;
    *) echo "Invalid choice";;
esac
