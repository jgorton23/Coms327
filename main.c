/**
 * Author: Jacob Gorton
 * 
 */

#include "ca.h"


/**
 * @brief 
 * a function that represents a simple rule as a transition function for simulating a 2DCA
 * 
 * determines if the CA is a wrapping CA or not and applies the rule and to see what the next
 * value for a given index should be
 * 
 * @param pointer 
 * @param col 
 * @param row 
 * @return unsigned char 
 */
unsigned char rule(CAPTR pointer, int col, int row){

    unsigned char tl,t,tr,r,br,b,bl,l;

    if (pointer->wrap==0){
        tl=pointer->cadata[((col-1)+pointer->width)%pointer->width][((row-1)+pointer->height)%pointer->height];
        t=pointer->cadata[col][((row-1)+pointer->height)%pointer->height];
        tr=pointer->cadata[((col+1)+pointer->width)%pointer->width][((row-1)+pointer->height)%pointer->height];
        r=pointer->cadata[((col+1)+pointer->width)%pointer->width][row];
        br=pointer->cadata[((col+1)+pointer->width)%pointer->width][((row+1)+pointer->height)%pointer->height];
        b=pointer->cadata[col][((row+1)+pointer->height)%pointer->height];
        bl=pointer->cadata[((col-1)+pointer->width)%pointer->width][((row+1)+pointer->height)%pointer->height];
        l=pointer->cadata[((col-1)+pointer->width)%pointer->width][row];

        unsigned char sum = tl+t+tr+r+br+b+bl+l;

        if(pointer->cadata[col][row]==1){
            return (sum==2 || sum == 3)?1:0;
        }else{
            return sum==3?1:0;
        }

    }else{
        printf("cannot perform function without wrap flag set to true");
        exit(-1);
    }
}

/**
 * @brief a main function that does some error checking on some collected input, and then simulates 
 * a 2DCA with the given conditions read from a file
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[]){

    if(argc!=3){
        printf("incorrect number of arguments");
        return 0;
    }
    int dim = atoi(argv[1]);
    if(dim != 2){
        printf("this program requires a 2DCA");
        return 0;
    }
    FILE *file = fopen(argv[2], "r");
    if(file == NULL){
        printf("couldn't find file");
        return 0;
    }
    int width;
    int height;
    fscanf(file, "%d %d", &height, &width);
    CAPTR ca = create2DCA(width, height, 0);

    for (int i = 0; i < ca->height; i++){
        for (int j = 0; j < ca->width; j++){
            int next;
            fscanf(file, "%d", &next);
            set2DCACell(ca,i,j,next);
        }
        
    }    
    displayCA(ca);
    ca->wrap=0;
    while(1){
        if(getchar()=='\n'){
            step2DCA(ca, rule);
            displayCA(ca);
        }else{
            return 1;
        }
    }
}

