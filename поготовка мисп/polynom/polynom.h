#ifndef POLYNOM_H
#define POLYNOM_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Polynom{
private:
    std::vector<double> coefficients;
    void removeLeadingZeros();
public:
    Polynom();
    Polynom(const std::vector<double>& coeffs);
    //Конструктор из списка инициализации
    //Позволяет удобно создавать многочлен: Polynom p{1, 2, 3};
    //@param coeffs список коэффициентов
    Polynom(std::initializer_list<double> coeffs);

    double& operator[](size_t degree);
    const double& operator[](size_t degree) const;

    bool operator ==(const Polynom& other)const;
    bool operator !=(const Polynom& other)const;

    size_t degree() const;

    friend std::ostream& operator <<(std::ostream& os, const Polynom& poly);
};

std::ostream& operator <<(std::ostream& os, const Polynom& poly);

#endif