#include <iostream>
using namespace std;

int main() {
    int nim, total_sks, jm_mk_pil, jm_sks_d, jm_sks_e, lama_lulus;
    float ipk;
    string nama, predikat_lulus;

    cout << "=== Cek apakah anda lulus atau tidak ===" << endl;

    cout << "\nMasukkan Nama anda: ";
    cin >> nama;

    cout << "Masukkan Nim anda: ";
    cin >> nim;

    cout << "Jawab beberapa pertanyaan dibawah ini:" << endl;
    cout << "- Berapa ipk anda: ";
    cin >> ipk;
    
    cout << "- Berapa total sks yg diambil: ";
    cin >> total_sks;

    cout << "- Berapa jml matkul pilihan diambil: ";
    cin >> jm_mk_pil;

    cout << "- Berapa jml sks dengan nilai D: ";
    cin >> jm_sks_d;

    cout << "- Berapa jml sks dengan nilai E: ";
    cin >> jm_sks_e;

    cout << "- Berapa lama anda lulus (semester): ";
    cin >> lama_lulus;

    if (ipk >= 2.25 && total_sks >= 144 
        && jm_mk_pil >= 15 && jm_sks_d < (total_sks * 0.25) && jm_sks_e == 0) {
        cout << "Selamat anda dinyatakan Lulus" << endl;
        if (ipk >= 3.51 && lama_lulus <= 8) {
            predikat_lulus = "Dengan Pujian (Cumlaude) \ndiusulkan mendapatkan Karya Cendekia"; 
        } else if (ipk >= 3.01 && ipk <= 3.50) {
            predikat_lulus = "Sangat Memuaskan (Very Satisfactory)"; 
        } else if (ipk >= 2.76 && ipk <= 3.00) {
            predikat_lulus = "Memuaskan (Satisfactory)";
        } else {
            predikat_lulus = "";
        }
        cout << predikat_lulus;
    } else {
        cout << "Maaf anda belum Lulus";
    }
    

    return 0;
}
