<<Question
Write a program to find the area of Circle using Heron's Formula.
Question

echo "Enter the first side: "
read a
echo "Enter the second side: "
read b
echo "Enter the third side: "
read c
s=$(echo "($a + $b + $c) / 2 " | bc -l)
area=$(echo "sqrt($s * ($s - $a) * ($s - $b) * ($s - $c))" | bc -l)
echo "The area of the triangle is $area"