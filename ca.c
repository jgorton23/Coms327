/**
 * Author: Jacob Gorton
 */

#include "ca.h"

/**
 * a function to print out the data stored in a struct representing a CA
 */
void display1DCA(CAPTR pointer){
    int x = pointer->numElements;
    unsigned char* address = pointer->arrayAddress;
    for(int i = 0; i < x; i++){
        printf("%u ", address[i]);
    }
    printf("\n");
}

/**
 * a function to change the value of a certain array index in a given struct representing a CA
 */
int set1DCACell(CAPTR pointer, unsigned int index, unsigned char state){
    if(pointer==NULL || index>=pointer->numElements || state>=pointer->numStates){
        return -1;
    }
    pointer->arrayAddress[index]=state;
    return 0;
}

/**
 * initializes the values of the array in a struct to the given value, or a random value if the given value is -1
 */
void init1DCA(CAPTR pointer, int value){
    srand(time(0));
    if(pointer != NULL){
        if(value >= 0){
            for(int i = 0; i < pointer->numElements; i++){
                pointer->arrayAddress[i]=value;
            }
        }else{
            for(int i = 0; i < pointer->numElements; i++){
                pointer->arrayAddress[i]=rand()%(pointer->numStates);
            }
        }
    }
}

/**
 * function allocates memory sufficient to hold a struct with an array to represent a CA
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

/**
 * applies a given function to a given CA and updates the given CA to the next value for each cell
 */
void stepCA(CAPTR pointer, unsigned char (*func)(CAPTR, int), int wrapFlag){
    CAPTR temp;
    temp = create1DCA(pointer->numElements,0);
    for(int i = 0; i < pointer->numElements; i++){
        temp->arrayAddress[i]=func(pointer,i);
    }
    for(int i = 0; i < pointer->numElements; i++){
        pointer->arrayAddress[i]=temp->arrayAddress[i];
    }
    free(temp);
}
