#include <stdio.h>
#include "ca.h"
#define MINIMUM_CELLS 10
#define MAXIMUM_CELLS 100

void display1DCA(CAPTR pointer){
    int x = pointer->numElements;
    unsigned char* address = pointer->arrayAddress;
    for(int i = 0; i < x; i++){
        printf("%u ", address[i]);
    }
    printf("\n");
}

int set1DCACell(CAPTR pointer, unsigned int index, unsigned char state){
    if(pointer==NULL || index>=pointer->numElements || state>=pointer->numStates){
        return -1;
    }
    pointer->arrayAddress[index]=state;
    return 0;
}

void init1DCA(CAPTR pointer, int value){
    if(pointer != NULL){
        if(value >= 0){
            for(int i = 0; i < pointer->numElements; i++){
                pointer->arrayAddress[i]=value;
            }
        }else{
            for(int i = 0; i < pointer->numElements; i++){
                pointer->arrayAddress[i]=rand();
            }
        }
    }
}

/**
 * when creating a 1DCA i can initialize it to any value, including those outside the range of the max values
 * IDK how many possible states there should be/what numStates should be set to
 */
CAPTR create1DCA(int size, unsigned char value){
    unsigned char *p=malloc(size*sizeof(unsigned char));
    CAPTR pointer = malloc(sizeof(ca_data));
    if(p==NULL || pointer==NULL){
        //return -1;
    }
    pointer->arrayAddress=p;
    pointer->numElements=size;
    pointer->qstate=value;
    init1DCA(pointer,value);
    return pointer;
}

void stepCA(CAPTR pointer, unsigned char (*func)(CAPTR, int), int wrapFlag){

}
