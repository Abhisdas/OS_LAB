<<Question
write a program in shell scripting using switch case to take number input from the user and find whether the 
number is prime number or not.
Question


#!/bin/bash

echo "Enter a number: "
read num

case $num in
    1)
        echo "$num is not a prime number"
        ;;
    2)
        echo "$num is a prime number"
        ;;
    *)
        is_prime=1
        for ((i=2; i<=$num/2; i++)); do
            if [ $((num%i)) -eq 0 ]; then
                is_prime=0
                break
            fi
        done

        if [ $is_prime -eq 1 ]; then
            echo "$num is a prime number"
        else
            echo "$num is not a prime number"
        fi
        ;;
esac
