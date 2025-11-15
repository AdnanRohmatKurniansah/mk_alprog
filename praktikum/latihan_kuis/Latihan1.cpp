#include <iostream>

using namespace std;

int main() {
	string username = "admin";
	string password = "12345";
	string voucher = "abcd";
		
	string userInput, passInput, voucherInput;
	int opsiMenu, pilihProduk, jml_produk, harga_produk, subTotal;
	float diskon;
	int chance = 3;
	bool succesLog = false;
	bool ulang = false;
	
	char kembali, punyaVoucher, cobaLagi;
	
	do {
		cout << "===============" << endl;
		cout << "|   Login     |" << endl;
		cout << "===============" << endl;
		
		cout << "Username: ";
		getline(cin, userInput);
		
		cout << "Password: ";
		getline(cin, passInput);
		
		if (userInput == username && passInput == password) {
			succesLog = true;
		} else {
			succesLog = false;
			if (chance > 1) {
				chance = chance - 1;
				cout << "Username tidak ditemukan" << endl;
				cout << "Tersisa " << chance << " kali kesempatan" << endl;
				cout << "\n";
				system("pause");
				system("cls");
			} else {
				cout << "Username tidak ditemukan" << endl;
				cout << "Kesempatan habis. Anda tidak bisa masuk" << endl;
				exit(0);
			}
		}
	} while (succesLog == false);
	
	system("cls");
	cout << "Login Berhasil" << endl;
	system("pause");
	system("cls");
	
	do {
		cout << "==============" << endl;
		cout << "| Menu Utama |" << endl;
		cout << "==============" << endl;
		cout << "1. Cek Daftar Produk" << endl;
		cout << "2. Beli Produk" << endl;
		cout << "3. Keluar" << endl;
		cout << "Pilih opsi: ";
		cin >> opsiMenu;
		
		switch(opsiMenu) {
			case 1:
				system("cls");
				ulang = false;
				cout << "=================" << endl;
				cout << "|  Daftar Menu  |" << endl;
				cout << "=================" << endl;
				cout << "1. Smartphone X : Rp5.000.000" << endl;
				cout << "2. Laptop Y : Rp10.000.000" << endl;
				cout << "3. Tablet Z : Rp3.500.000" << endl;
				cout << "4. Headphone A : Rp750.000" << endl;
				cout << "5. Smartwatch B : Rp1.200.000" << endl;
				
				system("pause");
				
				cout << "\n";
				
				cout << "Apakah Anda ingin kembali ke menu utama? (y/n): ";
				cin >> kembali;
				
				if (kembali != 'y') {
					system("cls");
					cout << "Anda keluar dari program" << endl;
					exit(0);
				} else {
					ulang = true;
					system("cls");
					continue;
				}
				
				break;
			case 2:
				system("cls");
				ulang = false;
				
				do {
					cout << "=================" << endl;
					cout << "|  Beli Produk  |" << endl;
					cout << "=================" << endl;
					cout << "Daftar Produk:" << endl;
					cout << "1. Smartphone X" << endl;
					cout << "2. Laptop Y" << endl;
					cout << "3. Tablet Z" << endl;
					cout << "4. Headphone A" << endl;
					cout << "5. Smartwatch B" << endl;
					cout << "\n";
					cout << "Produk yang mau dibeli: ";
					cin >> pilihProduk;
					
					switch (pilihProduk) {
						case 1:
							harga_produk = 5000000;
							break;
						case 2:
							harga_produk = 10000000;
						case 3:
							harga_produk = 3500000;
						case 4:
							harga_produk = 750000;
							break;
						case 5:
							harga_produk = 1200000;
							break;
						default:
							system("cls");
							ulang = true;
							cout << "Pilih produk sesuai opsi yang ada" << endl;
							cout << "\n";
					}		
				} while (ulang == true);
				
				do {
					cout << "Jumlah produk: ";
					cin >> jml_produk;
					
					if (jml_produk > 0) {
						ulang = false;
						subTotal = harga_produk * jml_produk;
					} else {
						ulang = true;
						system("cls");
						cout << "Input tidak boleh minus" << endl;
						cout << endl;
					}
				} while (ulang == true);
				
				
				cout << "Apakah Anda memiliki voucher? (y/t): ";
				cin >> punyaVoucher; 
				
				do {
					if (punyaVoucher == 'y') {
						cout << "Masukkan kode voucher: ";
						cin >> voucherInput;
						
						if (voucherInput == voucher) {
							if (subTotal >= 15000000) {
								diskon = 0.30;
								cout << "\n--- Selamat anda mendapatkan diskon 30% ----" << endl;
							} else {
								diskon = 0.10;
								cout << "\n--- Selamat anda mendapatkan diskon 10% ----" << endl;
							}
							
							cout << "\n";
							ulang = false;
						} else {
							cout << "\n--- Kode yang anda masukkan salah ---" << endl;
							cout << "\nApakah Anda ingin memasukkan ulang kode voucher? (y/n): ";
							cin >> cobaLagi;
							
							if (cobaLagi == 'y') {
								ulang = true;
								cout << "\n";
								continue;
							} else {
								ulang = false;
							}
							
							if (subTotal >= 15000000) {
								diskon = 0.20;
								cout << "\n--- Selamat anda mendapatkan diskon 20% ----" << endl;
							} else {
								diskon = 0;
							}
						}
					} else {
						if (subTotal >= 15000000) {
							diskon = 0.20;
							cout << "\n--- Selamat anda mendapatkan diskon 20% ----" << endl;
						} else {
							diskon = 0;
						}
						
					}
				} while (ulang == true);
				
				cout << "========================" << endl;
				cout << "|    Nota Pembelian    |" << endl;
				cout << "========================" << endl;
				cout << "Username: " << userInput << endl;
				cout << "Produk: " << pilihProduk << " x " << jml_produk << endl;
				cout << "Total Harga sebelum diskon: " << subTotal << endl;
				
				break;
			case 3:
				ulang = false;
				system("cls");
				cout << "\nTerima Kasih, program selesai." << endl;
				exit(0);
				break;
			default:
				system("cls");
				ulang = true;
				cout << "Pilihan tidak valid" << endl;
				cout << "\n";
		}
	} while (ulang == true);
	
	return 0;
}
