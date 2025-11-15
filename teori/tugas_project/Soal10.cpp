#include <iostream>
using namespace std;

void tampilProfile(string nama, string nim);
void tampilWarna(string warna[12]);
string cekNotasiWarna(int inputWarna);
string cekSifatWarna(int inputWarna);
void tampilKombinasi(int inputWarna);

int main() {
    string nama, nim, warnaDipilih, notasiWarna, sifatWarna;
    string warna[12] = {
        "Orange", "Red-Orange", "Red", "Red-Violet", "Violet", "Blue-Violet", "Blue", "Blue-Green", "Green", "Yellow-Green", "Yellow", "Yellow-Orange"
    };
    int inputWarna;

    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan Nim: ";
    getline(cin, nim);

    system("cls");
    
    do {
        tampilProfile(nama, nim);
    
        tampilWarna(warna);
    
        cout << "\nPilihan warna nomor : ";
        cin >> inputWarna;

        if (inputWarna < 1 || inputWarna > 12) {
            system("cls");
            cout << "Warna tdk tersedia, Ulangi" << endl;
            cout << "\n";
        } 
    } while(inputWarna < 1 || inputWarna > 12);

    notasiWarna = cekNotasiWarna(inputWarna);
    sifatWarna = cekSifatWarna(inputWarna);

    cout << "\nNotasi warna \t: " << notasiWarna << endl;
    cout << "Sifat warna \t: " << sifatWarna << endl;

    tampilKombinasi(inputWarna);
    
    return 0;
}

void tampilProfile(string nama, string nim) {
    cout << "===========================" << endl;
    cout << "  Nama \t: " << nama << "    " << endl;
    cout << "  Nim \t: " << nim << "    " << endl;
    cout << "===========================" << endl;
    cout << "Program Menentukan Notasi, Sifat Warna, \ndan Perpaduan Warna Harmonis Warna-warna: " << endl;
}

void tampilWarna(string warna[12]) {
    int i = 0;
    while (i < 12) {
        cout << i + 1 << ". " << warna[i] << endl; 
        i++;
    }
}

string cekNotasiWarna(int inputWarna) {
    string notasi;

    if (inputWarna == 3 || inputWarna == 7 || inputWarna == 11) {
        notasi = "Primer";
    } else if (inputWarna == 1 || inputWarna == 5 || inputWarna == 9) {
        notasi = "Sekunder";
    } else {
        notasi = "Tersier";
    }    
    
    return notasi;
}

string cekSifatWarna(int inputWarna) {
    string sifat;

    if (inputWarna > 6) {
        sifat = "Sejuk";
    } else {
        sifat = "Hangat";
    }

    return sifat;
}

void tampilKombinasi(int inputWarna) {
    bool ulang = false;
    char inputKombinasi;

    int kombinasi1;
    int kombinasi2;
    int kombinasi3;
    int kombinasi4;

    do {
        cout << "Perpaduan Warna Harmonis" << endl;
        cout << "a. Perpaduan Warna Analogous" << endl;
        cout << "b. Perpaduan Warna Complementary" << endl;
        cout << "c. Perpaduan Warna Split Complementary" << endl;
        cout << "d. Perpaduan Warna Triadic Complementary" << endl;
        cout << "e. Perpaduan Warna Tetrad Complementary" << endl;
        cout << "Pilihan : ";
        cin >> inputKombinasi;
        
        switch (inputKombinasi) {
        case 'a':
            ulang = false;
            
            kombinasi1 = inputWarna == 1 ? 12 : inputWarna - 1;
            kombinasi2 = inputWarna == 12 ? 1 : inputWarna + 1;

            cout << "\nPerpaduan Warna Analogous dengan warna nomor : \n" << kombinasi1 << "," << inputWarna << " atau " << kombinasi1 << "," << kombinasi2 << " atau " << kombinasi2 << "," << inputWarna << endl;
            
            break;
        case 'b':
            ulang = false;

            kombinasi1 = (inputWarna + 6) > 12 ? (inputWarna + 6 - 12) : (inputWarna + 6);

            cout << "\nPerpaduan Warna Complementary dengan warna nomor : \n" << kombinasi1 << "," << inputWarna << endl;
            break;
        case 'c':
            ulang = false;

            kombinasi1 = (inputWarna + 6) > 12 ? (inputWarna + 6 - 12) - 1 : (inputWarna + 6) - 1;
            kombinasi2 = (inputWarna + 6) > 12 ? (inputWarna + 6 - 12) + 1 : (inputWarna + 6) + 1;

            cout << "\nPerpaduan Warna Split Complementary dengan warna nomor : \n" << kombinasi1 << "," << inputWarna << " atau " << kombinasi1 << "," << kombinasi2 << " atau " << kombinasi2 << "," << inputWarna << endl;

            break;
        case 'd': 
            ulang = false;

            kombinasi1 = (inputWarna + 6) > 12 ? (inputWarna + 6 - 12) - 2 : (inputWarna + 6) - 2;
            kombinasi2 = (inputWarna + 6) > 12 ? (inputWarna + 6 - 12) + 2 : (inputWarna + 6) + 2;

            cout << "\nPerpaduan Warna Triadic Complementary dengan warna nomor : \n" << kombinasi1 << "," << inputWarna << " atau " << kombinasi1 << "," << kombinasi2 << " atau " << kombinasi2 << "," << inputWarna << endl;

            break;
        case 'e':
            ulang = false;

            kombinasi1 = (inputWarna + 6) > 12 ? (inputWarna + 6 - 12) - 3 : (inputWarna + 6) - 3;
            kombinasi2 = (inputWarna + 6) > 12 ? (inputWarna + 6 - 12) + 3 : (inputWarna + 6) + 3;
            kombinasi3 = (inputWarna + 6) > 12 ? (inputWarna + 6 - 12) : (inputWarna + 6);

            cout << "\nPerpaduan Warna Tetrad Complementary dengan warna nomor : \n" << kombinasi1 << "," << inputWarna << " atau " << kombinasi1 << "," << kombinasi2 << " atau " << kombinasi1 << "," << kombinasi3 << " atau " << kombinasi2 << "," << inputWarna << " atau " << kombinasi2 << "," << kombinasi3 << " atau " << kombinasi3 << "," << inputWarna << endl;

            break;
        default:
            system("cls");
            ulang = true;
            cout << "\nKombinasi tidak tersedia, ulangi" << endl;
            cout << "\n";
        }
    } while (ulang == true);
}

