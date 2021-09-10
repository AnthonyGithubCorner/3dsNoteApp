//
//  undo.cpp
//  3dsNoteApp
//
//  Created by Anthony Lazar on 2021-08-25.
//

#include "undo.hpp"
bool sameLine = true;
bool nextLine = false;
u8* undo = (u8*)linearAlloc(size);
u8* redo = (u8*)linearAlloc(size);
void checkUndo(int Order, u8* screen){
    //undo
    if (Order == UNDO){
        memcpy(redo, screen, size);
        memcpy(screen, undo, size);
        
    }
    //redo
    if (Order == REDO){
        //undo last change
        memcpy(screen, redo, size);
    }
}
void resetUndo(u8* screen){
    memcpy(undo, screen, size);
    memcpy(redo, screen, size);
}

void updateUndo(u8*screen){
    memcpy(undo, screen, size);
}
void deinitUndo(){
    if (undo != NULL){
        free(undo);
    }
    if(redo != NULL){
        free(redo);
    }
}
