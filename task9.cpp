#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Aircraft
{
    int id;
    double m, T, Cl, Cd, ay, a, S, L, LSopr, D;
};


void printTable(const vector<Aircraft>& smlt, const string& title)
{
    cout << "\n" << string(120, '=') << "\n";
    cout << "  " << title << "\n";
    cout << string(120, '=') << "\n";
    cout << left
         << setw(5)  << "№"
         << setw(10) << "m"
         << setw(10) << "T"
         << setw(10) << "D"
         << setw(10) << "Cl"
         << setw(10) << "Cd"
         << setw(10) << "S"
         << setw(12) << "L"
         << setw(12) << "LSopr"
         << setw(12) << "ay"
         << setw(12) << "a"
         << "\n";
    cout << string(120, '-') << "\n";
    cout << fixed << setprecision(3);
    for (const auto& s : smlt)
    {
        cout << left
             << setw(5)  << s.id
             << setw(10) << s.m
             << setw(10) << s.T
             << setw(10) << s.D
             << setw(10) << s.Cl
             << setw(10) << s.Cd
             << setw(10) << s.S
             << setw(12) << s.L
             << setw(12) << s.LSopr
             << setw(12) << s.ay
             << setw(12) << s.a
             << "\n";
    }
    cout << string(120, '=') << "\n";
}

int main()
{
    const double g = 9.81;
    double p, V;
    int n;

    cout << "Введите плотность воздуха p = ";
    cin >> p;
    cout << "Введите скорость V = ";
    cin >> V;
    cout << "Введите кол-во самолетов n = ";
    cin >> n;
    int count = 1;

    vector<Aircraft> smlt(n);
    for (int i = 0; i < n; i++)
    {
        smlt[i].id = count++;
        cout << "\nСамолет №" << smlt[i].id << endl;

        cout << "Введите маcсу самолета m = ";
        cin >> smlt[i].m;

        cout << "Введите сопротивление самолета D = ";
        cin >> smlt[i].D;

        cout << "Введите тягу самолета T = ";
        cin >> smlt[i].T;

        cout << "Введите коэффициент подъемной силы самолета Cl = ";
        cin >> smlt[i].Cl;

        cout << "Введите коэффициент сопротивления самолета Cd = ";
        cin >> smlt[i].Cd;

        cout << "Введите площадь крыла самолета S = ";
        cin >> smlt[i].S;

        smlt[i].L = 0.5 * p * V * V * smlt[i].S * smlt[i].Cl;
        smlt[i].ay = (smlt[i].L - smlt[i].m * g) / smlt[i].m;
        smlt[i].LSopr = 0.5 * p * V * V * smlt[i].S * smlt[i].Cd;
        smlt[i].a = (smlt[i].T - smlt[i].D) / smlt[i].m;
    }

    vector<Aircraft> sortedByA = smlt;
    std::sort(sortedByA.begin(), sortedByA.end(),
              [](const Aircraft& x, const Aircraft& y)
              {
                  return x.a > y.a;
              });

    printTable(sortedByA, "СОРТИРОВКА ПО УБЫВАНИЮ ГОРИЗОНТАЛЬНОГО УСКОРЕНИЯ (a)");

    vector<Aircraft> sortedByAy = smlt;
    std::sort(sortedByAy.begin(), sortedByAy.end(),
              [](const Aircraft& x, const Aircraft& y) {
                  return x.ay > y.ay;
              });

    printTable(sortedByAy, "СОРТИРОВКА ПО УБЫВАНИЮ ВЕРТИКАЛЬНОГО УСКОРЕНИЯ (ay)");

    return 0;
}