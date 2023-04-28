

read -p "Enter your roll number: " roll

if (( $(echo "scale=2; $(echo $roll | grep -o . | awk '{s+=$1} END {print s/NR}')" '<' 4 | bc -l) )); then
  echo "Sorted roll in ascending order: $(echo $roll | grep -o . | sort | tr -d '\n')"
elif (( $(echo "scale=2; $(echo $roll | grep -o . | awk '{s+=$1} END {print s/NR}')" '>' 4 | bc -l) )); then
  echo "Sorted roll in descending order: $(echo $roll | grep -o . | sort -r | tr -d '\n')"
else
  echo "Reversed roll: $(echo $roll | rev)"
fi
