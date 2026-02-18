#include <iostream>

using namespace std;

bool ulang = false;

void kembaliMenu();
void tampilPetaKursi(char petaKursi[5][8], char labelKursi[5]);
void pesanTiket(char petaKursi[5][8], string namaPemesan[5][8]);
void cariPelanggan(char petaKursi[5][8], string namaPemesan[5][8], char labelKursi[5]);
void cekLaporan(char petaKursi[5][8]);

int main() {
	char petaKursi[5][8] = {
		{'O','O','O','O','O','O','O','O'},
		{'O','O','X','X','O','O','O','O'},
		{'O','O','O','O','O','O','O','O'},
		{'O','O','O','O','O','O','O','O'},
		{'O','O','O','O','X','O','O','O'}
	};
	char labelKursi[5] = {'A', 'B', 'C', 'D', 'E'};
	
	string namaPemesan[5][8] = {
		{"-","-","-","-","-","-","-"},
		{"-","-","-","-","-","-","-"},
		{"-","-","-","-","-","-","-"},
		{"-","-","-","-","-","-","-"},
		{"-","-","-","-","-","-","-"}
	};
	
	int opsiMenu;
	
	do {
		cout << "=== Bioskop ===" << endl;
		cout << "1. Tampil Peta Kursi" << endl;
		cout << "2. Pesan Tiket" << endl;
		cout << "3. Cari Pelanggan" << endl;
		cout << "4. Laporan Penjualan Hari Ini" << endl;
		cout << "5. Keluar" << endl;
		cout << "Opsi menu: ";
		cin >> opsiMenu;
		
		switch(opsiMenu) {
			case 1:
				ulang = false;
				system("cls");
				
				tampilPetaKursi(petaKursi, labelKursi);
				kembaliMenu();
				
				break;
			case 2:
				ulang = false;
				system("cls");
				
				pesanTiket(petaKursi, namaPemesan);
				kembaliMenu();
				
				break;
			case 3:
				ulang = false;
				system("cls");
				
				cariPelanggan(petaKursi, namaPemesan, labelKursi);
				kembaliMenu();
				
				break;
			case 4:
				ulang = false;
				system("cls");
				
				cekLaporan(petaKursi);
				kembaliMenu();
				
				break;
			case 5: 
				ulang = false;
				system("cls");
				cout << "Terimakasih. Sistem loket ditutup..." << endl;
				exit(0);
				break;
			default:
				ulang = true;
				system("cls");
				cout << "Pilih menu yg tersedia...\n" << endl;
		}	
	} while(ulang == true);
	
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
		cout << "\nTerimakasih. Sistem loket ditutup..." << endl;
		exit(0);
	}
}

void tampilPetaKursi(char petaKursi[5][8], char labelKursi[5]) {
	cout << "=== Peta Kursi ===" << endl;
	cout << "  1 2 3 4 5 6 7 8" << endl;
    for(int i = 0; i < 5; i++) {
        cout << labelKursi[i] << " [ ";
        for(int j = 0; j < 8; j++) {
            cout << petaKursi[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void pesanTiket(char petaKursi[5][8], string namaPemesan[5][8]) {
	string namaPemesanan;
	char pilihBaris;
	int pilihKolom, baris, kolom;
	
	do {
		cin.ignore();
		cout << "=== Pesan Tiket ===" << endl;
		cout << "Masukkan Nama Pelanggan: ";
		getline(cin, namaPemesanan);
		cout << "Pilih baris (A-E): ";
		cin >> pilihBaris;
		cout << "Pilih kolom (1-8): ";
		cin >> pilihKolom;
		
		baris = pilihBaris - 'A';
		kolom = pilihKolom - 1;
		
		if (baris < 0 || baris > 5 || kolom < 0 || kolom > 8) {
			ulang = true;
			system("cls");
			cout << "Posisi kursi tidak valid...\n" << endl;
		} else {
			if (petaKursi[baris][kolom] == 'X') {
				ulang = true;
				system("cls");
				cout << "Kursi sudah dipesan...\n" << endl;
			} else {
				ulang = false;
				system("cls");
				petaKursi[baris][kolom] = 'X';
				namaPemesan[baris][kolom] = namaPemesanan;

				cout << "Tiket berhasil dipesan...\n" << endl;
				cout << "Kursi: " << pilihBaris << pilihKolom << endl;
				cout << "Atas nama: " << namaPemesanan << endl;
			}
		}
	} while(ulang == true);
}

void cariPelanggan(char petaKursi[5][8], string namaPemesan[5][8], char labelKursi[5]) {
	string inputNama;
	
	cin.ignore();
	cout << "=== Cari Pelanggan ===" << endl;
	cout << "Masukkan Nama: ";
	getline(cin, inputNama);
	
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 8; j++) {
			if(inputNama == namaPemesan[i][j]) {
				system("cls");
				cout << "Pelanggan '" << namaPemesan[i][j] << "' ditemukan di kursi " << labelKursi[i] << (j + 1) << "\n" << endl;
                return;
			}
		}
	}
	
	system("cls");
	cout << "Pelanggan tidak ditemukan....\n" << endl;
}

void cekLaporan(char petaKursi[5][8]) {
	int hargaTiket = 50000;
	int totalPendapatan = 0;
	int jmlTerjual = 0, jmlSisa = 0;
	
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 8; j++) {
			if(petaKursi[i][j] == 'X') {
				jmlTerjual = jmlTerjual + 1;
			} else {
				jmlSisa = jmlSisa + 1;
			}
		}
	} 
	
	totalPendapatan = jmlTerjual * hargaTiket;
	
	cout << "=== Laporan Penjualan ===" << endl;
	cout << "Tiket Terjual: " << jmlTerjual << endl;
	cout << "Sisa Tiket: " << jmlSisa << endl;
	cout << "Total Pendapatan: Rp. " << totalPendapatan << endl;
}
