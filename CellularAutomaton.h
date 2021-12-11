#ifndef CA_H
#define CA_H

#include <string>
#include "GraphicsClient.h"
using namespace std;

/**
 * @brief class declaration for the CellularAutomaton object
 * 
 */
class CellularAutomaton{
    public:
        CellularAutomaton(std::string file, int qstate);
        CellularAutomaton(int qstate, int width, int height);
        CellularAutomaton(const CellularAutomaton &other);
        CellularAutomaton operator=(const CellularAutomaton &rhs);
        void Step(unsigned char (*)(unsigned char, unsigned char**, int, int, int, int, int));
        void displayCA(GraphicsClient &window);
        ~CellularAutomaton();
        void clear();
        void randomize();
        void reset();
        int getHeight();
        int getWidth();
        int getCellSize();
        int getGapSize();
        void setCell(int,int);
    private:
        int width, height, m, qstate, cellSize, gapSize;
        unsigned char** cadata;
        unsigned char wrap;
        unsigned char** originalData;
};

#endif