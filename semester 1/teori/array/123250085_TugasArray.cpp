#include <iostream>

using namespace std;

int main() {
    int nilaiTugas[3][4] =  {
        {100, 54, 75, 70},
        {80, 65, 85, 65},
        {80, 65, 85, 65}
    };
    int tertinggi[3] = {0, 0, 0};
    int terendah[3] = {0, 0, 0};
    int jumlah[3] = {0, 0, 0};
    float rata[3] = {0, 0, 0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << nilaiTugas[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "=============" << endl;

    for (int i = 0; i < 3; i++) {
        terendah[i] = nilaiTugas[i][0];
        tertinggi[i] = nilaiTugas[i][0];

        for (int j = 0; j < 4; j++) {
            jumlah[i] += nilaiTugas[i][j];
            
            if (nilaiTugas[i][j] < terendah[i]) { 
                terendah[i] = nilaiTugas[i][j];
            }
            if (nilaiTugas[i][j] > tertinggi[i]) { 
                tertinggi[i] = nilaiTugas[i][j];
            }
        }
        rata[i] = (jumlah[i]*1.0)/4;
    }

    cout << "Rata-rata: " << endl;

    for (int i = 0; i < 3; i++) {
        cout << rata[i] << " | ";
    }

    cout << "\nNilai Terendah: " << endl;

    for (int i = 0; i < 3; i++) {
        cout << terendah[i] << " | ";
    }

    cout << "\nNilai Tertinggi: " << endl;

    for (int i = 0; i < 3; i++) {
        cout << tertinggi[i] << " | ";
    }

    return 0;
}