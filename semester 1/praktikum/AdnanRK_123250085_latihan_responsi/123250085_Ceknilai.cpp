#include <iostream>

using namespace std;

bool ulang = false;

void authenticate();
void inputNilai(int jmlInput, string mahasiswa[50], int nilai[50]);
void kembaliMenu();
void tampilNilai(int jmlInput, string mahasiswa[50], int nilai[50]);
float hitungRata(int jmlInput, int nilai[50]);
void cekTertinggi(int jmlInput, string mahasiswa[50], int nilai[50]);
void cekTerendah(int jmlInput, string mahasiswa[50], int nilai[50]);

int main() {
	int opsiMenu, jmlInput;
	int jmlNilai = 0;
	
	string mahasiswa[50];
	int nilai[50];
	float rata;
	
	do {
		cout << "==========================" << endl;
		cout << "|      Nilai Mahasiswa   |" << endl;
		cout << "==========================" << endl;
		cout << "1. Tambah Nilai" << endl;
		cout << "2. Lihat Nilai" << endl;
		cout << "3. Lihat Rata-rata" << endl;
		cout << "4. Lihat Tertinggi" << endl;
		cout << "5. Lihat Terendah" << endl;
		cout << "6. Keluar Program" << endl;
		cout << "==========================" << endl;
		cout << "Pilih Menu: ";
		cin >> opsiMenu;
		
		switch(opsiMenu) {
			case 1:
				system("cls");
				ulang = false;
				
				cin.ignore();
				
				authenticate();
				system("pause");
				system("cls");	
				
				do {
					cout << "==========================" << endl;
					cout << "|        Input Nilai     |" << endl;
					cout << "==========================" << endl;
					cout << "Banyak nilai saat ini - " << jmlNilai << endl;
					cout << "Max input nilai - 50" << endl;
					cout << "==========================" << endl;
					cout << "Jumlah input : ";
					cin >> jmlInput;
					
					if(jmlInput <= 0 || jmlInput > 50) {
						ulang = true;
						system("cls");
						cout << "Jml input tdk boleh <= 0 dan > 50...\n" << endl;
					} else {
						ulang = false;
						system("cls");
						
						inputNilai(jmlInput, mahasiswa, nilai);
					}
				} while(ulang == true);
				
				kembaliMenu();
				
				break;
			case 2:
				system("cls");
				ulang = false;
				if(jmlInput == 0) {
					system("cls");
					ulang = true;
					cout << "Tolong input data dulu...\n" << endl;
				} else {
					tampilNilai(jmlInput, mahasiswa, nilai);
				
					kembaliMenu();
				}
				break;
			case 3:
				system("cls");
				ulang = false;
				if(jmlInput == 0) {
					system("cls");
					ulang = true;
					cout << "Tolong input data dulu...\n" << endl;
				} else {
					rata = hitungRata(jmlInput, nilai);
					cout << "==========================" << endl;
					cout << "Nilai Rata-rata: " << rata << endl;
				
					kembaliMenu();
				}
				
				break;
			case 4:
				system("cls");
				ulang = false;
				if(jmlInput == 0) {
					system("cls");
					ulang = true;
					cout << "Tolong input data dulu...\n" << endl;
				} else {
					cout << "==========================" << endl;
					cout << "Nilai Tertinggi" << endl;
					cekTertinggi(jmlInput, mahasiswa, nilai);
				
					kembaliMenu();
				}
				
				break;
			case 5:
				system("cls");
				ulang = false;
				if(jmlInput == 0) {
					system("cls");
					ulang = true;
					cout << "Tolong input data dulu...\n" << endl;
				} else {
					cout << "==========================" << endl;
					cout << "Nilai Terendah" << endl;
					cekTerendah(jmlInput, mahasiswa, nilai);
				
					kembaliMenu();
				}
				
				break;
			case 6:
				ulang = false;
				system("cls");
				cout << "\nKeluar dari program..." << endl;
				exit(0);
				
				break;
			default:	
				system("cls");
				ulang = true;
				cout << "Pilih menu yg tersedia..." << endl;
				cout << "\n";
		}
		
	} while(ulang == true);
		
	return 0;
}

void authenticate() {
	int cobaLogin = 0;
	string username = "admin";
	string password = "12345";

	string userInput, passInput;
	bool successLog;
	
	do {
		cobaLogin = cobaLogin + 1;
		cout << "==========================" << endl;
		cout << "|  Percobaan Login Ke-" << cobaLogin <<"  |" << endl;
		cout << "==========================" << endl;
		cout << "Username : ";
		getline(cin, userInput);
		cout << "Password : ";
		getline(cin, passInput);
		cout << "==========================" << endl;
					
		if(userInput == username && passInput == password) {
			successLog = true;
			system("cls");
			
			cout << "Login berhasil...\n" << endl;
		} else {
			successLog = false;
			system("cls");
			
			if(cobaLogin == 3) {
				cout << "Kesempatan login anda habis..." << endl;
				cout << "Keluar dari Program" << endl;
				exit(0);
			} else {
				cout << "Kesempatan login tersisa " << (3 - cobaLogin) << "...\n" << endl;
			}
		}	 
	} while(successLog == false);
}

void inputNilai(int jmlInput, string mahasiswa[50], int nilai[50]) {
	cin.ignore();
	for(int i = 0; i < jmlInput; i++) {
		cout << "==========================" << endl;
		cout << "Input nilai ke-" << i+1 << endl;
		cout << "Nama : ";
		getline(cin, mahasiswa[i]);
		cout << "Nilai : ";
		cin >> nilai[i];
		cin.ignore();
	} 
	
	cout << "\nInput nilai selesai..." << endl;
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
		cout << "\nKeluar dari Program..." << endl;
		exit(0);
	}
}

void tampilNilai(int jmlInput, string mahasiswa[50], int nilai[50]) {
	cout << "================================" << endl;
	cout << "|Nama           |   Nilai      |" << endl;
	cout << "================================" << endl;
	for(int i = 0; i < jmlInput; i++) {
		cout << mahasiswa[i] << "            " << nilai[i] << endl;
	}
}

float hitungRata(int jmlInput, int nilai[50]) {
	int jmlTotal = 0;
	float rata;
	
	for(int i = 0; i < jmlInput; i++) {
		jmlTotal = jmlTotal + nilai[i];
	}
	
	rata = (jmlTotal*1.0)/jmlInput;
	
	return rata;
}

void cekTertinggi(int jmlInput, string mahasiswa[50], int nilai[50]) {
	int tertinggi;
	
	tertinggi = nilai[0];
	
	for(int i = 0; i < jmlInput; i++) {
		if (tertinggi < nilai[i]) {
			tertinggi = nilai[i];
		}
	}
	
	for(int i = 0; i < jmlInput; i++) {
		if (nilai[i] == tertinggi) {
			cout << "Nama : " << mahasiswa[i] << endl;
			cout << "Nilai : " << nilai[i] << endl;
		}
	}
}

void cekTerendah(int jmlInput, string mahasiswa[50], int nilai[50]) {
	int terendah;
	
	terendah = nilai[0];
	
	for(int i = 0; i < jmlInput; i++) {
		if (terendah > nilai[i]) {
			terendah = nilai[i];
		}
	}
	
	for(int i = 0; i < jmlInput; i++) {
		if (nilai[i] == terendah) {
			cout << "Nama : " << mahasiswa[i] << endl;
			cout << "Nilai : " << nilai[i] << endl;
		}
	}
}
