#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    double v0 = 50.0;
    double g = 9.8;
    double dt = 1.0;

    if (v0 <= 0)
    {
        cout << "Начальная скорость должна быть больше 0\n";
        return 1;
    }

    vector<double> times;
    vector<double> heights;

    // Запас по размеру, чтобы вектор не перераспределялся лишний раз
    times.reserve(20);
    heights.reserve(20);

    for (double t = 0.0; t <= 1000; t += dt)
    {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0)
            break;

        times.push_back(t);
        heights.push_back(h);
    }

    // Вывод таблицы (Задача 1)
    cout << "Таблица время - высота:\n";
    cout << left << setw(10) << "t (c)" << setw(10) << "h (m)" << "\n";
    for (size_t i = 0; i < times.size(); i++)
    {
        cout << left << setw(10) << times[i] << setw(10) << heights[i] << "\n";
    }

    // Поиск максимума (Задача 2)
    if (heights.empty())
    {
        cout << "Данных нет\n";
        return 0;
    }

    size_t idx_max = 0;
    for (size_t i = 1; i < heights.size(); i++)
    {
        if (heights[i] > heights[idx_max])
            idx_max = i;
    }

    cout << "\nМаксимальная высота: " << heights[idx_max] << " м\n";
    cout << "Время достижения: " << times[idx_max] << " с\n";

    return 0;
}
