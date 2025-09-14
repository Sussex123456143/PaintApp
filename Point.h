#ifndef POINT_H
#define POINT_H

#include <GL/gl.h>
#include <vector>
#include <cmath>
#include <GL/freeglut.h>
#include <string>
#include <iostream>

class Point {
private:
    float x,y,r,g,b,rad;
public:
    
    Point(float X, float Y, float R, float G, float B, float RAD){
        x = X;
        y = Y;
        r = R;
        g = G;
        b = B;
        rad = RAD;
    }
    void draw(){
        glColor3f(r,g,b);
        glPointSize(rad);
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
    }
    
    bool inRange(float X, float Y, float range){
       float _x = X-x;
       float _y = Y-y; 
       if (sqrt(_x*_x + _y*_y) <= (range)) return true;
        return false;
    }
    float getR(){
        return r;
    }
    float getG(){
        return g;
    }
    float getB(){
        return b;
    }
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
};

#endif