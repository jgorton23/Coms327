/**
 * Author: Jacob Gorton
 * this file contains prototypes for functions that are used in ca.c
 * and for a struct that represents a CA
 * 
 * It also contains 2 constants that represent the min and max values
 * a user can input for the number of cells in a CA
 */


#ifndef CA
#define CA
#define MINIMUM_CELLS 10
#define MAXIMUM_CELLS 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct ca_t{
    unsigned char* arrayAddress;
    int numElements;
    int numStates;
    int qstate;
    char* wrap;
}ca_data;

typedef struct ca_t* CAPTR;

void display1DCA(CAPTR pointer);

int set1DCACell(CAPTR pointer, unsigned int index, unsigned char state);

void init1DCA(CAPTR pointer, int numElements);

CAPTR create1DCA(int size, unsigned char value);

void stepCA(CAPTR, unsigned char (*)(CAPTR, int), int);

#endif