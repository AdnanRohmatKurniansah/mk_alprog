// Nama: Adnan Rohmat Kurniansah
// Nim: 123250085
// Plug: Praktikum Algoritma dan Pemrograman IF-D (20251)

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string nama, nim, plug;
    
    cout << "Masukkan Data Anda: " << endl;
    cout << "Nama \t: ";
    getline(cin, nama);

    cout << "Nim \t: ";
    cin >> nim;
    cin.ignore();

    cout << "Plug \t: ";
    getline(cin, plug);

    cout << "\nDalam bentuk tabel: " << endl;
    cout << setfill('=') << setw(90) << "=" << endl;   

    cout << setfill(' ') 
         << left << setw(30) << "NIM"
         << "| " << left << setw(30) << "Nama"
         << "| " << left << setw(30) << "Plug" << endl;

    cout << setfill('=') << setw(90) << "=" << endl;   

    cout << setfill(' ') 
         << left << setw(30) << nim
         << "| " << left << setw(30) << nama
         << "| " << left << setw(30) << plug << endl;

    cout << setfill('-') << setw(90) << "-" << endl;  

    return 0;
}
