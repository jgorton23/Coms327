/**
 * Author: Jacob Gorton
 */

#include "ca.h"

/**
 * a function to print out the data stored in a struct representing a CA
 */
void displayCA(CAPTR ca){
    int x = ca->width;
    int y = ca->height;
    unsigned char* address = ca->cadata;
    for (size_t i = 0; i < y; i++){
        for(int i = 0; i < x; i++){
            //printf("%u ", address[i]); this won't work for a 2DCA
        }
    }
    printf("\n");
}

/**
 * a function to change the value of a certain array index in a given struct representing a 1DCA
 */
int set1DCACell(CAPTR ca, unsigned int index, unsigned char state){
    if(ca==NULL || index>=ca->width || state>=ca->numStates){
        return -1;
    }
    ca->cadata[index]=state;
    return 0;
}

int set2DCACell(CAPTR ca, unsigned int col, unsigned int row, unsigned char state){

}

/**
 * initializes the values of the array in a struct to the given value, or a random value if the given value is -1
 */
void initCA(CAPTR ca, int value){
    srand(time(0));
    if(ca != NULL){
        if(value >= 0){
            for(int i = 0; i < ca->width; i++){
                ca->cadata[i]=value;
            }
        }else{
            for(int i = 0; i < ca->width; i++){
                ca->cadata[i]=rand()%(ca->numStates);
            }
        }
    }
}

/**
 * function allocates memory sufficient to hold a struct with an array to represent a CA
 */
CAPTR create1DCA(int width, unsigned char value){
    unsigned char *p=malloc(width*sizeof(unsigned char));
    CAPTR ca = malloc(sizeof(ca_data));
    if(p==NULL || ca==NULL){
        //return -1;
    }
    ca->cadata=p;
    ca->width=width;
    ca->qstate=value;
    init1DCA(ca,value);
    return ca;
}

CAPTR create2DCA(int width, int height, unsigned char value){

}

/**
 * applies a given function to a given CA and updates the given CA to the next value for each cell
 */
void step1DCA(CAPTR ca, unsigned char (*func)(CAPTR, int)){
    CAPTR temp;
    temp = create1DCA(ca->width,0);
    for(int i = 0; i < ca->width; i++){
        temp->cadata[i]=func(ca,i);
    }
    for(int i = 0; i < ca->width; i++){
        ca->cadata[i]=temp->cadata[i];
    }
    free(temp);
}

void step2DCA(CAPTR ca, unsigned char (*func)(CAPTR, int, int)){

}
