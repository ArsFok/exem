#include <iostream>
#include "fracture.h"

using namespace std;

int main() {
    try {
        // Тест конструкторов
        cout << "=== Тест конструкторов ===" << endl;
        fracture f1; // конструктор по умолчанию
        fracture f2(3); // конструктор с одним параметром
        fracture f3(2, 5); // конструктор с двумя параметрами
        fracture f4(4, 8); // дробь, которая должна упроститься
        
        cout << "f1 (по умолчанию): " << f1 << endl;
        cout << "f2(3): " << f2 << endl;
        cout << "f3(2, 5): " << f3 << endl;
        cout << "f4(4, 8): " << f4 << endl;

        // Тест отрицательных дробей
        cout << "\n=== Тест отрицательных дробей ===" << endl;
        fracture f5(-3, 4);
        fracture f6(3, -4);
        fracture f7(-6, -8);
        
        cout << "f5(-3, 4): " << f5 << endl;
        cout << "f6(3, -4): " << f6 << endl;
        cout << "f7(-6, -8): " << f7 << endl;

        // Тест арифметических операций
        cout << "\n=== Тест арифметических операций ===" << endl;
        fracture a(1, 2);
        fracture b(1, 3);
        
        cout << a << " + " << b << " = " << (a + b) << endl;
        cout << a << " - " << b << " = " << (a - b) << endl;
        cout << a << " * " << b << " = " << (a * b) << endl;
        cout << a << " / " << b << " = " << (a / b) << endl;

        // Тест составных операторов
        cout << "\n=== Тест составных операторов ===" << endl;
        fracture c(1, 4);
        fracture d(1, 2);
        
        cout << "c = " << c << ", d = " << d << endl;
        c += d;
        cout << "После c += d: c = " << c << endl;
        
        c -= fracture(1, 8);
        cout << "После c -= 1/8: c = " << c << endl;
        
        c *= fracture(2, 1);
        cout << "После c *= 2: c = " << c << endl;
        
        c /= fracture(3, 1);
        cout << "После c /= 3: c = " << c << endl;

        // Тест методов доступа
        cout << "\n=== Тест методов доступа ===" << endl;
        fracture f(3, 5);
        cout << "f: " << f << endl;
        cout << "Числитель: " << f._num() << ", Знаменатель: " << f._del() << endl;
        
        f.set_num(6);
        cout << "После set_num(6): " << f << endl;
        
        f.set_del(10);
        cout << "После set_del(10): " << f << endl;

        // Тест исключений
        cout << "\n=== Тест исключений ===" << endl;
        try {
            fracture bad(1, 0);
        } catch (const invalid_argument& e) {
            cout << "Поймано исключение: " << e.what() << endl;
        }
        
        try {
            fracture zero_div(1, 2);
            fracture zero(0, 1);
            fracture result = zero_div / zero;
        } catch (const invalid_argument& e) {
            cout << "Поймано исключение при делении: " << e.what() << endl;
        }

        // Дополнительные тесты
        cout << "\n=== Дополнительные тесты ===" << endl;
        fracture x(15, 25);
        fracture y(6, 18);
        
        cout << "x = " << x << ", y = " << y << endl;
        cout << "x + y = " << (x + y) << endl;
        cout << "x - y = " << (x - y) << endl;
        cout << "x * y = " << (x * y) << endl;
        cout << "x / y = " << (x / y) << endl;

    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}