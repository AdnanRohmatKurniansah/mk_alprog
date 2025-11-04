#include <iostream>
using namespace std;

int main() {
    int bilangan, km, m, cm, mm, sisa;

    cout << "Bilangan (dalam mm) = ";
    cin >> bilangan;

    // km konversi
    km = bilangan / 1000000;
    sisa = bilangan % 1000000;

    // m konversi
    m = sisa / 1000;
    sisa = sisa % 1000;

    // cm konversi
    cm = sisa / 10;
    sisa = sisa % 10;

    // mm konversi
    mm = sisa;
    
    cout << "Hasil konversi = " << km << " km, " << m << " m, " << cm << " cm, " << mm << " mm, ";

    return 0;
}
