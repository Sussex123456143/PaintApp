#ifndef SLIDER_H
#define SLIDER_H

#import "Button.h"

class Slider{
private:
    Button line;
    Button thumb;
public:
    Slider(){
        line = Button(0.0,0.0,0.6,0.2,0.0,0.0,0.0);
        thumb = Button(0.3,0.0,0.3,0.2,1.0,1.0,1.0);
    }
    Slider(float x, float y, float r, float g, float b){
        line = Button(x,y,.6f,.06,0.0,0.0,0.0);
        thumb = Button(x+.24,y,.12,.06,r,g,b);
    }
    void draw(){
        line.draw();
        thumb.draw();
    }
    
    bool contains(float x, float y){
        return line.contains(x,y);
    }
    void handleMouseClick(float x,float y){
        float thumbPos[4];
        thumb.getXY(thumbPos);
        if (x > thumbPos[0] + thumbPos[2]){
            thumb.setX(thumbPos[0]+.05);
        }
        else if(x < thumbPos[0]){
            thumb.setX(thumbPos[0]-.05);
        }
    }
    void handleMouseMotion(float x, float y){
        if (thumb.contains(x, y)){
            float thumbPos[4];
            thumb.getXY(thumbPos);
            thumb.setX(x-(thumbPos[2]/2));
        }
    }
    float getValue(){
        float output;
        float thumbPos[4];
        float sliderPos[4];
        thumb.getXY(thumbPos);
        line.getXY(sliderPos);
        output = (thumbPos[0]-sliderPos[0]+(.5*thumbPos[2]))/(sliderPos[2]);
        return output;
    }

};

#endif