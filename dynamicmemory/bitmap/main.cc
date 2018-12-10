/*
 * hw-bitmap
 * Author: Jiajia He
 */

#include <iostream>
#include "Color.hh"
#include <iomanip>
#include <cmath>
#include <stdint.h>
using namespace std;
class Bitmap{
private:
    uint32_t* rgba;
    int rows,cols;
public:
    Bitmap(int r,int c):rgba(new uint32_t[r*c]),rows(r),cols(c) {
        for (int i = 0; i < r * c; i++)
            rgba[i] = 0;
    }

    Bitmap(const Bitmap& orig){
        int r = orig.rows, c = orig.cols;
        rgba = new uint32_t[r *c];
        for (int i = 0; i < r *c; i++)
            rgba[i] = orig.rgba[i];
    }

    ~Bitmap() {
        delete []rgba;
    }

    uint32_t operator ()(uint32_t i, uint32_t j) const{
        return rgba[i * cols + j];
    }

    uint32_t& operator ()(uint32_t i, uint32_t j) {
        return rgba[i * cols + j];
    }

    Bitmap& operator =(const Bitmap& orig) {
        Bitmap copy(orig);
        swap(copy.rows, rows);
        swap(copy.cols, cols);
        swap(copy.rgba, rgba);
    }

    void horizLine(int x1, int x2, int y, Color color){
        for(int i=x1*cols+y;i<=x2*cols+y;i++){
            rgba[i] = color.get();
        }

    }
    void vertLine(int y1, int y2, int x, Color color){
        for(int i=x*cols+y1;i<=x*cols+y2;i++){
            rgba[i] = color.get();
        }

    }
    void line(int x1, int y1, int x2, int y2, Color color){
        double delx = (double)(x2 - x1);
        double dely = (double)(y2 - y1);
        double del = abs((double)(dely / delx));
        double error = 0.0;
        int y = y1;
        for(int x = x1; x <= x2; x++){
            rgba[x * cols + y] = color.get();
            error = error + del;
            if (error >= 0.5) {
                y += (int)del;
                error -= 1.0;
            }
        }

    }
    void fillRect(int x, int y, int w, int h, Color color){
        for(int i=x*cols+y;i<=(x + h)*cols+(y + w);i++){
            rgba[i] = color.get();
        }

    }
    void drawRect(int x, int y, int w, int h, Color color){
        for(int i=x*cols+y;i<=(x + h)*cols+y;i++){
            rgba[i] = color.get();
        }

        for(int i=x*cols+(y+w);i<=(x + h)*cols+(y+w);i++){
            rgba[i] = color.get();
        }

        for(int i=x*cols+y;i<=x*cols+(y+w);i++){
            rgba[i] = color.get();
        }

        for(int i=(x+h)*cols+y;i<=(x+h)*cols+(y+w);i++){
            rgba[i] = color.get();
        }

    }
//    void ellipse(int x, int y, int w, int h, Color color){
//        for(int i=y1*cols+x;i<y2*cols+x;i+=cols){
//            rgba[i] = color.get();
//        }
//
//    }
    friend ostream& operator <<(ostream& s,const Bitmap& bit);

};

ostream& operator <<(ostream& s,const Bitmap& bit) {
    for (int i = 0; i < bit.rows * bit.cols; i++) {
        int b = bit(i / bit.cols, i - i/ bit.cols) / (256 * 256);
        int g = (bit(i / bit.cols, i - i/ bit.cols) - b) / 256;
        int r = bit(i / bit.cols, i - i/ bit.cols) - b - g;
        s << setw(4) << r << "," << g << "," << b << ' ';
        if (i % bit.cols == bit.cols - 1) s << '\n';
    }
    return s;
}


int main() {
    Bitmap b(30,20); // 30 pixels across, 20 pixels high, each pixel RGBA
    // top left pixel = (0,0)
    Color RED(255,0,0); // all red, no green, no blue (fully opaque)
    Color BLUE(0,255,0);
    Color GREEN(0,0,255);
    Color WHITE(255,255,255);
    Color BLACK(0,0,0);


    b.line(0,0,   19,19, RED);
    b.line(0,5,   29,10, BLUE); //Bresenham algorithm
    //https://en.wikipedia.org/wiki/Bresenham's_line_algorithm

    // https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
    //TODO: b.line(0,100, 100,50, BLUE); //Wu algorithm
    b.horizLine(0, 20, 19, GREEN); // from x=0 to x=20 at y=19
    b.vertLine(5, 0,19, GREEN); // from y = 0 to y=19 at x = 5
    b.fillRect(10,10, 4, 3,BLACK); // x = 10, y =10 w=4, h=3
    b.drawRect(10,10, 4, 3,WHITE); // x = 10, y =10 w=4, h=3
    //b.ellipse(15,0, 8, 5, RED);    // ellipse centered at (15,0) w= 8, h=5
    cout << b;
    /*
R
 R
  R
   R
    R
BBB
   BBBBB
        BBBBBB
     */
}
