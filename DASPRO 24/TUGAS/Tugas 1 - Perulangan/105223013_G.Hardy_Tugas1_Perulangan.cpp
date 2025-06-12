#include <iostream>
using namespace std;

float fungsi(float x) {
    return x * x * x + x + 1;
}

float hitungLuasDaerah(float a, float b, float delta) {
    float luasDaerah = 0;
    int n = (b - a) / delta;
    for (int i = 0; i < n; i++) {
        float x1 = a + i * delta;
        float x2 = x1 + delta;
        float f_x1 = fungsi(x1);
        float f_x2 = fungsi(x2);
        luasDaerah += 0.5 * (f_x1 + f_x2) * delta;
    }
    return luasDaerah;
}

int main() {
    float a, b, delta;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    cout << "Masukkan nilai delta: ";
    cin >> delta;
    
    if (a < 0 || b <= 0 || a >= b || delta <= 0) {
        cout << "Input tidak valid! Pastikan:\n";
        cout << "- a >= 0\n";
        cout << "- b > 0\n";
        cout << "- a < b\n";
        cout << "- delta > 0\n";
        return 1;
    }
    
    float luas = hitungLuasDaerah(a, b, delta);
    cout << "Luas daerah di bawah kurva: " << luas << endl;

    return 0;
}
