#include <iostream>

using namespace std;

class Autopilot
{
private:
    double courseAngle;
    double altitude;

public:
    Autopilot(double course, double alt)
    {
        courseAngle = course;
        altitude = alt;
    }

    void changeCourse(double delta)
    {
        courseAngle += delta;
    }

    void changeAltitude(double delta)
    {
        altitude += delta;
    }

    void printStatus()
    {
        cout << "Курс: " << courseAngle << "°, высота: " << altitude << " м\n";
    }
};

int main()
{
    double course, altitude;
    cout << "Введите начальный курс (°): ";
    cin >> course;
    cout << "Введите начальную высоту (м): ";
    cin >> altitude;

    Autopilot a1(course, altitude);

    double deltaCourse, deltaAlt;
    cout << "Введите изменение курса (°): ";
    cin >> deltaCourse;
    cout << "Введите изменение высоты (м): ";
    cin >> deltaAlt;

    a1.changeCourse(deltaCourse);
    a1.changeAltitude(deltaAlt);
    a1.printStatus();

    return 0;
}
