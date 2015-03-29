//
//  letter.h
//  words
//
//  Created by Jackson Corgey on 3/19/15.
//
//

#ifndef __words__letter__
#define __words__letter__

#include <stdio.h>
#include "ofMain.h"
class letter{
public:
    letter();
    letter(ofVec2f pos);
    void update();
    void draw();
    bool mousePressed(int x, int y);
    ofVec3f returnPosition();
    void mouseRelease();
   
private:
    ofPlanePrimitive plane;
    ofTrueTypeFont verdana;
    static const int size  = 50;
    float width = size;
    float height = size;
    float scaleRate = .1;
    float currentScale = 1;
    int posX; //upper leftCorner of the plane object
    int posY;
    bool isMousePressed = false;
};

#endif /* defined(__words__letter__) */
