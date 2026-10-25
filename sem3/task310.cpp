#include <iostream>
#include <vector>

using namespace std;

struct Point { double x, y, z; };

class Rocket
{
    double x, y, z, vx, vy, vz, g;
public:
    Rocket(double _vx, double _vy, double _vz, double _h)
    {
        x = 0; y = 0; z = _h;
        vx = _vx; vy = _vy; vz = _vz;
        g = 9.8;
    }
    void update(double dt)
    {
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
        vz -= g * dt;
    }
    Point getPos() { return {x, y, z}; }
};

int main()
{
    double dt, T;
    cout << "Введите шаг dt: ";
    cin >> dt;
    cout << "Введите общее время T: ";
    cin >> T;

    vector<Rocket> squad;
    squad.emplace_back(1000, 10, 0, 50);
    squad.emplace_back(900, 15, -5, 40);
    squad.emplace_back(800, 8, 3, 55);
    squad.emplace_back(1100, 12, 2, 45);
    squad.emplace_back(950, 20, 0, 60);

    for (double t = 0; t <= T; t += dt)
    {
        for (int i = 0; i < 5; i++)
            squad[i].update(dt);
    }

    cout << "Конечные положения:\n";
    for (int i = 0; i < 5; i++)
    {
        Point p = squad[i].getPos();
        cout << "Ракета " << i + 1 << ": x=" << p.x << " y=" << p.y << " z=" << p.z << "\n";
    }

    return 0;
}
