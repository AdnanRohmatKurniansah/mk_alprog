// Nama: Adnan Rohmat Kurniansah
// Nim: 123250085

#include <iostream>
using namespace std;

int main() {
    int angka_input, i;
    bool angka_prima = true;
    
    cout << "Inputkan satu bilangan bulat: ";
    cin >> angka_input;
    
    if (angka_input == 0 || angka_input == 1) {
        angka_prima = false;
    } else {
        for (i = 2; i <= angka_input / 2; i++) {
            if (angka_input % i == 0) {
                angka_prima = false;
                break;
            }
        }
    }

    if (angka_prima) {
        cout << "\nBilangan Prima";
    } else {
        cout << "\nBukan Bilangan Prima";
    }
    
    return 0;
}
