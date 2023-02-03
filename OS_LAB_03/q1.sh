<<question
1 : WAP to take 3 numbers as the input and display the largest number among them
question
#!/bin/sh
echo "Enter the 1st number:-"
read num1
echo "Enter the 2nd number:-"
read num2
echo "Enter the 3rd number:-"
read num3
if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then
    echo "The Greatest Number is : $num1"
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]
then
    echo "The Greatest Number is : $num2"
else
    echo "The Greatest Number is : $num3"
fi