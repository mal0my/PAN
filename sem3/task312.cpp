#include <iostream>
#include <vector>

using namespace std;

int main()
{
    double v0 = 50.0;
    double g = 9.8;
    double dt = 1.0;

    vector<double> times;
    vector<double> heights;

    for (double t = 0; t <= 1000; t += dt)
    {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0) break;
        times.push_back(t);
        heights.push_back(h);
    }

    cout << "Таблица время - высота:\n";
    for (int i = 0; i < times.size(); i++)
    {
        cout << times[i] << " " << heights[i] << "\n";
    }

    if (heights.empty())
    {
        cout << "Данных нет\n";
        return 0;
    }

    int idx_max = 0;
    for (int i = 1; i < heights.size(); i++)
    {
        if (heights[i] > heights[idx_max])
            idx_max = i;
    }

    cout << "Максимальная высота: " << heights[idx_max] << "\n";
    cout << "Время: " << times[idx_max] << "\n";

    return 0;
}
