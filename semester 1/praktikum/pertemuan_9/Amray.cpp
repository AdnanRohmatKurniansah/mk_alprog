#include <iostream>
using namespace std;

int main() {
    // int nilai[10];

    // for (int i = 0; i < 10; i++) {
    //     cout << "Masukkan nilai ke-" << i+1 << " = ";
    //     cin >> nilai[i];
    // }

    // for (int i = 0; i < 10; i++) {
    //     cout << "Nilai ke-" << i+1 << " = " << nilai[i] << endl;
    // }

    int nilai[2][3];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Masukkan nilai ke-" << i+1 << "." << j+1 << " = ";
            cin >> nilai[i][j];
        }
    }

    cout << "\n";

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Nilai ke-" << i+1 << "." << j+1 << " = " << nilai[i][j] << endl;
        }
    }
    

    return 0;
}