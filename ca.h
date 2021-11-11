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
    unsigned char** cadata;
    int width;
    int height;
    int numStates;
    int qstate;
    unsigned char wrap;
    unsigned char dimension;
}ca_data;

typedef struct ca_t* CAPTR;

void displayCA(CAPTR ca);

int set1DCACell(CAPTR ca, unsigned int x, unsigned char state);

int set2DCACell(CAPTR ca, unsigned int x, unsigned int y, unsigned char state);

void initCA(CAPTR ca, int state);

CAPTR create1DCA(int w, unsigned char qstate);

CAPTR create2DCA(int w, int h, unsigned char qstate);

void step1DCA(CAPTR, unsigned char (*)(CAPTR, int));

void step2DCA(CAPTR, unsigned char (*)(CAPTR, int, int));

#endif