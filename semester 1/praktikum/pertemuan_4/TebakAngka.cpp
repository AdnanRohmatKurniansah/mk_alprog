#include <iostream>
using namespace std;

int main() {
    int angkaBenar = 13;
    int angkaInput = 0;

    do {
        cout << "Tebak angkanya : ";
        cin >> angkaInput;
    } while (angkaInput != angkaBenar);
    

    return 0;
}