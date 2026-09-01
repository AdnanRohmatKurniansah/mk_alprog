#include <iostream>

using namespace std;

int main() {
    int size = 10;
    int data[size] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; 
    int cari;
    int indexKiri, indexKanan, mid;
    bool found;

    cout << "Nilai yang dicari : ";
    cin >> cari;

    found = false;
    indexKiri = 0;
    indexKanan = size;

    while ((!found) & (indexKiri <= indexKanan)) {
        mid = (indexKiri + indexKanan) / 2;

        if (cari == data[mid]) {
            found = true;
        } else {
            if (cari < data[mid]) {
                indexKanan = mid - 1;
            } else {
                indexKiri = mid + 1;
            }
        }
    }

    if (found) {
        cout << "Data ditemukan pada index ke-" << mid << endl;
    } else {
        cout << "Data tdk ditemukan" << endl;
    }
    
    return 0;
}