<< Question
write a program in shell scripting to take number input from the user and display it in word.
Question

#!/bin/bash

echo "Enter a number: "
read num

digits=('zero' 'one' 'two' 'three' 'four' 'five' 'six' 'seven' 'eight' 'nine')
thousands=$((num / 1000))
num=$((num % 1000))
hundreds=$((num / 100))
num=$((num % 100))
tens=$((num / 10))
num=$((num % 10))
ones=$num

if [ $thousands -gt 0 ]; then
    echo -n "${digits[$thousands]} thousand "
fi

if [ $hundreds -gt 0 ]; then
    echo -n "${digits[$hundreds]} hundred "
fi

if [ $tens -eq 1 ]; then
    case $ones in
        0) echo -n "ten" ;;
        1) echo -n "eleven" ;;
        2) echo -n "twelve" ;;
        3) echo -n "thirteen" ;;
        4) echo -n "fourteen" ;;
        5) echo -n "fifteen" ;;
        6) echo -n "sixteen" ;;
        7) echo -n "seventeen" ;;
        8) echo -n "eighteen" ;;
        9) echo -n "nineteen" ;;
    esac
else
    if [ $tens -gt 1 ]; then
        case $tens in
            2) echo -n "twenty" ;;
            3) echo -n "thirty" ;;
            4) echo -n "forty" ;;
            5) echo -n "fifty" ;;
            6) echo -n "sixty" ;;
            7) echo -n "seventy" ;;
            8) echo -n "eighty" ;;
            9) echo -n "ninety" ;;
        esac

        if [ $ones -gt 0 ]; then
            echo -n " "
            echo -n "${digits[$ones]}"
        fi
    else
        if [ $ones -gt 0 ]; then
            echo -n "${digits[$ones]}"
        fi
    fi
fi

echo ""
