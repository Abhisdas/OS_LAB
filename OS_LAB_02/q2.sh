<<question
Write a program to take the input in sec and display the time in hrs,min,sec format.
question

#!/bin/bash
echo "Enter time in seconds:"
read seconds
hours=$((seconds / 3600))
minutes=$((seconds % 3600 / 60))
remaining_seconds=$((seconds % 60))
echo "Time in hh:mm:ss format: $hours:$minutes:$remaining_seconds"