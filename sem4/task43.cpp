#include <iostream>
#include <iomanip>

using namespace std;

class Engine
{
private:
    double thrust;
    double fuelFlow;

public:
    Engine(double T, double F)
    {
        thrust = T;
        fuelFlow = F;
    }

    double getSpecificImpulse()
    {
        return thrust / (fuelFlow * 9.81);
    }

    void printInfo()
    {
        cout << fixed << setprecision(2);
        cout << "Тяга: " << thrust << " Н | Расход: " << fuelFlow << " кг/с | Удельный импульс: " << getSpecificImpulse() << " с\n";
    }
};

int main()
{
    double thrust, fuelFlow;
    cout << "Введите тягу двигателя (Н): ";
    cin >> thrust;
    cout << "Введите расход топлива (кг/с): ";
    cin >> fuelFlow;

    Engine e1(thrust, fuelFlow);
    e1.printInfo();

    return 0;
}
