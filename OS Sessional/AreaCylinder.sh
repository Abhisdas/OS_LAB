#!/bin/bash

echo "Please enter your roll number: "
read roll

# Extract first and last digits of roll number
first=$(echo $roll | cut -c1)
last=$(echo $roll | rev | cut -c1)

# Set default values for radius and height if either is 0
if [ $first -eq 0 ]
then
    first=10
fi

if [ $last -eq 0 ]
then
    last=10
fi

# Calculate surface area of cylinder
radius=$first
height=$last
pi=3.14159265358979323846
area=$(echo "2 * $pi * $radius * ($radius + $height)" | bc -l)

echo "The surface area of the cylinder is: $area"
