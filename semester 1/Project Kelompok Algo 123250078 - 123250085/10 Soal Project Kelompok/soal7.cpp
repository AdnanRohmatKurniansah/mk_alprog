#include <iostream>
using namespace std;

string satuan(int n);

int main(){
    int angka;
    bool menu = true;
    do{
        cout << "masukkan angka dari 1 sampai 100 : ";
        cin>> angka; 
        if(angka < 0 || angka > 100){
            cout << "Angka di luar jangkauan (1 - 100)." << endl;
            return 0;
        }
        string hasil;
        if(angka < 10){
            hasil = satuan(angka);
        } else if(angka == 10){
            hasil = "sepuluh";
        } else if (angka == 11){
            hasil = "sebelas";
        } else if (angka < 20){
            hasil = satuan(angka%10) + " belas";
        } else {
            int puluh = angka / 10;
            int sisa = angka % 10;

            hasil = satuan(puluh) + satuan(sisa);
            if(sisa == 0){
                hasil += " " + satuan(sisa);
            }
        }
        cout << hasil << endl;
    }while(menu = true);
}

string satuan(int n){
    switch (n)
    {
    case 1:
        return "satu";
        break;
    case 2:
        return "dua";
        break;
    case 3:
        return "tiga";
        break;
    case 4:
        return "empat";
        break;
    case 5:
        return "lima";
        break;
    case 6:
        return "enam";
        break;
    case 7:
        return "tujuh";
        break;
    case 8:
        return "delapan";
        break;
    case 9:
        return "sembilan";
        break;
    default:
        return " ";
        break;
    }

}