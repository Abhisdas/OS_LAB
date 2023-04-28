#!/bin/bash

read -p "Enter a string: " input_string

if [[ "$input_string" == [[:upper:]]* ]]; then
    echo "The string is in uppercase."
elif [[ "$input_string" == [[:lower:]]* ]]; then
    echo "The string is in lowercase."
else
    echo "The string is not entirely uppercase or lowercase."
fi
