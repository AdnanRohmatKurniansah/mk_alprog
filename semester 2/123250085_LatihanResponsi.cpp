#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

typedef struct {
    string kodeBuku;   
    string judulBuku;
    string kategori;
    int stok;
    string penerbit;
} Buku;

void kembaliUtama(bool *statusUlang);

string spasiKeUnderscore(string teks);
string underscoreKeSpasi(string teks);
string toLowerCase(string teks);
// string toUpperCase(string teks);
string setKategori(int stok);

void dataTabel(int jmlBuku, Buku buku[]);
int bacaFile(Buku buku[], string namaFile); 
void simpanData(int jmlBuku, Buku buku[]); 
void tambahData(int *jmlBuku, Buku buku[]); 
void tampilData(int jmlBuku, Buku buku[]);
void updateData(int jmlBuku, Buku buku[]);
void hapusData(int *jmlBuku, Buku buku[]);

void searchData(int jmlBuku, Buku buku[]);
void menuSorting(int jmlBuku, Buku buku[]);

void bubbleSort(int jmlBuku, Buku buku[], bool ascending, int pilField);
void selectionSort(int jmlBuku, Buku buku[], bool ascending, int pilField);
void insertionSort(int jmlBuku, Buku buku[], bool ascending, int pilField);

int main() {
    bool ulang = false; 
    int opsiMenu;

    Buku buku[50];
    int jmlBuku = 0;

    jmlBuku = bacaFile(buku, "data.txt");

    do {
        cout << "Sistem Manajemen Buku :" << endl;
        cout << "=========================" << endl;
        cout << "1. Input Data Buku" << endl;
		cout << "2. Tampilkan Data Buku" << endl;
        cout << "3. Sorting Data Buku" << endl;
		cout << "4. Search Data" << endl;
		cout << "5. Update Data Buku" << endl;
		cout << "6. Hapus Data Buku" << endl;
		cout << "7. Keluar Program" << endl;
        cout << "=========================" << endl;
		cout << "Pilih : ";
		cin >> opsiMenu;

        cin.ignore();

        switch (opsiMenu) {
            case 1:
                system("cls");
                tambahData(&jmlBuku, buku);
                kembaliUtama(&ulang);
                break;  
            case 2:
                system("cls");
                tampilData(jmlBuku, buku);
                kembaliUtama(&ulang);
                break;
            case 3:
                system("cls");
                menuSorting(jmlBuku, buku);
                kembaliUtama(&ulang);
                break;
            case 4:
                system("cls");
                searchData(jmlBuku, buku);
                kembaliUtama(&ulang);
                break;
            case 5:
                system("cls");
                updateData(jmlBuku, buku);
                kembaliUtama(&ulang);
                break;
            case 6:
                system("cls");
                hapusData(&jmlBuku, buku);
                kembaliUtama(&ulang);
                break;
            case 7:
                ulang = false;
				system("cls");
				cout << "\nKeluar dari program...\n" << endl;
				exit(0);
                break;
            default:
				system("cls");
                cout << "Pilihan menu tidak ada..." << endl;
                cout << "==================================" << endl;
                kembaliUtama(&ulang);
                break;
        }
    } while (ulang == true);

    return 0;
}

void kembaliUtama(bool *statusUlang) {
	char kembali;

    cout << "\nKembali ke Menu Utama(y/t)? ";
	cin >> kembali;
				
    if (kembali == 'y' || kembali == 'Y') {
		*statusUlang = true;
		system("cls");
	} else {
		system("cls");
		cout << "\nKeluar dari program...\n" << endl;
		exit(0);
	}
}

string spasiKeUnderscore(string teks) {
    for (int i = 0; i < teks.length(); i++) {
        if (teks[i] == ' ') {
            teks[i] = '_';
        }
    }   
    return teks;
}

string underscoreKeSpasi(string teks) {
    for (int i = 0; i < teks.length(); i++) {
        if (teks[i] == '_') {
            teks[i] = ' ';
        }
    }
    return teks;
}

string setKategori(int stok) {
    if (stok == 0) {
        return "Habis";
    } else if (stok < 5) {
        return "Langka";
    } else if (stok < 20) {
        return "Tersedia";
    } else if (stok < 100) {
        return "Banyak";
    } else {
        return "Melimpah";
    }
}

string toLowerCase(string teks) {
    for (int i = 0; i < teks.length(); i++) {
        teks[i] = tolower(teks[i]);
    }
    return teks;
}

// string toUpperCase(string teks) {
//     for (int i = 0; i < teks.length(); i++) {
//         teks[i] = toupper(teks[i]);
//     }
//     return teks;
// }

