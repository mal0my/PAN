#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cout << "Введите количество координат: ";
    cin >> n;

    vector<double> x(n);
    cout << "Введите координаты x:\n";
    for (int i = 0; i < n; i++) cin >> x[i];

    sort(x.begin(), x.end());

    auto new_end = unique(x.begin(), x.end());
    x.erase(new_end, x.end());

    cout << "Результат: ";
    for (double val : x) cout << val << " ";
    cout << "\n";

    return 0;
}
