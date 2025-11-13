#include "fracture.h"
#include <stdexcept>
#include <cmath>

int gcd(int a, int b){
    a = std::abs(a);
    b = std::abs(b);
    while(b != 0){
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

fracture::fracture() : num(0), del(1){}

fracture::fracture(int n) : num(n), del(1){}

fracture::fracture(int n, int d) : num(n), del(d){
    if(d == 0){
        throw std::runtime_error("Del = 0");
    }
    simplify();
}
void fracture::simplify(){
    if(del < 0){
        num = -num;
        del = -del;
    }

    int k = gcd(num, del);
    num /= k;
    del /= k;
}

void fracture::set_del(int d){
    if(d == 0){
        throw std::runtime_error("Del = 0");
    }
    del = d;
    simplify();
}

fracture fracture::operator + (const fracture& other) const{
    return fracture(num * other.del + other.num * del, del * other.del);
}
fracture fracture::operator - (const fracture& other) const{
    return fracture(num * other.del - other.num * del, del * other.del);
}
fracture fracture::operator * (const fracture& other) const{
    return fracture(num * other.num, del * other.del);
}
fracture fracture::operator / (const fracture& other) const{
    if(other.num == 0){
        throw std::runtime_error("Del = 0");
    }
    return fracture(num * other.del, del * other.num);
}
fracture& fracture::operator +=(const fracture& other){
    *this = *this + other;
    return *this;
}
fracture& fracture::operator -=(const fracture& other){
    *this = *this - other;
    return *this;
}
fracture& fracture::operator *=(const fracture& other){
    *this = *this * other;
    return *this;
}
fracture& fracture::operator /=(const fracture& other){
    *this = *this / other;
    return *this;
}
std::ostream& operator << (std::ostream& os, const fracture& fr){
    /*if(fr.del == 1){
        os << fr.num; //целые числа при del = 1;
    }else{
        os << fr.num << "/" << fr.del;
    }*/
    os << fr.num << "/" << fr.del;
    return os;
}