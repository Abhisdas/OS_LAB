<<Question
write a program in shell scripting using switch case to take number input from the user and find whether
the number is Armstrong number or not.

Question


#!/bin/bash

echo "Enter a number: "
read num

num_copy=$num
num_digits=${#num} 
sum=0

case $num in
    0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9)
        echo "$num is an Armstrong number"
        ;;
    *)
        while [ $num -gt 0 ]; do
            digit=$((num % 10))
            sum=$((sum + digit**num_digits))
            num=$((num / 10))
        done

        if [ $sum -eq $num_copy ]; then
            echo "$num_copy is an Armstrong number"
        else
            echo "$num_copy is not an Armstrong number"
        fi
        ;;
esac
