//
//  drawUI.hpp
//  3dsNoteApp
//
//  Created by Anthony Lazar on 2021-09-09.
//

#ifndef drawUI_hpp
#define drawUI_hpp

#include <stdio.h>
#include <3ds.h>
#include "constants.hpp"
#include "draw.hpp"
#include "drawShapes.hpp"

void drawUI(u8* screen);
void eraseUI(u8* screen);
int checkUI(u8* screen, int x, int y);

#endif /* drawUI_hpp */
