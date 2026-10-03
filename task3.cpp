#include <iostream>

using namespace std;

int main()
{
    double m, L, D, T, a, ay, g;
    cout <<"Введите массу самолета m = ";
    cin >> m;
    cout <<"Введите подъемную силу самолета L = ";
    cin >> L;
    cout <<"Введите сопротивление D = ";
    cin >> D;
    cout <<"Введите тягу двигателя T = ";
    cin >> T;
    g = 9.81;
    a = (T - D) / m;
    ay = (L - m * g) / m;
    cout <<"Ускорение по направлению движения a = " <<a<< endl;
    cout <<"Вертикальное ускорение ay = " <<ay<< endl;
    return 0;
}
