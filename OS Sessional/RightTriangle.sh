#!/bin/bash

echo "Please enter your first name: "
read name

length=${#name}

if (( $length % 2 == 0 ))
then
    for (( i=1; i<=$length; i++ ))
    do
        for (( j=1; j<=$i; j++ ))
        do
            echo -n "*"
        done
        echo ""
    done
else
    for (( i=$length; i>=1; i-- ))
    do
        for (( j=1; j<=$i; j++ ))
        do
            echo -n "*"
        done
        echo ""
    done
fi
