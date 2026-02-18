// Nama: Adnan Rohmat Kurniansah
// Nim: 123250085
// Plug: Praktikum Algoritma dan Pemrograman IF-D (20251)

#include <iostream>
#define phi 3.14

using namespace std;

// Luas permukaan kerucut
int main() {
    int jari = 14;
    int gPelukis = 20;
    float luas;

    luas = (phi*jari*jari) + (phi*jari*gPelukis);

    cout << "Luas permukaan kerucut: " << luas << endl;

    return 0;
}