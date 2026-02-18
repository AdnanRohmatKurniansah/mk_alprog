// Nama: Adnan Rohmat Kurniansah
// Nim: 123250085
// Plug: Praktikum Algoritma dan Pemrograman IF-D (20251)

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float celcius, fahrenheit, kelvin, reamur;
    
    cout << setfill('-') << setw(5) << "- ";
    cout << "Konversi Suhu dlm Celcius ";
    cout << setfill('-') << setw(5) << "-\n";

    cout << "\nMasukkan Suhu Celcius \t: ";
    cin >> celcius;

    fahrenheit = (celcius * 9/5)+32;
    kelvin = 273 + celcius;
    reamur = (celcius * 4/9) + 32;

    cout << "\nHasil konversi suhu \n";
    cout << setfill('-') << setw(35);

    cout << "\n" << "Fahrenheit \t= " << fahrenheit;
    cout << "\n" << "Kelvin \t\t= " << kelvin;
    cout << "\n" << "Reamur \t\t= " << reamur;
    cout << "\n" << setfill('-') << setw(35);

    cout << "\n" << "Dengan C \t= " << celcius << endl;
    

    return 0;
}
