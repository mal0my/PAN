#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cout << "Введите количество измерений: ";
    cin >> n;

    vector<double> sensor(n);
    cout << "Введите показания:\n";
    for (int i = 0; i < n; i++) cin >> sensor[i];

    int zeros = count(sensor.begin(), sensor.end(), 0.0);

    cout << "Всего измерений: " << n << "\n";
    cout << "Нулевых показаний: " << zeros << "\n";

    return 0;
}
