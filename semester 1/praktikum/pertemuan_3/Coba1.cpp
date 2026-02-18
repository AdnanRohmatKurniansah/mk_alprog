#include <iostream>
using namespace std;

int main() {
    char opsi;
    int angka1, angka2, hasil;

    cout << "Input angka pertama \t: ";
    cin >> angka1;

    cout << "Input angka kedua \t: ";
    cin >> angka2;

    cout << "Pilih opsi dibawah ini" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "4. Pembagian" << endl;

    cout << "\nPilih: ";
    cin >> opsi;

    switch (opsi) {
        case '1':
            hasil = angka1 + angka2;
            cout << "Hasil Penjumlahan: " << hasil;
            break;
        case '2':
            hasil = angka1 - angka2;
            cout << "Hasil Pengurangan: " << hasil;
            break;
        case '3':
            hasil = angka1 * angka2;
            cout << "Hasil Perkalian: " << hasil;
            break;
        case '4':
            hasil = angka1 / angka2;
            cout << "Hasil Pembagian: " << hasil;
            break;
        default:
            cout << "Tolong pilih opsi yg tersedia";
            break;
    }

    return 0;
}