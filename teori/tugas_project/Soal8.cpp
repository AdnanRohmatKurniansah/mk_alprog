#include <iostream>
using namespace std;

int opsiMenu;
string tim[13];
bool ulang = false;
char kembali;
string inputTim;

void tampilTim();
void lanjutProgram();
void tambahData();

int main() {
    do {
        cout << "===================" << endl;
		cout << "| Kelola Data Tim |" << endl;
		cout << "===================" << endl;
		cout << "1. Tampilkan Data Tim" << endl;
		cout << "2. Input Data Tim" << endl;
		cout << "3. Keluar" << endl;
        cout << "Pilih opsi: ";
		cin >> opsiMenu;

        switch (opsiMenu) {
            case 1:
                system("cls");
                ulang = false;
                
                tampilTim();

                break;
            case 2:
                ulang = false;
                system("cls");

                tambahData();

                break;
            case 3:
                ulang = false;
                system("cls");
                cout << "\n" << endl;
                cout << "-- Anda keluar dari program --\n" << endl;
                exit(0);
                break;
            default:
                system("cls");
                ulang = true;
                cout << "\n" << endl;
                cout << "-- Pilihan tidak valid --\n" << endl;
                cout << "\n";
        }
    } while (ulang == true);
    

    return 0;
}

void tampilTim() {
    int i = 0;

    cout << "====================" << endl;
    cout << "|  Tampilkan Data  |" << endl;
    cout << "====================" << endl;

    while (i < 13) {
        if (tim[i] != "") {
            cout << i + 1 << ". Tim " << tim[i] << endl;
        } else {
            cout << i + 1 << ". Belum ada " << endl;
        }
        
        i++;
    }

    lanjutProgram();
}

void tambahData() {
    int i = 0;

    cout << "====================" << endl;
    cout << "|    Tambah Data   |" << endl;
    cout << "====================" << endl;

    cin.ignore();

    while (i < 13) {
        cout << "Masukkan Nama Tim " << i + 1 << " : ";
        getline(cin, inputTim);

        tim[i] = inputTim;
        
        i++;
    }

    cout << "\n" << endl;
    cout << "-- Selesai menambahkan data --\n" << endl;

    lanjutProgram();
}

void lanjutProgram() {
    cout << "\nApakah Anda ingin kembali ke menu utama? (y/n): ";
    cin >> kembali;
                    
    if (kembali != 'y') {
        system("cls");
        cout << "\n" << endl;
        cout << "-- Anda keluar dari program --\n" << endl;
        exit(0);
    } else {
        ulang = true;
        system("cls");
    }
}