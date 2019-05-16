# Monty


## Description
This is a interpreter program that is created to interpret Monty-like scripted files according to requested operation codes provided to the authors in the creation of this project. 

## Formatting and Examples

Format for user to place in "testfile.m":
opcode argument

NOTE: No more than one instruction per line is allowed, there can however be as many spaces, new lines or tabs before or after the instruction.



Examples:


home$ cat opcodetestfile.m
push 1
push 2
push 3
pall

home$ ./montyfile opcodetestfile.m
3
2
1
home$

---

home$ cat opcodetestfile.m
push 1
push 2
push 3
pall
rotl
pall

home$ ./montyfile opcodetestfile.m
3
2
1
2
1
3

---

home$ cat opcodetestfile.m
push 4
push 5
push 18
push 3
pall
sub
pall

home$ ./montyfile opcodetestfile.m
3
18
5
4
15
5
4

---



## File List

| File Name | Description |
| --- | --- |
| README.md | Provides details regarding functionality and creation of our version of a monty program (present file) |
| data.c | Contains data struct singleton pattern, returns pointer to our struct and central controler to free all data |
| dlist1.c | Handles data list functions length, sum, print and add node to end of list |
| dlist2.c | Handles data list functions add node to head, insert, get, delete node at index and free the list |
| interpreter.c | Starting point of program; counts arguments, calls strtok, parses opcode and executes if valid |
| lists.h | Header file containing dlist prototypes, libraries and dlist struct definition |
| main.c | Entry point of program, interprets return |
| monty.h | Calls libraries, holds prototypes for all files except dlists, defines structs for parameter pattern, opcode functionality and doubly linked-list representation of stack. Contains all error code definitions |
| opcodes1.c | Contains operation code functions for push, pop, pint, pall and swap |
| opcodes2.c | Contains operation code functions for nop, add, sub, div and mul |
| opcodes3.c | Contains the operation code functions for mod, pchar, pstr, rotl and rotr |
| opcodes4.c | Contains the operation code functions for stack and queue (uses boolian values) |
| stack.c | Handles push, pop, peek, if string is empty from input and pall(prints) |
| token.c | Tokenizes input string, checks that all strings are proper input and checks delimiters |

## Exit Status
Exits with status EXIT_FAILURE

## Compilation
All files where compiled on Ubuntu 14.04 LTS.

All programs and functions were compiled with gcc 4.8.4 using flags -Wall -Werror -Wextra and -pedantic.

## Styling
All files have been written in the Betty Style for a cohesive and readable format.

## Authors
* **Arthur Damm** - [Arthur Damm](https://github.com/arthurdamm)
* **Rene Goertzen** - [renefibonacci660](https://github.com/renefibonacci660)
