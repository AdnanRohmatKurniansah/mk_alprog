#include <iostream>
using namespace std;
int ongkir(int harga);
float promo(int harga, int diskon);
float total(int hargaperkg, int jml);
int main(){
    string namaadmin = "adnan";
    string password = "admin123";
    string namain,  passwordin, pembeli, pakaidiskon, pakaiongkir, ulang;
    int jml, pill, diskon, hargaperkg, harga;
    do{
        cout << "masukkan nama admin : ";
        cin >> namain;
        cout << "masukkan passowrd : ";
        cin >> passwordin;
    } while(passwordin != password || namain != namaadmin);
    do{
        cin.ignore();
        cout << "masukkan nama pembeli : ";
        getline(cin, pembeli);
        cout << "berapa total berat pakaian : ";
        cin >> jml;
        cout << "masukkan jenis layanan :" << endl;
        cout << "1. 4 jam = Rp24.000/kg" << endl;
        cout << "2. 7 jam = Rp19.000/kg" << endl;
        cout << "3. 12 jam = Rp10.000/kg" << endl;
        cout << "pilih jenis laundry = ";
        cin >> pill;
        
        switch (pill)
        {
        case 1:
            hargaperkg = 24000;
            break;
        case 2:
            hargaperkg = 19000;
            break;
        case 3:
            hargaperkg = 10000;
            break;
        default:
            cout << "pilihan tidak valid"<< endl;
            break;
        }

        harga = total(hargaperkg, jml);

        total(hargaperkg, jml);
        if(jml >=5){
            do{
                cout << "apakah menggunakan diskon ";
                cin >> pakaidiskon;
                if(pakaidiskon == "y"){
                    cout << "diskon berapa persen : ";
                    cin >> diskon;
                    harga = promo(harga, diskon);
                } else if(pakaidiskon == "n"){
                    harga = total(hargaperkg, jml);
                } else {
                    cout << "pilihan tidak valid"<< endl;
                }
            }while(pakaidiskon != "y" && pakaidiskon != "n");
        } else {
            harga = promo(harga, 5);
        }
        
        do{
            cout << "apakah menggunakan ongkir ";
            cin >> pakaiongkir;
            if(pakaiongkir == "y"){
                    harga = ongkir(harga);
                } else if(pakaiongkir == "n"){
                    harga = total(hargaperkg, jml);
                } else {
                    cout << "pilihan tidak valid"<< endl;
                }
        }while(pakaiongkir != "y" && pakaiongkir != "n");

        cout << "total laundry untuk " << pembeli <<" = " << harga << endl;
        cout << "\napakah ingin mengulang transaksi? (y/n): ";
        cin >> ulang;
    }while(ulang == "y");
}

int ongkir(int harga){
     return harga + 10000;
}
float promo(int harga, int diskon){
    float diskonan = harga * diskon / 100.0;
    return harga - diskonan;
}

float total(int hargaperkg, int jml){
    return hargaperkg* jml;
}

