/**
 * Author jacob gorton
 * 
 * Program to model basic behavior of DCA 
 */

#include <stdio.h>
#include "./dca1d.h"


/**
 * has parameters for the number of cells and the initial address
 * initilaizes all the elements to 0 by saying for offset i from the starting address, set address[i] to 0
 * c compiler offsets by the correct amount automatically
 */
void init1DCA(int numCells, unsigned char* address){
    for(int i = 0; i < numCells; i++){
        address[i]=0;
    }
}

/**
 * has parameters for the starting address, the index to be changed, and the new state
 * function checks of the new state is below 0 and if it is not then sets the 
 * element of the array at the specified index to the new state
 */
void set1DCACell(unsigned char* address, int index, unsigned char state){
    if(index >= 0){
        address[index]=state;
    }
}

/**
 * has parameters for the starting address and the number of cells to print
 * uses a for-loop to print the first numCells cells from the array starting at the given index
 */
void display1DCA(unsigned char* address, int numCells){
    for(int i = 0; i < numCells; i++){
        printf("%u ", address[i]);
    }
    printf("\n");
}

int main(){
    int numCells = 25;
    unsigned char* address;
    init1DCA(numCells, address);    
    for(int i = 0; i < numCells; i++){
        if(i%2 == 0){
            set1DCACell(address, i, 2);
        }else{
            set1DCACell(address, i, 1);
        }
    }
    display1DCA(address, numCells);
}