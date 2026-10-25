#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cout << "Введите количество высот: ";
    cin >> n;

    vector<double> heights(n);
    cout << "Введите высоты:\n";
    for (int i = 0; i < n; i++)
        cin >> heights[i];

    cout << "До удаления: ";
    for (double h : heights) cout << h << " ";
    cout << "\n";

    auto new_end = remove_if(heights.begin(), heights.end(), [](double h) {
        return h < 10.0;
    });
    heights.erase(new_end, heights.end());

    cout << "После удаления (h < 10): ";
    for (double h : heights) cout << h << " ";
    cout << "\n";

    return 0;
}
