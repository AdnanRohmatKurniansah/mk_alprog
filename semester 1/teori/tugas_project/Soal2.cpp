#include <iostream>
using namespace std;

void balikKata(char kalimat[]) {
    char kata[20][50]; 
    int j = 0, k = 0;
    int i = 0;

    while (true) {
        if (kalimat[i] == ' ' || kalimat[i] == '\0') {
            kata[j][k] = '\0'; 
            j++;               
            k = 0;            
            if (kalimat[i] == '\0') {
                break; 
            }
        } else {
            kata[j][k] = kalimat[i];
            k++;
        }
        i++;
    }

    cout << "Hasil = ";
    for (int x = j - 1; x >= 0; x--) {
        cout << kata[x];
        if (x > 0) cout << " ";
    }
    cout << endl;
}

int main() {
    char kalimat[200];
    cout << "Kalimat = ";
    cin.getline(kalimat, 200);

    balikKata(kalimat);
    return 0;
}
