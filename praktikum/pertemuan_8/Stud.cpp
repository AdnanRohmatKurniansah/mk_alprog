// #include <iostream>

// using namespace std;

// double diskon = 0.1;

// int banyakBarang(string namaBrg, int harga) {
//     int qty, total, totalBill;

//     cout << "berapa " << namaBrg << " yg ingin anda beli: ";
//     cin >> qty;
//     total = qty * harga;
//     totalBill = total - (total*diskon)

//     if (saldo < totalBill)
//     {
//         cout << "Saldo anda tdk cukup" << endl;
//         return saldo;
//     }

//     return ;
// }

// int beliBarang(int saldo) {
//     int pilihan, qty, totalBill;

//     cout << "== Barang ===" << endl;
//     cout << "1. Pasta gigi" << endl;
//     cout << "2. Sikat gigi" << endl;
//     cout << "Pilih barang: " << endl;
//     cin >> pilihan;
//     switch (pilihan) {
//         case 1:
//             totalBill = banyakBarang("pasta gigi", 12000);
//             break;
//         case 2:
//             totalBill = banyakBarang("sikat gigi", 10000);
//             break;
//         default:
//             break;
//     }

//     return saldo - totalBill;
// }

// int main() {
//     int pilihUser, saldo;
//     saldo = 1000000;
    
//     while (true) {
//         cout << "1. Beli Barang" << endl;
//         cout << "2. Cek Saldo" << endl;
//         cout << "Pilih menu: ";
//         cin >>  pilihUser;
//         switch (pilihUser) {
//             case 1:
//                 saldo = beliBarang(saldo);
//                 break;
            
//             default:
//                 break;
//         }
        
//     }
    

//     return 0;
// }
