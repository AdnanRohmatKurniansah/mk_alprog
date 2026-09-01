#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

typedef struct {
	string namaHewan;
	string keterangan;
	int populasi;
	string habitat; 
} Satwa;

void kembaliUtama(bool *statusUlang);
string spasiKeUnderscore(string teks);
string underscoreKeSpasi(string teks);
string toLowerCase(string teks);
string setKeterangan(int populasi);
void dataTabel(int jmlSatwa, Satwa satwa[]);

int bacaFile(Satwa satwa[], string namaFlle);
void tampilData(int jmlSatwa, Satwa satwa[]);
void tambahData(int *jmlSatwa, Satwa satwa[]);

void searchData(int jmlSatwa, Satwa satwa[]);
void menuSorting(int jmlSatwa, Satwa satwa[]);
void bubbleSort(int jmlSatwa, Satwa satwa[], bool ascending, int pilField);

int main() {
	bool ulang = false ;
	int opsiMenu;
	Satwa satwa[50];
	int jmlSatwa = 0;
	
	jmlSatwa = bacaFile(satwa, "data.txt");
	
	do {
		cout << "Manajemen Data Konservasi" << endl;
		cout << "===================================================================================" << endl;
		cout << "1. Tambah Data" << endl;
		cout << "2. Tampil Data" << endl;
		cout << "3. Sorting Data" << endl;
		cout << "4. Search Data" << endl;
		cout << "5. Keluar Program" << endl;
		cout << "Pilih : ";
		cin >> opsiMenu;
		cin.ignore();
		
		switch(opsiMenu) {
			case 1:
				system("cls");
				tambahData(&jmlSatwa, satwa);
				kembaliUtama(&ulang);
				break;
			case 2:
				system("cls");
				tampilData(jmlSatwa, satwa);
				kembaliUtama(&ulang);
				break;
			case 3:
				system("cls");
				menuSorting(jmlSatwa, satwa);
				kembaliUtama(&ulang);
				break;
			case 4:
				system("cls");
				searchData(jmlSatwa, satwa);
				kembaliUtama(&ulang);
				break;
			case 5:
				ulang = false;
				system("cls");
				cout << "\nKeluar dari program" << endl;
				exit(0);
				break;
			default:
				system("cls");
				cout << "\nPilihan menu tdk valid" << endl;
				cout << "===================================================================================" << endl;
				kembaliUtama(&ulang);
				break;
		}
	} while(ulang == true);
	
	return 0;
}

void kembaliUtama(bool *statusUlang) {
	char kembali;
	cout << "\nKembali ke menu utama (y/t)?";
	cin >> kembali;
	if (kembali == 'y' || kembali == 'Y') {
		*statusUlang = true;
		system("cls");
	} else {
		system("cls");
		cout << "\nKeluar dari program" << endl;
		exit(0);
	} 
}

string spasiKeUnderscore(string teks) {
	for (size_t i = 0; i < teks.length(); i++) {
		if(teks[i] == ' ') {
			teks[i] = '_';
		}
	}
	return teks;
}

string underscoreKeSpasi(string teks) {
	for (size_t i = 0; i < teks.length(); i++) {
		if(teks[i] == '_') {
			teks[i] = ' ';
		}
	}
	return teks;
}

string setKeterangan(int populasi) {
	if(populasi == 0) {
		return "PUNAH";
	} else if(populasi < 100) {
		return "DILINDUNGI";
	} else if(populasi < 1000) {
		return "LANGKA";
	} else if(populasi < 1000000) {
		return "TDK DILINDUNGI";
	} else {
		return "MELIMPAH";
	}
}

string toLowerCase(string teks) {
	for(size_t i = 0; i < teks.length(); i++) {
		teks[i] = tolower(teks[i]);
	}
	return teks;
}

void dataTabel(int jmlSatwa, Satwa satwa[]) {
	cout << "===================================================================================" << endl;
	cout << left << setw(30) << " Nama hewan"
		<< setw(20) << " Keterangan"
		<< setw(10) << " Populasi"
		<< setw(30) << " Habitat" << endl;
	cout << "===================================================================================" << endl;
	for(int i = 0; i < jmlSatwa; i++) {
	cout << left << setw(30) << " " + satwa[i].namaHewan
		<< setw(20) << " " + satwa[i].keterangan
		<< setw(10) << " " + to_string(satwa[i].populasi)
		<< setw(30) << " " + satwa[i].habitat << endl;
	}
	cout << "===================================================================================" << endl;
}

int bacaFile(Satwa satwa[], string namaFile) {
	ifstream file(namaFile);
	int index = 0;
	if(!file) {
		return 0;
	}
	while(file >> satwa[index].namaHewan >> satwa[index].keterangan >> satwa[index].populasi >> satwa[index].habitat) {
		satwa[index].namaHewan = underscoreKeSpasi(satwa[index].namaHewan);
		satwa[index].habitat = underscoreKeSpasi(satwa[index].habitat);
		index++;
	}
	file.close();
	return index;
}

