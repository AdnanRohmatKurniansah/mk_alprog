#include <iostream>

using namespace std;

int main() {
    char jenjang_studi, program_studi;
    string tahun_masuk, kode_fti, kode_prodi, nim;

    cout << "Jenjang Studi: " << endl;
    cout << "A. S1" << endl;
    cout << "B. D3 TK" << endl;
    cout << "Pilih: ";
    cin >> jenjang_studi;

    switch (jenjang_studi) {
    case 'A':
        kode_fti = "12";
        cout << "Program Studi: " << endl;
        cout << "1. Teknik Kimia" << endl;
        cout << "2. Teknik Industri" << endl;
        cout << "3. Informatika" << endl;
        cout << "4. Sistem Informasi" << endl;
        cout << "Pilih: ";
        cin >> program_studi;

        if (program_studi == '1') {
            kode_prodi = "1";
        } else if(program_studi == '2') {
            kode_prodi = "2";
        } else if(program_studi == '3') {
            kode_prodi = "3";
        } else if(program_studi == '4') {
            kode_prodi = "4";
        } else {
            cout << "Pilih Prodi Sesuai Opsi" << endl;
        }

        cout << "Tahun Masuk: 20";
        cin >> tahun_masuk;
        tahun_masuk = tahun_masuk + "0";
        
        nim = kode_fti + kode_prodi + tahun_masuk;
        cout << "Nim Anda: " << nim;
        break;
    
    case 'B':
        kode_fti = "021";
        cout << "Tahun Masuk: 20";
        cin >> tahun_masuk;
        tahun_masuk = tahun_masuk + "0";

        nim = kode_fti + tahun_masuk;

        cout << "Nim Anda: " << nim << endl;
        break;
    default:
        cout << "Pilih Jenjang Studi Sesuai Opsi" << endl;
        break;
    }

    return 0;
}