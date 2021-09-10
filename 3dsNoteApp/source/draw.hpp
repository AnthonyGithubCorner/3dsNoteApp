//
//  draw.hpp
//  3dsNoteApp
//
//  Created by Anthony Lazar on 2021-08-25.
//

#ifndef draw_hpp
#define draw_hpp

#include <stdio.h>
#include <3ds.h>
#include "constants.hpp"
void setPixel(u8 *fb, u16 x, u16 y,u8 color[3]);
void drawDot(int touchX, int touchY, u8 *screen, u8 color[3], int size);
void fillScreen(u8* screen, u8 color[3]);
#endif /* draw_hpp */
