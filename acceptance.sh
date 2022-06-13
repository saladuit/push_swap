#!/bin/bash

./push_swap ""
./push_swap 1
./push_swap a
./push_swap 1 2
./push_swap 10+-
./push_swap -+10
./push_swap 1 2 3 4 5 6 7 8 9
./push_swap 0 9 8 7 6 5 4 3 2 1

#Error Cases
./push_swap 0 a
./push_swap 0 1a
./push_swap 0 \n
