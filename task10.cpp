#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    const double g = 9.81;
    double h, S, p, Cl, V, m, D;
    double T_min, T_max, delta_T;

    cout << "Введите высоту h = ";
    cin >> h;
    cout << "Введите площадь крыла S = ";
    cin >> S;
    cout << "Введите плотность воздуха p = ";
    cin >> p;
    cout << "Введите коэффициент подъемной силы Cl = ";
    cin >> Cl;
    cout << "Введите скорость полета V = ";
    cin >> V;
    cout << "Введите массу самолета m = ";
    cin >> m;
    cout << "Введите сопротивление D = ";
    cin >> D;

    cout << "\nВведите минимальную тягу T_min = ";
    cin >> T_min;
    cout << "Введите максимальную тягу T_max = ";
    cin >> T_max;
    cout << "Введите шаг тяги delta_T = ";
    cin >> delta_T;

    double L = 0.5 * p * V * V * S * Cl;

    cout << "\nПодъемная сила L = " << L << " Н\n";
    cout << "Вес самолета mg = " << m * g << " Н\n\n";

    double min_time = 1e18;
    double optimal_T_for_time = 0;
    double max_a = -1e18;
    double optimal_T_for_a = 0;
    double max_ay = -1e18;
    double optimal_T_for_ay = 0;

    cout << string(80, '=') << "\n";
    cout << "  Таблица значений тяги, ускорений и времени\n";
    cout << string(80, '=') << "\n";
    cout << left
         << setw(10) << "T (Н)"
         << setw(12) << "a (м/с²)"
         << setw(12) << "ay (м/с²)"
         << setw(12) << "t (с)"
         << setw(20) << "Статус"
         << "\n";
    cout << string(80, '-') << "\n";

    cout << fixed << setprecision(3);

    for (double T = T_min; T <= T_max; T += delta_T)
    {
        double a = (T - D) / m;

        double ay = (L - m * g) / m;

        double t;
        string status;

        if (ay > 0)
        {
            t = sqrt(2 * h / ay);
            status = "Может набрать высоту";

            if (t < min_time)
            {
                min_time = t;
                optimal_T_for_time = T;
            }

            if (ay > max_ay)
            {
                max_ay = ay;
                optimal_T_for_ay = T;
            }
        }
        else
        {
            t = -1;
            status = "Не может набрать высоту";
        }

        if (a > max_a)
        {
            max_a = a;
            optimal_T_for_a = T;
        }

        cout << left
             << setw(10) << T
             << setw(12) << a
             << setw(12) << ay
             << setw(12) << (t >= 0 ? t : 0)
             << setw(20) << status
             << "\n";
    }

    cout << string(80, '=') << "\n";

    cout << "\n" << string(80, '=') << "\n";
    cout << "  РЕЗУЛЬТАТ 1: Лучшее горизонтальное ускорение a\n";
    cout << string(80, '=') << "\n";
    cout << "Максимальное ускорение a = " << max_a << " м/с²\n";
    cout << "Достигается при тяге T = " << optimal_T_for_a << " Н\n";
    cout << string(80, '=') << "\n";

    cout << "\n" << string(80, '=') << "\n";
    cout << "  РЕЗУЛЬТАТ 2: Лучшее вертикальное ускорение ay и минимальное время t\n";
    cout << string(80, '=') << "\n";
    if (max_ay > 0)
    {
        cout << "Максимальное вертикальное ускорение ay = " << max_ay << " м/с²\n";
        cout << "Достигается при тяге T = " << optimal_T_for_ay << " Н\n";
        cout << "----------------------------------------\n";
        cout << "Минимальное время набора высоты t = " << min_time << " с\n";
        cout << "Достигается при тяге T = " << optimal_T_for_time << " Н\n";
        cout << "----------------------------------------\n";
        cout << "Высота набора: h = " << h << " м\n";
    }
    else
    {
        cout << "Самолет не может набрать высоту " << h << " м\n";
        cout << "Подъемная сила L = " << L << " Н меньше веса mg = " << m * g << " Н\n";
        cout << "Вертикальное ускорение ay <= 0\n";
    }
    cout << string(80, '=') << "\n";

    return 0;
}
