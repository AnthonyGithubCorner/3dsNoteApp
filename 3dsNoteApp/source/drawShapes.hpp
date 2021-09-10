//
//  drawShapes.hpp
//  3dsNoteApp
//
//  Created by Anthony Lazar on 2021-09-09.
//

#ifndef drawShapes_hpp
#define drawShapes_hpp

#include <stdio.h>
#include <3ds.h>
#include "constants.hpp"
#include "draw.hpp"

void drawBox(u8* screen, int pO[2], int pF[2], u8 color[3]);
void drawArrowRight(u8* screen, int originX, int originY, u8 color[3]);
void drawArrowLeft(u8* screen, int originX, int originY, u8 color[3]);
void drawArrowUp(u8* screen, int originX, int originY, u8 color[3]);
void drawArrowDown(u8* screen, int originX, int originY, u8 color[3]);
void drawX(u8* screen, int centerX, int centerY, u8 color[3]);

#endif /* drawShapes_hpp */
