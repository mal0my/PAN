#include <iostream>

using namespace std;
#include <cmath>

int main()
{
    double S, V, p, Cl, L;
    cout <<"Введите площадь крыла самолета S = ";
    cin >> S;
    cout <<"Введите скорость полета самолета V = ";
    cin >> V;
    cout <<"Введите плотность воздуха p = ";
    cin >> p;
    cout <<"Введите коэффициент подъемной силы Cl = ";
    cin >> Cl;

    L = 0.5 * p * std::pow(V, 2) * S * Cl;

    cout <<"Подъемная сила L = " <<L<< endl;
    return 0;
}
