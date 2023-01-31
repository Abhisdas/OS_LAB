<<Question
Write a Program to try all the Syntaxes for Division Operation Using Bash.
Question

#!/bin/sh
echo "Enter the Numbers Of Your Choice :-"
read a b
ans1= $((a/b))
ans2= `expr $a / $b`
ans3= `echo $a / $b || bc`
ans4= `echo $a / $b |bc -l`
ans5= $(echo "scale=4; $a / $b" |bc)
echo "The Answer By 1st method is $ans1"
echo "The Answer By 2nd method is $ans2"
echo "The Answer By 3rd method is $ans3"
echo "The Answer By 4th method is $ans4"
echo "The Answer By 5th method is $ans5"