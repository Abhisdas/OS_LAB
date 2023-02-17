#!/bin/bash

echo "Enter the size of the array: "
read size

echo "Enter the elements of the array: "
for (( i=0; i<$size; i++ )); do
    read arr[$i]
done

echo "The original array is: ${arr[@]}"

echo "The array in reverse order is: "
for (( i=$size-1; i>=0; i-- )); do
    echo "${arr[$i]}"
done
