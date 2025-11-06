#include <iostream>
using namespace std;

void tampilProfile(string nama, string nim);
void tampilWarna(string warna[12]);

int main() {
    string nama, nim;
    string warna[12] = {
        "Orange", "Red-Orange", "Red", "Red-Violet", "Violet", "Blue-Violet", "Blue", "Blue-Green", "Green", "Yellow-Green", "Yellow", "Yellow-Orange"
    };
    int inputWarna;

    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan Nim: ";
    getline(cin, nim);

    system("cls");

    tampilProfile(nama, nim);

    tampilWarna(warna);

    cout << "\nPilihan warna nomor : ";
    cin >> inputWarna;

    return 0;
}

void tampilProfile(string nama, string nim) {
    cout << "===========================" << endl;
    cout << "  Nama \t: " << nama << "    " << endl;
    cout << "  Nim \t: " << nim << "    " << endl;
    cout << "===========================" << endl;
    cout << "Program Menentukan Notasi, Sifat Warna, dan Perpaduan Warna Harmonis Warna-warna: " << endl;
}

void tampilWarna(string warna[12]) {
    int i = 0;
    while (i < 12) {
        cout << i + 1 << ". " << warna[i] << endl; 
        i++;
    }
}
