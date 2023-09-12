#!/bin/sh

try() {
    result=$(./RPN "$1")
    if [ "$result" = "$2" ]; then
        echo "OK"
    else
        echo "KO (Expected $2, but got $result)"
    fi
}

try_no_value() {
    try "$1" "There's no value to pick."
}

try_unexpected_token() {
    try "$1" "Unexpected token."
}

# Compile
make re >/dev/null

# Test
try '6' '6'
try '6 8' '8'
try '6 8 1 0' '0'
try '1234' '4'
try '1234--' '3'
try '   5     ' '5'
try '1  2  +   ' '3'
try '8     9  *  9 -  9   -  9 - 4 -  1 +    ' '42'
try '7 7 * 7 -' '42'
try '124324523432523453456++++++++++' '42'

try_no_value '6 +'
try_no_value '6 6 * *'

try_unexpected_token '(1 + 1)'
try_unexpected_token '6 6 !'
try_unexpected_token '\0'
