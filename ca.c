#include <stdio.h>
#include "ca.h"

void display1DCA(CAPTR pointer){
    int x = pointer->numElements;
    unsigned char* address = pointer->arrayAddress;
    for(int i = 0; i < x; i++){
        printf("%u ", address[i]);
    }
    printf("\n");
}

int set1DCACell(CAPTR pointer, unsigned int index, unsigned char value){

}

void init1DCA(CAPTR pointer, int numElements){

}

CAPTR create1DCA(int size, unsigned char value){

}
