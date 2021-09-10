//
//  pages.hpp
//  3dsNoteApp
//
//  Created by Anthony Lazar on 2021-08-25.
//

#ifndef pages_hpp
#define pages_hpp

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <3ds.h>
#include "constants.hpp"
#include "undo.hpp"

void initPages(u8* firstPage, u8* blankPage);
void deinitPages();
void checkChangePages(int direction, u8* screen, u8* topScreen);
#endif /* pages_hpp */
