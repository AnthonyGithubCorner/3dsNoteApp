//
//  undo.hpp
//  3dsNoteApp
//
//  Created by Anthony Lazar on 2021-08-25.
//

#ifndef undo_hpp
#define undo_hpp

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <3ds.h>
#include "constants.hpp"
//used for undo and redo
extern bool sameLine;
extern bool nextLine;
void checkUndo(int Order, u8* screen);
void updateUndo(u8* screen);
void resetUndo(u8* screen);
void deinitUndo();
#endif /* undo_hpp */
