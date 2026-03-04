#include <iostream>

using namespace std;

int main() {
    int size = 10;
    int x[size] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int cari;
    int indKiri = 0;
    int indKanan = size;
    int mid = 0;
    bool found = false;

    cout << "Nilai yg dicari: ";
    cin >> cari;

    while ((!found) && (indKiri >= indKanan)) {
        mid = (indKiri + indKanan)/2;
        if (cari == x[mid]) {
            found = true;
        } else {
            if (cari < x[mid]) {
                indKanan = mid - 1;
            } else {
                indKiri = mid + 1;
            }
            
        }
        
    }

    if (found) {
        cout << cari << " ditemukan di index ke-" << mid << endl;
    } else {
        cout << "tidak ada " << cari << " dlm array " << endl;
    }
    
    return 0;
}