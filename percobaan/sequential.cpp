#include <iostream>

using namespace std;

int main() {
    // int data[6] = {10, 40, 79, 80, 32, 97};
    int data[6] = {10, 40, 79, 80, 32};
    int i, nilaiCari;
    bool found = false;

    cout << "Nilai yg dicari : ";
    cin >>  nilaiCari;

    data[5] = nilaiCari;

    i = 0;
    // while (i < 6 && found == false) {
    //     if (data[i] == nilaiCari) {
    //         found = true;
    //     } else {
    //         i++;
    //     }
    // }

    // if (found) {
    //     cout << nilaiCari << " ditemukan di index ke-" << i << endl;
    // } else {
    //     cout << "Tidak ada " << nilaiCari << " dalam array" << endl;
    // }

    while (data[i] != nilaiCari) {
        i++;
    }

    if (i > 4) {
        cout << nilaiCari << " ditemukan di index ke-" << i << endl;
    } else {
        cout << nilaiCari << " tidak ditemukan" << endl;
    }

    return 0;
}