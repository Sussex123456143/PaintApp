#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "Rectangle.h"
#include "Texture.h"
#include "Tool.h"

class Toolbar {
private:
    Rectangle* area;
    Texture* pencil;
    Texture* eraser;
    Tool tool;

public:
    Toolbar() {
        area = new Rectangle(-1.0f, 1.0f, 0.2f, 2.0f, 0.8f, 0.8f, 0.8f);
        pencil = new Texture(-1.0f, 1.0f, 0.2f, 0.2f, "assets/pencil.png");
        eraser = new Texture(-1.0f, 0.8f, 0.2f, 0.2f, "assets/eraser.png");
        tool = PENCIL;
        pencil->select();
    }
    
    void draw() {
        area->draw();
        pencil->draw();
        eraser->draw();
    }

    void handleMouseClick(float mx, float my) {
        if (pencil->contains(mx, my)) {
            pencil->select();
            eraser->deselect();
            tool = PENCIL;
        }
        else if (eraser->contains(mx, my)) {
            pencil->deselect();
            eraser->select();
            tool = ERASER;
        }
    }

    bool contains(float mx, float my) {
        return area->contains(mx, my);
    }

    // getters
    Tool getSelectedTool() {
        return tool;
    }

    ~Toolbar() {
        delete area;
        delete pencil;
        delete eraser;
    }
};

#endif