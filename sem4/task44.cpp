#include <iostream>

using namespace std;

class Gyroscope
{
private:
    double angularVelocity;
    bool calibrationRequired;

public:
    Gyroscope(double vel, bool calib)
    {
        angularVelocity = vel;
        calibrationRequired = calib;
    }

    void calibrate()
    {
        calibrationRequired = false;
    }

    void printStatus()
    {
        cout << "Скорость: " << angularVelocity << " °/с | ";
        if (calibrationRequired)
            cout << "Калибровка требуется\n";
        else
            cout << "Калибровка не требуется\n";
    }
};

int main()
{
    double velocity;
    int calib;

    cout << "Введите скорость вращения (°/с): ";
    cin >> velocity;
    cout << "Требуется ли калибровка (1 - да, 0 - нет): ";
    cin >> calib;

    Gyroscope g1(velocity, calib == 1);
    g1.printStatus();

    g1.calibrate();
    g1.printStatus();

    return 0;
}
