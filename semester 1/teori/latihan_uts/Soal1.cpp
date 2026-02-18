#include <iostream>
using namespace std;

int main() {
    char jenisKelamin;
    int umur, pendidikan;
    string pekerjaan;

    cout << "Masukkan Jenis Kelamin: " << endl;
    cout << "L. Laki-laki" << endl;
    cout << "P. Perempuan" << endl;
    cout << "Pilih: ";
    cin >> jenisKelamin;

    cout << "Masukkan Umur: ";
    cin >> umur;

    cout << "Masukkan Tingkat Pendidikan: " << endl;
    cout << "1. SMA" << endl;
    cout << "2. D3" << endl;
    cout << "3. S1" << endl;
    cout << "4. S2" << endl;
    cout << "Pilih: ";
    cin >> pendidikan;

    if (jenisKelamin == 'L' && umur >= 17 && umur <= 35 && (pendidikan == 1 || pendidikan == 2)) {
        pekerjaan = "Operator";
    } else if (jenisKelamin == 'P' && umur >= 17 && umur <= 35 && 
             (pendidikan == 1 || pendidikan == 2 || pendidikan == 3)) {
        pekerjaan = "Sekretaris";
    } else if ((jenisKelamin == 'L' || jenisKelamin == 'P') && umur >= 17 && umur <= 40 && 
             (pendidikan == 2 || pendidikan == 3)) {
        pekerjaan = "Programmer";
    } else if ((jenisKelamin == 'L' || jenisKelamin == 'P') && umur > 25 && umur <= 40 && 
             (pendidikan == 3 || pendidikan == 4)) {
        pekerjaan = "Manajer";
    } else {
        pekerjaan = "Tidak ada pekerjaan yang sesuai";
    }

    cout << "Jenis pekerjaan yang ditawarkan: " << pekerjaan << endl;

    return 0;
}
