<<Question
write a program in shell scripting to take array as input from the user and print it in descending order.
Question

#!/bin/bash

echo "Enter the size of the array: "
read size

echo "Enter the elements of the array: "
for (( i=0; i<$size; i++ )); do
    read arr[$i]
done

echo "The original array is: ${arr[@]}"

for (( i=0; i<$size-1; i++ )); do
    for (( j=i+1; j<$size; j++ )); do
        if [ ${arr[$i]} -lt ${arr[$j]} ]; then
            temp=${arr[$i]}
            arr[$i]=${arr[$j]}
            arr[$j]=$temp
        fi
    done
done

echo "The array in descending order is: ${arr[@]}"
