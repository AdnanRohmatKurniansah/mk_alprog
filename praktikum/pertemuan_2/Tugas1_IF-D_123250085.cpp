#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Study Case

    string nama, bmi_clasification, tanggal, bulan, tahun;
    int berat_badan, tinggi_badan_cm;
    float tinggi_badan, bmi; 

    cout << "Masukkan Nama \t: ";
    getline(cin, nama);

    cout << "\nMasukkan Tanggal Lahir \t " << endl;
    cout << "Tanggal \t: ";
    getline(cin, tanggal);
    cout << "Bulan \t\t: ";
    getline(cin, bulan);
    cout << "Tahun \t\t: ";
    getline(cin, tahun);

    cout << "\nBerat Badan \t: ";
    cin >> berat_badan;

    cout << "Tinggi Badan \t: ";
    cin >> tinggi_badan_cm;

    cout << "\n" << setfill('-') << setw(45) << "-";

    tinggi_badan = tinggi_badan_cm / 100.0;
        
    bmi = berat_badan / tinggi_badan;

    if (bmi >= 60.0) {
        bmi_clasification = "Obesitas II";
    } else if (bmi < 60.0 && bmi >= 50.0) {
        bmi_clasification = "Obesitas I";
    } else if (bmi < 50.0 && bmi >= 40.0) {
        bmi_clasification = "Kegemukan (Overweight)";
    } else if (bmi < 40.0 && bmi >= 30.0) {
        bmi_clasification = "Normal (Ideal)";
    } else {
        bmi_clasification = "Kurus";
    }
        
    cout << "\nNama \t\t\t: " << nama << endl;
    cout << "Tanggal Lahir \t\t: " << tanggal << ", " << bulan << ", " << tahun << endl;
    cout << "BMI Level \t\t: " << bmi << endl;
    cout << "BMI Clasification \t: " << bmi_clasification;
        
    return 0;
}


