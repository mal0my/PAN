#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cout << "Введите количество точек: ";
    cin >> n;

    vector<double> h(n);
    cout << "Введите высоты:\n";
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<double> smoothed(n);
    smoothed[0] = h[0];
    smoothed[n - 1] = h[n - 1];

    for (int i = 1; i + 1 < n; i++)
    {
        smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
    }

    cout << "Исходные: ";
    for (double x : h) cout << x << " ";
    cout << "\nСглаженные: ";
    for (double x : smoothed) cout << x << " ";
    cout << "\n";

    return 0;
}
