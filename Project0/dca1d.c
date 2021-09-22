#include <stdio.h>

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
    display1DCA(address, numCells);
    set1DCACell(address, 5, 2);
    display1DCA(address, numCells);
}