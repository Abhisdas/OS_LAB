<<Question
Write a Program to take Two numbers as input from the user and swap them Using the third variable.
Question

#!/bin/bash
echo "Enter first number(A) Of Your Choice :"
read a
echo "Enter Second number(B) Of Your Choice :"
read b
echo "__________________Before Swapping________________"
#swapping
echo "First number: $a"
echo "Second number: $b"
temp=$a
a=$b
b=$temp
echo "_________________After Swapping________________"
echo "First number: $a"
echo "Second number: $b"