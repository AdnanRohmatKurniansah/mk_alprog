#include <iostream>
using namespace std;

int main() {
    int nilaiSekarang, nilaiTotal, jumlahNilaiMasukan;

    cout << "Masukkan jumlah bilangan yg ingin diinput: ";
    cin >> jumlahNilaiMasukan;

    for (int i = 0; i < jumlahNilaiMasukan; i++) {
        cout << "Masukkan nilai ke-" << i + 1 << ": ";
        cin >> nilaiSekarang;

        nilaiTotal += nilaiSekarang; 
    }

    cout << "Total: " << nilaiTotal;
    
    
    return 0;
}

