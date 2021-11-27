//using namespace std;
#include "CellularAutomaton.h"
#include "CellularAutomaton.cpp"
#include "GraphicsClient.h"
#include "GraphicsClient.cpp"

unsigned char rule(unsigned char wrap, unsigned char** data, int x, int y, int width, int height){
    //TODO change ruel to accept a ca object param and then add getters to get the sum etc.
    unsigned char tl,t,tr,r,br,b,bl,l;
    if(wrap==1){
        tl=data[((x-1)+width)%width][((y-1)+height)%height];
        t=data[x][((y-1)+height)%height];
        tr=data[((x+1)+width)%width][((y-1)+height)%height];
        r=data[((x+1)+width)%width][y];
        br=data[((x+1)+width)%width][((y+1)+height)%height];
        b=data[x][((y+1)+height)%height];
        bl=data[((x-1)+width)%width][((y+1)+height)%height];
        l=data[((x-1)+width)%width][y];

        //384 is 48*8, and I have to subtract it because the unsigned char 0 is represented by 48, 1 is 49 and so on
        //so the addition is adding 48+unsigned char value, so that is what I have to compare against the desired sum
        //returns 48 or 49 for the same reason
        unsigned char sum = tl+t+tr+r+br+b+bl+l-384;

        unsigned char center = data[x][y];
        if(data[x][y]-48==1){
            return (sum==2 || sum == 3)?49:48;
        }else{
            return sum==3?49:48;
        }
    }else{
        //TODO fill in else statement
    }
}

int main(){
    //TODO main method
    CellularAutomaton ca = CellularAutomaton("glider.txt", 0);
    GraphicsClient gc = GraphicsClient("127.0.0.1",7777);
    ca.displayCA(gc);
    while(1){
        if(getchar()=='\n'){
            ca.Step(rule);
            ca.displayCA(gc);
        }else{
            return 1;
        }
    }
}