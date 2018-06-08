# PushSwap

* The goal of the project is to sort, using two stacks and a list of instructions (see below), in minimal number of steps possible, a list of integers in ascending order

* This project broke down into two programs: a checker program and a push\_swap program
	* Checker takes a file containing a list of instructions (potentially produced by push_swap) and a series of numbers, run the instructions on the list (animated onscreen) and prints out wheather the list is sorted and the number of instructions it took.
	* Push\_Swap takes a series of numbers as arguments, creates stacks, and then output the list operations which sorts the stack.

## Instruction set
For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

Code	| Instruction			| Action
--------|-----------------------|----------------------------------------------
`sa`	| swap a				| swaps the 2 top elements of stack a
`sb`	| swap b				| swaps the 2 top elements of stack b
`ss`	| swap a + swap b		| both `sa` and `sb`
`pa`	| push a				| moves the top element of stack b at the top of stack a
`pb`	| push b				| moves the top element of stack a at the top of stack b
`ra`	| rotate a				| shifts all elements of stack a from bottom to top
`rb`	| rotate b				| shifts all elements of stack b from bottom to top
`rr`	| rotate a + rotate b	| both `ra` and `rb`
`rra`	| reverse rotate a		| shifts all elements of stack a from top to bottom
`rrb`	| reverse rotate b		| shifts all elements of stack b from top to bottom
`rrr`	| reverse rotate a + reverse rotate b	| both `rra` and `rrb`

## Methodology
* Go through the numbers, assign the rank in the stack to each number
* Look at binary expansion of the rank, starting at the most significent bit, go thorugh stack a and push all numbers starting with 1 into stack b
* Recursion (for both stacks) on the bits (moving towards less significent bits);
* Put all instructions in excusion order into a linked list
* Find relations which instructions cancel out, remove/shorten respective nodes

## Results
* Asymptotically orders list of size n in <img src="http://latex.codecogs.com/gif.latex?O%28n%5Clog%20n%29"> instructions

## Compiling
Run `make`.
Two excutables should compile, `push_swap` and `checker`

## Running
```
./push_swap 5 3 4 2 1
```
Animated display of the sorting:
```
./push_swap 5 3 4 2 1 > [file_name]
./cw_display [file_name] 5 3 4 2 1
```
Quick display of the sorting result:
```
./cw_display -q [file_name] 5 3 4 2 1
```
Game mode where user can sort the list themselves by passing instructions in stdin:
```
./cw_display -v [file_name] 5 3 4 2 1
```
