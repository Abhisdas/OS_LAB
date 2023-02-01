<<Question
Write a program to find the simple interest with required Variable.
Question

echo "Enter the Principle Ammount :"
read p
echo "Enter the Time :"
read t
echo "Enter the Rate Of Interest :"
read r
mul=$((p*t*r)) 
sl=$((mul/100))
si=$((mul%100))
n=$((sl*10))
j=$((n+si))
echo "The Simple Interest Is $j"
