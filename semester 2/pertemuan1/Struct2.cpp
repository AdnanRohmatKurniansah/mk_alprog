#include <iostream>

using namespace std;



int main() {
    struct matkul {
        string nama_mk;
        string dosen;
        int sks;
        string ruang;
    };

    struct mahasiswa {
        int nim;
        string nama;
        matkul matkul[2];
    };

    mahasiswa mhs[2];

    for (int i = 0; i < 2; i++)
    {
        cout << "== Input data mahasiswa ==" << endl;
        cout << "Data mahasiswa ke-" << i+1 << ": " << endl;
        cout << "Nim: ";
        cin >> mhs[i].nim;

        cin.ignore();

        cout << "Nama: ";
        getline(cin, mhs[i].nama);

        cout << "== Data matkul ==" << endl;
        for (int j = 0; j < 2; j++)
        {
            cout << "Nama Matkul: ";
            getline(cin, mhs[i].matkul[j].nama_mk);
            cout << "Dosen: ";
            getline(cin, mhs[i].matkul[j].dosen);

            cout << "Sks: ";
            cin >> mhs[i].matkul[j].sks;

            cin.ignore();

            cout << "Ruang: ";
            getline(cin, mhs[i].matkul[j].ruang);

            cout << "---------------" << endl;

        }
        
    }
    
    return 0;
}