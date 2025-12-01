#include <iostream>
using namespace std;

void banyakpecahan(long uang, long pecahan[]);

int main(){
    long uang, pecahan[9] = { 50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100};
    int lembar[9], i;
    cout << "jumlah uang kembalian : Rp.";
    cin >> uang;
    cout << "Pecahan uang kembali: " << endl;
    banyakpecahan(uang, pecahan);
    return 0;
}

void banyakpecahan(long uang, long pecahan[]){
    int lembar;
    for(int i; i < 9; i++){
        lembar = uang/pecahan[i];
        if (lembar > 0) {
            cout << "Rp " << pecahan[i] << " : " << lembar << " lembar" << endl;
            uang = uang % pecahan[i];
        }
       
    }
}