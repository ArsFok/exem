#include "Polynom.h"
#include <cmath>     // для fabs, если понадобится
#include <iomanip>   // для форматирования вывода


void Polynom::removeLeadingZeros() {
    // Удаляем нули с конца, пока не встретим ненулевой коэффициент
    // или не останется только один элемент
    while (coefficients.size() > 1 && std::abs(coefficients.back()) < 1e-10) {
        coefficients.pop_back();  // удаляем последний элемент
    }
    // Гарантируем, что для нулевого многочлена есть хотя бы один ноль
    if (coefficients.empty()) {
        coefficients.push_back(0.0);
    }
}

Polynom::Polynom() : coefficients(1, 0.0) {}

Polynom::Polynom(const std::vector<double>& coeffs) : coefficients(coeffs) {
    removeLeadingZeros();  // удаляем ведущие нули после инициализации
}

Polynom::Polynom(std::initializer_list<double> coeffs) 
    : coefficients(coeffs.begin(), coeffs.end()) {
    removeLeadingZeros();
}

double& Polynom::operator[](size_t degree) {
    // Если запрашивают степень выше текущей, расширяем вектор
    if (degree >= coefficients.size()) {
        coefficients.resize(degree + 1, 0.0);
    }
    return coefficients[degree];
}

const double& Polynom::operator[](size_t degree) const {
    // Для константного доступа не можем расширять вектор
    if (degree >= coefficients.size()) {
        throw std::out_of_range("Степень превышает размер многочлена");
    }
    return coefficients[degree];
}

bool Polynom::operator ==(const Polynom& other) const {
    size_t maxDegree = std::max(degree(), other.degree());
    
    for (size_t i = 0; i <= maxDegree; ++i) {
        double coeff1 = (i < coefficients.size()) ? coefficients[i] : 0.0;
        double coeff2 = (i < other.coefficients.size()) ? other.coefficients[i] : 0.0;
        // Сравниваем с учетом погрешности вычислений с плавающей точкой
        if (std::abs(coeff1 - coeff2) > 1e-10) {
            return false;
        }
    }
    return true;
}

bool Polynom::operator !=(const Polynom& other) const {
    return !(*this == other);
}


size_t Polynom::degree() const {
    if (coefficients.empty()) return 0;
    
    // Идем справа налево до первого ненулевого коэффициента
    for (size_t i = coefficients.size() - 1; i > 0; --i) {
        if (std::abs(coefficients[i]) > 1e-10) {
            return i;  // Нашли наибольшую степень
        }
    }
    // Проверяем свободный член
    return (std::abs(coefficients[0]) > 1e-10) ? coefficients[0] : 0;
}

/**
 * Оператор вывода многочлена в поток
 * Форматирует вывод в виде: 3.5x^4 + 2x^2 - 1.2x + 7
 * @param os выходной поток
 * @param poly выводимый многочлен
 * @return ссылка на выходной поток
 */
std::ostream& operator <<(std::ostream& os, const Polynom& poly) {
    bool firstTerm = true;  // флаг для первого члена (чтобы не ставить + перед ним)
    
    // Проходим по всем коэффициентам от старшей степени к младшей
    for (int i = static_cast<int>(poly.coefficients.size()) - 1; i >= 0; --i) {
        double coeff = poly.coefficients[i];
        
        // Пропускаем нулевые коэффициенты
        if (std::abs(coeff) < 1e-10) continue;
        
        // Вывод знака
        if (firstTerm) {
            // Первый член: если отрицательный, выводим минус
            if (coeff < 0) {
                os << "-";
            }
            firstTerm = false;
        } else {
            // Остальные члены: выводим знак
            os << (coeff > 0 ? " + " : " - ");
        }
        
        // Вывод коэффициента (кроме случая, когда это 1 или -1 и степень > 0)
        double absCoeff = std::abs(coeff);
        if (std::abs(absCoeff - 1.0) > 1e-10 || i == 0) {
            os << absCoeff;
        }
        
        // Вывод переменной и степени
        if (i > 0) {
            os << "x";
            if (i > 1) {
                os << "^" << i;
            }
        }
    }
    
    // Если многочлен нулевой, выводим просто 0
    if (firstTerm) {
        os << "0";
    }
    
    return os;
}

/**
 * Оператор ввода многочлена из потока
 * Ожидает формат: коэффициент1 коэффициент2 ... (пробелы разделители)
 * @param is входной поток
 * @param poly многочлен для заполнения
 * @return ссылка на входной поток
 */
std::istream& operator >>(std::istream& is, Polynom& poly) {
    std::vector<double> coeffs;
    double coeff;
    
    // Читаем коэффициенты до конца строки или потока
    while (is >> coeff) {
        coeffs.push_back(coeff);
    }
    
    // Очищаем флаги ошибок потока
    is.clear();
    
    // Создаем новый многочлен из прочитанных коэффициентов
    if (!coeffs.empty()) {
        poly = Polynom(coeffs);
    }
    
    return is;
}
