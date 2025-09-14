#ifndef DIAMOND_H
#define DIAMOND_H
#include <GL/gl.h>
#include "LineSlope.h"

class Diamond{
private:
    float r,g,b,x,y,size;
public:
    Diamond(float r, float g, float b, float x, float y, float size){
            this->r = r;
            this->g = g;
            this->b = b;
            this->x = x;
            this->y = y;
            this->size = size;
    }
    void draw(){
        glColor3f(r,g,b);
        glBegin(GL_POLYGON);
        glVertex2f(x,y+size); //Top
        glVertex2f(x+size/2,y+size*.75);//Top right
        glVertex2f(x+size/2,y-size*.75);//Bottom right
        glVertex2f(x,y-size);//Bottom
        glVertex2f(x-size/2,y-size*.75);//Bottom left
        glVertex2f(x-size/2,y+size*.75);//Top left
        glEnd();
    }
    bool contains(float mx, float my){
        if (mx >= x-size/2 && mx <= x+size/2){
            if (my <= findY(x,y+size,x+size/2,y+size*.75,mx) && my <= findY(x-size/2,y+size*.75,x,y+size,mx)){
                if (my >= findY(x-size/2,y-size*.75,x,y-size,mx) && my >= findY(x,y-size,x+size/2,y-size*.75,mx)){
                    return true;
                }
            }
        }
        return false;
    }

    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
    float getSize(){
        return size;
    }
    void setX(float x){
        this->x = x;
    }
    void setY(float y){
        this -> y = y;
    }
    void setSize(float size){
        this -> size = size;
    }
    void setR(float r){
        this -> r = r;
    }
    void setG(float g){
        this -> g = g;
    }
    void setB(float b){
        this -> b = b;
    }
};

#endif