_printf
A collaborative C project implementing a custom version of the standard printf function

Description
_printf is a custom implementation of the C standard library's printf function. This project recreates the functionality of formatted output, handling various data types and format specifiers.

Features
Format specifier support
	- %c: print a single character
	- %s: print a string
	- %d or %i: print an integer
	- %%: print a literal percent sign

Error handling: Returns -1 for invalid format strings
Return value: Returns the number of characters succesfully printed

Installation and Compilation
	-gcc compiler
	-standard C libraries

Compiling
	- To compile the project with _printf:
	gcc -Wall -Wextra -Werror -pedantic -std=c99 *.c -o printf_program

Usage
Basic Syntax
	#include "main.h"

	int _printf(const char *format, ...);

Example
	_printf("Hello %s\n, "World"); //output: Hello World!
	_printf("Character: %c\n, 'A'); //output: Character: A

Project Files
	main.h - Header file with function declarations and includes
	_printf.c - Main function implementation containing

How it works
Core functions
	_putchar(char c)
	-writes a single character to stdout
	-Returns 1 on success, -1 on error
	-Uses the write() system call directly

	_printf(const char *form, ...)
	-Main function that processes the format string
	-Parses format specifiers and calls apropiate handlers
	-Returns the total number of characters

	print_number(int n)
	-Helper function to handle integer printing
	-Uses recursion to process digits in reverse order
	-Handles negative numbers by prepending a minus sign
	-Returns the number of characters printed

Return Value
	Success: Number of characters printed
	Failure: -1

Authors
This is a collaborative project for Holberton Coding School by:
	Alberto Frias
	Miguel Bauza

Testing
	To test your _printf implementation, recreate a test file then compile and run.
