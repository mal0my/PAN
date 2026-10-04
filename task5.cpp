#include <iostream>

using namespace std;
double vvod(double arr[5])
{
    cout <<"Введите параметры самолета в порядке (m, S, T, Cl, V): ";
    for (int i = 0; i < 5; i ++)
    {
        cin >> arr[i];
    }
    if (arr[0] < 0)
    {
        while (arr[0] < 0)
        {
            cout <<"Введите массу (m >= 0): ";
            cin >> arr[0];
        }
    }
    if (arr[1] < 0)
    {
        while (arr[1] < 0)
        {
            cout <<"Введите площадь (S >= 0): ";
            cin >> arr[1];
        }
    }
    if (arr[4] < 0)
    {
        while (arr[4] < 0)
        {
            cout <<"Введите скорость (V >= 0): ";
            cin >> arr[4];
        }
    }
    return 0;
}
double sravnenieANDvivod(double T1, double T2, double T3)
{
    double min_time = 99999;
    int bestSam = 0;
    if (T1 < min_time)
    {
        min_time = T1;
        bestSam = 1;
    }
    else if (T2 < min_time)
    {
        min_time = T2;
        bestSam = 2;
    }
    else if (T3 < min_time)
    {
        min_time = T3;
        bestSam = 3;
    }
    if (min_time != 99999)
    {
        cout <<"Быстрее всех взлетит самолет №" << bestSam << endl;
    }
    else
    {
        cout <<"Ни один самолет не взлетит!";
    }
    return 0;
}

int main()
{
    double param1[5];
    double param2[5];
    double param3[5];
    double p, L1, L2, L3, ay1, ay2, ay3, g, t1, t2, t3, h;
    g = 9.81;
    cout <<"Введите плотность воздуха p = ";
    cin >> p;
    if (p < 0)
    {
        while (p < 0)
        {
            cout <<"Введите плотность воздуха (p >= 0): ";
            cin >> p;
        }
    }
    vvod(param1);
    vvod(param2);
    vvod(param3);
    L1 = 0.5 * p * param1[4] * param1[4] * param1[1] * param1[3];
    L2 = 0.5 * p * param2[4] * param2[4] * param2[1] * param2[3];
    L3 = 0.5 * p * param3[4] * param3[4] * param3[1] * param3[3];
    ay1 = (L1 - param1[0] * g) / param1[0];
    ay2 = (L2 - param2[0] * g) / param2[0];
    ay3 = (L3 - param3[0] * g) / param3[0];
    cout <<"Введите высоту полета h = ";
    cin >> h;
    if (h < 0)
    {
        while (h < 0)
        {
            cout <<"Введите высоту полета (h >= 0): ";
            cin >> h;
        }
    }
    t1 = sqrt(2 * h / ay1);
    t2 = sqrt(2 * h / ay2);
    t3 = sqrt(2 * h / ay3);
    sravnenieANDvivod(t1, t2, t3);
    return 0;
}