void tampilData(int jmlSatwa, Satwa satwa[]) {
	if(jmlSatwa == 0) {
		cout << "\nData masih kosong" << endl;
		return;
	}
	cout << "Daftar Data Satwa" << endl;
	dataTabel(jmlSatwa, satwa);
}

void tambahData(int *jmlSatwa, Satwa satwa[]) {
	ofstream file("data.txt", ios::app);
	
	cout << "Tambah Data Satwa" << endl;
	cout << "===================================================================================" << endl;
	cout << "Nama hewan : ";
	getline(cin, satwa[*jmlSatwa].namaHewan);
	cout << "Populasi : ";
	cin >> satwa[*jmlSatwa].populasi;
	cin.ignore();
	
	cout << "Habitat : ";
	getline(cin, satwa[*jmlSatwa].habitat);
	
	satwa[*jmlSatwa].keterangan = setKeterangan(satwa[*jmlSatwa].populasi);
	
	file << spasiKeUnderscore(satwa[*jmlSatwa].namaHewan) << " " << satwa[*jmlSatwa].keterangan << satwa[*jmlSatwa].populasi << spasiKeUnderscore(satwa[*jmlSatwa].habitat) << endl;
	
	(*jmlSatwa)++;
	file.close();
	cout << "\nData baru berhasil ditambah\n" << endl;
}

void searchData(int jmlSatwa, Satwa satwa[]) {
	string keyword;
	bool ditemukan = false;
	Satwa hasilSearch[50];
	int jmlHasil = 0;
	
	if(jmlSatwa == 0) {
		cout << "Data masih kosong" << endl;
		return;
	}
	
	cout << "Search Data Satwa" << endl;
	cout << "===================================================================================" << endl;
	cout << "Masukkan keyword : ";
	getline(cin, keyword);
	
	keyword = toLowerCase(keyword);
	
	for (int i = 0; i < jmlSatwa; i++) {
		string nama = toLowerCase(satwa[i].namaHewan);
		string habitat = toLowerCase(satwa[i].habitat);
		
		if(nama.find(keyword) != string::npos || habitat.find(keyword) != string::npos) {
			hasilSearch[jmlHasil] = satwa[i];
			jmlHasil++;
			ditemukan = true;
		}
	}
	
	if(ditemukan == true) {
		cout << "\nHasil Search : " << endl;
		dataTabel(jmlHasil, hasilSearch);
	} else {
		cout << "\nData tdk ditemukan" << endl;
	}
}

void bubbleSort(int jmlSatwa, Satwa satwa[], bool ascending, int pilField) {
	for (int i = 0; i < jmlSatwa - 1; i++) {
		for (int j = 0; j < jmlSatwa - i - 1; j++) {
			bool kondisi = false;
			if (pilField == 1) {
				string a = toLowerCase(satwa[j].namaHewan);
				string b = toLowerCase(satwa[j + 1].namaHewan);
				kondisi = ascending ? (a > b) : (a < b);
			} else if (pilField == 2) {
				string a = toLowerCase(satwa[j].habitat);
				string b = toLowerCase(satwa[j + 1].habitat);
				kondisi = ascending ? (a > b) : (a < b);
			} else if (pilField == 3) {
				kondisi = ascending ? (satwa[j].populasi > satwa[j + 1].populasi) : (satwa[j].populasi < satwa[j + 1].populasi);
			}
			
			if(kondisi) {
				swap(satwa[j], satwa[j+1]);
			} 
		}
	}
}

void menuSorting(int jmlSatwa, Satwa satwa[]) {
	Satwa tempData[50];
	int pilUrut, pilField;
	bool ascending;
	
	for (int i = 0; i < jmlSatwa; i++) {
		tempData[i] = satwa[i];
	}
	
	if(jmlSatwa == 0) {
		cout << "Data masih kosong" << endl;
		return;
	}
	
	do { 
		system("cls");
		cout << "Menu Sorting Data" << endl;
		cout << "===================================================================================" << endl;
		cout << "1. Berdasarkan Nama hewan" << endl;
		cout << "2. Berdasarkan Habitat" << endl;
		cout << "3. Berdasarkan Populasi" << endl;
		cout << "===================================================================================" << endl;
		cout << "Pilih field : ";
		cin >> pilField;
		
		if (pilField < 1 || pilField > 3) {
			cout << "Pilihan anda tdk valid" << endl;
			system("pause");
		}
	} while(pilField < 1 || pilField > 3);
	
	do { 
		system("cls");
		cout << "Arah Sorting Data" << endl;
		cout << "===================================================================================" << endl;
		cout << "1. Ascending" << endl;
		cout << "2. Descending" << endl;
		cout << "===================================================================================" << endl;
		cout << "Pilih arah : ";
		cin >> pilUrut;
		
		if (pilUrut < 1 || pilUrut > 2) {
			cout << "Pilihan anda tdk valid" << endl;
			system("pause");
		}
	} while(pilUrut < 1 || pilUrut > 2);
	
	ascending = (pilUrut == 1);
	
	bubbleSort(jmlSatwa, tempData, ascending, pilField);
	
	cout << "\nData berhasil diurutkan" << endl;
	dataTabel(jmlSatwa, tempData);
}


