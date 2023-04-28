#!/bin/bash

echo "Please enter your roll number: "
read roll

# Extract the second last digit of the roll number
second_last_digit=$(echo $roll | rev | cut -c 2)

# If the second last digit is 0, consider N-5 instead
if (( $second_last_digit == 0 ))
then
    second_last_digit=5
fi

# Calculate the coordinates of point X and Y
x=$(( $second_last_digit ))
y=$(( 2 * $second_last_digit ))
y2=$(( $second_last_digit / 2 ))
y=$(( 2 * $y2 ))

# Calculate the distance between points X and Y
distance=$(echo "sqrt(($x - $y)^2 + ($y - $y2)^2)" | bc)

echo "The coordinates of point X are: ($x, $y)"
echo "The coordinates of point Y are: ($y, $y2)"
echo "The distance between points X and Y is: $distance"
