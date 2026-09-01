#include <iostream>
#include <fstream>

using namespace std;

typedef struct {
    int NoIjasah;
    string JenisIjasah;
    string Nama;
} Ijazah;

bool ulang = false; 

void kembaliUtama();
void tambahData();
void bacaData();
void updateData();
void hapusData();

int main() {
    int opsiMenu;

    Ijazah ijazah[10];
    int jmlIjazah = 0;

    do {
		cout << "MENU :" << endl;
        cout << "=========================" << endl;
        cout << "1. Tambah Data" << endl;
		cout << "2. Baca Data" << endl;
		cout << "3. Update Data" << endl;
		cout << "4. Hapus Data" << endl;
		cout << "5. EXIT" << endl;
        cout << "=========================" << endl;
		cout << "Pilih : ";
		cin >> opsiMenu;

        cin.ignore();

        switch (opsiMenu) {
            case 1:
                system("cls");
                tambahData();
                kembaliUtama();
                break;
            case 2:
                system("cls");
                bacaData();
                kembaliUtama();
                break;
            case 3:
                system("cls");
                updateData();
                kembaliUtama();
                break;
            case 4:
                system("cls");
                hapusData();
                kembaliUtama();
                break;
            case 5:
                ulang = false;
				system("cls");
				cout << "\nKeluar dari program...\n" << endl;
				exit(0);
                break;
            default:
				system("cls");
                cout << "Pilihan menu tidak ada..." << endl;
                cout << "==================================" << endl;

                kembaliUtama();
                break;
        }

    } while (ulang == true);

    return 0;
}

void kembaliUtama() {
	char kembali;

    cout << "\nKembali ke Menu Utama(y/t)? ";
	cin >> kembali;
				
    if (kembali == 'y' || kembali == 'Y') {
		ulang = true;
		system("cls");
	} else {
		system("cls");
		cout << "\nKeluar dari program...\n" << endl;
		exit(0);
	}
}

void tambahData() {
    string input, namaFile;

    cout << "Masukkan nama file : ";
    cin.ignore();
    getline(cin, namaFile);
    namaFile = namaFile + ".txt";

    ofstream file(namaFile, ios::app);

    cout << "Masukkan nama : ";
    getline(cin, input);
    file << input << endl;
    file.close();
}

void bacaData() {
    string data;

    ifstream file("data.txt");
    while (getline(file, data)) {
        cout << data << endl;
    }
    file.close();
}

void updateData() {
    fstream file("data.txt", ios::in);
    fstream fileTemp("temp.txt", ios::out);

    string cari, ganti, text;

    cout << "Nama yg ingin diubah : ";
    cin.ignore();
    getline(cin, cari);

    cout << "Mengganti menjadi : ";
    getline(cin, ganti);

    while (getline(file, text)) {
        if (text == cari) {
            fileTemp << ganti << endl;
        } else {
            fileTemp << text << endl;
        }
    }
    
    file.close();
    fileTemp.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    cout << "Data berhasil diupdate" << endl;
}

void hapusData() {
    fstream file("data.txt", ios::in);
    fstream fileTemp("temp.txt", ios::out);

    string hapus, text;

    cout << "Nama yg ingin dihapus : ";
    getline(cin, hapus);

    while (getline(file, text)) {
        if (text != hapus) {
            fileTemp << text << endl;
        }
    }
    
    file.close();
    fileTemp.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    cout << "Data berhasil dihapus" << endl;
}