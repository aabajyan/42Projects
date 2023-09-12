#!/bin/bash

trap "rm -f sort_check.log output.log" EXIT

# Compile
make re >/dev/null

END=${1:-100}

for n in $(seq 1 $END); do
    printf "Case $n: "
    ./PmergeMe $(seq 1 $(( $RANDOM % 10000 + 3000 )) | sort -R | tr '\n' ' ') >/dev/null
    if [ $? -eq 0 ]; then
        echo "OK"
    else
        echo "KO"
    fi
done
