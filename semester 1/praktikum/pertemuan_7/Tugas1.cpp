#include <iostream>

using namespace std;

float volumeTabung(int jari, int tinggi) {
    float volume;

    volume = 3.14*(jari*jari)*tinggi;

    return volume;
}

float volumeKerucut(int jari, int tinggi) {
    float volume;

    volume = (3.14*(jari*jari)*tinggi)/3;

    return volume;
}

int kelSegitiga(int sisi) {
    int keliling;

    keliling = sisi*3;

    return keliling;
}

float luasSegitiga(int alas, int tinggi) {
    float luas;

    luas = (alas*tinggi)/2;

    return luas;
}

int kelPersegiPanjang(int panjang, int lebar) {
    float keliling;

    keliling = (panjang*2)+(lebar*2);

    return keliling;
}

float luasPersegiPanjang(int panjang, int lebar) {
    float luas;

    luas = panjang*lebar;

    return luas;
}

int main() {
    int opsi, jari, tinggi, sisi, panjang, lebar;

    cout << "=== Program Hitung ===" << endl;
    cout << "1. Hitung Volume Tabung" << endl;
    cout << "2. Hitung Volume Kerucut" << endl;
    cout << "3. Keliling dan Luas Segitiga" << endl;
    cout << "4. Keliling dan Luas Persegi Panjang" << endl;
    cout << "Pilih Opsi: ";
    cin >> opsi;
    cout << endl;

    switch (opsi) {
    case 1:
        cout << "== Hitung Volume Tabung ==" << endl;
        cout << "Masukkan Jari2: ";
        cin >> jari;
        cout << "Masukkan Tinggi: ";
        cin >> tinggi;
        cout << "Volume Tabung: " << volumeTabung(jari, tinggi) << endl;
        break;
    case 2:
        cout << "== Hitung Volume Kerucut ==" << endl;
        cout << "Masukkan Jari2: ";
        cin >> jari;
        cout << "Masukkan Tinggi: ";
        cin >> tinggi;
        cout << "Volume Tabung: " << volumeKerucut(jari, tinggi) << endl;
        break;
    case 3:
        cout << "== Keliling dan Luas Segitiga ==" << endl;
        cout << "Masukkan panjang sisi2: ";
        cin >> sisi;
        cout << "Masukkan tinggi: ";
        cin >> tinggi;
        cout << "Keliling Segitiga: " << kelSegitiga(sisi) << endl;
        cout << "Luas Segitiga: " << luasSegitiga(sisi, tinggi) << endl;
        break;
    case 4:
        cout << "== Keliling dan Luas Persegi Panjang ==" << endl;
        cout << "Masukkan panjang: ";
        cin >> panjang;
        cout << "Masukkan lebar: ";
        cin >> lebar;
        cout << "Keliling Persegi Panjang: " << kelPersegiPanjang(panjang, lebar) << endl;
        cout << "Luas Persegi Panjang: " << luasPersegiPanjang(panjang, lebar) << endl;
        break;
    default:
        cout << "Input Menu yg benar.." << endl; 
        break;
    }

    return 0;
}