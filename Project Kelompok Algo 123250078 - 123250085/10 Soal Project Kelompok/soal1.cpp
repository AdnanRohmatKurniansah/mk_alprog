#include <iostream>
using namespace std;

int main(){
    int nilai[10];
    int jumlah = 0; 
    cout << "masukkan nilai :" << endl;
    for(int i = 0; i < 10; i++){
        cout << "nilai " << i+1 << " : " ;
        cin  >> nilai[i];
    }
    int nilaimax = nilai[10];
    for(int i= 0; i <10; i++){
        if(nilai[i] > nilaimax){
            nilaimax = nilai[i];
            
        }
    }
    for(int i= 0; i <10; i++){
        if(nilai[i] == nilaimax){
            jumlah = jumlah + 1;
        }
       
       
    }
    cout << "nilai tertinggi : " << nilaimax << endl;
    cout << "mahasiswa yang memiliki nilai tertinggi " <<jumlah << endl;
    return 0;
}