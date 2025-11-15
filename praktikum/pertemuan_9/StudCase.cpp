#include <iostream>
using namespace std;

int main() {
    int baris, kolom;

    cout << "Masukkan Jumlah Baris = ";
    cin >> baris;
    cout << "Masukkan Jumlah Kolom = ";
    cin >> kolom;

    int nilai[baris][kolom];


    cout << "Masukkan nilai matriks" << endl;
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "[" << i << "]" << "[" << j << "]" << " = ";
            cin >> nilai[i][j];
        }
    }

    cout << "\n";
    cout << "Tampilan Matriks" << endl;

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "[" << nilai[i][j] << "]";
        }
        cout << endl;
    }
    

    return 0;
}