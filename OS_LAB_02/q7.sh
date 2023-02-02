<<question
Write a Program to Find the area of triangle using heron's formula.
question
#!/bin/sh
echo "Enter three sides of triangle (a,b,c): "
read a b c
s=$((($a+$b+$c)/2))
peri=$(echo "scale=4; $s * ($s - $a)* ($s- $b)*($s- $c)" | bc)
perim=$(echo "scale=4; sqrt($peri)" |bc)
echo "The perimeter of the triangle by hereons formula is $perim"