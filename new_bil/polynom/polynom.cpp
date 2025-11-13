#include "polynom.h"

Polynom::Polynom() : coefficients({0.0}){}
Polynom::Polynom(const std::vector<double>& coeffs) : coefficients(coeffs){
    removeLeadingZeros();
}
Polynom::Polynom(std::initializer_list<double> coeffs) : coefficients(coeffs){
    removeLeadingZeros();
}

double& Polynom::operator [] (size_t  degree){
    if(degree >= coefficients.size()){
        coefficients.resize(degree + 1, 0.0);
    }
    return coefficients[degree];
}
const double& Polynom::operator [](size_t degree) const{
    if(degree >= coefficients.size()){
        throw std::runtime_error("Степень выходит за границы диапозона!");
    }
    return coefficients[degree];
}

bool Polynom::operator ==(const Polynom& other) const{
    return coefficients == other.coefficients;
}

bool Polynom::operator !=(const Polynom& other) const{
    return !(*this == other);
}

size_t Polynom::degree() const{
    if(coefficients.empty()) return 0;
    return coefficients.size() - 1;
}

void Polynom::removeLeadingZeros(){
    while(coefficients.size() > 1 && coefficients.back() == 0.0){
        coefficients.pop_back();
    }
    if(coefficients.empty()){
        coefficients.push_back(0.0);
    }
}

std::ostream& operator <<(std::ostream& os, const Polynom& poly){
    if(poly.coefficients.empty()){
        os << "0";
        return os;
    }
    bool FirstTerm = true;

    for(int i = poly.coefficients.size() - 1; i >= 0; --i){
        double coeff = poly.coefficients[i];

        if(coeff == 0.0) continue;

        if(!FirstTerm){
            if(coeff > 0){
                os << "+";
            }else{
                os << "-";
                coeff = -coeff;
            }
        }else{
            if(coeff < 0){
                os << "-";
                coeff = -coeff;
            }
        }
        if(i == 0){
            os << coeff;
        }else  if(i == 1){
            if(coeff == 1){
                os << "x";
            }else{
                os << coeff << "x";
            }
        }else{
            if(coeff == 1){
                os << "x^" << i;
            }else{
                os << coeff << "x^" << i;
            }
        }
        FirstTerm = false;
    }
    if(FirstTerm){
        os << "0"; 
    }
    return os;
}