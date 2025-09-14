#ifndef LINE_SLOPE
#define LINE_SLOPE

float calcM(float x1, float y1, float x2, float y2){
    return ((y2-y1)/(x2-x1));
}
float calcB(float x, float y, float m){
    return (y - x*m);
}
float calcY(float x, float m, float b){
    return (x*m + b);
}
float findY(float x1, float y1, float x2, float y2, float x){
    float m = calcM(x1, y1, x2, y2);
    float b = calcB(x1, y1, m);
    return calcY(x,m,b);
}
#endif