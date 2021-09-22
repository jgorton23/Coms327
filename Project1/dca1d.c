#include <stdio.h>
#include "./dca1d.h"

void init1DCA(int numCells, unsigned char* address){
    for(int i = 0; i < numCells; i++){
        address[i]=0;
    }
}

void set1DCACell(unsigned char* address, int index, unsigned char state){
    if(index >= 0){
        address[index]=state;
    }
}

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