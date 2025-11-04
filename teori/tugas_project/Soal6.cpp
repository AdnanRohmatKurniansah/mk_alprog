#include <iostream>
using namespace std;

void konversi(int bilangan, int *jam, int *menit, int *detik);

int main() {
    int bilangan, jam, menit, detik;

    cout << "Bilangan = "; 
    cin >> bilangan;

    konversi(bilangan, &jam, &menit, &detik);

    cout << bilangan << " detik = " << jam << " jam " << menit << " menit " << detik << " detik ";

    return 0;
}


void konversi(int bilangan, int *jam, int *menit, int *detik) {
    int sisa;

    // jam konversi
    *jam = bilangan / 3600;
    sisa = bilangan % 3600;

    // menit konversi
    *menit = sisa / 60;
    sisa = sisa % 60;

    // detik konversi
    *detik = sisa;
}