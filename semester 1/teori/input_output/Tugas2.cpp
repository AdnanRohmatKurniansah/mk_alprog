#include <iostream>
using namespace std;

int main() {
    float celcius, fahrenheit;
    cout << "Masukkan Suhu Celcius \t: ";
    cin >> celcius;

    fahrenheit = (celcius * 9/5)+32;

    cout << "\nHasil konversi suhu";

    cout << "\n" << "Dalam Fahrenheit \t: " << fahrenheit;
    

    return 0;
}
