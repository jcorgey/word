//
//  grid.cpp
//  words
//
//  Created by Jackson Corgey on 3/25/15.
//
//

#include "grid.h"
grid::grid(){
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
   
    ofVec2f pos(100,100);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = new letter(pos);
            pos.x = pos.x + 60;
        }
        pos.x = 100;
        pos.y = pos.y + 60;
    }
}

void grid::draw(){
   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j]->draw();
            
        }
    }
    mesh.draw();
    

}

void grid::update(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j]->update();
        }
    }
}

void grid::mousePressed(int x, int y){
    static int preX = nil;
    static int preY = nil;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if(preX == nil){
                if(board[i][j]->mousePressed(x, y)){
                    mesh.addVertex(board[i][j]->returnPosition());
                    preX = i;
                    preY = j;
                }
            }
            else{
                if(board[i][j]->mousePressed(x, y))
                    if(i >= preX-1 && i <= preX + 1)
                         if(j >= preY-1 && j <= preY + 1)
                         {
                             mesh.addVertex(board[i][j]->returnPosition());
                             preX = i;
                             preY = j;                }
                }

    }

}
}

void grid::mouseRelease(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j]->mouseRelease();
        }
    }
}