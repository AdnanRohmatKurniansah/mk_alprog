#include <iostream>
using namespace std;

int main() {
    int panjang;
    panjang = 0;

    cout << "Masukkan nilai panjang: ";
    cin >> panjang;

    for (int i = 0; i < panjang; i++) {
        // cetak spasi
        for (int j = 1; j <= panjang - i; j++) {
            cout << " ";
        }
        // cetak bintang
        for (int k = 1; k <= i+1; k++) {
            cout << "*";
        }
        for (int l = 1; l <= i; l++) {
            cout << "*";
        }
        cout << endl; 
    }
    

    return 0;
}

