# Monty


## Description
This is a version of a simple shell that utilizes a built UNIX command line interpreter that is able to handle command lines with arguments, execute commands found in the PATH as well as preforms the built-ins exit and env. All input in obtained from stdin and written to stdout.

## Formatting and Examples

Format for user to place in standard input:
command argument



Examples:


$ ls -lamp

./, ../, .git/, README.md, a.out, apples.c, pears.c, pickles/, testfolder/, header.h

$

---

$ echo please work

please work

$

---

$ tail -3 test.c

These are the

last

three lines of this file

$

---



## File List

| File Name | Description |
| --- | --- |
| README.md | Provides details regarding functionality and creation of our version of a simple shell (present file) |
| checkCurrent.c | Checks for specified conditions to execute current directory |
| countWords.c | Counts number of words from input string |
| getEnv.c | Gets the environ so we can check for PATH and frees double pointer |
| getInput.c | Asks the user for input, the input will be used to check for executables |
| getPath.c | Gets the tokenized input and attempts to find the executable from PATH and executes it if found & concatenates path and command to check if it's an executable|
| getVar.c | Returns the directories contained in the variable "name" |
| main.c | Runs a copy of shell and determines functionality |
| mainshell.c | Main entrance and exit function (runs the shell)|
| printEnv.c | Prints the environments and exits with status 0 if successful |
| printError.c | Prints errors in shell format |
| signalHander.c | When cntrl-c is used, this function resets the buffer |
| strFunc.c | Recived a string from str and uses _putchar to print every character on the screen followed by newline, compares two strings at a specified length and returns the difference of both strings, concatenates both dest and src strings, measures length  of the string from pointer str, contains a string from source, which will then be copied to pointer dest. It will then return the same pointer that points to dest |
| token.c | Tokenizes input |
| holberton.h | Header file; contains libaries and function protoypes |
| AUTHORS | Lists all contributors to repository |

## Compilation
All files where compiled on Ubuntu 14.04 LTS.

All programs and functions were compiled with gcc 4.8.4 using flags -Wall -Werror -Wextra and -pedantic.

## Styling
All files have been written in the Betty Style for a cohesive and readable format.

## Authors
* **Arthur Damm** - [GeorgeSolorio](https://github.com/arthurdamm)
* **Rene Goertzen** - [renefibonacci660](https://github.com/renefibonacci660)
