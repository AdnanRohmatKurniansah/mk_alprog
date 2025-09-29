#include <iostream>
using namespace std;

int main() {
    string cuaca;
    char kelembapan_tinggi, sinar_matahari_menyengat;

    cout << "=== Berenang atau Tidak? ===" << endl;
    cout << "Apa cuaca hari ini? (hujan / mendung / cerah): ";
    getline(cin, cuaca);

    if (cuaca == "hujan") {
        cout << "Tidak jadi berenang";
    } 
    else if (cuaca == "mendung") {
        cout << "Apakah kelembapan hari ini tinggi? (y / n): ";
        cin >> kelembapan_tinggi;
        if (kelembapan_tinggi == 'y') {
            cout << "Tidak jadi berenang";
        } else {
            cout << "Jadi berenang";
        }
    } 
    else { 
        cout << "Apakah sinar matahari hari ini menyengat? (y / n): ";
        cin >> sinar_matahari_menyengat;
        if (sinar_matahari_menyengat == 'y') {
            cout << "Tidak jadi berenang";
        } else {
            cout << "Jadi berenang";
        }
    }

    return 0;
}
