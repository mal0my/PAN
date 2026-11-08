#include <iostream>

using namespace std;

class Sensor
{
private:
    double signalStrength;
    bool isActive;

public:
    Sensor(double strength)
    {
        signalStrength = strength;
        isActive = true;
    }

    void activate()
    {
        isActive = true;
    }

    void deactivate()
    {
        isActive = false;
    }

    void setSignalStrength(double s)
    {
        if (s < 0)
            signalStrength = 0;
        else
            signalStrength = s;
    }

    double getSignalStrength()
    {
        return signalStrength;
    }

    void printStatus()
    {
        if (isActive)
            cout << "Датчик активен | Сила сигнала: " << signalStrength << " дБ\n";
        else
            cout << "Датчик выключен | Сила сигнала: " << signalStrength << " дБ\n";
    }
};

int main()
{
    double strength;
    cout << "Введите силу сигнала (дБ): ";
    cin >> strength;

    Sensor s1(strength);
    s1.printStatus();

    cout << "Введите новую силу сигнала: ";
    cin >> strength;
    s1.setSignalStrength(strength);
    s1.printStatus();

    s1.deactivate();
    s1.printStatus();

    return 0;
}
