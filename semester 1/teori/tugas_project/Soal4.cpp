#include <iostream>
using namespace std;

void konversi(int bilangan, int *km, int *m, int *cm, int *mm);

int main() {
    int bilangan, km, m, cm, mm, sisa;

    cout << "Bilangan (dalam mm) = ";
    cin >> bilangan;

    konversi(bilangan, &km, &m, &cm, &mm);
    
    cout << "Hasil konversi = " << km << " km, " << m << " m, " << cm << " cm, " << mm << " mm, ";

    return 0;
}

void konversi(int bilangan, int *km, int *m, int *cm, int *mm) {
    int sisa;

    // km konversi
    *km = bilangan / 1000000;
    sisa = bilangan % 1000000;

    // m konversi
    *m = sisa / 1000;
    sisa = sisa % 1000;

    // cm konversi
    *cm = sisa / 10;
    sisa = sisa % 10;

    // mm konversi
    *mm = sisa;
}
