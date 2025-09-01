#ifndef BUTTON_H
#define BUTTON_H

#include <GL/freeglut.h>
#include <string>
#include <iostream>

class Button {
public:
    float r,g,b,thick;
    float x;
    float y;
    float w;
    float h;
    bool pressed;
    std::string text;

    Button() {
        x = 0.0f;
        y = 0.0f;
        w = 0.4f;
        h = 0.2f;
        pressed = false;
        text = "Button";
    }

    Button(float x, float y, std::string _text) {
        this -> x = x;
        this -> y = y;
        w = 0.4f;
        h = 0.2f;
        r = 0.0;
        g = 0.0;
        b = 0.0;
        thick = 1.0;
        pressed = false;
        text = _text;
    }
    Button(float _x, float _y, float _w, float _h){
        x = _x;
        y = _y;
        w = _w;
        h = _h;
        thick = 3.0;
        r = 0.0;
        g = 0.0;
        b = 0.0;
        text = "";
    }
    Button(float x, float y, float w, float h, float r, float g, float b){
        this -> x = x;
        this -> y = y;
        this -> w = w;
        this -> h = h;
        this -> r = r;
        this -> g = g;
        this -> b = b;
        text = "";
    }
    void updateRGB(float _r, float _g, float _b){
        r = _r;
        g = _g;
        b = _b;
        
    }
    void updateT(float _thick){
        thick = _thick;
       
    }
    void draw() {
        float padding = 0.06f;

        if (text.length()>0){
            float textWidth = 0;
            for (int i = 0; i < text.length(); i++) {
                textWidth += glutBitmapWidth(GLUT_BITMAP_9_BY_15, text[i]);
            }
            textWidth = 2 * (textWidth / 400);
            w = textWidth + padding;
        }

        // white polygon
        glColor3f(1.0f, 1.0f, 1.0f);
        
        
        // black border
        glLineWidth(thick);
        glColor3f(1-r,1-g,1-b);
        glBegin(GL_POLYGON);
            glVertex2f(x,y);
            glVertex2f(x+w,y);
            glVertex2f(x+w,y-h);
            glVertex2f(x,y-h);
        glEnd();
        glColor3f(r, g, b);
        glBegin(GL_LINES);
            glVertex2f(x, y);
            glVertex2f(x + w, y);

            glVertex2f(x + w, y);
            glVertex2f(x + w, y - h);

            glVertex2f(x + w, y - h);
            glVertex2f(x, y - h);

            glVertex2f(x, y - h);
            glVertex2f(x, y);
        glEnd();

        // position of where text will be rendered
        if (pressed) {
            glRasterPos2f(x + (padding / 2) - 0.02f, y - (h / 2) - 0.045f);
        } else {
            glRasterPos2f(x + (padding / 2), y - (h / 2) - 0.025f);
        }
        for (int i = 0; i < text.length(); i++) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text[i]);
        }

        // // alternative way to render text
        // const unsigned char* temp = (unsigned char*) text.c_str();
        // glutBitmapString(GLUT_BITMAP_9_BY_15, temp);
    }
    

    bool contains(float mx, float my) {
        if (mx >= x && mx <= x + w && my <= y && my >= y - h) {
            return true;
        }
        return false;
    }

    void getXY(float XYWH[4]){
        XYWH[0] = x;
        XYWH[1] = y;
        XYWH[2] = w;
        XYWH[3] = h;

    }

    void setX(float x){
        this->x = x;
    }
};

#endif