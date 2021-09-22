/**
 * file contains prototypes of functions in dca1d.c
 */

#ifndef DCA1D
#define DCA1D

void init1DCA(int numCells, unsigned char* address);

void set1DCACell(unsigned char* address, int index, unsigned char state);

void display1DCA(unsigned char* address, int numCells);

#endif