#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <new>
#include <vector>
#include <GL/freeglut.h>
#include "AppController.h"
#include "Button.h"
#include "Point.h"
#include "Shape.h"
#include "Polygon.h"
//#include "Triangle.h"
//#include "Diamond.h"
//#include "Square.h"

class Controller : public AppController {
private:

    std::vector<Point> dots;
    std::vector<Shape*> shapes;
    std::vector<Polygon*> polygons;
    Button* Canvas;
    Button* Eraser;
    Button* Paint;
    Button* Clear;
    Button* Thin;
    Button* Med;
    Button* Large;
    Button* C;
    Button* M;
    Button* Y;
    Button* K;
    Button* R;
    Button* G;
    Button* B;
    Button* Square;
    Button* Triangle;
    Button* Diamond;
    Button* Select;
    Button* PolygonTool;
    //Button* Hint;
    

    float thick;
    float r,g,b;
    Shape* selected;

    enum toolTypes {PAINT, ERASE, SELECT, TRI, SQR, DIA, POLY};
    toolTypes tool;

        //Shape* poly;
        //Shape* polyQuad;
        //Shape* polyPent;

public:

    Controller(){

        r = 0.0;
        g = 0.0;
        b = 0.0;
        thick = 1.0;
        tool = PAINT;

        Canvas = new Button(-.70,1.0, 1.4,2.0);
        C  = new Button(-1.0,1.0,"Cyan ");
        M = new Button(-1.0,.80,"Yello");
        Y = new Button(-1.0,.60,"Mgnta");
        K = new Button(-1.0,.40," Key ");
        R = new Button(-1.0,.20," Red ");
        G = new Button(-1.0,-.0,"Green");
        B = new Button(-1.0,-.20,"Blue ");
        Eraser = new Button(-1.0,-.40,"Erase");
        Clear = new Button(-1.0,-.60,"Clear");
        Thin = new Button(.70,1.0,"Thin ");
        Med = new Button(.70,.80," Med ");
        Large = new Button(.70,.60,"Large");
        Square = new Button(.70,.40," Squ ");
        Diamond = new Button(.70,.20," Dia ");
        Triangle = new Button(.70,.0," Tri ");
        Select = new Button(.70,-.20," SEL ");
        Paint = new Button(.70,-.40,"Paint");
        PolygonTool = new Button(.70,-.60,"Poly ");
        //Hint = new Button(-0.70,-0.80,"Drag edges to resize");

        selectedColor(*K);
        selectedThick(*Thin);
        selectedTool(*Paint);

            //poly = new Shape(-0.5,0.5,0.5,0.5,0.0,.25,3);
            //polyQuad = new Shape(0.5,-0.5,0.0,0.3,0.3,.25,4);
            //polyPent = new Shape(0.25,0.25,0.5,0.0,0.5,.36,6);

            
    }

    void render() {
        Canvas -> draw();
            //polyPent -> draw();
            //polyQuad -> draw();
            //poly -> draw();
            //if (tool == SELECT) Hint -> draw();
    
        for(int i = 0; i < dots.size(); i++){
            dots[i].draw();
        }
        for(int i = 0; i < shapes.size(); i++){
            shapes[i] -> draw();
        }
        for(int i = 0; i < polygons.size(); i++){
            polygons[i] -> draw();
        }
        C -> draw();
        M -> draw();
        Y -> draw();
        K -> draw();
        R -> draw();
        G -> draw();
        B -> draw();
        Eraser -> draw();
        Clear -> draw();
        Thin -> draw();
        Med -> draw();
        Large -> draw();
        Square -> draw();
        Diamond -> draw();
        Triangle -> draw();
        Select -> draw();
        Paint -> draw();
        PolygonTool -> draw();

        if (tool == SELECT && selected != nullptr){
            selected -> setRGB(r,g,b);
            float *XY = selected -> getXY();
            Point cursor = Point(XY[0],XY[1],1-r,1-g,1-b,10);
            cursor.draw();
            delete XY;
        }
        //if (shape == TRI) std::cout << "Tri type" << std::endl;
        //else if (shape == SQR) std::cout << "Sqr type" << std::endl;
        //else if (shape == DIA) std::cout << "Dia type" << std::endl;
    }

