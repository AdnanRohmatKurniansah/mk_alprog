#include <iostream>

using namespace std;

int main() {
    int tahun_lahir, tahun_sekarang, umur;

    cout << "Masukkan Tahun Lahir \t: ";
    cin >> tahun_lahir;

    cout << "Masukkan Tahun Sekarang : ";
    cin >> tahun_sekarang;

    umur = tahun_sekarang - tahun_lahir;

    cout << "Anda berumur " << umur << " tahun."; 

    return 0;
}