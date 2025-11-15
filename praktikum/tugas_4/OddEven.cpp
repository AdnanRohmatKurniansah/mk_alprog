#include <iostream>

using namespace std;

void inputMatriks(int baris, int kolom, int nilai[50][50]);
void tampilMatriks(int baris, int kolom, int nilai[50][50]);
int ekstrakNilai(int baris, int kolom, int nilai[50][50], string pilihBaris, string pilihKolom, int hasil[250]);

int main() {
    int baris, kolom, jumlahData, total;
    string pilihBaris, pilihKolom; 
    float rata;

    int nilai[50][50];
    int hasil[250]; 

    do {
        cout << "Masukkan jumlah baris = ";
        cin >> baris;
        cout << "Masukkan jumlah kolom = ";
        cin >> kolom;

        if (baris <= 0 || kolom <= 0) {
            system("cls");
            cout << "Masukkan jumlah yg valid (tdk minus/0)...\n" << endl;
        }
    } while (baris <= 0 || kolom <= 0);
    

    cout << "\nMasukkan nilai matriks" << endl;
    inputMatriks(baris, kolom, nilai);
    
    system("cls");
    cout << "\nTampilan matriks" << endl;
    tampilMatriks(baris, kolom, nilai);
    cout << "Kolom (ganjil/genap): ";
    cin >> pilihKolom;
    cout << "Baris (ganjil/genap): ";
    cin >> pilihBaris;

    jumlahData = ekstrakNilai(baris, kolom, nilai, pilihBaris, pilihKolom, hasil);

    if (jumlahData == 0) {
        cout << "\nTidak ada data yang sesuai..." << endl;
    } else {
        cout << "\nHasil : [";
        for (int i = 0; i < jumlahData; i++) {
            cout << hasil[i];
            if (i < jumlahData - 1) {
                cout << ", ";
            }
            total += hasil[i];
        }
        cout << "]\n";

        rata = total*1.0 / jumlahData;
        cout << "Rata-rata : " << rata << endl;
    }

    return 0;
}

void inputMatriks(int baris, int kolom, int nilai[50][50]) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "[" << i+1 << "]" << "[" << j+1 << "]" << " = ";
            cin >> nilai[i][j];
        }
    }
}

void tampilMatriks(int baris, int kolom, int nilai[50][50]) {
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "[" << nilai[i][j] << "]";
        }
        cout << endl;
    }
    cout << "\n";
}

int ekstrakNilai(int baris, int kolom, int nilai[50][50], string pilihBaris, string pilihKolom, int hasil[250]) {
    int nomorBaris, nomorKolom;
    int jumlahData = 0;
    bool sesuaiBaris, sesuaiKolom;

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            nomorBaris = i + 1;
            nomorKolom = j + 1;

            sesuaiBaris = (pilihBaris == "genap") ? (nomorBaris % 2 == 0) : (nomorBaris % 2 == 1);
            sesuaiKolom = (pilihKolom == "genap") ? (nomorKolom % 2 == 0) : (nomorKolom % 2 == 1);

            if (sesuaiBaris && sesuaiKolom) {
                hasil[jumlahData] = nilai[i][j];
                jumlahData++;
            }
        }
    }

    return jumlahData;
}