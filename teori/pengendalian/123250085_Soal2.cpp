// Nama: Adnan Rohmat Kurniansah
// Nim: 123250085

#include <iostream>
using namespace std;

int main() {
    int hari;
    cout << "Masukkan Angka antara 1 s.d 7 \t: ";
    cin >> hari;

    switch (hari) {
    case 1:
        cout << "Hari Senin";
        break;
    case 2:
        cout << "Hari Selasa";
        break;
    case 3:
        cout << "Hari Rabu";
        break;
    case 4:
        cout << "Hari Kamis";
        break;
    case 5:
        cout << "Hari Jumat";
        break;
    case 6:
        cout << "Hari Sabtu";
        break;
    case 7:
        cout << "Hari Minggu";
        break;
    default:
        cout << "Angka yg dimasukkan diluar range";
        break;
    }

    return 0;
}
