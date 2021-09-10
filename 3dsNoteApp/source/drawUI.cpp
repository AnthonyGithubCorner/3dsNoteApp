//
//  drawUI.cpp
//  3dsNoteApp
//
//  Created by Anthony Lazar on 2021-09-09.
//

#include "drawUI.hpp"

u8 whiteish[3] = {240,240,240};
u8 erase[3] = {255,255,255};
u8 greyish[3] = {128, 128, 128};

u8 whiteUI[3] = {255,255,255};
u8 blackUI[3] = {0,0,0};
u8 redUI[3] = {0,0,255};
u8 blueUI[3] = {255,0,0};

int box1O[2] = {0, 210};
int box1F[2] =  {30, 240};

int box2O[2] = {30, 210};
int box2F[2] =  {60, 240};

int box3O[2] = {60, 210};
int box3F[2] =  {90, 240};

int box4O[2] = {90, 210};
int box4F[2] =  {120, 240};

int box5O[2] = {120, 210};
int box5F[2] =  {150, 240};

int box6O[2] = {150, 210};
int box6F[2] =  {180, 240};

int box7O[2] = {180, 210};
int box7F[2] =  {210, 240};

int box8O[2] = {210, 210};
int box8F[2] =  {240, 240};

int box9O[2] = {240, 210};
int box9F[2] =  {270, 240};

bool pointInBox(int pO[2], int pF[2], int x, int y){
    if(x>=pO[0]&&x<=pF[0]&&y>=pO[1]&&y<=pF[1]){
        return true;
    }
    return false;
}

void drawEraser(u8* screen){
    int p1[2] = {box4O[0]+10, box4F[1]-20};
    int p2[2] = {box4F[0]-10, box4F[1]-5};
    drawBox(screen, p1, p2, blackUI);
    int p3[2] = {box4O[0]+10, box4F[1]-25};
    int p4[2] = {box4F[0]-10, box4F[1]-20};
    drawBox(screen, p3, p4, whiteUI);
}
void drawUI(u8* screen){
    drawBox(screen, box1O, box1F, blackUI);
    drawBox(screen, box2O, box2F, blueUI);
    drawBox(screen, box3O, box3F, redUI);
    
    drawBox(screen, box4O, box4F, whiteish);
    drawEraser(screen);
    
    drawBox(screen, box5O, box5F, whiteish);
    int p2[2] = {box5F[0]-5, box5O[1]+15};
    drawArrowLeft(screen,p2[0],p2[1], blackUI);
    
    drawBox(screen, box6O, box6F, whiteish);
    int p3[2] = {box6O[0]+5, box6O[1]+15};
    drawArrowRight(screen,p3[0],p3[1], blackUI);
    
    drawBox(screen, box7O, box7F, whiteish);
    int p4[2] = {box7O[0]+15, box7F[1]};
    drawArrowUp(screen,p4[0],p4[1], blackUI);
    
    drawBox(screen, box8O, box8F, whiteish);
    int p5[2] = {box8O[0]+15, box8O[1]};
    drawArrowDown(screen,p5[0],p5[1], blackUI);
    
    drawBox(screen, box9O, box9F, whiteish);
    int p1[2] = {box9O[0]+15, box9O[1]+15};
    drawX(screen,p1[0],p1[1], redUI);

}

void eraseUI(u8* screen){
    int p1[2] = {0,210};
    int p2[2] = {400,240};
    drawBox(screen, p1, p2, erase);
}


int previousTool;
int checkUI(u8* screen, int x, int y){
    int toolSelected = 0;
    if(pointInBox(box1O,box1F,x,y)){
        toolSelected= 1;
    }
    if(pointInBox(box2O,box2F,x,y)){
        toolSelected= 2;
    }
    if(pointInBox(box3O,box3F,x,y)){
        toolSelected= 3;
    }
    if(pointInBox(box4O,box4F,x,y)){
        toolSelected= 4;
    }
    if(pointInBox(box5O,box5F,x,y)){
        toolSelected= 5;
    }
    if(pointInBox(box6O,box6F,x,y)){
        toolSelected= 6;
    }
    if(pointInBox(box7O,box7F,x,y)){
        toolSelected= 7;
    }
    if(pointInBox(box8O,box8F,x,y)){
        toolSelected= 8;
    }
    if(pointInBox(box9O,box9F,x,y)){
        toolSelected= 9;
    }

    if(previousTool==toolSelected){
        return 0;
    }
    previousTool = toolSelected;
    return toolSelected;
    
}