void dataTabel(int jmlBuku, Buku buku[]) {
    cout << "======================================================================" << endl;
    cout << left << setw(15) << "  Kode Buku"
            << setw(20) << "  Judul Buku"   
            << setw(15) << "  Kategori"
            << setw(10) << "  Stok"
            << setw(15) << "  Penerbit" << endl;
    cout << "======================================================================" << endl;
    for (int i = 0; i < jmlBuku; i++) {
        cout << left << setw(15) << ("  " + buku[i].kodeBuku)
            << setw(20) << ("  " + buku[i].judulBuku)
            << setw(15) << ("  " + buku[i].kategori)
            << setw(10) << ("  " + to_string(buku[i].stok))
            << setw(15) << ("  " + buku[i].penerbit) << endl;
    }
    cout << "======================================================================" << endl;
}

int bacaFile(Buku buku[], string namaFile) { 
    ifstream file(namaFile); 
    int index = 0; 

    if (!file) { 
        return 0; 
    } 
    while (file >> buku[index].kodeBuku >> buku[index].judulBuku >> buku[index].kategori >> buku[index].stok >> buku[index].penerbit) { 
        buku[index].judulBuku = underscoreKeSpasi(buku[index].judulBuku); 
        buku[index].penerbit = underscoreKeSpasi(buku[index].penerbit); 
        index++; 
    } 
    
    file.close(); 
    return index; 
}

void simpanData(int jmlBuku, Buku buku[]) { 
    ofstream file("data.txt"); 

    for (int i = 0; i < jmlBuku; i++) { 
        file << buku[i].kodeBuku << " " 
        << spasiKeUnderscore(buku[i].judulBuku) << " " 
        << buku[i].kategori << " " 
        << buku[i].stok << " " 
        << spasiKeUnderscore(buku[i].penerbit) 
        << endl; 
    } 
    
    file.close(); 
}   

void tambahData(int *jmlBuku, Buku buku[]) { 
    ofstream file("data.txt", ios::app); 

    cout << "Tambah Data" << endl;
    cout << "==================================" << endl;
    cout << "Kode Buku : "; 
    getline(cin, buku[*jmlBuku].kodeBuku);

    cout << "Judul Buku : "; 
    getline(cin, buku[*jmlBuku].judulBuku); 

    cout << "Stok : "; 
    cin >> buku[*jmlBuku].stok; 
    cin.ignore(); 
    
    cout << "Penerbit : "; 
    getline(cin, buku[*jmlBuku].penerbit); 
    
    buku[*jmlBuku].kategori = setKategori(buku[*jmlBuku].stok); 
    
    file << buku[*jmlBuku].kodeBuku << " " 
        << spasiKeUnderscore(buku[*jmlBuku].judulBuku) << " " 
        << buku[*jmlBuku].kategori << " " 
        << buku[*jmlBuku].stok << " " 
        << spasiKeUnderscore(buku[*jmlBuku].penerbit) 
        << endl; 
    
    (*jmlBuku)++; 
    
    file.close(); 

    cout << "\nData berhasil ditambah!\n"; 
}

void tampilData(int jmlBuku, Buku buku[]) { 
    if (jmlBuku == 0) { 
        cout << "Data masih kosong" << endl; 
        return; 
    } 
    
    cout << "Daftar Data Buku" << endl; 
    dataTabel(jmlBuku, buku);
}

void updateData(int jmlBuku, Buku buku[]) { 
    string kodeCari; 
    bool ditemukan = false; 

    if (jmlBuku == 0) { 
        cout << "Data masih kosong" << endl; 
        return; 
    } 
    
    cout << "Update Data Buku" << endl; 
    cout << "==================================" << endl; 
    cout << "Masukkan Kode Buku : "; 
    cin >> kodeCari; 
    cin.ignore(); 
    
    for (int i = 0; i < jmlBuku && ditemukan == false; i++) { 
        if (buku[i].kodeBuku == kodeCari) { 
            ditemukan = true; 
            cout << "\nData ditemukan!" << endl; 
            cout << "==================================" << endl; 
            cout << "Kode Buku  : " << buku[i].kodeBuku << endl; 
            cout << "Judul Buku : " << buku[i].judulBuku << endl; 
            cout << "Kategori   : " << buku[i].kategori << endl; 
            cout << "Stok       : " << buku[i].stok << endl; 
            cout << "Penerbit   : " << buku[i].penerbit << endl; 
            cout << "==================================" << endl; 
            cout << "\nInput Data Baru" << endl; 
            cout << "Judul Buku : "; 
            getline(cin, buku[i].judulBuku); 
            cout << "Stok : "; 
            cin >> buku[i].stok; 
            cin.ignore(); 

            cout << "Penerbit : "; 
            getline(cin, buku[i].penerbit); 
            buku[i].kategori = setKategori(buku[i].stok); 
            simpanData(jmlBuku, buku); 
            cout << "\nData berhasil diupdate!" << endl; 
        } 
    } 
    
    if (ditemukan == false) { 
        cout << "\nKode buku salah/tdk valid!" << endl; 
    } 
}

