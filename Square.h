#ifndef SQUARE_H
#define SQUARE_H
#include <GL/gl.h>


class Square{
private:
    float r,g,b,x,y,size;

public:
    Square(float r, float g, float b, float x, float y, float size){
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
        glVertex2f(x-size,y+size);
        glVertex2f(x+size,y+size);
        glVertex2f(x+size,y-size);
        glVertex2f(x-size,y-size);
        glEnd();
    }
    bool contains(float mx, float my){
        if (mx >= x-size && mx <= x+size){
            if (my >= y-size && my <= y+size){
                return true;
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