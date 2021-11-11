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
    unsigned char** address = ca->cadata;
    if(ca->dimension == 1){
        for (int i = 0; i < x; i++){
            printf("%u ", *address[i]);
            
        }
        printf("\n");
    }else if(ca->dimension == 2){
        for (int j = 0; j < y; j++){
            for (int i = 0; i < x; i++){
                printf("%u ", address[i][j]);
            }
            printf("\n");
        }
        
    }
}

/**
 * a function to change the value of a certain array index in a given struct representing a 1DCA
 */
int set1DCACell(CAPTR ca, unsigned int index, unsigned char state){
    if(ca==NULL || index>=ca->width){ // || state>=ca->numStates
        return -1;
    }
    ca->cadata[index]=&state; //fix this
    return 0;
}

int set2DCACell(CAPTR ca, unsigned int row, unsigned int col, unsigned char state){
    if(ca==NULL || col>=ca->width || row>=ca->height){ // || state>=ca->numStates from last time, idt we need it anymore
        return -1;
    }
    ca->cadata[col][row]=state;
    return 0;
}

/**
 * initializes the values of the array in a struct to the given value, or a random value if the given value is -1
 */
void initCA(CAPTR ca, int value){
    srand(time(0));
    //unsigned char num = (unsigned char)value;
    if(ca != NULL){
        if(ca->dimension == 1){
            if(value >= 0){
                for(int i = 0; i < ca->width; i++){
                    ca->cadata[i]=(unsigned char *)&ca->qstate;
                }
            }else{
                for(int i = 0; i < ca->width; i++){
                    unsigned char num = rand()%(ca->numStates);
                    ca->cadata[i]= &num;
                }
            }
        }else if(ca->dimension == 2){
            if(value >= 0){
                for (int i = 0; i < ca->width; i++){
                    for (int j = 0; j < ca->height; j++){
                        ca->cadata[i][j]=value; //switch to ca->qstate later
                    }
                }
            }else{
                for (int i = 0; i < ca->width; i++){
                    for (int j = 0; j < ca->height; j++){
                        ca->cadata[i][j]=rand()%(ca->numStates);
                    }
                }
            }
        }
    }
}


/**
 * function allocates memory sufficient to hold a struct with an array to represent a CA
 */
CAPTR create1DCA(int width, unsigned char value){
    unsigned char **p=malloc(width*sizeof(unsigned char **));
    CAPTR ca = malloc(sizeof(ca_data));
    if(p==NULL || ca==NULL){
        return NULL;
    }
    ca->cadata=p;
    ca->width=width;
    ca->qstate=value;
    ca->dimension=1;
    initCA(ca,value);
    return ca;
}

CAPTR create2DCA(int width, int height, unsigned char value){
    unsigned char **p = (unsigned char **)malloc(width*sizeof(unsigned char *));
    CAPTR ca = malloc(sizeof(ca_data));
    if(p==NULL || ca==NULL){
        return NULL;
    }else{
        for(int i = 0; i < width; i++){
            p[i]=(unsigned char *)malloc(height*sizeof(unsigned char));
            if(p[i]==NULL){
                return NULL;
            }
        }
        ca->cadata=p;
        ca->width = width;
        ca->height = height;
        ca->qstate = value;
        ca->dimension = 2;
        initCA(ca, value);
        return ca;
    }
}

/**
 * applies a given function to a given CA and updates the given CA to the next value for each cell
 */
void step1DCA(CAPTR ca, unsigned char (*func)(CAPTR, int)){
    CAPTR temp;
    temp = create1DCA(ca->width,0);
    for(int i = 0; i < ca->width; i++){
        unsigned char num = func(ca,i);
        temp->cadata[i]=&num;
    }
    for(int i = 0; i < ca->width; i++){
        ca->cadata[i]=temp->cadata[i];
    }
    free(temp->cadata);
    free(temp);
}

void step2DCA(CAPTR ca, unsigned char (*func)(CAPTR, int, int)){
    CAPTR temp;
    temp = create2DCA(ca->width, ca->height, 0);
    for (int i = 0; i < ca->width; i++){
        for (int j = 0; j < ca->height; j++){
            temp->cadata[i][j]=func(ca,i,j);
        }
        
    }
    for (int i = 0; i < ca->width; i++){
        for (int j = 0; j < ca->height; j++){
            ca->cadata[i][j]=temp->cadata[i][j];
        }
    }
    for (int i = 0; i < temp->width; i++){
        free(temp->cadata[i]);
    }
    free(temp->cadata);
    free(temp);
}
