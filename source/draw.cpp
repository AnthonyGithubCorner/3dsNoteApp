//
//  draw.cpp
//  3dsNoteApp
//
//  Created by Anthony Lazar on 2021-08-25.
//

#include "draw.hpp"


void setPixel(u8 *fb, u16 x, u16 y, u8 color[3]) {
    fb[3 * (240 - y + (x - 1) * 240)] = color[0];
    fb[3 * (240 - y + (x - 1) * 240) + 1] = color[1];
    fb[3 * (240 - y + (x - 1) * 240) + 2] = color[2];
}

void drawDot(int touchX, int touchY, u8 *screen, u8 color[3], int size=1){
    for(int j = 0; j<size; j++){
        setPixel(screen, touchX, touchY, color);
        for(int i = 0; i<2; i++){
            if(touchX-i+j > 0 ){
                setPixel(screen, touchX-i+j, touchY, color);
            }
            if(touchX+i+j < SCREEN_WIDTH ){
                setPixel(screen, touchX+i+j, touchY, color);
            }
            if(touchY-i+j > 0 ){
                setPixel(screen, touchX, touchY-i+j, color);
            }
            if(touchY+i+j < SCREEN_HEIGHT){
                setPixel(screen, touchX, touchY+i+j, color);
            }
        }
        for(int i = 0; i<2; i++){
            if(touchX-i-j > 0 ){
                setPixel(screen, touchX-i-j, touchY, color);
            }
            if(touchX+i-j < SCREEN_WIDTH ){
                setPixel(screen, touchX+i-j, touchY, color);
            }
            if(touchY-i-j > 0 ){
                setPixel(screen, touchX, touchY-i-j, color);
            }
            if(touchY+i-j < SCREEN_HEIGHT){
                setPixel(screen, touchX, touchY+i-j, color);
            }
        }
    }
    
}



void fillScreen(u8* screen, u8 color[3]){//render white screen on bottom screen
    for(int i = 0; i<=SCREEN_WIDTH; i++){
        for(int j = 0; j<=SCREEN_HEIGHT; j++){
            setPixel(screen, i, j, color);
        }
    }
}


