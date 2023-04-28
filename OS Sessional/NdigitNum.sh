#!/bin/bash

echo "Please enter your first name: "
read name

length=${#name}

# Calculate smallest and largest N-digit numbers
smallest=$(printf "1%0.s" $(seq 1 $((length-1))))
largest=$(printf "9%0.s" $(seq 1 $((length-1))))

echo "Smallest $length-digit number: $smallest"
echo "Largest $length-digit number: $largest"
