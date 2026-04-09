#include "3d.h"
#include <iostream>
#include <cmath>

point3d::point3d(float x, float y, float z): x(x), y(y), z(z) {}
point3d::point3d(const point3d& p): x(p.x), y(p.y), z(p.y) {}
point3d& point3d::operator=(const point3d& other) 
{
    if (&other != this)
    {
        x=other.x;
        y=other.y;
        z=other.z;
    }
    return *this;
}

float point3d::getx() const {return x;}
float point3d::gety() const {return y;}
float point3d::getz() const {return z;}
void point3d::setx(float _x) {x=_x;}
void point3d::sety(float _y) {y=_y;}
void point3d::setz(float _z) {z=_z;}

const point3d getRoPhi(const point3d& other)
{
    float x = other.getx();  // используем геттеры
    float y = other.gety();
    float z = other.getz();
    
    float rho = std::sqrt(x * x + y * y);
    
    // Вычисляем φ (азимутальный угол) с учетом знаков x и y
    float phi;
    if (x == 0 && y == 0) {
        phi = 0;  // Начало координат - угол не определен, возвращаем 0
    } else {
        phi = std::atan2(y, x);
    }
    
    return point3d(rho, phi, z);
}