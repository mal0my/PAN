#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout << "Введите количество координат: ";
    cin >> n;

    vector<double> y(n);
    cout << "Введите координаты y:\n";
    for (int i = 0; i < n; i++) cin >> y[i];

    vector<double> diffs(n);
    adjacent_difference(y.begin(), y.end(), diffs.begin());

    double total_path = 0;
    for (int i = 1; i < n; i++)
    {
        total_path += abs(diffs[i]);
    }

    cout << "Суммарный путь: " << total_path << "\n";

    return 0;
}
