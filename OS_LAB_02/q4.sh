<<Question
Write a Program to take Two numbers as input from the user and swap them without the third variable.
Question

#!/bin/bash
echo "Enter first number(A) Of Your Choice :"
read a
echo "Enter Second number(A) Of Your Choice :"
read b
echo "A Before Swapping is $a and B is $b"
#swapping
a=$((a+b))
b=$((a - b))
a=$((a-b))
echo "A after swapping is  $a and B is $b"