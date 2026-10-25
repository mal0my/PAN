#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    double x, y, z;
};

int main()
{
    double vx = 30, vy = 20, vz = 40;
    double dt, t_max;

    cout << "Введите шаг dt: ";
    cin >> dt;
    cout << "Введите максимальное время t_max: ";
    cin >> t_max;

    double x = 0, y = 0, z = 0;
    vector<Point> traj;
    vector<double> times;

    for (double t = 0; t <= t_max; t += dt)
    {
        traj.push_back({x, y, z});
        times.push_back(t);
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
    }

    cout << "Таблица траектории (t x y z):\n";
    for (int i = 0; i < times.size(); i++)
    {
        cout << times[i] << " " << traj[i].x << " " << traj[i].y << " " << traj[i].z << "\n";
    }

    return 0;
}



