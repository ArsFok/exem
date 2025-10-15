#include "point3D.h"
#include <iostream>
#include <cmath>


point3d::point3d(float x, float y, float z) : x(x), y(y), z(z) {}

point3d::point3d(const point3d& p) : x(p.x), y(p.y), z(p.z){}

point3d& point3d::operator=(const point3d& other){
    if(&other != this){
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}
float point3d::getX() const{
    return x;
}
float point3d::getY() const{
    return y;
}
float point3d::getZ() const{
    return z;
}
void point3d::setX(const float _x){
    x = _x;
}
void point3d::setY(const float _y){
    y = _y;
}
void point3d::setZ(const float _z){
    z = _z;
}

void getRoPhi(point3d& p){
    float x_val = p.getX();
    float y_val = p.getY();
    float z_val = p.getZ();

    float r = sqrt(pow(x_val, 2) + pow(y_val, 2));
    float fi = atan2(y_val, x_val);
    p.setX(r * cos(fi));
    p.setY(r * sin(fi));
    p.setZ(z_val);
}