#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <GL/freeglut.h>
#include "AppController.h"
#include "Toolbar.h"
#include "ColorSelector.h"
#include "Canvas.h"

class Controller : public AppController {
    Toolbar* toolbar;
    ColorSelector* colorSelector;
    Canvas* canvas;

public:
    Controller(){
        // Initialize your state variables
        toolbar = new Toolbar();
        colorSelector = new ColorSelector();
        canvas = new Canvas();
    }

    void render() {
        // Render some graphics
        toolbar->draw();
        colorSelector->draw();
        canvas->draw();
    }

    void leftMouseDown(float mx, float my) {
        if (toolbar->contains(mx, my)) {
            toolbar->handleMouseClick(mx, my);
        }

        if (colorSelector->contains(mx, my)) {
            colorSelector->handleMouseClick(mx, my);
        }

        if (canvas->contains(mx, my)) {
            canvas->handleMouseClick(mx, my, colorSelector->getSelectedColor(), toolbar->getSelectedTool());
        }
    }

    void mouseMotion(float mx, float my) {
         if (canvas->contains(mx, my)) {
            canvas->handleMouseMotion(mx, my, colorSelector->getSelectedColor(), toolbar->getSelectedTool());
        }
    }

    ~Controller(){
        // Release memory
        delete toolbar;
        delete colorSelector;
        delete canvas;
    }
};

#endif