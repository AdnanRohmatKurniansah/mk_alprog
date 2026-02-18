#include <iostream>
using namespace std;

int main(){
    bool member = false;
    int pill, jml;
    string nama;
    int jmlmember = 3;
    string membership[jmlmember] = {"andi", "budi", "siti"};
    int poin[jmlmember] = {20, 40, 50};
    string menu[7] = {"Kopi Hitam", "Cappuccino", "Teh Manis", "Nasi Goreng", "Mie Goreng", "Sosis Bakar", "Roti Bakar"};
    int harga[7] = {10000, 18000, 8000, 20000, 18000, 12000, 15000};
    int histori[20];

    int totalharga = 0, jumlahhistori = 0, memberindex = 0;
    cout << "=======================\n";   
    cout << "cafe komimart" << endl;
    cout << "masukkan nama anda " ;
    cin >> nama;
    cout << "=======================\n\n";
    for(int i = 0; i < jmlmember; i++){
        if(nama == membership[i]){
            member = true;
            memberindex = i;
            break;
        }
    }
    if(member){
        cout << "anda merupakan member, poin anda " << poin[memberindex] << endl;
    } else {
        cout << "anda bukan member" << endl;
    }

    cout << "\n=== MENU KAFE ===\n";
    for(int i = 0; i < 7; i++){
        cout << i+1 << ". " << menu[i] << " - Rp" << harga[i] << endl;
    }
   cout << "\nPilih menu (0 untuk selesai): \n";
    while(true){
        cout << "Pilih nomor menu: ";
        cin >> pill;

        if(pill == 0) break;  
        if(pill < 1 || pill > 7){
            cout << "Menu tidak tersedia!\n";
            continue;
        }

        cout << "Jumlah: ";
        cin >> jml;

        int subtotal = harga[pill - 1] * jml;
        totalharga += subtotal;
        histori[jumlahhistori] = subtotal;
        jumlahhistori++;

        cout << "Ditambahkan ke pesanan!\n";
    }

    float diskon = 0;
    int tambahpoin = 0;
    
    if(member){
        diskon = totalharga * 0.15;
        tambahpoin = totalharga / 10000;
        poin[memberindex] += tambahpoin;
    }

    float totalakhir = totalharga - diskon;

    for(int i = 0; i < jumlahhistori; i++){
        cout << "- Item " << i+1 << ": Rp" << histori[i] << endl;
    }

    cout << "\nTotal Belanja : Rp" << totalharga << endl;
    cout << "Diskon        : Rp" << diskon << endl;
    cout << "Total Akhir   : Rp" << totalakhir << endl;

    if(member){
        cout << "Poin Didapat  : " << tambahpoin << endl;
        cout << "Total Poin    : " << poin[memberindex] << endl;
    } else {
        cout << "Poin Didapat  : 0 (bukan member)\n";
    }
}