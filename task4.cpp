#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double h, ay, t;
    cout <<"Введите высоту h = ";
    cin >> h;
    if (h < 0)
    {
        cout <<"Вы ввели отрицательную высоту. Ведите заново (h >= 0) h = ";
        cin >> h;
    }
    cout <<"Введите ускорение ay = ";
    cin >> ay;
    if (ay < 0)
    {
        cout <<"Вы ввели отрицательное ускорение. Ведите заново (ay >= 0) ay = ";
        cin >> ay;
    }
    t = sqrt(2 * h / ay);
    cout <<"Время для набора высоты t = " << t << endl;
    return 0;
}
