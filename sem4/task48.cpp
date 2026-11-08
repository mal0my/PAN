#include <iostream>

using namespace std;

class NavigationSystem
{
private:
    double x, y;
    double velocityX, velocityY;
    bool gpsAvailable;

public:
    NavigationSystem(double _x, double _y, double vx, double vy, bool gps)
    {
        x = _x;
        y = _y;
        velocityX = vx;
        velocityY = vy;
        gpsAvailable = gps;
    }

    void integratePosition(double dt)
    {
        x += velocityX * dt;
        y += velocityY * dt;
    }

    void correctGPS(double realX, double realY)
    {
        if (gpsAvailable)
        {
            x = (x + realX) / 2;
            y = (y + realY) / 2;
        }
    }

    void printPosition()
    {
        cout << "Скорректированные координаты: (" << x << ", " << y << ")\n";
    }
};

int main()
{
    double x, y, vx, vy;
    int gps;

    cout << "Введите начальную координату X: ";
    cin >> x;
    cout << "Введите начальную координату Y: ";
    cin >> y;
    cout << "Введите скорость по X (м/с): ";
    cin >> vx;
    cout << "Введите скорость по Y (м/с): ";
    cin >> vy;
    cout << "Доступен ли GPS (1 - да, 0 - нет): ";
    cin >> gps;

    NavigationSystem nav(x, y, vx, vy, gps == 1);

    double dt;
    cout << "Введите шаг времени (с): ";
    cin >> dt;

    nav.integratePosition(dt);

    double realX, realY;
    cout << "Введите реальные координаты GPS X: ";
    cin >> realX;
    cout << "Введите реальные координаты GPS Y: ";
    cin >> realY;

    nav.correctGPS(realX, realY);
    nav.printPosition();

    return 0;
}
