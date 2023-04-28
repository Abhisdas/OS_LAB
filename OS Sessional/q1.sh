#!/bin/bash

echo "Enter a character: "
read char

case $char in

    [[:upper:]])
        echo "The character is uppercase."
        ;;

    [[:lower:]])
        echo "The character is lowercase."
        ;;

    *)
        echo "The character is not a letter."
        ;;
esac
