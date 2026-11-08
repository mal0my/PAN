#include <iostream>
#include <iomanip>

using namespace std;

class Engine
{
private:
    double thrust;
    double fuelFlow;
    double fuel;

public:
    Engine(double T, double F, double f)
    {
        thrust = T;
        fuelFlow = F;
        fuel = f;
    }

    double getThrust()
    {
        return thrust;
    }

    bool hasFuel()
    {
        return fuel > 0;
    }

    void burn(double dt)
    {
        if (fuel > 0)
        {
            fuel -= fuelFlow * dt;
            if (fuel < 0)
                fuel = 0;
        }
    }

    double getFuel()
    {
        return fuel;
    }
};

class Navigation
{
private:
    double altitude;
    double velocity;
    double acceleration;
    double mass;

public:
    Navigation(double alt, double vel, double m)
    {
        altitude = alt;
        velocity = vel;
        mass = m;
        acceleration = 0;
    }

    void update(double thrust, double dt)
    {
        acceleration = thrust / mass - 9.81;
        velocity += acceleration * dt;
        altitude += velocity * dt;
    }

    void printStatus(double time)
    {
        cout << fixed << setprecision(2);
        cout << "t=" << time << "с | h=" << altitude << "м | v=" << velocity << "м/с | a=" << acceleration << "м/с²\n";
    }
};

class AutonomousFlightSystem
{
private:
    Engine engine;
    Navigation nav;
    double time;

public:
    // Исправлено: используем список инициализации
    AutonomousFlightSystem(Engine e, Navigation n) : engine(e), nav(n), time(0)
    {
    }

    void simulate(double dt, double totalTime)
    {
        while (time < totalTime && engine.hasFuel())
        {
            engine.burn(dt);
            nav.update(engine.getThrust(), dt);
            nav.printStatus(time);
            time += dt;
        }
        cout << "--- Полет завершен ---\n";
    }

    void printSummary()
    {
        cout << "Оставшееся топливо: " << engine.getFuel() << " кг\n";
    }
};

int main()
{
    double thrust, fuelFlow, fuel;
    cout << "=== Параметры двигателя ===\n";
    cout << "Введите тягу (Н): ";
    cin >> thrust;
    cout << "Введите расход топлива (кг/с): ";
    cin >> fuelFlow;
    cout << "Введите количество топлива (кг): ";
    cin >> fuel;

    double altitude, velocity, mass;
    cout << "\n=== Параметры навигации ===\n";
    cout << "Введите начальную высоту (м): ";
    cin >> altitude;
    cout << "Введите начальную скорость (м/с): ";
    cin >> velocity;
    cout << "Введите массу ракеты (кг): ";
    cin >> mass;

    double dt, totalTime;
    cout << "\n=== Параметры симуляции ===\n";
    cout << "Введите шаг времени (с): ";
    cin >> dt;
    cout << "Введите общее время симуляции (с): ";
    cin >> totalTime;

    Engine engine(thrust, fuelFlow, fuel);
    Navigation nav(altitude, velocity, mass);
    AutonomousFlightSystem flight(engine, nav);

    cout << "\n=== Начало симуляции ===\n";
    flight.simulate(dt, totalTime);
    flight.printSummary();

    return 0;
}
