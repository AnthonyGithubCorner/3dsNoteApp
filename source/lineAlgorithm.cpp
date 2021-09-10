//
//  lineAlgorithm.cpp
//  3dsNoteApp
//
//  Created by Anthony Lazar on 2021-08-25.
//

#include "lineAlgorithm.hpp"

//Implements Bresenham Line Algorithm for something the line. Used https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm as a refrence, highly recommended reading to understand code

//last point used for line smoothing
int lastTouchX = 0;
int lastTouchY = 0;



void plotLineHigh(int xO, int yO, int xF, int yF, u8 *screen,u8 color[3], int size){
    int xi = 1;
    int dx = xF - xO;
    int dy = yF - yO;
    if (dx < 0){
        xi = -1;
        dx = -dx;
    }
    
    int D = (2 * dx) - dy;
    int x = xO;
    int y = yO;
    
    while(y<yF){
        drawDot(x, y, screen, color, size);
        if (D > 0){
            x = x + xi;
            D = D + (2 * (dx - dy));
        }
        else{
            D = D + 2*dx;
        }
        y++;
    }
}

void plotLineLow(int xO, int yO, int xF, int yF, u8 *screen,u8 color[3], int size){
    int yi = 1;
    int dx = xF - xO;
    int dy = yF - yO;
    if (dy < 0){
        yi = -1;
        dy = -dy;
    }
    
    int y = yO;
    int x = xO;
    int D = (2 * dy) - dx;
    while(x<xF){
        drawDot(x, y, screen, color, size);
        if (D > 0){
            y = y + yi;
            D = D + (2 * (dy - dx));
        }
        else{
            D = D + 2*dy;
        }
        x++;
    }
}

void drawLine(u8 *screen, int x, int y, u8 color[3], int size){
    if(x > 0 && y > 0){
        if(lastTouchX>0 && lastTouchY>0){
            if(!sameLine){
                updateUndo(screen);
                sameLine = true;
            }
            if(abs(y-lastTouchY)<abs(x-lastTouchX)){
                if (lastTouchX>x){
                    plotLineLow(x, y, lastTouchX, lastTouchY, screen, color, size);
                }
                else{
                    plotLineLow(lastTouchX, lastTouchY, x, y, screen, color, size);
                }
            }
            else{
                if (lastTouchY>y){
                    plotLineHigh(x, y, lastTouchX, lastTouchY, screen, color, size);
                }
                else{
                    plotLineHigh(lastTouchX, lastTouchY, x, y, screen, color, size);
                }
            }
        }
        lastTouchX = x;
        lastTouchY = y;
    }
    else{
        sameLine = false;
        lastTouchX = 0;
        lastTouchY = 0;
    }
}
