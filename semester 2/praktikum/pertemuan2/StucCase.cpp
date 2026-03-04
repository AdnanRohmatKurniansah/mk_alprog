#include <iostream>

using namespace std;

struct Kontak {
    string nama;
    string no_hp;
};

struct PhoneBook {
    string nama_pemilik;
    string no_hp;
    string alamat;
    Kontak kt[2];
};

void kembaliMenu();

bool ulang = false;

int main() {
    PhoneBook pb[3];
    int pilMenu;
   
    do {
        cout << "== Phone Book ==" << endl;
        cout << "1. Lihat Phone Book" << endl;
        cout << "2. Tambah Phone Book" << endl;
        cout << "Pilih Menu: ";
        cin >> pilMenu;

        cin.ignore();

        switch (pilMenu) {
            case 1:
                system("cls");
                ulang = false;

                cout << "== Lihat Phone Book ==" << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << "Nama Pemilik: " << pb[i].nama_pemilik << endl;
                    cout << "No HP: " << pb[i].no_hp << endl;
                    cout << "Alamat: " << pb[i].alamat << endl;
                    cout << "---------------" << endl;
                    for (int j = 0; j < 2; j++)
                    {
                        cout << "Nama Kontak ke-" << j+1 << ": " << pb[i].kt[j].nama << endl;
                        cout << "No HP Kontak: " << pb[i].kt[j].no_hp << endl;
                        cout << endl;
                    }
                }

                kembaliMenu();
                break;
            case 2:
                system("cls");
                ulang = false;

                cout << "== Tambah Phone Book ==" << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << "Phone Book ke-" << i+1 << endl;
                    cout << "---------------" << endl;
                    cout << "Nama Pemilik : ";
                    getline(cin, pb[i].nama_pemilik);
                    cout << "No Hp: ";
                    getline(cin, pb[i].no_hp);
                    cout << "Alamat: ";
                    getline(cin, pb[i].alamat);
                    for (int j = 0; j < 2; j++)
                    {
                        cout << "---------------" << endl;
                        cout << "Kontak ke-" << j+1 << endl;
                        cout << "Nama Kontak: ";
                        getline(cin, pb[i].kt[j].nama);
                        cout << "No HP Kontak: ";
                        getline(cin, pb[i].kt[j].no_hp);
                    }
                    cout << endl;
                }

                kembaliMenu();
                break;
            default:
                ulang = true;
                system("cls");
                cout << "Menu tdk tersedia, Ulangi...\n" << endl;
                break;
        }
    } while (ulang == true);

    return 0;
}


void kembaliMenu() {
	char kembali;

    cout << "\nKembali ke menu utama? (Y/N): ";
	cin >> kembali;
				
    if (kembali == 'y' || kembali == 'Y') {
		ulang = true;
		system("cls");
	} else {
		system("cls");
		cout << "\nTelah keluar dari program...\n" << endl;
		exit(0);
	}
}