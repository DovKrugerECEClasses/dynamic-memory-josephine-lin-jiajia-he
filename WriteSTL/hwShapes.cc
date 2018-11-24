/*
	Cube
	Cylinder
	Sphere (optional)
https://en.wikipedia.org/wiki/STL_(file_format)

*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979;

class Cube{
private:
    double rad,x,y,z;
public:
    Cube(double s): rad(s),x(0),y(0),z(0){}
    void translate(double dx, double dy, double dz){
        x+=dx;
        y+=dy;
        z+=dz;
    }
    double volume(){
        return rad*rad*rad;
    }
    void write(const string& filename){
        ofstream file(filename);
        file << //"solid cube"<<
                "\n\tfacet normal 0 0 0\n\t\touter loop\n\t\t\tvertex "<< x <<" "<< y <<" "<< z <<"\n\t\t\tvertex "<< x <<" "<< y+rad <<" "<< z <<
        "\n\t\t\tvertex "<< x+rad<<" "<< y+rad<<" "<< z <<"\n\t\tendloop" << "\n\tendfacet"<<
        "\n\tfacet normal 0 0 0\n\t\touter loop\n\t\t\tvertex "<< x <<" "<< y <<" "<< z <<"\n\t\t\tvertex "<< x+rad <<" "<< y+rad <<" "<< z <<
        "\n\t\t\tvertex "<< x+rad<<" "<< y<<" "<< z <<"\n\t\tendloop" << "\n\tendfacet"<<
        "\n\tfacet normal 0 0 0\n\t\touter loop\n\t\t\tvertex "<< x <<" "<< y <<" "<< z <<"\n\t\t\tvertex "<< x <<" "<< y <<" "<< z+rad <<
        "\n\t\t\tvertex "<< x <<" "<< y+rad <<" "<< z+rad <<"\n\t\tendloop" << "\n\tendfacet"<<
        "\n\tfacet normal 0 0 0\n\t\touter loop\n\t\t\tvertex "<< x <<" "<< y <<" "<< z <<"\n\t\t\tvertex "<< x <<" "<< y+rad <<" "<< z+rad <<
        "\n\t\t\tvertex "<< x <<" "<< y+rad <<" "<< z <<"\n\t\tendloop" << "\n\tendfacet"<<
        "\n\tfacet normal 0 0 0\n\t\touter loop\n\t\t\tvertex "<< x <<" "<< y <<" "<< z <<"\n\t\t\tvertex "<< x+rad <<" "<< y <<" "<< z <<
        "\n\t\t\tvertex "<< x+rad <<" "<< y <<" "<< z+rad <<"\n\t\tendloop" << "\n\tendfacet"<<
        "\n\tfacet normal 0 0 0\n\t\touter loop\n\t\t\tvertex "<< x <<" "<< y <<" "<< z <<"\n\t\t\tvertex "<< x+rad <<" "<< y <<" "<< z+rad <<
        "\n\t\t\tvertex "<< x <<" "<< y <<" "<< z+rad <<"\n\t\tendloop" << "\n\tendfacet"<<
        "\n\tfacet normal 0 0 0\n\t\touter loop\n\t\t\tvertex "<< x <<" "<< y <<" "<< z+rad <<"\n\t\t\tvertex "<< x+rad <<" "<< y <<" "<< z+rad <<
        "\n\t\t\tvertex "<< x+rad <<" "<< y+rad <<" "<< z+rad <<"\n\t\tendloop" << "\n\tendfacet"<<
        "\n\tfacet normal 0 0 0\n\t\touter loop\n\t\t\tvertex "<< x <<" "<< y <<" "<< z+rad <<"\n\t\t\tvertex "<< x+rad <<" "<< y+rad <<" "<< z+rad <<
        "\n\t\t\tvertex "<< x <<" "<< y+rad <<" "<< z+rad <<"\n\t\tendloop" << "\n\tendfacet"<<
        "\n\tfacet normal 0 0 0\n\t\touter loop\n\t\t\tvertex "<< x+rad <<" "<< y <<" "<< z <<"\n\t\t\tvertex "<< x+rad <<" "<< y+rad <<" "<< z <<
        "\n\t\t\tvertex "<< x+rad <<" "<< y+rad <<" "<< z+rad <<"\n\t\tendloop" << "\n\tendfacet"<<
        "\n\tfacet normal 0 0 0\n\t\touter loop\n\t\t\tvertex "<< x+rad <<" "<< y <<" "<< z <<"\n\t\t\tvertex "<< x+rad <<" "<< y+rad <<" "<< z+rad <<
        "\n\t\t\tvertex "<< x+rad <<" "<< y <<" "<< z+rad <<"\n\t\tendloop" << "\n\tendfacet"<<
        "\n\tfacet normal 0 0 0\n\t\touter loop\n\t\t\tvertex "<< x <<" "<< y+rad <<" "<< z <<"\n\t\t\tvertex "<< x <<" "<< y+rad <<" "<< z+rad <<
        "\n\t\t\tvertex "<< x+rad <<" "<< y+rad <<" "<< z+rad <<"\n\t\tendloop" << "\n\tendfacet"<<
        "\n\tfacet normal 0 0 0\n\t\touter loop\n\t\t\tvertex "<< x <<" "<< y+rad <<" "<< z <<"\n\t\t\tvertex "<< x+rad <<" "<< y+rad <<" "<< z+rad <<
        "\n\t\t\tvertex "<< x+rad <<" "<< y+rad <<" "<< z <<"\n\t\tendloop" << "\n\tendfacet";
        //"\nendsolid cube"<< endl;
        file.close();
    }

};

class Cylinder{
private:
    double rad, height;
    int fn;
public:
    Cylinder(double r, double height): rad(r), height(height),fn(){
        fn=6;
    }
    Cylinder(double r, double height, int a): rad(r), height(height),fn(a){
    }
    void write(const string& filename){
        double dot[100][3]={0};
        for(int i=0;i<fn;i++){
            int theta = (360.0/fn)*(i+1);
            dot[i][0]=rad*cos(theta*PI/180.0);
            dot[i][1]=rad*tan(theta*PI/180.0)*cos(theta*PI/180.0);
        }
        ofstream file(filename);
        //file << "solid cylinder";
        for(int i=0;i<fn;i++){
            file << "\n\tfacet normal 0 0 0\n\t\touter loop"<<"\n\t\t\tvertex "<< 0 <<" "<< 0 <<" "<< 0 <<"\n\t\t\tvertex "<< dot[i][0] <<" "<< dot[i][1] <<" "<< 0 <<
                 "\n\t\t\tvertex "<< dot[i+1][0]<<" "<< dot[i+1][1]<<" "<< 0 <<"\n\t\tendloop" << "\n\tendfacet";
        }
        file << "\n\tfacet normal 0 0 0\n\t\touter loop"<<"\n\t\t\tvertex "<< 0 <<" "<< 0 <<" "<< 0 <<"\n\t\t\tvertex "<< dot[fn-1][0] <<" "<< dot[fn-1][1] <<" "<< 0 <<
             "\n\t\t\tvertex "<< dot[0][0]<<" "<< dot[0][1]<<" "<< 0 <<"\n\t\tendloop" << "\n\tendfacet";
        for(int i=0;i<fn;i++){
            file << "\n\tfacet normal 0 0 0\n\t\touter loop"<<"\n\t\t\tvertex "<< dot[i][0] <<" "<< dot[i][1] <<" "<< 0 <<"\n\t\t\tvertex "<< dot[i+1][0] <<" "<< dot[i+1][1] <<" "<< 0 <<
                 "\n\t\t\tvertex "<< dot[i][0]<<" "<< dot[i][1]<<" "<< height <<"\n\t\tendloop" << "\n\tendfacet"<<
                 "\n\tfacet normal 0 0 0\n\t\touter loop"<<"\n\t\t\tvertex "<< dot[i][0] <<" "<< dot[i][1] <<" "<< height <<"\n\t\t\tvertex "<< dot[i+1][0] <<" "<< dot[i+1][1] <<" "<< height <<
                 "\n\t\t\tvertex "<< dot[i][0]<<" "<< dot[i][1]<<" "<< 0 <<"\n\t\tendloop" << "\n\tendfacet";
        }
        file << "\n\tfacet normal 0 0 0\n\t\touter loop"<<"\n\t\t\tvertex "<< dot[fn-1][0] <<" "<< dot[fn-1][1] <<" "<< 0 <<"\n\t\t\tvertex "<< dot[0][0] <<" "<< dot[0][1] <<" "<< 0 <<
             "\n\t\t\tvertex "<< dot[fn-1][0]<<" "<< dot[fn-1][1]<<" "<< height <<"\n\t\tendloop" << "\n\tendfacet"<<
             "\n\tfacet normal 0 0 0\n\t\touter loop"<<"\n\t\t\tvertex "<< dot[fn-1][0] <<" "<< dot[fn-1][1] <<" "<< height <<"\n\t\t\tvertex "<< dot[0][0] <<" "<< dot[0][1] <<" "<< height <<
             "\n\t\t\tvertex "<< dot[fn-1][0]<<" "<< dot[fn-1][1]<<" "<< 0 <<"\n\t\tendloop" << "\n\tendfacet";
        for(int i=0;i<fn;i++){
            file << "\n\tfacet normal 0 0 0\n\t\touter loop"<<"\n\t\t\tvertex "<< 0 <<" "<< 0 <<" "<< height <<"\n\t\t\tvertex "<< dot[i][0] <<" "<< dot[i][1] <<" "<< height <<
                 "\n\t\t\tvertex "<< dot[i+1][0]<<" "<< dot[i+1][1]<<" "<< height <<"\n\t\tendloop" << "\n\tendfacet";
        }
        file << "\n\tfacet normal 0 0 0\n\t\touter loop"<<"\n\t\t\tvertex "<< 0 <<" "<< 0 <<" "<< height <<"\n\t\t\tvertex "<< dot[fn-1][0] <<" "<< dot[fn-1][1] <<" "<< height <<
             "\n\t\t\tvertex "<< dot[0][0]<<" "<< dot[0][1]<<" "<< height <<"\n\t\tendloop" << "\n\tendfacet";
        //file << "\nendsolid cylinder"<< endl;
        file.close();


    }

};

class Design{
private:

public:
    void add(Cube a){
        a.write("addfile.stl");
    }
    void add(Cylinder a){
        a.write("addfile1.stl");
    }
    void write(const string& filename){
        ifstream file1( "addfile.stl");
        ifstream file2( "addfile1.stl");
        ofstream combinefile(filename);
        combinefile << "solid cube"<<file1.rdbuf()<< file2.rdbuf()<<"\nendsolid cylinder"<< endl;
        combinefile.close();
    }
};

int main(){
    Design d;
    double s = 10;
    Cube c(s);
    double x=1, y=2, z=3;//define the position of the cube
    c.translate(x,y,z);
    // rotate??
    cout << c.volume() << '\n';
    //c.write("out.stl"); // how to get all my shapes into the same file
    d.add(c);
    double r = 10, height = 20;
    Cylinder cyl(r, height);
    int a;
    cout << "insert n-sided cylinder"<< endl;
    cin>>a;
    Cylinder cylin(r, height,a);
    d.add(cylin);
    d.write("test.stl");
}
