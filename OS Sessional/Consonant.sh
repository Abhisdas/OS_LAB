#!/bin/bash

echo "Enter a string: "
read string

small_alpha=$(echo "$string" | grep -o "[a-z]" | tr -d "\n")
large_alpha=$(echo "$string" | grep -o "[A-Z]" | tr -d "\n")
consonants=$(echo "$string" | grep -io "[^aeiou]" | tr -d "\n")


echo "Small Alphabets: $small_alpha"
echo "Large Alphabets: $large_alpha"
echo "Consonants: $consonants"
