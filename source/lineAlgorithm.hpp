//
//  lineAlgorithm.hpp
//  3dsNoteApp
//
//  Created by Anthony Lazar on 2021-08-25.
//

#ifndef lineAlgorithm_hpp
#define lineAlgorithm_hpp

#include <stdio.h>
#include "draw.hpp"
#include "undo.hpp"

void plotLineHigh(int xO, int yO, int xF, int yF, u8 *screen,u8 color[3]);
void plotLineLow(int xO, int yO, int xF, int yF, u8 *screen,u8 color[3]);
void drawLine(u8 *screen, int x, int y, u8 color[3], int size=1);


#endif /* lineAlgorithm_hpp */
