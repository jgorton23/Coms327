/**
 * Author: Jacob Gorton
 * 
 */

#include "ca.h"

/**
 * a function that represents a simple rule as a transition function for simulating a CA
 * 
 * determines if the CA is a wrapping CA or not and applies the rule and to see what the next
 * value for a given index should be
 */
unsigned char rule(CAPTR pointer, int index){
    unsigned char below;
    unsigned char above;
    if(strcmp(pointer->wrap,"wrap")==1){
        below = pointer->arrayAddress[pointer->numElements-1];
        above = pointer->arrayAddress[0];
    }else{
        if(pointer->qstate==-1){
            below = rand()%pointer->numStates;
            above = rand()%pointer->numStates;
        }else{
            below = pointer->qstate;
            above = pointer->qstate;
        }
    }

    unsigned char first;
    unsigned char last;
    unsigned char middle = pointer->arrayAddress[index];
    if(index == 0){
        first = below;
        last = pointer->arrayAddress[index+1];
    }else if(index == pointer->numElements-1){
        first = pointer->arrayAddress[index-1];
        last = above;
    }else{
        first = pointer->arrayAddress[index-1];
        last = pointer->arrayAddress[index+1];
    }

    if((first && middle && last)||(first && !middle && !last)||(!first && !middle && !last)){
        return 0;
    }else{
        return 1;
    }

}

/**
 * a main function that does some error checking on some collected input, and then simulates 
 * a CA with the given conditions
 */
int main(int argc, char *argv[]){
    if(argc!=6){
        printf("\nThe number of arguments passed was incorrect\n");
        return 0;
    }
    if(argv[1]==NULL || atoi(argv[1])<MINIMUM_CELLS || atoi(argv[1])>MAXIMUM_CELLS){
        printf("\nThe number of cells must be between %d and %d\n", MINIMUM_CELLS, MAXIMUM_CELLS);
        return 0;
    }
    if(argv[2]==NULL || atoi(argv[2])<1){
        printf("\nThe number of possible states for each cell must be positive\n");
        return 0;
    }
    if(argv[3]==NULL || strcmp(argv[3],"wrap")!=0 && strcmp(argv[3],"nowrap")!=0){
        printf("\nThe wrap flag is missing or incorrect\n");
        return 0;
    }
    if(argv[4]==NULL || atoi(argv[4])<-1 || atoi(argv[4])>atoi(argv[2])){
        printf("\nThe starting state input must be between -1 and the number of possible states for each cell\n");
        return 0;
    }
    if(argv[5]==NULL || atoi(argv[5])<0){
        printf("\nThe number of steps to simulate must not be negative\n");
        return 0;
    }

    CAPTR p = create1DCA(atoi(argv[1]),0);
    p->numStates=atoi(argv[2]);
    init1DCA(p,atoi(argv[4]));
    p->qstate=atoi(argv[4]);
    p->wrap=argv[3];
    display1DCA(p);
    for(int i = 0; i < atoi(argv[5]); i++){
        stepCA(p,rule,strcmp("wrap",argv[3])+1);
        display1DCA(p);
    }
    display1DCA(p);
}

