#include <iostream>

using namespace std;

int main() {
	string nama, member, barang;
	int umur, saldo, cash, menu, jml_barang;
	float diskon, harga_barang, total_belanja;
	char mauKeluar;
	bool ulang = false;
	
    cout << "=========================" << endl;
    cout << "|       Input Data      |" << endl;
    cout << "=========================" << endl;
    
    cout << "Masukkan Nama : ";
    getline(cin, nama);
    cout << "Masukkan Umur : ";
    cin >> umur;
	cout << "\n";
	
	cin.ignore();
	
	cout << "Daftar Member" << endl;
	cout << "1. Immortal" << endl;
	cout << "2. Glory" << endl;
	cout << "3. Honor" << endl;
	cout << "4. Warrior - Mythic" << endl;
	
	cout << "Masukkan Nama Member bukan Nomor : ";
	getline(cin, member);
	
	cout << "\n";
	
	do {
		cout << "Masukkan Saldo : Rp. ";
		cin >> saldo;
		cout << "Masukkan Cash : Rp. ";
		cin >> cash;
		
		if (saldo < 0 || cash < 0) {
			ulang = true;
			cout << "\n--- Masukkan nominal yg valid (tdk boleh minus) ---" << endl;
			cout << "\n";
		} else {
			ulang = false;
		}	
	} while (ulang == true);
	
	system("cls");
	
	do {
		cout << "==========================" << endl;
		cout << "|       Toko Dingin      |" << endl;
		cout << "==========================" << endl;
		cout << "1. Sikat Gigi - 10.000" << endl;
		cout << "2. Pasta Gigi - 12.000" << endl;
		cout << "3. Sabun Mandi - 20.000" << endl;
		cout << "4. Shampoo Motor - 25.000" << endl;
		cout << "5. Cek Uang Anda" << endl;
		cout << "\n-------------------------" << endl;
		cout << "0. Keluar" << endl;
		cout << "Pilih Menu : ";
		cin >> menu;
		
		switch(menu) {
			case 0:
				exit(0);
				break;
			case 1:
				barang = "Sikat Gigi";
				harga_barang = 10000;
				break;
			case 2:
				barang = "Pasta Gigi";
				harga_barang = 12000;
				break;
			case 3:
				barang = "Sabun Mandi";
				harga_barang = 20000;
				break;
			case 4:
				barang = "Shampoo Motor";
				harga_barang = 25000;
				break;
			case 5:
				cout << "\n========================" << endl;
				cout << "|       Uang Anda      |" << endl;
				cout << "========================" << endl;
				cout << "Nama: " << nama << endl;
				cout << "Umur: " << umur << endl;
				cout << "Member: " << member << endl;
				cout << "Saldo: " << saldo << endl;
				cout << "Cash: " << cash << endl;
				cout << "\n";
				cout << "Apakah anda ingin keluar?(y/n) : ";
				cin >> mauKeluar;
				
				if (mauKeluar == 'y') {
					exit(0);
				} else {
					system("cls");
					ulang = true;
					continue;
				}
				
				break;
			default: 
				ulang = true;
				system("cls");
				cout << "Input pilihan menu dengan benar!" << endl;
				cout << "\n";
				continue;
		}	
		
		cout << "=========================" << endl;
		cout << "|     " << barang << "  |" << endl;
		cout << "=========================" << endl;
		
		do {
			cout << "Berapa " << barang << " yang ingin anda beli ? : ";
			cin >> jml_barang;
			
			if (jml_barang < 1) {
				cout << "\n--- Masukkan jumlah yg valid (tdk boleh minus / 0) --- \n" << endl;
				ulang = true;
			} else {
				ulang = false;
			}
		} while(ulang == true);
		 
		if (saldo != 0) {
			if (member == "Immortal") {
				diskon = 0.15;	
				cout << "\nDiskon 15% karena member Immortal" << endl;
			} else if (member == "Glory") {
				diskon = 0.10;
				cout << "\nDiskon 10% karena member Glory" << endl;
			} else if (member == "Honor") {
				diskon = 0.05;
				cout << "\nDiskon 5% karena member Honor" << endl;
			} else {
				diskon = 0;
			}
		} else {
			cout << "\n---------------------------" << endl;
			cout << "Saldo anda 0" << endl;
			cout << "Pembayaran dengan metode Cash" << endl;
			cout << "Anda tidak akan dapat promo" << endl;
			cout << "---------------------------" << endl;
		}
		
		total_belanja = (harga_barang - (harga_barang * diskon)) * jml_barang;
		
		cout << "\nTotal Belanja adalah " << total_belanja << endl;
		
		if (saldo != 0) {
			if (total_belanja > saldo) {
				cout << "Saldo anda : Saldo tidak cukup" << endl;
			} else {
				saldo = saldo - total_belanja;
				cout << "Saldo anda : " << saldo << endl;
			}
		} else {
			if (total_belanja > cash) {
				cout << "Cash anda : Cash tidak cukup" << endl;
			} else {
				cash = cash - total_belanja;
				cout << "Cash anda : " << cash << endl;
			}
		}
		
		cout << "Apakah anda ingin keluar?(y/n) : ";
		cin >> mauKeluar;
		
		if (mauKeluar == 'y') {
			exit(0);
		} else {
			system("cls");
			ulang = true;
		}
	} while (ulang == true);
	
	
    return 0;
}

