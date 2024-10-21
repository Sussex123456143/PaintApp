#ifndef CANVAS_H
#define CANVAS_H

#include "Rectangle.h"
#include "Point.h"
#include "Color.h"
#include "Tool.h"

class Canvas {
private:
    Rectangle* area;
    Point* points;
    int capacity;
    int pCounter;

public:
    Canvas() {
        area = new Rectangle(-0.8f, 1.0f, 1.8f, 1.8f, 1.0f, 1.0f, 1.0f);
        capacity = 1000;
        pCounter = 0;
        points = new Point[capacity];
    }

    void draw() {
        area->draw();

        for (int i = 0; i < pCounter; i++) {
            points[i].draw();
        }
    }

    void handleMouseClick(float mx, float my, Color color, Tool tool) {
        if (tool == PENCIL) {
            points[pCounter] = Point(mx, my, color.getR(), color.getG(), color.getB(), 7.0f);
            pCounter++;
        }
        else if (tool == ERASER) {
            points[pCounter] = Point(mx, my, 1.0f, 1.0f, 1.0f, 7.0f);
            pCounter++;
        }
    }

    void handleMouseMotion(float mx, float my, Color color, Tool tool) {
        if (tool == PENCIL) {
            points[pCounter] = Point(mx, my, color.getR(), color.getG(), color.getB(), 7.0f);
            pCounter++;
        }
        else if (tool == ERASER) {
            points[pCounter] = Point(mx, my, 1.0f, 1.0f, 1.0f, 7.0f);
            pCounter++;
        }
    }

    bool contains(float mx, float my) {
        return area->contains(mx, my);
    }

    ~Canvas() {
        delete area;
        delete[] points;
    }
};

#endif