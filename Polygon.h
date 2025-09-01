#ifndef POLY_H
#define POLY_H
#include "Point.h"

class Polygon{
private:
    Point* curr;
    Polygon* next;
public:
    bool closed = false;
    Polygon(float x, float y, float r, float g, float b){
        curr = new Point(x,y,r,g,b,1.0);
    }
    void draw(){
        curr -> draw();
        if (next != 0){
            glLineWidth(1.0);
            glColor3f(curr -> getR(), curr -> getG(), curr -> getB());
            glBegin(GL_LINES);
                glVertex2f(curr -> getX(), curr -> getY());
                glVertex2f(next -> getX(), next -> getY());
            glEnd();
            next -> draw();
        }
    }
    void append(float x, float y, float r, float g, float b){
        if (next == 0){
            next = new Polygon(x,y,r,g,b);   
        }
        else {
            next -> append(x,y,r,g,b);
        }
    }

    bool complete(float x, float y){
        if (next == 0){
            if(curr->getX() == x && curr->getY() ==y){
                return true;
            }
            else return false;
        }
        return next -> complete(x,y);

    }

    float getX(){
        return curr -> getX();
    }
    float getY(){
        return curr -> getY();
    }

    ~Polygon(){
        delete curr;
        delete next;
    }
    

};

#endif