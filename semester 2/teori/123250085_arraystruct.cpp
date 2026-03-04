#include <iostream>
#include <iomanip>
using namespace std;

struct Komponen {
    int No;
    string Nama;
    float Skor;
};

struct Mahasiswa {
    int NoMhs;
    string Nama;
    string Mtkul;
    int jmlKomp;
    Komponen komp[100];
};

int main() {
    int jmlMhs;

    cout << "== Input Data Mahasiswa ==" << endl;
    cout << "Jumlah Mahasiswa: ";
    cin >> jmlMhs;
    system("cls");

    Mahasiswa mhs[jmlMhs];

    for (int i = 0; i < jmlMhs; i++) {
        cout << "--------------------------" << endl;
        cout << "Data Mahasiswa ke-" << i+1 << endl;
        cout << "No. Mhs \t: ";
        cin >> mhs[i].NoMhs;
        cout << "Nama \t\t: ";
        cin.ignore();
        getline(cin, mhs[i].Nama);
        cout << "Mata Kuliah \t: ";
        getline(cin, mhs[i].Mtkul);
        cout << "Jumlah Komponen : ";
        cin >> mhs[i].jmlKomp;
        cout << endl;
        cin.ignore();

        for (int j = 0; j < mhs[i].jmlKomp; j++) {
            mhs[i].komp[j].No = j+1;

            cout << "No. Komponen \t: " << mhs[i].komp[j].No << endl;

            cout << "Nama Komponen \t: "; 
            getline(cin, mhs[i].komp[j].Nama);
            cout << "Skor \t\t: ";
            cin >> mhs[i].komp[j].Skor;
            cin.ignore();
            cout << endl;
        }
    }

    system("cls");

    for (int i = 0; i < jmlMhs; i++)
    {
        cout << "No. Mhs \t: " << mhs[i].NoMhs << endl;
        cout << "Nama \t\t: " << mhs[i].Nama << endl;
        cout << "Matakuliah \t: " << mhs[i].Mtkul << endl;
        
        cout << left << setw(5) << "No" << setw(20) << "Nama Komponen" << setw(10) << "Nilai" << endl;
        cout << "-------------------------------" << endl;

        for (int j = 0; j < mhs[i].jmlKomp; j++)
    
            cout << left << setw(5) << mhs[i].komp[j].No
                << setw(20) << mhs[i].komp[j].Nama
                << setw(10) << mhs[i].komp[j].Skor << endl;
        }
    }

    return 0;
}