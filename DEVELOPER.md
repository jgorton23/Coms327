# Project 1 - Part C
## Data Structures
The key data structures used are arrays and pointers

# Files
There are 3 files in this project
- ca.h is a header file that contains prototypes for the 8 functions initCA, set1DCACell, set2DCACell, displayCA, create1DCA, create2DCA, step2DCA, and step1DCA, as well as a structure to represent a CA
- ca.c is the c file that contains the 8 functions mentioned above
- main.c is a file containing a main method that gets input and simulates a 2DCA accordingly, and has a function to represent a simple transition to demonstrate how a CA can be simulated
# Functions
- `initCA` sets all elements in the array inside a given struct to a given value, for either a 1D or 2D CA
- `set1DCACell` changes the value at a given index, the array in a given struct, to a given value >= 0
- `set2DCACell` changes the value at a given x,y coordinate in a 2DCA to a given value
- `displayCA` outputs the elements in the array of a given struct representing a CA The elements have a space between them, with rows being separated by a newline
- `create1DCA` allocates memory for a structure to represent a 1DCA and calls initCA
- `create2DCA` allocates memory for a structure to represent a 2DCA and calls initCA
- `step1DCA` simulates a step of a given 1DCA and a given transition function
- `step2DCA` simulates a step of a given 2DCA and a given transition function
