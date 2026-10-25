#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct Aircraft
{
    int id;
    double m, T, Cl, Cd, ay, t, S;
};

int main()
{
    const double g = 9.81;
    double p, V, h;
    int n;

    cout << "Введите плотность воздуха p = ";
    cin >> p;
    cout << "Введите скорость V = ";
    cin >> V;
    cout << "Введите высоту полета h = ";
    cin >> h;
    cout << "Введите кол-во самолетов n = ";
    cin >> n;
    int count = 1;

    vector<Aircraft> smlt(n);
    for (int i = 0; i < n; i++)
    {
        smlt[i].id = count++;
        cout << "Самолет №" << smlt[i].id << endl;

        cout << "Введите маcсу самолета m = ";
        cin >> smlt[i].m;

        cout << "Введите тягу самолета T = ";
        cin >> smlt[i].T;

        cout << "Введите коэффициент подъемной силы самолета Cl = ";
        cin >> smlt[i].Cl;

        cout << "Введите коэффициент сопротивления самолета Cd = ";
        cin >> smlt[i].Cd;

        cout << "Введите площадь крыла самолета S = ";
        cin >> smlt[i].S;

        double L = 0.5 * p * V * V * smlt[i].S * smlt[i].Cl;

        smlt[i].ay = (L - smlt[i].m * g) / smlt[i].m;

        if (smlt[i].ay > 0)
            smlt[i].t = sqrt(2 * h / smlt[i].ay);
        else
        {
            smlt[i].t = -5;
            cout << "Данный самолет не наберет нужную высоту\n";
        }
    }
    for (int k = 0; k < n - 1; k++)
    {
        for (int j = 0; j < n - k - 1; j++)
        {
            bool needSwap = false;
            if (smlt[j].t >= 0 && smlt[j+1].t >= 0)
            {
                needSwap = smlt[j].t > smlt[j+1].t;
            }
            else if (smlt[j].t < 0 && smlt[j+1].t >= 0)
            {
                needSwap = true;
            }
            if (needSwap)
            {
                std::swap(smlt[j], smlt[j+1]);
            }
        }
    }

    for (int y = 0; y < n; y++)
    {
        if (smlt[y].t >= 0)
        {
            cout << "Самолет №" << smlt[y].id++ << " | Ускорение: " << smlt[y].ay;
            cout << " | Время t: " << smlt[y].t << " секунд\n";
        }
        else
        {
            cout << "Самолет №" << smlt[y].id++ << " | Ускорение: " << smlt[y].ay;
            cout << " | Самолет не наберет высоту\n";
        }
    }
    return 0;
}
