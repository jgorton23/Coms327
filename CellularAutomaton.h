#ifndef CA_H
#define CA_H

#include <string>
#include "GraphicsClient.h"
using namespace std;

class CellularAutomaton{
    public:
        CellularAutomaton(std::string file, int qstate);
        CellularAutomaton(const CellularAutomaton &other);
        CellularAutomaton operator=(const CellularAutomaton &rhs);
        void Step(unsigned char (*)(int, int)); //unsure about rule format, here it is the same as last time but without the pointer parameter, since it is an object method
        void Display(); //GraphicsClient &window
        ~CellularAutomaton();
    private:
        int width, height, m, qstate;
        unsigned char** cadata;
        unsigned char wrap;
};

#endif