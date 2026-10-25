#include <iostream>
#include <cmath>
using namespace std;

double sopr(double S, double V, double p, double Cd)
{
    double L = 0.5 * p * S * Cd* std::pow(V, 2);
    cout <<"Аэродинамическое сопротивление L = " <<L<< endl;
    return 0;
}

int main()
{
    double S, V, p, Cd, L;
    cout <<"Введите площадь крыла самолета S = ";
    cin >> S;
    cout <<"Введите скорость полета самолета V = ";
    cin >> V;
    cout <<"Введите плотность воздуха p = ";
    cin >> p;
    cout <<"Введите коэффициент сопротивления Cd = ";
    cin >> Cd;
    sopr(S, V, p, Cd);
    return 0;
}
