#ifndef FRACTURE_H
#define FRACTURE_H

#include <iostream>

class fracture{
private:
    int num = 0;
    int del = 1;

    void simplify();
public:
    fracture();
    fracture(int n);
    fracture(int n, int d);

    int _num() const {return num;}
    int _del() const {return del;}
    void set_num(int n) {num = n; simplify();}
    void set_del(int d);

    fracture operator + (const fracture& other) const;
    fracture operator - (const fracture& other) const;
    fracture operator * (const fracture& other) const;
    fracture operator / (const fracture& other) const;

    fracture& operator += (const fracture& other);
    fracture& operator -= (const fracture& other);
    fracture& operator *= (const fracture& other);
    fracture& operator /= (const fracture& other);

    friend std::ostream& operator << (std::ostream& os, const fracture& fr);
};

#endif