    void leftMouseDown(float x,float y){
        //std::cout << "UI Update" << std::endl;
        
        if (C -> contains(x,y)){
            b = 1.0;
            g = 1.0;
            r = 0.0;
            selectedColor(*C);
        }
        else if (M -> contains(x,y)){
            r = 1.0;
            g = 1.0;
            b = 0.0;
            selectedColor(*M);
        }
        else if (Y -> contains(x,y)){
            r = 1.0;
            b = 1.0;
            g = 0.0;
            selectedColor(*Y);
        }
        else if (K -> contains(x,y)){
            r = 0.0;
            b = 0.0;
            g = 0.0;
            selectedColor(*K);
        }
        else if (R -> contains(x,y)) {
            r = 1.0; 
            g = 0.0; 
            b = 0.0;
            selectedColor(*R);
        }
        else if (G -> contains(x,y)){ 
            g = 1.0; 
            r = 0.0;
            b = 0.0;
            selectedColor(*G);
        } 
        else if (B -> contains(x,y)) {
            b = 1.0; 
            r = 0.0; 
            g = 0.0;
            selectedColor(*B);
        }
        else if (Clear -> contains(x,y)) {
            dots.clear();
            for(int i = 0; i < shapes.size(); i++){
                delete shapes[i];
            }
            shapes.clear();
            for(int i = 0; i < polygons.size(); i++){
                delete polygons[i];
            }
            polygons.clear();
            selected = nullptr;
            
        }
        else if (Thin -> contains(x,y)) {thick = 1.0; selectedThick(*Thin);}
        else if (Med -> contains(x,y)) {thick = 5.0; selectedThick(*Med);}
        else if (Large -> contains(x,y)) {thick = 10.0;selectedThick(*Large); }
        else if(Triangle -> contains(x,y)){
            selectedTool(*Triangle);
            tool = TRI;
        }
        else if(Square -> contains(x,y)){
            selectedTool(*Square);
            tool = SQR;
        }
        else if(Diamond -> contains(x,y)){
            selectedTool(*Diamond);
            tool = DIA;
        }
        else if (Eraser -> contains(x,y)) {
            selectedTool(*Eraser);
            tool = ERASE;
        }
        else if (Paint -> contains(x,y)){
            selectedTool(*Paint);
            tool = PAINT;
        }
        else if (Select -> contains(x,y)){
            tool = SELECT;
            selectedTool(*Select);

        }
        else if(PolygonTool -> contains(x,y)){
            tool = POLY;
            selectedTool(*PolygonTool);
        }
        else if (tool == TRI && Canvas -> contains(x,y)){
            Shape* sp = new Shape(x,y,r,g,b,.125,3);
            shapes.push_back(sp);
        }
        else if (tool == SQR && Canvas -> contains(x,y)){
            Shape* sp = new Shape(x,y,r,g,b,.125,4);
            shapes.push_back(sp);
        }
        else if (tool == DIA && Canvas -> contains(x,y)){
            Shape* sp = new Shape(x,y,r,g,b,.125,6);
            shapes.push_back(sp);
        }
        else if (tool == SELECT && Canvas -> contains(x,y)){
            for(int i = 0; i < shapes.size(); i++){
                if(shapes[i] ->contains(x,y)){
                    selected = shapes[i];
                }
            }
        }
        else if(tool == POLY && Canvas -> contains(x,y)){
            
            if (polygons.empty()){
                Polygon* pg = new Polygon(x,y,r,g,b);
                polygons.push_back(pg);
            }
            else if(polygons.back() -> closed){
                Polygon* pg = new Polygon(x,y,r,g,b);
                polygons.push_back(pg);
            }
            else {
                polygons.back() -> append(x,y,r,g,b);
            }
            
            
        }
        

    }

    void selectedColor(Button a){
        if (C->text == a.text) C->updateRGB(r,g,b);
        else {C->updateRGB(0.0,0.0,0.0);}
        if (M->text == a.text)M->updateRGB(r,g,b);
        else M->updateRGB(0.0,0.0,0.0);
        if (Y->text == a.text) Y->updateRGB(r,g,b);
        else Y->updateRGB(0.0,0.0,0.0);
        if (K->text == a.text) K->updateT(2.0);
        else K->updateT(1.0);
        if (R->text == a.text) R->updateRGB(r,g,b);
        else R->updateRGB(0.0,0.0,0.0);
        if (G -> text == a.text) G -> updateRGB(r,g,b);
        else G -> updateRGB(0.0,0.0,0.0);
        if (B->text == a.text) B->updateRGB(r,g,b);
        else B->updateRGB(0.0,0.0,0.0);
    }

    void selectedThick(Button a){
        if (Thin -> text == a.text) Thin -> updateT(thick*2.5);
        else {Thin -> updateT(1.0);}
        if (Med -> text == a.text)Med -> updateT(thick);
        else Med -> updateT(1.0);
        if (Large -> text == a.text) Large -> updateT(thick);
        else Large -> updateT(1.0);
    }
    
    void selectedTool(Button a){
        if(Square -> text == a.text) Square -> updateT(1.5);
        else Square -> updateT(1.0);
        if(Diamond -> text == a.text) Diamond -> updateT(1.5);
        else Diamond -> updateT(1.0);
        if(Triangle -> text == a.text) Triangle -> updateT(1.5);
        else Triangle -> updateT(1.0);
        if(Eraser -> text == a.text) Eraser -> updateT(1.5);
        else Eraser -> updateT(1.0);
        if(Paint -> text == a.text) Paint -> updateT(1.5);
        else Paint -> updateT(1.0);
        if(Select -> text == a.text) Select -> updateT(1.5);
        else Select -> updateT(1.0);
        if(PolygonTool -> text == a.text) PolygonTool -> updateT(1.5);
        else {
            PolygonTool -> updateT(1.0);
            if (!polygons.empty()){
                polygons.back() -> append(polygons.back()->getX(), polygons.back()->getY(),r,g,b);
                polygons.back() -> closed = true;
            }
            //polygons.push_back(nullptr);
        }

    }


    void mouseMotion(float x, float y) {
        if (tool == PAINT && Canvas->contains(x,y)){
            Point pt = Point(x,y,r,g,b,thick);
            dots.push_back(pt);
        }
        else if (tool == ERASE && Canvas->contains(x,y)){
            for(int i = 0; i < dots.size(); i++){
                if (dots[i].inRange(x,y,thick/10)){
                    dots.erase(dots.begin()+i);
                }
            }
        }
        else if(tool == SELECT && Canvas -> contains(x,y) && selected -> contains(x,y)){
            //for(int i = 0; i < shapes.size(); i++){
                //if(shapes[i] ->contains(x,y)){
                    selected -> handleMouseMotion(x,y);
                //}
            //}
        }
    }




    ~Controller(){
        delete Canvas;
        delete Eraser;
        delete Clear;
        delete Thin;
        delete Med;
        delete Large;
        delete C;
        delete M;
        delete Y;
        delete K;
        delete R;
        delete G;
        delete B;
        delete Square;
        delete Diamond;
        delete Triangle;
        delete Select;
        delete selected;
        delete PolygonTool;
        //delete Hint;


    }
};

#endif