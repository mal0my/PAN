#include <iostream>

using namespace std;

class Trajectory
{
private:
    double startX, startY;
    double angle;

public:
    Trajectory()
    {
        startX = 0;
        startY = 0;
        angle = 0;
    }

    Trajectory(double x, double y, double ang)
    {
        startX = x;
        startY = y;
        angle = ang;
    }

    void printTrajectory()
    {
        cout << "Старт: (" << startX << ", " << startY << "), угол: " << angle << "°\n";
    }
};

int main()
{
    Trajectory t1;
    t1.printTrajectory();

    double x, y, ang;
    cout << "Введите координату X: ";
    cin >> x;
    cout << "Введите координату Y: ";
    cin >> y;
    cout << "Введите угол (градусы): ";
    cin >> ang;

    Trajectory t2(x, y, ang);
    t2.printTrajectory();

    return 0;
}
