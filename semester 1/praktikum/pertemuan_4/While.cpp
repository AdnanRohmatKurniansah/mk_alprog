#include <iostream>
using namespace std;

int main() {
    int i = -1;
    while (i < 0 || i % 2 == 1) {
        cout << "Masukkan angka bilangan bulat genap positif: ";
        cin >> i;
    }

    cout << "Selesai";

    return 0;
}