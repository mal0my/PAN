#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    double v0 = 50.0;
    double g = 9.8;
    double dt = 1.0;

    vector<double> heights;
    for (double t = 0; t <= 100; t += dt)
    {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0) break;
        heights.push_back(h);
    }

    auto it = max_element(heights.begin(), heights.end());
    int idx = distance(heights.begin(), it);

    cout << "Максимальная высота: " << *it << "\n";
    cout << "Время: " << idx * dt << "\n";

    return 0;
}

