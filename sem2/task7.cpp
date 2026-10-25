#include <iostream>

using namespace std;

int main()
{
    double L, m;
    double g = 9.81;
    cout << "Введите подъемную силу L = ";
    cin >> L;
    cout << "Введите массу m = ";
    cin >> m;
    double ay = (L - m * g) / m;
    if (ay > 0.5)
        cout << "Режим наборы высоты";
    else if (ay < 0)
        cout << "Режим снижения";
    else
        cout << "Режим горизонтального полета";
    return 0;
}
