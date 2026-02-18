#include <iostream>
using namespace std;

int main(){
    string menu[7] = {"paramex", "obhcombi", "bodrexin", "hufagrip", "betadin", "panadon", "amphetamine"};
    int stok[7] = {10, 18, 80, 20, 18, 12, 15};
    int harga[7] = {10000, 18000, 8000, 20000, 18000, 12000, 15000};
    bool obkeras = false;
    string obatkeras[4] = {"paramex", "bodrexin", "hufagrip", "amphetamine"};
    int pill, jumlah, total = 0;
    char ulang, resep;
    cout << "\n=== MENU apotek ===\n";
    do{
        for(int i = 0; i < 7; i++){
            cout << i+1 << ". " << menu[i] << " - stok " << stok[i] << "\n  | harga = " << harga[i] << endl;
        }
        cout << "\nPilih obat (1-7)";
        cin >> pill;
        for(int i = 0; i < 4; i++){
            if(menu[pill-1] == obatkeras[i]){
                obkeras = true;
                break;
            }
        }

        int idx = pill - 1;

        if(stok[idx] == 0){
            cout << "maaf stok obat sedang habis" << endl;
            continue;
        }

        if(obkeras){
            cout << "apakah anda memiliki resep dokter untuk membeli obat ini? ";
            cin >> resep;
            if (resep != 'Y' && resep != 'y') {
                cout << "Pembelian ditolak, tidak ada resep.\n";
                continue;
            }
        } 

        cout << "masukan jumlah obat yang ingin dibeli = ";
        cin >> jumlah; 
        if(stok[idx] < jumlah){
            cout << "Stok tidak cukup! Stok tersedia: " << stok[idx] << endl;
            continue;
        }

        int subtotal = harga[idx] * jumlah;
        total += subtotal;

        stok[idx] -= jumlah;
        cout << "apakah ingin membeli lagi? (y/n) ";
        cin >> ulang;
    }while(ulang == 'y');

    cout << "\n\n========== STRUK PEMBELIAN ==========\n";

    cout << "Total pembayaran: Rp " << total << endl;
    cout << "Terima kasih telah berbelanja di Apotek!\n";

    cout << "\nSisa stok obat:\n";
    for (int i = 0; i < 7; i++) {
        cout << "- " << menu[i] << ": " << stok[i] << endl;
    }

    cout << "=====================================\n";

    return 0;
}