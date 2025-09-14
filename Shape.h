#ifndef SHAPE_H
#define SHAPE_H
#include <cmath>
#include <iostream>
#include "Triangle.h"
#include "Square.h"
#include "Diamond.h"


class Shape{
private:
    int polyType;
    Triangle* Tri;
    Square* Sqr;
    Diamond* Dia;
   

public:
    Shape (float x,float y, float r, float g, float b, float size, int type){
        if (type == 3)  {
            Tri = new Triangle(r,g,b,x,y,size);
            this-> polyType = type;
        }
        else if (type == 4) {
            Sqr = new Square(r,g,b,x,y,size);
            this-> polyType = type;
        }
        else if(type == 6){
            Dia = new Diamond(r,g,b,x,y,size);
            this -> polyType = type;
        }

        
    }
    bool contains(float mx, float my){
        if (polyType == 3)  {
            //std::cout << "Triangle contains called" << std::endl;            
            return Tri -> contains(mx,my);

        }
        else if (polyType == 4) {
            //std::cout << "Square contains called" << std::endl;
            return Sqr -> contains(mx,my);
        }
        else if(polyType == 6){
            //if (Dia -> contains(mx,my)) std::cout << "Diamond Contains true" << std::endl;
            return Dia -> contains(mx,my);
        }
        return false;
    }

    void draw(){
        if (polyType == 3){
            Tri -> draw();
            //std::cout << "Triangle drawn" << std::endl;
        }
        else if(polyType == 4){
            Sqr -> draw();
            //std::cout << "Square drawn" << std::endl;
        }
        else if(polyType == 6){
            Dia -> draw();
            //std::cout<< "Diamond drawn" << std::endl;
        }
    }

    void handleMouseMotion(float mx, float my){
        float x,y,size;
        if (polyType == 3){
            x = Tri -> getX();
            y = Tri -> getY();
            size = Tri -> getSize();
            if (sqrt(pow(x-mx,2)+pow(y-my,2)) <= size/2){
                Tri -> setX(mx);
                Tri -> setY(my);
            }
            else{
                Tri -> setSize(sqrt(pow(x-mx,2)+pow(y-my,2)) + 0.05);
                //std::cout << size << std::endl;
                if (!Tri -> contains(mx,my)) Tri -> setSize(size);
            }

        }
        else if (polyType == 4){
            x = Sqr -> getX();
            y = Sqr -> getY();
            size = Sqr -> getSize();
            if (sqrt(pow(x-mx,2)+pow(y-my,2)) <= size/2){
                Sqr -> setX(mx);
                Sqr -> setY(my);
            }
            else{
                Sqr -> setSize(sqrt(pow(x-mx,2)+pow(y-my,2)) + 0.05);
                if (!Sqr -> contains(mx,my)) Sqr -> setSize(size);
            }
        }
        else if (polyType == 6){
            x = Dia -> getX();
            y = Dia -> getY();
            size = Dia -> getSize();
            if (sqrt(pow(x-mx,2)+pow(y-my,2)) <= size/2){
                Dia -> setX(mx);
                Dia -> setY(my);
            }
            else{
                Dia -> setSize(sqrt(pow(x-mx,2)+pow(y-my,2)) + 0.05);
                if (!Dia -> contains(mx,my)) Dia -> setSize(size);
            }
        }
    }
    void setRGB(float r, float g, float b){
        if (polyType == 3){
            Tri -> setR(r);
            Tri -> setG(g);
            Tri -> setB(b);
        }
        else if (polyType == 4){
            Sqr -> setR(r);
            Sqr -> setG(g);
            Sqr -> setB(b);
        }
        else if(polyType == 6){
            Dia -> setR(r);
            Dia -> setG(g);
            Dia -> setB(b);
        }
    }
    float* getXY(){
        float* XY = new float[2];
        if (polyType == 3){
            XY[0] = Tri -> getX();
            XY[1] = Tri -> getY();
        }
        else if (polyType == 4){
            XY[0] = Sqr -> getX();
            XY[1] = Sqr -> getY();
        }
        else if(polyType == 6){
            XY[0] = Dia -> getX();
            XY[1] = Dia -> getY();
        }
        return XY;
    }
    
    ~Shape(){
        delete Tri;
        delete Sqr;
        delete Dia;
    }

};

#endif