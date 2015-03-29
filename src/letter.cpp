//
//  letter.cpp
//  words
//
//  Created by Jackson Corgey on 3/19/15.
//
//

#include "letter.h"

letter::letter(){
    
}

letter::letter(ofVec2f pos){
    verdana.loadFont("verdana.ttf", size);
    posX = pos.x - (size/2);
    posY = pos.y - (size/2);
    plane.setPosition(pos.x, pos.y, 1);
}

void letter::update(){
    if (isMousePressed) {
        if(currentScale <.1)
            currentScale = .1;
        plane.setScale(currentScale);
        currentScale = currentScale - scaleRate;
    }
}
void letter::draw(){
    plane.set(width, height);
    plane.drawWireframe();
    verdana.drawString("A", posX, posY+size);
}

bool letter::mousePressed(int x, int y){
    if(x >= posX && y >= posY)
        if(x <= posX+size && y <= posY+size)
        {
        isMousePressed = true;
            return true;
        }
    return false;
    
}

void letter::mouseRelease(){
    isMousePressed = false;
    plane.setScale(1);
    currentScale = 1;
}

ofVec3f letter::returnPosition(){
    return ofVec3f(plane.getX(),plane.getY(),0);
}