void hapusData(int *jmlBuku, Buku buku[]) { 
    string kodeCari; 
    bool ditemukan = false; 

    if (*jmlBuku == 0) { 
        cout << "Data masih kosong" << endl; 
        return; 
    } 
    cout << "Hapus Data Buku" << endl; 
    cout << "==================================" << endl; 
    cout << "Masukkan Kode Buku : ";    
    getline(cin, kodeCari); 

    for (int i = 0; i < *jmlBuku && ditemukan == false; i++) { 
        if (buku[i].kodeBuku == kodeCari) { 
            ditemukan = true; 
            cout << "\nData ditemukan!" << endl; 
            cout << "==================================" << endl; 
            cout << "Kode Buku  : " << buku[i].kodeBuku << endl; 
            cout << "Judul Buku : " << buku[i].judulBuku << endl; 
            cout << "Kategori   : " << buku[i].kategori << endl; 
            cout << "Stok       : " << buku[i].stok << endl; 
            cout << "Penerbit   : " << buku[i].penerbit << endl; 
            cout << "==================================" << endl; 

            for (int j = i; j < *jmlBuku - 1; j++) { 
                buku[j] = buku[j + 1]; 
            } 
            (*jmlBuku)--; 

            simpanData(*jmlBuku, buku); 

            cout << "\nData berhasil dihapus!" << endl; 
        } 
    } 

    if (ditemukan == false) { 
        cout << "\nKode buku salah/tdk valid!" << endl; 
    } 
}

