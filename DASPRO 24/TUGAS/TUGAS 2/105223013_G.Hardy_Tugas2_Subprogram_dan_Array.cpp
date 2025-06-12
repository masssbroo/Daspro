#include <iostream>
using namespace std;

const int MAX_POINTS = 20;

int get_corners(double x[], double y[], int max_size) 
{
    int n;
    cout << "Masukkan jumlah titik sudut: ";
    cin >> n;

    if (n > max_size - 1) 
    {
        cout << "Jumlah titik terlalu banyak, hanya " << max_size - 1 << " yang akan digunakan.\n";
        n = max_size - 1;
    }

    for (int i = 0; i < n; ++i) 
    {
        cout << "Titik ke " << i + 1 << ":\n";
        cout << "  x: ";
        cin >> x[i];
        cout << "  y: ";
        cin >> y[i];
    }

    x[n] = x[0];
    y[n] = y[0];

    return n + 1;
}

double polygon_area(const double x[], const double y[], int size) 
{
    double area = 0.0;
    for (int i = 0; i < size - 1; ++i) {
        area += (x[i] * y[i + 1]) - (x[i + 1] * y[i]);
    }

    area = area >= 0 ? area : -area;
    return 0.5 * area;
}

int main() 
{
    double x[MAX_POINTS], y[MAX_POINTS];
    int size = get_corners(x, y, MAX_POINTS);

    double area = polygon_area(x, y, size);
    cout << "Luas poligon tertutup: " << area << endl;

    return 0;
}