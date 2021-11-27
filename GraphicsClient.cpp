using namespace std;

#include "CellularAutomaton.h"
#include "GraphicsClient.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define shift(x) x>>4

/**
 * @brief Construct a new Graphics Client:: Graphics Client object
 * 
 * @param url the url to connect
 * @param port the port number to connect
 */
GraphicsClient::GraphicsClient(std::string url, int port){
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        fprintf( stderr, "Error creating socket\n");
        exit(-1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(url.c_str()));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if(inet_pton(AF_INET, url.c_str(), &serv_addr.sin_addr)<=0){
        fprintf(stderr, "Invalid address/ Address not supported \n");
        exit(-1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        fprintf(stderr, "Connection Failed \n");
        exit(-1);
    }
}

/**
 * @brief Construct a new Graphics Client:: Graphics Client object
 * 
 * @param other the Graphics client to copy
 */
GraphicsClient::GraphicsClient(const GraphicsClient &other){

}

/**
 * @brief the assignment = operator for GraphicsClient objects
 * 
 * @param rhs the GraphicsClient on the right hand side of the =
 * @return GraphicsClient 
 */
GraphicsClient GraphicsClient::operator=(const GraphicsClient &rhs){
    //TODO write assignment =
}

/**
 * @brief Destroy the Graphics Client:: Graphics Client object
 * 
 */
GraphicsClient::~GraphicsClient(){
    close(sockfd);
}

/**
 * @brief sets the color of the background
 * 
 * @param r red value
 * @param g green value
 * @param b blue value
 */
void GraphicsClient::setBackgroundColor(int r, int g, int b){
    
    char message[100];
    message[0]=0xFF;
    message[1]=message[2]=message[3]=0x00;
    message[4]=0x07;
    message[5]=0x02;
    message[6]=shift(r)&0x0F;
    message[7]=r&0x0F;
    message[8]=shift(g)&0x0F;
    message[9]=g&0x0F;
    message[10]=shift(b)&0x0F;
    message[11]=b&0x0F;

    send(sockfd, message, 12, 0);
}

/**
 * @brief sets the current drawing color
 * 
 * @param r red value
 * @param g green value
 * @param b blue value
 */
void GraphicsClient::setDrawingColor(int r, int g, int b){
    char message[100];
    message[0]=0xFF;
    message[1]=message[2]=message[3]=0x00;
    message[4]=0x07;
    message[5]=0x06;
    //TODO convert 3 ints to char array
    send(sockfd, message, 18, 0);
}

/**
 * @brief clears the window
 * 
 */
void GraphicsClient::clear(){
    char message[100];
    message[0]=0xFF;
    message[1]=message[2]=message[3]=0x00;
    message[4]=0x01;
    message[5]=0x01;
    send(sockfd, message, 6, 0);
}

/**
 * @brief sets a pixel to a given color
 * 
 * @param x coordinate
 * @param y coordinate
 * @param r red value
 * @param g green value
 * @param b blue value
 */
void GraphicsClient::setPixel(int x, int y, int r, int g, int b){
    char message[100];
    message[0]=0xFF;
    message[1]=message[2]=message[3]=0x00;
    message[4]=0x0E;
    message[5]=0x02;
    //TODO convert ints to char array
    send(sockfd, message, 18, 0);
}

/**
 * @brief draws a rectanle of given coordinate and size
 * 
 * @param x coordinate
 * @param y coordinate
 * @param width
 * @param height 
 */
void GraphicsClient::drawRectangle(int x, int y, int width, int height){
    char message[100];
    message[0]=0xFF;
    message[1]=message[2]=0x00;
    message[3]=0x01;
    message[4]=0x01;
    message[5]=0x07;
    //TODO fill in char array
    send(sockfd, message, 22, 0);
}

/**
 * @brief draws a filled in rectangle of the current drawing color and given size at the given coordinate
 * 
 * @param x coordinate
 * @param y coordinate
 * @param width 
 * @param height 
 */
void GraphicsClient::fillRectangle(int x, int y, int width, int height){
    char message[100];
    message[0]=0xFF;
    message[1]=message[2]=0x00;
    message[3]=0x01;
    message[4]=0x01;
    message[5]=0x08;
    //TODO fill in char array
    send(sockfd, message, 22, 0);
}

/**
 * @brief sets a rectanlge to the background color of the given coordinates and size
 * 
 * @param x coordinate
 * @param y coordinate
 * @param width 
 * @param height 
 */
void GraphicsClient::clearRectangle(int x, int y, int width, int height){
    char message[100];
    message[0]=0xFF;
    message[1]=message[2]=0x00;
    message[3]=0x01;
    message[4]=0x01;
    message[5]=0x09;
    //TODO fill in char array
    send(sockfd, message, 22, 0);
}

/**
 * @brief draws an oval inscribed in the rectangle described by the given coordinates and size
 * 
 * @param x coordinate
 * @param y coordiante
 * @param width 
 * @param height 
 */
void GraphicsClient::drawOval(int x, int y, int width, int height){
    char message[100];
    message[0]=0xFF;
    message[1]=message[2]=0x00;
    message[3]=0x01;
    message[4]=0x01;
    message[5]=0x0a;
    //TODO fill in char array
    send(sockfd, message, 22, 0);
}

/**
 * @brief draws a filled oval inscribed in teh rectangle described by the given coordinates and size
 * 
 * @param x coordinate
 * @param y coordinate
 * @param width 
 * @param height 
 */
void GraphicsClient::fillOval(int x, int y, int width, int height){
    char message[100];
    message[0]=0xFF;
    message[1]=message[2]=0x00;
    message[3]=0x01;
    message[4]=0x01;
    message[5]=0x0b;
    //TODO fill in char array
    send(sockfd, message, 22, 0);
}

/**
 * @brief draws a line from the first point to the second
 * 
 * @param x1 coordinate of first point
 * @param y1 coordinate of first point
 * @param x2 coordinate of second point
 * @param y2 coordinate of second point
 */
void GraphicsClient::drawLine(int x1, int y1, int x2, int y2){
    char message[100];
    message[0]=0xFF;
    message[1]=message[2]=0x00;
    message[3]=0x01;
    message[4]=0x01;
    message[5]=0x0D;
    //TODO fill in char array
    send(sockfd, message, 22, 0);
}

/**
 * @brief draws a string at teh given coordiante
 * 
 * @param x coordinate
 * @param y coordiante
 * @param s string to be drawn
 */
void GraphicsClient::drawString(int x, int y, string s){
    char message[100];
    message[0]=0xFF;
    int length = strlen(s.c_str());
    //message[1]-message[4]= length converted to char array
    message[5]=0x05;
    //TODO fill in x, y coordinates, string char nibbles
    send(sockfd, message, length*2+10, 0);
}

/**
 * @brief sends the redraw signal to the server
 * 
 */
void GraphicsClient::repaint(){
    char message[100];
    message[0]=0xFF;
    message[1]=message[2]=message[3]=0x00;
    message[4]=0x01;
    message[5]=0x0C;
    send(sockfd, message, 6, 0);
}
