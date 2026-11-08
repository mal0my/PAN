#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

class DroneFlight
{
private:
    vector<double> x, y;
    double totalDistance;

public:
    DroneFlight()
    {
        totalDistance = 0;
    }

    void addPoint(double newX, double newY)
    {
        if (!x.empty())
        {
            double dx = newX - x.back();
            double dy = newY - y.back();
            totalDistance += sqrt(dx * dx + dy * dy);
        }
        x.push_back(newX);
        y.push_back(newY);
    }

    double getTotalDistance()
    {
        return totalDistance;
    }

    void printPath()
    {
        cout << "Точки маршрута: ";
        for (int i = 0; i < x.size(); i++)
        {
            cout << "(" << x[i] << ", " << y[i] << ") ";
        }
        cout << "\n";
    }
};

int main()
{
    int n;
    cout << "Введите количество точек маршрута: ";
    cin >> n;

    DroneFlight d;

    for (int i = 0; i < n; i++)
    {
        double px, py;
        cout << "Точка " << (i + 1) << " - X: ";
        cin >> px;
        cout << "Точка " << (i + 1) << " - Y: ";
        cin >> py;
        d.addPoint(px, py);
    }

    d.printPath();
    cout << fixed << setprecision(2);
    cout << "Пройдено: " << d.getTotalDistance() << " м\n";

    return 0;
}
