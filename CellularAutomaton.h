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
        void Step(unsigned char (*)(unsigned char, unsigned char**, int, int, int, int));
        void displayCA(GraphicsClient &window);
        ~CellularAutomaton();
    private:
        int width, height, m, qstate;
        unsigned char** cadata;
        unsigned char wrap = 1; //edit depending on if a CA should wrap or not, (1,0 respectively)
};

#endif