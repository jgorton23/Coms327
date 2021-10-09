#ifndef CA
#define CA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct ca_t{
    unsigned char* arrayAddress;
    int numElements;
    int numStates;
    unsigned char qstate;
}ca_data;

typedef struct ca_t* CAPTR;

void display1DCA(CAPTR pointer);

int set1DCACell(CAPTR pointer, unsigned int index, unsigned char state);

void init1DCA(CAPTR pointer, int numElements);

CAPTR create1DCA(int size, unsigned char value);

void stepCA(CAPTR, unsigned char (*)(CAPTR, int), int);

#endif