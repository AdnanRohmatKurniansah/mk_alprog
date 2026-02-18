#include <iostream>
using namespace std;

int main() {
    int n = 9; 

    for (int i = 1; i <= n; i++) {
        // cetak spasi
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // cetak bintang
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl; 
    }

    return 0;
}
