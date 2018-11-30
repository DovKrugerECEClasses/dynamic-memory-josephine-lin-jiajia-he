#pragma once
//
// Created by Jacklyn He on 2018/11/25.
//

#ifndef VEC3D_VEC3D_H
#define VEC3D_VEC3D_H

#endif //VEC3D_VEC3D_H
#include<iostream>
#include<string>
using namespace std;

template <typename Precision>
class Vec3d{
private:
    Precision r,i,j;
public:
    Vec3d(Precision r, Precision i, Precision j) {}
    friend Vec3d operator +(const Vec3d& a, const Vec3d& b){
        return Vec3d(a.r+b.r, a.i+b.i, a.j+b.j);
    }
    friend ostream& operator <<(ostream s, const Vec3d& c){
        return s << c.r << "," << c.i << "," << c.j;
    }

};
