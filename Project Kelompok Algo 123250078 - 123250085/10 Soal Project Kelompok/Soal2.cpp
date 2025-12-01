#include <iostream>
using namespace std;

// Fungsi untuk membalik urutan kata dalam sebuah kalimat
void balikKata(char kalimat[]) {

    char kata[20][50]; 
    // Array 2 dimensi untuk menyimpan maksimal 20 kata,
    // setiap kata maksimal 50 karakter.

    int j = 0, k = 0;
    // j = indeks kata (baris)
    // k = indeks karakter dalam kata (kolom)

    int i = 0; 
    // i = indeks untuk karakter dalam kalimat asli

    // Loop untuk memisahkan kalimat menjadi kata-kata
    while (true) {
        if (kalimat[i] == ' ' || kalimat[i] == '\0') {
            // Jika bertemu spasi atau akhir string
            kata[j][k] = '\0'; 
            // Akhiri kata dengan null-terminator

            j++;  // Pindah ke kata berikutnya
            k = 0; // Reset index karakter kata

            if (kalimat[i] == '\0') {
                // Jika sudah mencapai akhir kalimat, hentikan loop
                break;
            }
        } else {
            // Jika karakter normal, masukkan ke kata saat ini
            kata[j][k] = kalimat[i];
            k++;
        }
        i++; // Lanjutkan ke karakter berikutnya
    }

    // Menampilkan hasil dengan urutan kata dibalik
    cout << "Hasil = ";
    for (int x = j - 1; x >= 0; x--) {
        cout << kata[x]; // Cetak kata dari yang terakhir ke pertama
        if (x > 0) cout << " "; // Tambahkan spasi kecuali di akhir
    }
    cout << endl;
}

int main() {
    char kalimat[200]; 
    // Buffer untuk menyimpan input kalimat

    cout << "Kalimat = ";
    cin.getline(kalimat, 200); 
    // Ambil input termasuk spasi sampai maksimal 200 karakter

    balikKata(kalimat); 
    // Panggil fungsi untuk membalik kata

    return 0;
}
