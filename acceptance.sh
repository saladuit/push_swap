#!/bin/bash

check_error() {

	./push_swap $1 2>| ERROR
	if [[ $(cat ERROR) == "Error" ]]; 
then
	echo ok
else
	echo ko
fi
rm ERROR
}

check_pass() {

	./push_swap $1 2>| PASS
	if [[ $(cat PASS) == "" ]]; 
then
	echo ok
else
	echo ko
fi
rm PASS
}

check_pass "1"
check_pass "1 2"
check_pass "1 2 3 4 5 6 7 8 9"
check_pass ""2 3" 1 2 3 4 5 6 7 8 9"
#./push_swap "-+10"
#./push_swap "10+-"
#./push_swap 0 9 8 7 6 5 4 3 2 1

#Error Cases
check_error "Error afwahifaw"
#./push_swap a
#./push_swap 0 a
#./push_swap 0 1a
#./push_swap 0 \n
