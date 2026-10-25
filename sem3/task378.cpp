#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Задача 7
    double v0 = 50.0;
    double g = 9.8;
    double dt = 1.0;

    vector<double> times;
    vector<double> heights;

    for (double t = 0; t <= 100; t += dt)
    {
        double h = v0 * t - 0.5 * g * t * t;
        times.push_back(t);
        heights.push_back(h);
    }

    auto it = find_if(heights.begin(), heights.end(), [](double h) {
        return h <= 0.0;
    });

    if (it != heights.end())
    {
        int idx = distance(heights.begin(), it);
        cout << "Момент падения: t = " << times[idx] << ", h = " << heights[idx] << "\n";
    }
    else
    {
        cout << "Падения не было\n";
    }

    // Задача 8
    int n1, n2;
    cout << "Введите количество точек для ракеты 1: ";
    cin >> n1;
    vector<double> h1(n1);
    cout << "Введите высоты ракеты 1:\n";
    for (int i = 0; i < n1; i++) cin >> h1[i];

    cout << "Введите количество точек для ракеты 2: ";
    cin >> n2;
    vector<double> h2(n2);
    cout << "Введите высоты ракеты 2:\n";
    for (int i = 0; i < n2; i++) cin >> h2[i];

    auto max1 = max_element(h1.begin(), h1.end());
    auto max2 = max_element(h2.begin(), h2.end());

    cout << "Макс высота ракеты 1: " << *max1 << "\n";
    cout << "Макс высота ракеты 2: " << *max2 << "\n";

    if (*max1 > *max2) cout << "Ракета 1 выше\n";
    else if (*max2 > *max1) cout << "Ракета 2 выше\n";
    else cout << "Одинаково\n";

    // Исправлено: сохраняем первые элементы в переменные
    double h1_start = h1[0];
    double h2_start = h2[0];

    auto fall1 = find_if(h1.begin(), h1.end(), [h1_start](double h) {
        return h <= 0 && h != h1_start;
    });
    auto fall2 = find_if(h2.begin(), h2.end(), [h2_start](double h) {
        return h <= 0 && h != h2_start;
    });

    if (fall1 != h1.end()) cout << "Ракета 1 упала на шаге " << distance(h1.begin(), fall1) << "\n";
    else cout << "Ракета 1 не упала\n";

    if (fall2 != h2.end()) cout << "Ракета 2 упала на шаге " << distance(h2.begin(), fall2) << "\n";
    else cout << "Ракета 2 не упала\n";

    return 0;
}
