//using namespace std;
#include "CellularAutomaton.h"
#include "CellularAutomaton.cpp"
#include "GraphicsClient.h"
#include "GraphicsClient.cpp"

/**
 * @brief a rule that determines how 1 transition of a 2DCA takes place
 * because this function is only called inside the step method of a CA object, rather than using getters for the private variables
 * I opted to just let the CA method pass the variables in directly as parameters
 * 
 * @param wrap the flag that determines if the ca wraps around the edges or not
 * @param data the 2D array that represents the CA states
 * @param x the x coordinate to apply the rule to
 * @param y the y coordinate to apply the rule to
 * @param width the width of the array
 * @param height the height of the array
 * @param qstate the quiescent state of the CA
 * @return unsigned char the new state of the given index
 */
unsigned char rule(unsigned char wrap, unsigned char** data, int x, int y, int width, int height, int qstate){
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
    }else{
        if(qstate==-1){
            srand(time(0));
            tl=(x!=0&&y!=0)?data[x-1][y-1]:rand()%2;
            t=(y!=0)?data[x][y-1]:rand()%2;
            tr=(x!=width&&y!=0)?data[x+1][y-1]:rand()%2;
            r=(x!=width)?data[x+1][y]:rand()%2;
            br=(x!=width&&y!=height)?data[x+1][y+1]:rand()%2;
            b=(y!=height)?data[x][y+1]:rand()%2;
            bl=(x!=0&&y!=height)?data[x-1][y+1]:rand()%2;
            l=(x!=0)?data[x-1][y]:rand()%2;
        }else{
            tl=(x!=0&&y!=0)?data[x-1][y-1]:qstate;
            t=(y!=0)?data[x][y-1]:qstate;
            tr=(x!=width&&y!=0)?data[x+1][y-1]:qstate;
            r=(x!=width)?data[x+1][y]:qstate;
            br=(x!=width&&y!=height)?data[x+1][y+1]:qstate;
            b=(y!=height)?data[x][y+1]:qstate;
            bl=(x!=0&&y!=height)?data[x-1][y+1]:qstate;
            l=(x!=0)?data[x-1][y]:qstate;
        }
    }
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
}

int main(int argc, char *argv[]){
    if(argc!=2){
        cout << "incorrect number of arguments";
        return -1;
    }
    string file = argv[1];
    CellularAutomaton ca = CellularAutomaton(file, 0);
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