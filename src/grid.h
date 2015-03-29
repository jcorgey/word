//
//  grid.h
//  words
//
//  Created by Jackson Corgey on 3/25/15.
//
//

#ifndef __words__grid__
#define __words__grid__

#include <stdio.h>
#include "letter.h"

class grid{
public:
    grid();
    void draw();
    void update();
    void mousePressed(int x, int y);
    void mouseRelease();
private:
   letter * board[9][3];
   ofMesh mesh;
};
#endif /* defined(__words__grid__) */
