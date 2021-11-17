#ifndef CA_H
#define CA_H

#include <string>
#include "GraphicsClient.h"
using namespace std;

class CellularAutomaton{
    public:
        CellularAutomaton(string url, int qstate);
        //TODO COPY CONSTRUCTOR
        //TODO ASSIGNMENT =
        //TODO DESCTRUCTOR
        void Step(unsigned char (*)(int, int)); //unsure about rule format, here it is the same as last time but without the pointer parameter, since it is an object method
        void Display(GraphicsClient &window);
    private:
        int m;
};

#endif