#include <iostream>
using namespace std;

void nilai(int data[10]);
void hitung(int data[10], int &jumlah, float &rata);

int main() {
    int data[10];
    int jumlah;
    float rata;

    nilai(data);
    hitung(data, jumlah, rata);

    cout << "Jumlah nilai < 5 atau >= 7 : " << jumlah << endl;
    cout << "Rata-rata nilai tersebut    : " << rata << endl;

    return 0;
}

void nilai(int data[10]) {
    int temp[10] = {2,5,1,2,4,6,3,2,7,1};
    for (int i = 0; i < 10; i++) {
        data[i] = temp[i];
    }
}
  
void hitung(int data[10], int &jumlah, float &rata) {
    jumlah = 0;
    int count = 0;

    for(int i = 0; i < 10; i++) {
        if (data[i] < 5 || data[i] >= 7) {
            jumlah += data[i];
            count++;
        }
    }

    if(count > 0)
        rata = (float)jumlah / count;
    else
        rata = 0;
}
