#!/bin/bash

echo "Enter a number: "
read num

num_copy=$num
reverse=0

case $num in
    0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9)
        echo "$num is a palindrome number"
        ;;
    *)
        while [ $num -gt 0 ]; do
            digit=$((num % 10))
            reverse=$((reverse * 10 + digit))
            num=$((num / 10))
        done

        if [ $num_copy -eq $reverse ]; then
            echo "$num_copy is a palindrome number"
        else
            echo "$num_copy is not a palindrome number"
        fi
        ;;
esac
