#include <iostream>

using namespace std;

int main() {
    string nama;
    int umur;
    float tinggi_badan;

    cout << "Masukkan Nama \t: ";
    getline(cin, nama);

    cout << "Masukkan Umur \t: ";
    cin >> umur;

    cout << "Masukkan Tinggi Badan \t: ";
    cin >> tinggi_badan;

    cout << "Halo " << nama << "," << "umur Anda " << umur << " tahun" << ", " << "tinggi badan Anda " << tinggi_badan << " cm."; 

    return 0;
}