#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include "Rectangle.h"
#include "Color.h"

class ColorSelector {
private:
    Rectangle* area;
    Rectangle* red;
    Rectangle* green;
    Rectangle* blue;
    Color* color;

public:
    ColorSelector() {
        area = new Rectangle(-0.8f, -0.8f, 1.8f, 0.2f, 0.8f, 0.8f, 0.8f);
        red = new Rectangle(-0.8f, -0.8f, 0.2f, 0.2f, 1.0f, 0.0f, 0.0f);
        green = new Rectangle(-0.6f, -0.8f, 0.2f, 0.2f, 0.0f, 1.0f, 0.0f);
        blue = new Rectangle(-0.4f, -0.8f, 0.2f, 0.2f, 0.0f, 0.0f, 1.0f);
        color = new Color(1.0f, 0.0f, 0.0f);
        red->select();
    }

    ColorSelector(float r, float g, float b) {
        area = new Rectangle(-0.8f, -0.8f, 1.8f, 0.2f, 0.8f, 0.8f, 0.8f);
        red = new Rectangle(-0.8f, -0.8f, 0.2f, 0.2f, 1.0f, 0.0f, 0.0f);
        green = new Rectangle(-0.6f, -0.8f, 0.2f, 0.2f, 0.0f, 1.0f, 0.0f);
        blue = new Rectangle(-0.4f, -0.8f, 0.2f, 0.2f, 0.0f, 0.0f, 1.0f);
        color = new Color(r, g, b);
        red->select();
    }

    void draw() {
        area->draw();
        red->draw();
        green->draw();
        blue->draw();
    }

    void handleMouseClick(float mx, float my) {
        if (red->contains(mx, my)) {
            red->select();
            green->deselect();
            blue->deselect();
            color->makeRed();
        }
        else if (green->contains(mx, my)) {
            red->deselect();
            green->select();
            blue->deselect();
            color->makeGreen();
        }
        else if (blue->contains(mx, my)) {
            red->deselect();
            green->deselect();
            blue->select();
            color->makeBlue();
        }
    }

    bool contains(float mx, float my) {
        return area->contains(mx, my);
    }

    // getters
    Color getSelectedColor() {
        return *color;
    }

    ~ColorSelector() {
        delete area;
        delete red;
        delete green;
        delete blue;
        delete color;
    }
};

#endif