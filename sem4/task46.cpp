#include <iostream>
#include <iomanip>

using namespace std;

class RocketStage
{
private:
    double thrust;
    double burnTime;
    double mass;

public:
    RocketStage(double T, double t, double m)
    {
        thrust = T;
        burnTime = t;
        mass = m;
    }

    double getDeltaV()
    {
        return (thrust * burnTime) / mass;
    }

    void printInfo(int num)
    {
        cout << "Ступень " << num << ": тяга=" << thrust << " Н, время=" << burnTime << " с, масса=" << mass << " кг, deltaV=" << getDeltaV() << " м/с\n";
    }
};

int main()
{
    double thrust, burnTime, mass;
    RocketStage* stages[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "\nСтупень " << (i + 1) << ":\n";
        cout << "Введите тягу (Н): ";
        cin >> thrust;
        cout << "Введите время работы (с): ";
        cin >> burnTime;
        cout << "Введите массу (кг): ";
        cin >> mass;

        stages[i] = new RocketStage(thrust, burnTime, mass);
        stages[i]->printInfo(i + 1);
    }

    double totalV = stages[0]->getDeltaV() + stages[1]->getDeltaV() + stages[2]->getDeltaV();

    cout << fixed << setprecision(2);
    cout << "\nИтоговая скорость ракеты: " << totalV << " м/с\n";

    for (int i = 0; i < 3; i++)
        delete stages[i];

    return 0;
}
