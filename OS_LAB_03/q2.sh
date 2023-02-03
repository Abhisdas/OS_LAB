<<question
2 : WAP to take a number as a input and find the sum of it's digits , if the sum is a single digit number that 
itself is your final ans otherwise continue the process till the sum is a single digit number.
question
#!/bin/sh
echo "Enter a number Of Your Choice :"
read num
while [ $num -gt 9 ]; do
sum=0
while [ $num -gt 0 ]; do
sum=$((sum+num % 10 ))
num=$(( num / 10))
done
num=$sum
done
echo "The single digit num is : $num"