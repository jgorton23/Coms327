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
    wrap = 1;
    ifstream f(file);
    if(!f.is_open()){
        cout << "Error opening file";
        exit(-1);
    }
    f >> height;
    f >> width;
    m = width>height?width:height;
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
    f.close();
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
    m=other.m;
    wrap = other.wrap;
    cadata = (unsigned char**)malloc(width*sizeof(unsigned char*));
    if(cadata==NULL){
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
    for(int i = 0; i < width; i++){
        delete cadata[i];
    }
    delete cadata;
}

/**
 * @brief simulate 1 step of the given rule on this 2DCA
 * 
 * @param rule a rule to simulate a step of the CA
 */
void CellularAutomaton::Step(unsigned char (* rule)(unsigned char, unsigned char**, int, int, int, int, int)){
    CellularAutomaton temp(*this);
    unsigned char result;
    for(int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            result = rule(wrap, cadata, j,i,width,height,qstate);
            temp.cadata[j][i]=result;
        }
    }
    swap(cadata, temp.cadata);
}

/**
 * @brief function to display the CA on the graphics server in the given window
 * 
 * @param window the window on which to display the 2DCA
 */
void CellularAutomaton::displayCA(GraphicsClient &window){
    int cellSize, gapSize;
    if(m>200){
        cellSize=1;
        gapSize=0;
    }else if(m>100){
        cellSize=2;
        gapSize=1;
    }else if(m>50){
        cellSize=4;
        gapSize=1;
    }else if(m>1){
        cellSize=10;
        gapSize=4;
    }
    //window.setBackgroundColor(255,255,255);
    window.clear();
    window.repaint();
    window.setDrawingColor(255,255,255);
    //DRAW BUTTONS
    window.drawLine(600,0,600,600);
    window.drawRectangle(650,20,100,50);
    window.drawRectangle(650,90,100,50);
    window.drawRectangle(650,160,100,50);
    window.drawRectangle(650,220,100,50);
    window.drawRectangle(650,290,100,50);
    window.drawRectangle(650,360,100,50);
    window.drawRectangle(650,430,100,50);
    window.drawRectangle(650,500,100,50);
    
    //DRAW CELLS
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(m<=50){
                if(cadata[j][i]==48){ //use 48 bc 48 is what 0 is represented as
                    window.drawRectangle(cellSize*j+gapSize*(j-1),cellSize*i+gapSize*(i-1),cellSize, cellSize);
                }else{
                    window.fillRectangle(cellSize*j+gapSize*(j-1),cellSize*i+gapSize*(i-1),cellSize, cellSize);
                }
            }else{
                if(cadata[j][i]!=48){
                    //window.setPixel(cellSize*j+gapSize*(j-1),cellSize*i+gapSize*(i-1),0,0,0);
                    window.fillRectangle(cellSize*j+gapSize*(j-1),cellSize*i+gapSize*(i-1),cellSize, cellSize);
                }
            }
        }
    }

    //GET MOUSE INPUT
    //window.drawString(700,35,"0");
    window.getClick();

    window.repaint();
}