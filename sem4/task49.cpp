#include <iostream>

using namespace std;

class AutonomousControl
{
private:
    double altitude;
    double thrust;
    double targetAltitude;

public:
    AutonomousControl(double alt, double T, double target)
    {
        altitude = alt;
        thrust = T;
        targetAltitude = target;
    }

    void updateControl()
    {
        if (altitude < targetAltitude)
            thrust += 100;
        else
            thrust -= 100;
    }

    void simulateStep(double dt)
    {
        altitude += (thrust / 500) * dt;
    }

    void printStatus()
    {
        cout << "Высота: " << altitude << "м, тяга: " << thrust << "\n";
    }
};

int main()
{
    double altitude, thrust, targetAltitude;
    cout << "Введите начальную высоту (м): ";
    cin >> altitude;
    cout << "Введите начальную тягу (Н): ";
    cin >> thrust;
    cout << "Введите целевую высоту (м): ";
    cin >> targetAltitude;

    int steps;
    cout << "Введите количество шагов симуляции: ";
    cin >> steps;

    AutonomousControl ac(altitude, thrust, targetAltitude);

    for (int i = 0; i < steps; ++i)
    {
        ac.updateControl();
        ac.simulateStep(1.0);
        ac.printStatus();
    }

    return 0;
}
