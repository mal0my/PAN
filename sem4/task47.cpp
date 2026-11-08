#include <iostream>
#include <iomanip>

using namespace std;

class FlightComputer
{
private:
    double altitude;
    double velocity;
    double fuel;
    double thrust;

public:
    FlightComputer(double alt, double vel, double f, double T)
    {
        altitude = alt;
        velocity = vel;
        fuel = f;
        thrust = T;
    }

    void simulateStep(double dt)
    {
        velocity += (thrust / 1000 - 9.8) * dt;
        altitude += velocity * dt;
        fuel -= dt * 2;
    }

    void printStatus(double time)
    {
        cout << fixed << setprecision(1);
        cout << "t=" << time << "с: высота=" << altitude << "м, скорость=" << velocity << "м/с, топливо=" << fuel << "\n";
    }
};

int main()
{
    double altitude, velocity, fuel, thrust;
    cout << "Введите начальную высоту (м): ";
    cin >> altitude;
    cout << "Введите начальную скорость (м/с): ";
    cin >> velocity;
    cout << "Введите количество топлива (кг): ";
    cin >> fuel;
    cout << "Введите тягу (Н): ";
    cin >> thrust;

    int steps;
    cout << "Введите количество шагов симуляции: ";
    cin >> steps;

    double dt;
    cout << "Введите шаг времени (с): ";
    cin >> dt;

    FlightComputer fc(altitude, velocity, fuel, thrust);

    for (int i = 0; i < steps; i++)
    {
        double time = (i + 1) * dt;
        fc.simulateStep(dt);
        fc.printStatus(time);
    }

    return 0;
}