void searchData(int jmlBuku, Buku buku[]) {
    string keyword;
    bool ditemukan = false;

    Buku hasil[50];
    int jmlHasil = 0;

    if (jmlBuku == 0) {
        cout << "Data masih kosong" << endl;
        return;
    }

    cout << "Search Data Buku" << endl;
    cout << "==================================" << endl;

    cout << "Masukkan Keyword (Judul / Penerbit) : ";
    getline(cin, keyword);

    keyword = toLowerCase(keyword);

    for (int i = 0; i < jmlBuku; i++) {
        string judul = toLowerCase(buku[i].judulBuku);
        string penerbit = toLowerCase(buku[i].penerbit);

        if (judul.find(keyword) != string::npos || penerbit.find(keyword) != string::npos) {
            hasil[jmlHasil] = buku[i];
            jmlHasil++;
            ditemukan = true;
        }
    }

    if (ditemukan == true) {
        cout << "\nHasil Pencarian" << endl;
        dataTabel(jmlHasil, hasil);
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}

void bubbleSort(int jmlBuku, Buku buku[], bool ascending, int pilField) {
    for (int i = 0; i < jmlBuku - 1; i++) {
        for (int j = 0; j < jmlBuku - i - 1; j++) {
            bool kondisi = false;
            if (pilField == 1) {
                string a = toLowerCase(buku[j].judulBuku);
                string b = toLowerCase(buku[j + 1].judulBuku);
                kondisi = ascending ? (a > b) : (a < b);
            } else if (pilField == 2) {
                string a = toLowerCase(buku[j].kategori);
                string b = toLowerCase(buku[j + 1].kategori);
                kondisi = ascending ? (a > b) : (a < b);
            } else if (pilField == 3) {
                kondisi = ascending ? (buku[j].stok > buku[j + 1].stok) : (buku[j].stok < buku[j + 1].stok);
            }

            if (kondisi) {
                swap(buku[j], buku[j + 1]);
            }
        }
    }
}

void selectionSort(int jmlBuku, Buku buku[], bool ascending, int pilField) {
    for (int i = 0; i < jmlBuku - 1; i++) {
        int posisi = i;
        for (int j = i + 1; j < jmlBuku; j++) {
            bool kondisi = false;
            if (pilField == 1) {
                string a = toLowerCase(buku[j].judulBuku);
                string b = toLowerCase(buku[posisi].judulBuku);
                kondisi = ascending ? (a < b) : (a > b);
            } else if (pilField == 2) {
                string a = toLowerCase(buku[j].kategori);
                string b = toLowerCase(buku[posisi].kategori);
                kondisi = ascending ? (a < b) : (a > b);
            } else if (pilField == 3) {
                kondisi = ascending ? (buku[j].stok < buku[posisi].stok) : (buku[j].stok > buku[posisi].stok);
            }
            if (kondisi) {
                posisi = j;
            }
        }
        swap(buku[i], buku[posisi]);
    }
}

void insertionSort(int jmlBuku, Buku buku[], bool ascending, int pilField) {
    for (int i = 1; i < jmlBuku; i++) {
        Buku key = buku[i];
        int j = i - 1;

        if (pilField == 1) {
            if (ascending) {
                while (j >= 0 &&
                    toLowerCase(buku[j].judulBuku) > toLowerCase(key.judulBuku)) {
                    buku[j + 1] = buku[j];
                    j--;
                }
            } else {
                while (j >= 0 &&
                    toLowerCase(buku[j].judulBuku) < toLowerCase(key.judulBuku)) {
                    buku[j + 1] = buku[j];
                    j--;
                }
            }
        } else if (pilField == 2) {
            if (ascending) {
                while (j >= 0 &&
                    toLowerCase(buku[j].kategori) > toLowerCase(key.kategori)) {
                    buku[j + 1] = buku[j];
                    j--;
                }
            } else {
                while (j >= 0 &&
                    toLowerCase(buku[j].kategori) < toLowerCase(key.kategori)) {
                    buku[j + 1] = buku[j];
                    j--;
                }
            }
        } else if (pilField == 3) {
            if (ascending) {
                while (j >= 0 &&
                    buku[j].stok > key.stok) {
                    buku[j + 1] = buku[j];
                    j--;
                }
            } else {
                while (j >= 0 &&
                    buku[j].stok < key.stok) {
                    buku[j + 1] = buku[j];
                    j--;
                }
            }
        }
        buku[j + 1] = key;
    }
}

void menuSorting(int jmlBuku, Buku buku[]) {
    Buku temp[50];
    int pilMetode, pilUrut, pilField;
    bool ascending;
    string fieldSort, arahSort;

    for (int i = 0; i < jmlBuku; i++) {
        temp[i] = buku[i];
    }
    if (jmlBuku == 0) {
        cout << "Data masih kosong" << endl;
        return;
    }

    do {
        system("cls");
        cout << "Menu Sorting" << endl;
        cout << "==================================" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "==================================" << endl;
        cout << "Pilih Metode : ";
        cin >> pilMetode;

        if (pilMetode < 1 || pilMetode > 3) {
            cout << "\nPilihan metode tidak valid" << endl;
            system("pause");
        }
    } while (pilMetode < 1 || pilMetode > 3);

    do {
        system("cls");
        cout << "Field Sorting" << endl;
        cout << "==================================" << endl;
        cout << "1. Judul Buku" << endl;
        cout << "2. Kategori" << endl;
        cout << "3. Stok" << endl;
        cout << "==================================" << endl;
        cout << "Pilih Field : ";
        cin >> pilField;

        if (pilField < 1 || pilField > 3) {
            cout << "\nPilihan field tidak valid" << endl;
            system("pause");
        }
    } while (pilField < 1 || pilField > 3);

    do {
        system("cls");
        cout << "Urutan Sorting" << endl;
        cout << "==================================" << endl;
        cout << "1. Ascending" << endl;
        cout << "2. Descending" << endl;
        cout << "==================================" << endl;
        cout << "Pilih : ";
        cin >> pilUrut;

        if (pilUrut < 1 || pilUrut > 2) {
            cout << "\nPilihan urutan tidak valid" << endl;
            system("pause");
        }
    } while (pilUrut < 1 || pilUrut > 2);

    ascending = (pilUrut == 1);

    if (pilField == 1) {
        fieldSort = "Judul Buku";
    } else if (pilField == 2) {
        fieldSort = "Kategori";
    } else {
        fieldSort = "Stok";
    }

    if (ascending == true) {
        arahSort = "ASC";
    } else {
        arahSort = "DESC";
    }

    switch (pilMetode) {
        case 1:
            bubbleSort(jmlBuku, temp, ascending, pilField);
            break;
        case 2:
            selectionSort(jmlBuku, temp, ascending, pilField);
            break;
        case 3:
            insertionSort(jmlBuku, temp, ascending, pilField);
            break;
    }
    cout << "\nData berhasil diurutkan berdasarkan " << fieldSort << " (" << arahSort << ")\n" << endl;

    dataTabel(jmlBuku, temp);
}