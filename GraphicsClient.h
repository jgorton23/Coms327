#ifndef GRAPHICS_CLIENT_H
#define GRAPHICS_CLIENT_H

#include "CellularAutomaton.h"
#include "GraphicsClient.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

/**
 * @brief class declaration for the GraphicsClient opject
 * 
 */
class GraphicsClient{
    public:
        GraphicsClient(std::string, int);
        GraphicsClient(const GraphicsClient &other);
        GraphicsClient operator=(const GraphicsClient &rhs);
        ~GraphicsClient();
        void setBackgroundColor(int, int, int);
        void setDrawingColor(int, int, int);
        void clear();
        void setPixel(int, int, int, int, int);
        void drawRectangle(int, int, int, int);
        void fillRectangle(int, int, int, int);
        void clearRectangle(int, int, int, int);
        void drawOval(int, int, int, int);
        void fillOval(int, int, int, int);
        void drawLine(int, int, int, int);
        void drawString(int, int, string);
        void repaint();
        void getClick(); //test method
        int getBytesReady();
        int getNumClicks();
    private:
        int sockfd;
        string server_url;
        int server_port;
        int numClicks;//test variable
};

#endif