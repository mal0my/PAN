#include <iostream>
#include <iomanip>


using namespace std;

double raschetANDvivod(double L[], double p[], double V[], int count, double plosh, double koaf)
{
    for (int k = 0; k < count; k++)
    {
        L[k] = 0.5 * p[k] * V[k] * V[k] * plosh * koaf;
    }
    cout <<"Введите коэффициент подъемной силы Cl = ";
    cout << "\n Шаг |  Скорость  | Плотность  |  Подъемная сила \n";
    cout << "--------------------------------------------------\n";
    for (int m = 0; m < count; m++)
    {
        cout << setw(4) << m+1 << " | " << setw(10) << V[m] << " | " << setw(10) << p[m] << " | " << setw(15) << L[m] << "\n";
    }
    return 0;
}

int main()
{
    double Cl, S;
    cout <<"Введите коэффициент подъемной силы Cl = ";
    cin >> Cl;
    cout <<"Введите площадь крыла S = ";
    cin >> S;
    //0.5 * p * V * V * S * Cl подъемная сила
    int n;
    int num = 1;
    cout <<"Введите количество шагов n = ";
    cin >> n;
    double *scor = new double[n];
    double *plot = new double[n];
    double *sila = new double[n];
    for (int i = 0; i < n; i++)
    {
        cout <<"Введите скорость для шага №" << num++ << endl;
        cin >> scor[i];
    }
    num = 1;
    for (int j = 0; j < n; j++)
    {
        cout <<"Введите плотность воздуха для шага №" << num++ << endl;
        cin >> plot[j];
        if (plot[j] < 0)
        {
            while(plot[j] < 0)
            {
                cout <<"Введите плотность воздуха (p >= 0): ";
                cin >> plot[j];
            }
        }
    }
    raschetANDvivod(sila, plot, scor, n, S, Cl);
    delete[] scor;
    delete[] plot;
    delete[] sila;
    return 0;
}
