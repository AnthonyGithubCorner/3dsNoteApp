//
//  drawShapes.cpp
//  3dsNoteApp
//
//  Created by Anthony Lazar on 2021-09-09.
//

#include "drawShapes.hpp"



//render box (rectangle) on screen, pO is the origin of the rectangle from the top left, pF is it's bottom right corner
// first int is x, second int is y
void drawBox(u8* screen, int pO[2], int pF[2], u8 color[3]){
    for(int i = pO[0]; i<=pF[0]; i++){
        for(int j = pO[1]; j<=pF[1]; j++){
            setPixel(screen, i, j, color);
        }
    }
}
void drawX(u8* screen, int centerX, int centerY, u8 color[3]){
    for(int i = 0; i<10; i++){
        setPixel(screen, centerX-i, centerY-i, color);
        setPixel(screen, centerX+i, centerY+i, color);
        setPixel(screen, centerX+i, centerY-i, color);
        setPixel(screen, centerX-i, centerY+i, color);
    }
}
//draws triangle in 4 directions (very specific to UI)
void drawArrowRight(u8* screen, int originX, int originY, u8 color[3]){
    for(int i = 0; i<=25; i++){
        setPixel(screen, originX+i, originY, color);
    }
    for(int i = 0; i<=7; i++){
        setPixel(screen, originX+25-i, originY-i, color);
        setPixel(screen, originX+25-i, originY+i, color);
    }
    
}

void drawArrowLeft(u8* screen, int originX, int originY, u8 color[3]){
    for(int i = 0; i<=25; i++){
        setPixel(screen, originX-i, originY, color);
    }
    for(int i = 0; i<=7; i++){
        setPixel(screen, originX-25+i, originY+i, color);
        setPixel(screen, originX-25+i, originY-i, color);
    }
}

void drawArrowUp(u8* screen, int originX, int originY, u8 color[3]){
    for(int i = 0; i<=25; i++){
        setPixel(screen, originX, originY-i, color);
    }
    for(int i = 0; i<=7; i++){
        setPixel(screen, originX-i, originY-25+i, color);
        setPixel(screen, originX+i, originY-25+i, color);
    }
    
}

void drawArrowDown(u8* screen, int originX, int originY, u8 color[3]){
    for(int i = 0; i<=25; i++){
        setPixel(screen, originX, originY+i, color);
    }
    for(int i = 0; i<=7; i++){
        setPixel(screen, originX-i, originY+25-i, color);
        setPixel(screen, originX+i, originY+25-i, color);
    }
    
}

