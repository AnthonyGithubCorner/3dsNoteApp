#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <math.h>
#include <cmath>
#include "draw.hpp"
#include "lineAlgorithm.hpp"
#include "pages.hpp"
#include "constants.hpp"
#include "drawShapes.hpp"
#include "drawUI.hpp"



int gamestate = 0;
int toolState = 0;

int sizePen = 1;



u8 red[3] = {0,0,255};
u8 blue[3] = {255,0,0};
u8 white[3] = {255,255,255};
u8 grey[3] = {128, 128, 128};
u8 black[3] = {0, 0, 0};

u8 selectedColor[3];





int main(int argc, char* argv[]) {
    
    // Init libs
    gfxInitDefault();
    
    //config Framebuffers
    u8* screen;
    screen = gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL);
    
    u8* topScreen;
    topScreen = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
    
    gfxSetDoubleBuffering(GFX_TOP, true);
    gfxSetDoubleBuffering(GFX_BOTTOM, true);
    
    memcpy(selectedColor, red, sizeof(red));
    resetUndo(screen);
    
    // Main loop
    while (aptMainLoop())
    {
        hidScanInput();
        
        // Respond to user input gotten from libctru example
        u32 kDown = hidKeysDown();
        
        //Respond to touch
        touchPosition touch;
        hidTouchRead(&touch);
        
        if (kDown & KEY_START)
            break; // break in order to return to hbmenu
        
        if(gamestate == 0){

            //render grey screen on bottom screen
            fillScreen(topScreen, grey);
            
            
            fillScreen(screen, white);
            initPages(topScreen, screen);
//            int pO[2]= {20, 40};
//            int pF[2]= {80, 100};
//            drawBox(screen, pO, pF, blue);
//
//            int p1[2]= {100, 40};
//            int p2[2]= {20, 50};
//            int p3[2]= {60, 60};
//
//            drawTriangle(screen,p1,p2,p3, grey);

            //TO ADD MENU LATER (GAMESTATE == 1 wihtout any selection)
            // ADD following code below for exit to menu
            //            if(kDown & KEY_B){
            //                gamestate = 0;
            //            }
            //draw ui
            drawUI(screen);
            gamestate = 1;
            
        }
        
        if(gamestate == 1 ){
            //Check if user changes pages and if so changes pages

            
            //Checks if user undos
           
            
            //User tools gets from UI
            toolState = checkUI(screen, touch.px, touch.py);
            if(toolState == 0 && touch.py<SCREEN_HEIGHT-UI_HEIGHT){
                //draws line based on user touch
                drawLine(screen, touch.px , touch.py, selectedColor, sizePen);
            }
            if(toolState == 1){
                sizePen = 1;
                memcpy(selectedColor, black, sizeof(black));
                toolState = 0;
            }
            if(toolState == 2){
                sizePen = 1;
                memcpy(selectedColor, blue, sizeof(blue));
                toolState = 0;
            }
            if(toolState == 3){
                sizePen = 1;
                memcpy(selectedColor, red, sizeof(red));
                toolState = 0;
            }
            if(toolState == 4){
                memcpy(selectedColor, white, sizeof(white));
                sizePen = 7;
                toolState = 0;
            }

            if((toolState == 5 || (kDown & KEY_L))){
                //Undo
                checkUndo(UNDO, screen);
                toolState = 0;
            }
            if((toolState == 6 || (kDown & KEY_R))){
                //Redo
                checkUndo(REDO, screen);
                toolState = 0;
            }
            if((toolState == 7 || (kDown & KEY_DUP))){
                //changes page up
                checkChangePages(UP, screen, topScreen);
                toolState = 0;
            }
            if((toolState == 8 || (kDown & KEY_DDOWN))){
                //changes page down
                checkChangePages(DOWN, screen, topScreen);
                toolState = 0;
            }
            if((toolState == 9 || (kDown & KEY_X))){
                //clears drawing
                int p1[2] = {1,1};
                int p2[2] = {320,210};
                drawBox(screen, p1, p2, white);
                toolState = 0;
            }


            
        }
            
            //swap buffers and wait
            gfxSwapBuffers();
            gspWaitForEvent(GSPGPU_EVENT_VBlank1, false);
            gfxFlushBuffers();
            gfxSwapBuffers();



        
    }
    
    // Deinit libs
    
    //seems like freeing up memory is not required, more investigation is needed
//    deinitPages();
//    deinitUndo();
    gfxExit();
    return 0;
}
