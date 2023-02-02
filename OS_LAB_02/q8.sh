<<Question
Write a program to Enter the value of base and exponent and Find the final answer.
Question

#!/bin/sh
echo "Enter the values of base :"
read base 
echo "Enter the values of exponent :"
read exponent
answer=$((base** exponent))
echo "The Final answer is : $answer"