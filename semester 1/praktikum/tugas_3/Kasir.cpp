#include <iostream>

using namespace std;

void kembaliMenu();

float hitungDiskon(float total, int diskon); 
float hitungPajak(float total, int pajak); 
float hitungTotalAkhir(float total, float jmlDiskon, float jmlPajak);

bool ulang = false;

int main() {
	int opsiMenu, harga = 0, jumlah = 0, diskon, pajak;
	float jmlDiskon, jmlPajak, total;
	
	do {
		cout << "Kasir" << endl;
		cout << "1. Input Data Barang" << endl;
		cout << "2. Lihat Data" << endl;
		cout << "Pilih menu: ";
		cin >> opsiMenu;
		
		switch(opsiMenu) {
			case 1:
				system("cls");
				ulang = false;

				do {
					cout << "Input Data Barang" << endl;
					cout << "Masukkan Harga Barang(Rp): ";
					cin >> harga;
					cout << "Masukkan Jumlah Barang: ";
					cin >> jumlah;
					cout << "Masukkan Diskon Barang(%): ";
					cin >> diskon;
					cout << "Masukkan Pajak Barang(%): ";
					cin >> pajak;
					
					if (harga < 0 || jumlah < 0 || diskon < 0 || pajak < 0) {
						system("cls");
						ulang = true;
						cout << "Masukkan jumlah yg valid (tdk boleh minus)" << endl;
						cout << "\n";
					} else {
						ulang = false;
					}	
				} while (ulang == true);

				total = harga * jumlah;
				
				kembaliMenu();
				
				break;
			case 2:
				system("cls");
				ulang = false;
				
				cout << "Data Barang" << endl;
				
				if (harga != 0) {
					cout << "\nTotal Sebelum Diskon dan Pajak : Rp. " << total << endl;

					jmlDiskon = hitungDiskon(total, diskon);
					cout << "Jumlah Diskon : Rp. " << jmlDiskon << endl;

					jmlPajak = hitungPajak(total, pajak);
					cout << "Jumlah Pajak : Rp. " << jmlPajak << endl;

					total = hitungTotalAkhir(total, jmlDiskon, jmlPajak);
					cout << "Total Pembayaran Akhir : Rp. " << total << endl;
				} else {
					cout << "\nTolong input data terlebih dahulu..." << endl;
				}
				
				kembaliMenu();
				
				break;
			default:
				system("cls");
				ulang = true;
				cout << "Maaf Menu tidak valid" << endl;
				cout << "\n";
		}
	} while (ulang == true);
	
	return 0;
}


void kembaliMenu() {
	char kembali;

    cout << "\nApakah Anda ingin kembali ke menu? (y/n): ";
	cin >> kembali;
				
    if (kembali == 'y' || kembali == 'Y') {
		ulang = true;
		system("cls");
	} else {
		system("cls");
		cout << "Anda keluar dari program, Terimakasih" << endl;
		exit(0);
	}
}

float hitungDiskon(float total, int diskon) {
	float jmlDiskon;

	jmlDiskon = total*(diskon*1.0/100);

	return jmlDiskon;
}

float hitungPajak(float total, int pajak) {
	float jmlPajak;
	
	jmlPajak = total*(pajak*1.0/100);

	return jmlPajak;
}

float hitungTotalAkhir(float total, float jmlDiskon, float jmlPajak) {
	total = total - jmlDiskon + jmlPajak;

	return total;
}