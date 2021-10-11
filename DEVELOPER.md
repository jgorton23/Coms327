# Project 1 - Part B
## Data Structures
The key data structures used are arrays and pointers

# Files
There are 3 files in this project
- ca.h is a header file that contains prototypes for the 5 functions init1DCA, set1DCACell, display1DCA, create1DCA and stepCA, as well as a structure to represent a CA
- ca.c is the c file that contains the 5 functions mentioned above
- main.c is a file containing a main method that gets input and simulates a CA accordingly, and has a function to represent a simple transition to demonstrate how a CA can be simulated
# Functions
- `init1DCA` sets all elements in the array inside a given struct to a given value
- `set1DCACell` changes the value at a given index, the array in a given struct, to a given value >= 0
- `display1DCA` outputs the elements in the array of a given struct representing a CA The elements have a space between them and the list ends with a newline
- `create1DCA` allocates memory for a structure to represent a CA
- `stepCA` simulates a step of a given CA and a given transition function
