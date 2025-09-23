// Nama: Adnan Rohmat Kurniansah
// Nim: 123250085
// Plug: Praktikum Algoritma dan Pemrograman IF-D (20251)

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // IF Statement

    // int ipk = 4;
    // int tahunLulus = 4;

    // if (ipk >= 3 && tahunLulus <= 4) {
    //     cout << "Anda Cumlaude";
    // } else {
    //     cout << "Anda Tidak Cumlaude";
    // }

    // cout << "Selesai";


    // IF Else Statement

    // int nilaiKalkulus;

    // cout << "Masukkan nilai kalkulus anda \t: ";
    // cin >> nilaiKalkulus;

    // if (nilaiKalkulus >= 85){
    //     cout << "Anda dapat nilai A";
    // } else if(nilaiKalkulus < 85 && nilaiKalkulus >= 75) {
    //     cout << "Anda dapat nilai B";
    // } else if (nilaiKalkulus < 75 && nilaiKalkulus >= 65) {
    //     cout << "Anda dapat nilai C";
    // } else if(nilaiKalkulus < 65 && nilaiKalkulus >= 55) {
    //     cout << "Anda dapat nilai D";
    // } else {
    //     cout << "Anda dapat nilai E";
    // }


    // Ternary Operation

    // int nilaiKalkulus;

    // cout << "Masukkan nilai kalkulus \t: ";
    // cin >> nilaiKalkulus;

    // string kepintaran = nilaiKalkulus > 90 ? "Kamu Pintar" : "Biasa Aj";

    // cout << kepintaran;


    // Switch Statements

    // int nilaiKalkulus = 'A';

    // switch (nilaiKalkulus) {
    // case 'A':
    //     cout << "Nilai anda 85 - 90";
    //     break;
    // case 'B':
    //     cout << "Nilai anda 80 - 84";
    //     break;
    // case 'C':
    //     cout << "Nilai anda <= 79";
    //     break;
    // default:
    //     cout << "Nilai anda Tidak Valid";
    //     break;
    // }


    // Study Case

    int umur;
    char ktp;

    cout << "Isi data berikut" << endl;

    cout << "Masukkan umur \t: ";
    cin >> umur;

    if (umur > 17)  {
        cout << "Apakah punya ktp \t: ";
        cin >> ktp;

        if (ktp == 'Y') {
            cout << "Budi memenuhi syarat membuat SIM";
        } else {
            cout << "Budi belum bisa membuat SIM";
        }
    } else {
        cout << "Budi belum cukup umur untuk membuat SIM";
    }   
    
    
    return 0;
}
