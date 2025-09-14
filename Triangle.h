#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <GL/gl.h>
#include "LineSlope.h"


class Triangle{
private:
    float r,g,b;
    float x,y, size;
public:

    Triangle(float r, float g, float b, float x, float y, float size){
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
        glVertex2f(x,y+size); //Top vertex
        glVertex2f(x+size*.866,y-size/2); //Right vertex
        glVertex2f(x-size*.866,y-size/2); //Left vertex
        glEnd();
    }

    bool contains(float mx, float my){
        if (my >= y-size/2){
            if (my <= findY(x-(size*.866),y-(size/2),x,y+size,mx)){
                if (my <= findY(x,y+size,x+(size*.866),y-(size/2),mx)){
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