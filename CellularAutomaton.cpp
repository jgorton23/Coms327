using namespace std;

#include <string>
#include <iostream>
#include <fstream>
#include "CellularAutomaton.h"
#include <sstream>
#include <iostream>

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
    if(m>200){
        cellSize=1;
        gapSize=0;
    }else if(m>100){
        cellSize=2;
        gapSize=1;
    }else if(m>=50){
        cellSize=4;
        gapSize=1;
    }else if(m>1){
        cellSize=10;
        gapSize=4;
    }
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
    //Keep track of original data
    originalData = (unsigned char **)malloc(width*sizeof(unsigned char*));
    if(originalData == NULL){
        cout << "Error mallocing array";
        exit(-1);
    }else{
        for(int i = 0; i < width; i++){
            originalData[i]=(unsigned char *)malloc(height*sizeof(unsigned char));
            if(originalData[i]==NULL){
                cout << "Error mallocing array";
                exit(-1);
            }
        }
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            originalData[j][i] = cadata[j][i];
        }
    }

    changelog = (unsigned char **)malloc(width*sizeof(unsigned char*));
    if(changelog==NULL){
        cout << "Error mallocing array";
        exit(-1);
    }else{
         for(int i = 0; i < width; i++){
            changelog[i]=(unsigned char *)malloc(height*sizeof(unsigned char));
            if(changelog[i]==NULL){
                cout << "Error mallocing array";
                exit(-1);
            }
        }
    }
     for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            changelog[j][i] = 1;
        }
    }
    
}

CellularAutomaton::CellularAutomaton(int qstate, int w, int h){
    this->qstate = qstate;
    wrap = 1;
    width=w;
    height=h;
    m = w>h?w:h;
    if(m>200){
        cellSize=1;
        gapSize=0;
    }else if(m>100){
        cellSize=2;
        gapSize=1;
    }else if(m>=50){
        cellSize=4;
        gapSize=1;
    }else if(m>1){
        cellSize=10;
        gapSize=4;
    }
    cadata = (unsigned char **)malloc(w*sizeof(unsigned char*));
    if(cadata == NULL){
        cout << "Error mallocing array";
        exit(-1);
    }else{
        for(int i = 0; i < width; i++){
            cadata[i]=(unsigned char *)malloc(h*sizeof(unsigned char));
            if(cadata[i]==NULL){
                cout << "Error mallocing array";
                exit(-1);
            }
        }
    }
    //initialize the array
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cadata[j][i]=qstate+48;
        }
    }
    originalData = (unsigned char **)malloc(width*sizeof(unsigned char*));
    if(originalData == NULL){
        cout << "Error mallocing array";
        exit(-1);
    }else{
        for(int i = 0; i < width; i++){
            originalData[i]=(unsigned char *)malloc(height*sizeof(unsigned char));
            if(originalData[i]==NULL){
                cout << "Error mallocing array";
                exit(-1);
            }
        }
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            originalData[j][i] = qstate+48;
        }
    }

    changelog = (unsigned char **)malloc(width*sizeof(unsigned char*));
    if(changelog==NULL){
        cout << "Error mallocing array";
        exit(-1);
    }else{
         for(int i = 0; i < width; i++){
            changelog[i]=(unsigned char *)malloc(height*sizeof(unsigned char));
            if(changelog[i]==NULL){
                cout << "Error mallocing array";
                exit(-1);
            }
        }
    }
     for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            changelog[j][i] = 1;
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
    m=other.m;
    wrap = other.wrap;
    cellSize=other.cellSize;
    gapSize=other.gapSize;
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
    originalData = (unsigned char **)malloc(width*sizeof(unsigned char*));
    if(originalData == NULL){
        cout << "Error mallocing array";
        exit(-1);
    }else{
        for(int i = 0; i < width; i++){
            originalData[i]=(unsigned char *)malloc(height*sizeof(unsigned char));
            if(originalData[i]==NULL){
                cout << "Error mallocing array";
                exit(-1);
            }
        }
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            originalData[j][i] = other.originalData[j][i];
        }
    }

    changelog = (unsigned char **)malloc(width*sizeof(unsigned char*));
    if(changelog==NULL){
        cout << "Error mallocing array";
        exit(-1);
    }else{
         for(int i = 0; i < width; i++){
            changelog[i]=(unsigned char *)malloc(height*sizeof(unsigned char));
            if(changelog[i]==NULL){
                cout << "Error mallocing array";
                exit(-1);
            }
        }
    }
     for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            changelog[j][i] = 1;
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
    std::swap(cellSize, temp.cellSize);
    std::swap(gapSize, temp.gapSize);
    std::swap(originalData, temp.originalData);
    std::swap(changelog, temp.changelog);
    return *this;
}

