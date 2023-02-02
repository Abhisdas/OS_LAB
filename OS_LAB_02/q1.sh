<<Question
Write a Program to do all the Possible Syntax for division Operation.
Question

#!/bin/sh
echo "Enter the Numbers:-"
read n1 n2
ans1=$(( n1 / n2))
ans2=`expr $n1 / $n2`
ans3=`echo $n1 / $n2 |bc`
ans4=`echo $n1 / $n2 |bc -l`
ans5=$(echo "scale=4; $n1 / $n2" | bc)
echo "The number by first method is: $ans1"
echo "The number by second method is: $ans2"
echo "The number by third method is: $ans3"
echo "The number by fourth method is: $ans4"
echo "The number by fifth method is: $ans5"