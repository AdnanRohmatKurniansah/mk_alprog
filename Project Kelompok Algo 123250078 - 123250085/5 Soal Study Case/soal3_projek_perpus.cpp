#include <iostream>

using namespace std;

void daftarBuku(string buku[5], string statusBuku[5]);
void pinjamBuku(string peminjam[5], int lamaPinjam[5], string buku[5], string statusBuku[5]);
void prosesPinjam(string peminjam[5], int lamaPinjam[5], int opsiBuku, string namaPeminjam, int lama, string statusBuku[5]);
void kembalikanBuku(string peminjam[5], int lamaPinjam[5], string buku[5], string statusBuku[5]);

void kembaliMenu();

bool ulang = false;

int main() {
    string username = "admin";
	string password = "12345";
	string voucher = "abcd";

    string userInput, passInput;
    int opsiMenu;

    string buku[5] = {
        "Laut Bercerita", 
        "Look Back", 
        "Namaku Alam", 
        "Filosofi Teras", 
        "Bandung After Rain"
    };

    string statusBuku[5] = {
        "Tersedia",
        "Tersedia",
        "Tersedia",
        "Tersedia",
        "Tersedia"
    };

    string peminjam[5];
    int lamaPinjam[5];
    int opsiBuku;

    do {
		cout << "=== Login Petugas ===" << endl;
		cout << "Username: ";
		getline(cin, userInput);
		cout << "Password: ";
		getline(cin, passInput);
		
		if (userInput == username && passInput == password) {
			ulang = false;
		} else {
			ulang = true;
			system("cls");
			cout << "Credentials tdk valid...\n" << endl;
		}
	} while (ulang == true);

    system("cls");
	cout << "Login Berhasil...\n" << endl;
	system("pause");
	system("cls");

    do {
		cout << "=== Perpus ===" << endl;
        cout << "1. Daftar Buku" << endl;
		cout << "2. Pinjam Buku" << endl;
		cout << "3. Kembalikan Buku" << endl;
		cout << "4. Keluar" << endl;
		cout << "Pilih Opsi: ";
		cin >> opsiMenu;

        switch (opsiMenu) {
            case 1:
                system("cls");
				ulang = false;

                daftarBuku(buku, statusBuku); 
                kembaliMenu();
                break;
            case 2:
                system("cls");
				ulang = false;

                pinjamBuku(peminjam, lamaPinjam, buku, statusBuku);
                break;
            case 3:
                system("cls");
				ulang = false;

                kembalikanBuku(peminjam, lamaPinjam, buku, statusBuku);
                break;
            case 4:
                ulang = false;
				system("cls");
				cout << "\nTelah keluar dari program...\n" << endl;
				exit(0);
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

void daftarBuku(string buku[5], string statusBuku[5]) {
    cout << "=== Daftar Buku ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i+1 << ". " << buku[i] << " | " << statusBuku[i] << endl;
    }
}

void pinjamBuku(string peminjam[5], int lamaPinjam[5], string buku[5], string statusBuku[5]) {
    string namaPeminjam;
    int opsiBuku, lama;

    do {
        daftarBuku(buku, statusBuku);
        cout << "\n=== Info Peminjam ===" << endl;
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, namaPeminjam);
        cout << "Lama Pinjam (Hari): ";
        cin >> lama;

        if (lama <= 0) {
            ulang = true;
		    system("cls");
            cout << "Input lama pinjam harus valid(tdk minus/0)\n";
        }

        cout << "Pilih buku: ";
        cin >> opsiBuku;

        if (opsiBuku >= 1 && opsiBuku <= 5) {
            ulang = false;
            prosesPinjam(peminjam, lamaPinjam, opsiBuku, namaPeminjam, lama, statusBuku);
        } else {
            ulang = true;
            system("cls");
            cout << "Input sesuai opsi buku yg tersedia...\n";
        }
    } while (ulang == true);

    kembaliMenu();
}

void prosesPinjam(string peminjam[5], int lamaPinjam[5], int opsiBuku, string namaPeminjam, int lama, string statusBuku[5]) {
    if (statusBuku[opsiBuku - 1] == "Dipinjam") {
        cout << "\nBuku sedang dipinjam orang lain..." << endl;
    } else {
        peminjam[opsiBuku - 1] = namaPeminjam;
        lamaPinjam[opsiBuku - 1] = lama;
        statusBuku[opsiBuku - 1] = "Dipinjam";

        cout << "\nBuku berhasil dipinjam..." << endl;
    }
}

void kembalikanBuku(string peminjam[5], int lamaPinjam[5], string buku[5], string statusBuku[5]) {
    int opsiBuku;

    do {
        daftarBuku(buku, statusBuku);
        cout << "\nPilih buku yang ingin dikembalikan: ";
        cin >> opsiBuku;

        if (opsiBuku >= 1 && opsiBuku <= 5) {
            ulang = false;
            if (statusBuku[opsiBuku - 1] == "Tersedia") {
                cout << "\nBuku masih tersedia..." << endl;
            } else {
                cout << "\n=== Detail Pengembalian ===" << endl;
                cout << "Buku        : " << buku[opsiBuku - 1] << endl;
                cout << "Peminjam    : " << peminjam[opsiBuku - 1] << endl;
                cout << "Lama Pinjam : " << lamaPinjam[opsiBuku - 1] << " hari" << endl;

                peminjam[opsiBuku - 1] = "";
                lamaPinjam[opsiBuku - 1] = 0;
                statusBuku[opsiBuku - 1] = "Tersedia";
                cout << "\nBuku berhasil dikembalikan..." << endl;
            }
        } else {
            ulang = true;
            system("cls");
            cout << "Input sesuai opsi buku yg tersedia...\n";
        }
    } while (ulang == true);

    kembaliMenu();
}