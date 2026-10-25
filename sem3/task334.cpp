#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    double v0 = 50.0;
    double g = 9.8;
    double dt = 1.0;
    double t_max;

    cout << "Введите максимальное время t_max: ";
    cin >> t_max;

    vector<double> times;
    vector<double> velocities;

    for (double t = 0; t <= t_max; t += dt)
    {
        double v = v0 - g * t;
        times.push_back(t);
        velocities.push_back(v);
    }

    cout << "Таблица время - скорость:\n";
    for (int i = 0; i < times.size(); i++)
    {
        cout << times[i] << " " << velocities[i] << "\n";
    }

    if (velocities.empty())
    {
        cout << "Данных нет\n";
        return 0;
    }

    double sum = accumulate(velocities.begin(), velocities.end(), 0.0);
    double avg = sum / velocities.size();

    cout << "Средняя скорость: " << avg << "\n";

    return 0;
}
