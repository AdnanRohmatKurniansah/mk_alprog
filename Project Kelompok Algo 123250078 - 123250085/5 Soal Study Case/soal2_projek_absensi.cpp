#include <iostream>

using namespace std;

void kembaliMenu();
void mulaiAbsen(int jumlahMurid, string siswa[45], char absen[45]);
void tampilDaftar(int jumlahMurid, string siswa[45], char absen[45]);
void filterStatus(int jumlahMurid, string siswa[45], char absen[45], char statusLow, char statusUp);

bool ulang = false;

int main() {
    string username = "admin";
	string password = "12345";
		
    string siswa[45];
    char absen[45];
	string userInput, passInput;
    int opsiMenu, jumlahMurid;

    do {
		cout << "=== Login ===" << endl;
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
		cout << "=== Absensi ===" << endl;
        cout << "1. Mulai Absensi" << endl;
		cout << "2. Lihat Daftar Hadir" << endl;
		cout << "3. Keluar" << endl;
		cout << "Pilih Menu: ";
		cin >> opsiMenu;

        switch (opsiMenu) {
            case 1:
                system("cls");
				ulang = false;

                cout << "Masukkan Jumlah Murid (Max 45/Kelas): ";
                cin >> jumlahMurid;

                system("cls");
                
                mulaiAbsen(jumlahMurid, siswa, absen);

                break;
            case 2:
                system("cls");
				ulang = false;

                if (jumlahMurid == 0) {
                    cout << "Belum ada data, Input terlebih dulu...\n" << endl;
                    ulang = true;
                } else {
                    tampilDaftar(jumlahMurid, siswa, absen);
                }

                break;
            case 3:
                ulang = false;
				system("cls");
				cout << "\nAnda keluar dari program, Terimakasih...\n" << endl;
				exit(0);
                break;
            default:
                ulang = true;
                system("cls");
                cout << "Input menu sesuai opsi...\n" << endl;
                break;
        }

    } while (ulang == true);
    

    return 0;
}

void kembaliMenu() {
	char kembali;

    cout << "\nApakah Anda ingin kembali ke menu utama? (Y/N): ";
	cin >> kembali;
				
    if (kembali == 'y' || kembali == 'Y') {
		ulang = true;
		system("cls");
	} else {
		system("cls");
		cout << "\nAnda keluar dari program, Terimakasih...\n" << endl;
		exit(0);
	}
}

void mulaiAbsen(int jumlahMurid, string siswa[45], char absen[45]) {
    char tampil;

	cout << "=== Proses Input ===" << endl;
    cout << "Hadir(H) | Sakit(S) | Izin(I) | Alpha(A)" << endl;

    for (int i = 0; i < jumlahMurid; i++) {
        cout << i+1 << ". Nama : ";
        cin.ignore();
        getline(cin, siswa[i]);
        cout << "  Absen (H/S/I/A): ";
        cin >> absen[i];
    }

    system("cls");

    cout << "\nInput Telah Selesai..." << endl;

    cout << "\nTampilkan daftar hadir (Y/N): ";
	cin >> tampil;

    if (tampil == 'y' || tampil == 'Y') {
		tampilDaftar(jumlahMurid, siswa, absen);
	} else {
        kembaliMenu();
    }
}

void tampilDaftar(int jumlahMurid, string siswa[45], char absen[45]) {
    int opsiTampil;

    do {
        cout << "Status Daftar Hadir:" << endl;
        cout << "1. Semua" << endl;
        cout << "2. Hadir" << endl;
        cout << "3. Sakit" << endl;
        cout << "4. Izin" << endl;
        cout << "5. Alpha" << endl;
        cout << "Pilih : ";
        cin >> opsiTampil;

        switch (opsiTampil) {
            case 1:
                system("cls");
                cout << "=== Daftar Absen ===" << endl;
                for (int i = 0; i < jumlahMurid; i++) {
                    cout << i+1 << ". " << siswa[i] << " => " << absen[i] << endl;
                }
                break;
            case 2:
                system("cls");
                filterStatus(jumlahMurid, siswa, absen, 'h', 'H');
                break;
            case 3:
                system("cls");
                filterStatus(jumlahMurid, siswa, absen, 's', 'S');
                break;
            case 4:
                system("cls");
                filterStatus(jumlahMurid, siswa, absen, 'i', 'I');
                break;
            case 5:
                system("cls");
                filterStatus(jumlahMurid, siswa, absen, 'a', 'A');
                break;
            default:
                ulang = true;
                system("cls");
                cout << "Input menu sesuai opsi...\n" << endl;
                break;
        }
    } while (ulang == true);

    kembaliMenu();
}

void filterStatus(int jumlahMurid, string siswa[45], char absen[45], char statusLow, char statusUp) {
    bool adaData = false; 

    cout << "=== Daftar Absen (" << statusUp << ") ===" << endl;
    for (int i = 0; i < jumlahMurid; i++) {
        if (absen[i] == statusLow || absen[i] == statusUp) {
            cout << i+1 << ". " << siswa[i] << " => " << absen[i] << endl;
            adaData = true;
        }
    }
    if (adaData == false) {
        cout << "Tidak ada data...\n";
    }
}
