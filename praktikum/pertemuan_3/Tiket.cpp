#include <iostream>
using namespace std;

int main() {    
    int umur;
    int jam;
    int harga;
    char pilihanUser;
    string film;
    bool pilihanValid = true;

    jam = 0;
    umur = 0;

    cout << "=== Harga Tiket Bioskop ===" << endl;

    cout << "Masukkan Umur \t: ";
    cin >> umur;
    cin.ignore(255, '\n');

    cout << "Masukkan Jam \t: ";
    cin >> jam;
    cin.ignore(255, '\n');

    cout << "List movie\n";
    cout << "1. Sore" << endl;
    cout << "2. Demon Slayer" << endl;
    cout << "3. Merah Putih" << endl;
    cout << "4. The Conjuring" << endl;

    cout << "Opsi : ";
    cin >> pilihanUser;

    switch (pilihanUser)
    {
    case '1':
        harga = 90000;
        film = "Sore";
        break;
    case '2':
        harga = 95000;
        film = "Demon Slayer";
        break;
    case '3':
        harga = 100000;
        film = "Merah Putih";
        break;
    case '4':
        harga = 70000;
        film = "The Conjuring";
        break;
    default:
       pilihanValid = false;
       break;
    }

    if (pilihanValid)
    {
        if (umur >= 12) {
            harga = harga * 0.6;
        } else if (umur >= 60) {
            harga = harga * 0.5;
        } else {
            harga = harga;
        }

        if (jam >= 17) {
            harga -= 15000;
        } 
        
        harga = (harga < 25000) ? 25000 : harga;
        system("cls");
        cout << "Harga Tiket Anda: " << harga; 
        cout << "\nJudul Movie: " << film; 
    } else {
        system("cls");
        cout << "Pilihan movie tidak valid\nSilahkan masukkan movie yg ada";
    }
    
}