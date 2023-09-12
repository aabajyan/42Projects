#!/bin/sh

./PmergeMe $(seq 1 $(( $RANDOM % 10000 + 3000 )) | sort -R | tr '\n' ' ')