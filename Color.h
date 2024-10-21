#ifndef COLOR_H
#define COLOR_H

class Color {
private:
    float r;
    float g;
    float b;

public:
    Color() {
        r = 0.0f;
        g = 0.0f;
        b = 0.0f;
    }

    Color(float _r, float _g, float _b) {
        r = _r;
        g = _g;
        b = _b;
    }

    void setRGB(float _r, float _g, float _b) {
        r = _r;
        g = _g;
        b = _b;
    }

    // getters
    float getR() {
        return r;
    }

    float getG() {
        return g;
    }

    float getB() {
        return b;
    }

    // setters
    void makeRed() {
        r = 1.0f;
        g = 0.0f;
        b = 0.0f;
    }

    void makeGreen() {
        r = 0.0f;
        g = 1.0f;
        b = 0.0f;
    }

    void makeBlue() {
        r = 0.0f;
        g = 0.0f;
        b = 1.0f;
    }
};

#endif