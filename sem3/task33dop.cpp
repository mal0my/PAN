#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cout << "Введите количество измерений: ";
    cin >> n;

    vector<double> temp(n);
    cout << "Введите температуры:\n";
    for (int i = 0; i < n; i++) cin >> temp[i];

    cout << "До очистки: ";
    for (double x : temp) cout << x << " ";
    cout << "\n";

    auto new_end = remove_if(temp.begin(), temp.end(), [](double x) {
        return x < -100 || x > 200;
    });
    temp.erase(new_end, temp.end());

    cout << "После очистки: ";
    for (double x : temp) cout << x << " ";
    cout << "\n";

    return 0;
}
