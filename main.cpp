//using namespace std;
#include "CellularAutomaton.h"
#include "CellularAutomaton.cpp"

int main(){
    CellularAutomaton ca = CellularAutomaton("glider.txt", 0);
    ca.Display();
}