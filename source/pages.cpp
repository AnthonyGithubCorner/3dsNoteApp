//
//  pages.cpp
//  3dsNoteApp
//
//  Created by Anthony Lazar on 2021-08-25.
//

#include "pages.hpp"
#include "drawUI.hpp"
u8* pages[10];
int botPage = 1;
int maxPage = (sizeof(pages)/sizeof(*pages)) - 1;
int minPage = 0;

void initPages(u8* firstPage, u8* blankPage){
    pages[0] =(u8*)linearAlloc(size);
    memcpy(pages[0], firstPage, size);
    for(int i = 1; i<=maxPage; i++){
        pages[i] =(u8*)linearAlloc(size);
        memcpy(pages[i], blankPage, size);
    }

}

void deinitPages(){
    for(int i = 0; i<=maxPage; i++){
        if (pages[i] != NULL){
            free(pages[i]);
        }
        
    }
}

void checkChangePages(int Direction, u8* screen, u8* topScreen){
    //page down
    if (Direction==DOWN && botPage < maxPage){
        //so it isn't captured when switching pages

        //save drawing to pages

        memcpy(pages[botPage], screen, size);
        memcpy(pages[botPage-1], topScreen, size);
        botPage++;

        //update change
        eraseUI(pages[botPage-1]);
        drawUI(pages[botPage]);
        memcpy(screen, pages[botPage], size);
        memcpy(topScreen, pages[botPage-1], size);
        resetUndo(screen);

    }
    
    //page up
    if (Direction==UP && (botPage - 1 > minPage)){
        //save drawing to pages
        memcpy(pages[botPage], screen, size);
        memcpy(pages[botPage-1], topScreen, size);
        botPage--;
        //update change
        eraseUI(pages[botPage-1]);
        drawUI(pages[botPage]);
        memcpy(screen, pages[botPage], size);
        memcpy(topScreen, pages[botPage-1], size);
        resetUndo(screen);
    }
}
