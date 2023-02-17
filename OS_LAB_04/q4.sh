#!/bin/bash

echo "Enter a number: "
read num

case $num in
    1)
        echo "$num is not a perfect number"
        ;;
    *)
        sum=1
        for ((i=2; i<$num; i++)); do
            if [ $((num % i)) -eq 0 ]; then
                sum=$((sum + i))
            fi
        done

        if [ $sum -eq $num ]; then
            echo "$num is a perfect number"
        else
            echo "$num is not a perfect number"
        fi
        ;;
esac
