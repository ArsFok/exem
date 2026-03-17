#include "point3D.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    cout << fixed << setprecision(3);
    
    // Простой тест
    cout << "=== ПРОСТОЙ ТЕСТ ===" << endl;
    point3d test_point(3.0f, 4.0f, 5.0f);
    cout << "До преобразования: (" << test_point.getX() << ", " << test_point.getY() << ", " << test_point.getZ() << ")" << endl;
    
    getRoPhi(test_point);
    
    cout << "После преобразования: (" << test_point.getX() << ", " << test_point.getY() << ", " << test_point.getZ() << ")" << endl;
    
    // Проверка
    float r = sqrt(3.0f*3.0f + 4.0f*4.0f); // должно быть 5.0
    float fi = atan2(4, 3);
    cout << "Ожидаемый r: " << r << endl;
    cout << "Ожидаемый fi: " << fi << endl;
    cout << r * cos(fi) << " " << r * sin(fi) << " " << 5 << endl;
    
    return 0;
}