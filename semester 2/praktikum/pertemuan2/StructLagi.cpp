#include <iostream>

using namespace std;

struct Mahasiswa {
    int Nim;
    string Nama;
    string Kelas;
    float Nilai;
};

void tampilkan(Mahasiswa &mhs);

void tambahData();

int main() {
    Mahasiswa mhs = {123250085, "Andi", "2A", 85.5};
    
    tampilkan(mhs);

    return 0;
}

void tampilkan(Mahasiswa &mhs) {
    mhs.Nama = "Dimas";
    cout << "Nama: " << mhs.Nama << endl;
    cout << "NIM: " << mhs.Nim << endl;
    cout << "Kelas: " << mhs.Kelas << endl;
    cout << "Nilai: " << mhs.Nilai << endl;
}

// #include <iostream>

// using namespace std;

// struct Pegawai {
//     string nama;
//     int jam;
//     double upah;
// };

// double hitungGaji(Pegawai p) {
//     return p.jam * p.ubah;
// }



// int main() {


//     return 0;
// }