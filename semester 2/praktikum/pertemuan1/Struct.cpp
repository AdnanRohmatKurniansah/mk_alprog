#include <iostream>

using namespace std;



int main() {
    struct Mahasiswa{
        string nim;
        string nama;
        string kelas;
        int nilai[2];
    };

    Mahasiswa mhs[2];

    for (int i = 0; i < 2; i++)
    {
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "NIM: ";
        getline(cin, mhs[i].nim);
        cout << "Nama: ";
        getline(cin, mhs[i].nama);
        cout << "Kelas: ";
        getline(cin, mhs[i].kelas);
        for (int j = 0; j < 2; j++)
        {
            cout << "Masukkan nilai ke-" << j+1 << " : ";
            cin >> mhs[i].nilai[j];
        };
        cout << "==================" << endl;

        cin.ignore();
    }
    
    cout << "Input selesai..." << endl;
    system("cls");

    cout << "-- Daftar Mahasiswa --" << endl;

    for (int i = 0; i < 2; i++)
    {
        cout << "NIM \t: " << mhs[i].nim << endl;
        cout << "Nama \t: " << mhs[i].nama << endl;
        cout << "Kelas \t: " << mhs[i].kelas << endl;
        for (int j = 0; j < 2; j++)
        {
            cout << "Nilai ke-" << j+1 << " : " << mhs[i].nilai[j] << endl;
        };
        cout << "=======================" << endl;
    }
    

    

    return 0;
}