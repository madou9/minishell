#!/bin/bash

# Test basic echo
./builtins/echo_builtins.c echo "Hello, world!"

# Test multiple arguments
./builtins/echo_builtins.c echo "Hello," "world!"

# Test -n flag
./builtins/echo_builtins.c echo -n "This is a test"

# Test combination of -n flag and multiple arguments
./builtins/echo_builtins.c echo -n "No newline" "here"

# Test empty echo
./builtins/echo_builtins.c echo

# Test echo with escaped characters
./builtins/echo_builtins.c echo "Escape characters: \n\t"

# ... Add more test cases as needed
