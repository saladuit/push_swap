# *The “push_swap” program*
+ You have to write a program named push_swap which will receive as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
+ The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
+ Instructions must be separaed by a ’\n’ and nothing else.
+ The goal is to sort the stack with the minimum possible number of operations. During defence we’ll compare the number of instructions your program found with a maximum number of operations tolerated. If your program either displays a list too big or if the list isn’t sorted properly, you’ll get no points.
+ In case of error, you must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.
```console
$>./push_swap 2 1 3 6 5 8
sa
pb pb
pb sa
pa pa
pa
$>./push_swap 0 one 2 3
Error 
$>
```
During the defence we’ll provide a binnary to properly check your program. It will work as follows:
```console
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK 
$>
```
If the program checker_OS displays KO, it means that your push_swap came up with a list of instructions that doesn’t sort the list. The checker_OS program is available in the resources of the project on the intranet. You can find in the bonus section of this document a description of how it works.
