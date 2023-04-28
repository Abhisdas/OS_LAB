#!/bin/bash

read -p "Please enter your roll number: " roll

# Compute the average of the digits
digits_sum=0
for digit in ${roll// /}; do
    digits_sum=$((digits_sum+digit))
done

average=$(bc -l <<< "$digits_sum/${#roll}")

# Apply different operations based on the value of the average
if (( $(bc -l <<< "$average < 4") )); then
    echo "The sorted roll number is $(echo $roll | grep -o . | sort | tr -d '\n')"
elif (( $(bc -l <<< "$average > 4") )); then
    echo "The reverse sorted roll number is $(echo $roll | grep -o . | sort -r | tr -d '\n')"
else
    echo "The reversed roll number is $(rev <<< $roll)"
fi
