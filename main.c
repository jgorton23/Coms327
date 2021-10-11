#include "ca.h"

unsigned char rule(CAPTR pointer, int index){
    
}

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
    init1DCA(p,atoi(argv[4]));
    p->numStates=atoi(argv[2]);
    p->qstate=atoi(argv[4]);
    p->wrap=argv[3];
    for(int i = 0; i < atoi(argv[5]); i++){
        stepCA(p,rule,strcmp("wrap",argv[3])+1);
    }
    display1DCA(p);
}

