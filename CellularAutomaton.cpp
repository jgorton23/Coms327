using namespace std;

#include <string>
#include <iostream>
#include <fstream>
#include "CellularAutomaton.h"

/**
 * @brief Construct a new Cellular Automaton:: Cellular Automaton object
 * 
 * @param file the file name from which to read in a 2DCA
 * @param qstate the quiescent state of the 2DCA
 */
CellularAutomaton::CellularAutomaton(std::string file, int qstate){
    this->qstate = qstate;
    cout << "qstate: " << qstate << "\n";
    wrap=1; //change this value to change if the rule wraps or not (1/0 respectively)
    ifstream f(file);
    if(!f.is_open()){
        cout << "Error opening file";
        exit(-1);
    }
    f >> height;
    cout << "height: " << height << "\n";
    f >> width;
    cout << "width: " << width << "\n";
    m = width>height?width:height;
    cout <<"m: " << m << "\n";
    //allocate memory for the 2D array
    cadata = (unsigned char **)malloc(width*sizeof(unsigned char*));
    if(cadata == NULL){
        cout << "Error mallocing array";
        exit(-1);
    }else{
        for(int i = 0; i < width; i++){
            cadata[i]=(unsigned char *)malloc(height*sizeof(unsigned char));
            if(cadata[i]==NULL){
                cout << "Error mallocing array";
                exit(-1);
            }
        }
    }
    //initialize the array
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            f >> cadata[j][i];
        }
    }
}

/**
 * @brief Construct a new Cellular Automaton:: Cellular Automaton object
 * 
 * @param rhs a CA to copy from
 */
CellularAutomaton::CellularAutomaton(const CellularAutomaton &other){
    width = other.width;
    height = other.height;
    qstate = other.qstate;
    wrap = other.wrap;
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            cadata[i][j] = other.cadata[i][j];
        }
    }
}

/**
 * @brief used when ca1 = ca2; is writtem
 * 
 * @param rhs the right hand side of the equals operator
 * @return CellularAutomaton 
 */
CellularAutomaton CellularAutomaton::operator=(const CellularAutomaton &rhs){
    CellularAutomaton temp(rhs);
    std::swap(width, temp.width);
    std::swap(height, temp.height);
    std::swap(qstate, temp.qstate);
    std::swap(wrap, temp.wrap);
    std::swap(cadata, temp.cadata);
    return *this;
}

/**
 * @brief Destroy the Cellular Automaton:: Cellular Automaton object
 * 
 */
CellularAutomaton::~CellularAutomaton(){
    delete cadata;
}

/**
 * @brief simulate 1 step of the given rule on this 2DCA
 * 
 * @param rule a rule to simulate a step of the CA
 */
void CellularAutomaton::Step(unsigned char (* rule)(int, int)){

}

/**
 * @brief function to display the CA on the graphics server in the given window
 * 
 * @param window the window on which to display the 2DCA
 */
void CellularAutomaton::Display(){ //GraphicsClient &window
    for (int j = 0; j < height; j++){
        for (int i = 0; i < width; i++){
            cout << cadata[i][j];
            cout << " ";
        }
        cout << "\n";
    }
}