/**
 * @brief Destroy the Cellular Automaton:: Cellular Automaton object
 * 
 */
CellularAutomaton::~CellularAutomaton(){
    for(int i = 0; i < width; i++){
        delete cadata[i];
        delete originalData[i];
        delete changelog[i];
    }
    delete cadata;
    delete originalData;
    delete changelog;
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
            if(sumSurrounding(i,j)>0){
                result = rule(wrap, cadata, j,i,width,height,qstate);
                if(result!=temp.cadata[j][i]){
                    temp.cadata[j][i]=result;
                    temp.changelog[j][i]=1;
                }else{
                    temp.changelog[j][i]=0;
                }
            }
        }
    }
    swap(cadata, temp.cadata);
    swap(changelog, temp.changelog);
}

int CellularAutomaton::sumSurrounding(int i, int j){
    int sum = 0;
    int iStart = i==0?1:0;
    int iEnd = i==height-1?2:3;
    int jStart = j==0?1:0;
    int originalJStart = jStart;
    int jEnd = j==width-1?2:3;
    for(; iStart < iEnd; iStart++){
        for(; jStart < jEnd; jStart++){
            sum+=changelog[j-1+jStart][i-1+iStart];
        }
        jStart=originalJStart;
    }
    return sum;
}

void CellularAutomaton::clear(){
    for(int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cadata[j][i]=48;
        }
    }
}

void CellularAutomaton::randomize(){
    srand(time(0));
    for(int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int x = rand()%2;
            cadata[j][i]=x+48;
        }
    }
}

void CellularAutomaton::reset(){
    for(int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cadata[j][i]=originalData[j][i];
        }
    }
}

int CellularAutomaton::getWidth(){
    return width;
}

int CellularAutomaton::getHeight(){
    return height;
}

int CellularAutomaton::getCellSize(){
    return cellSize;
}

int CellularAutomaton::getGapSize(){
    return gapSize;
}

void CellularAutomaton::setCell(int x, int y){
    cadata[x][y]=(cadata[x][y]-47)%2+48;
}

/**
 * @brief function to display the CA on the graphics server in the given window
 * 
 * @param window the window on which to display the 2DCA
 */
void CellularAutomaton::displayCA(GraphicsClient &window){
    //window.setBackgroundColor(255,255,255);
    window.clear();
    window.repaint();
    window.setDrawingColor(255,0,0);
    //DRAW BUTTONS
    window.drawLine(600,0,600,600);
    window.drawRectangle(650,20,100,50);
    window.drawString(675,40, "step");
    window.drawRectangle(650,90,100,50);
    window.drawString(675,110, "run");
    window.drawRectangle(650,160,100,50);
    window.drawString(675,180, "pause");
    window.drawRectangle(650,220,100,50);
    window.drawString(675,240, "reset");
    window.drawRectangle(650,290,100,50);
    window.drawString(675,310, "random");
    window.drawRectangle(650,360,100,50);
    window.drawString(675,380, "load");
    window.drawRectangle(650,430,100,50);
    window.drawString(675,450, "clear");
    window.drawRectangle(650,500,100,50);
    window.drawString(675,520, "quit");
    window.drawRectangle(650,560,20,20);
    window.drawString(655,575, "S");
    window.drawRectangle(680,560,20,20);
    window.drawString(685,575, "M");
    window.drawRectangle(710,560,20,20);
    window.drawString(715,575, "L");
    
    //DRAW CELLS
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(m<=50){
                if(cadata[j][i]==48){ //use 48 bc 48 is what 0 is represented as
                    //window.drawRectangle(cellSize*j+gapSize*(j-1),cellSize*i+gapSize*(i-1),cellSize, cellSize);
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
    window.repaint();
}