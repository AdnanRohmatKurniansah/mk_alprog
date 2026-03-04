#include <iostream>

using namespace std;

void kembaliMenu();
void SenSearch(int x[7], bool found, int target) {
    int i = 0;
    x[6] = target;  
    
    while (x[i] != target)
    {
        i++;
    }

    if (i > 5) {
        cout << "tidak ada " << target << " dlm array " << endl;
    } else {
        cout << target << " ditemukan di index ke-" << i << endl;
    }
}

bool ulang = false;

int main() {
    int x[7] = {20, 10, 30, 50, 60, 64};
    int opsiMenu, target;
    bool found = false;

    do {
		cout << "=== Search ===" << endl;
        cout << "1. Cari Data" << endl;
		cout << "2. Input Data" << endl;
		cout << "3. Keluar" << endl;
		cout << "Pilih Menu: ";
		cin >> opsiMenu;

        switch (opsiMenu) {
            case 1:
                system("cls");
				ulang = false;

                cout << "Nilai yg dicari: ";
                cin >> target;

                SenSearch(x, found, target);

                break;
            case 2:
                system("cls");
				ulang = false;

                cout << "bonk" << endl;

                break;
            case 3:
                ulang = false;
				system("cls");
				cout << "\nAnda keluar dari program, Terimakasih...\n" << endl;
				exit(0);
                break;
            default:
                ulang = true;
                system("cls");
                cout << "Input menu sesuai opsi...\n" << endl;
                break;
        }

    } while (ulang == true);
    
    return 0;
}

void kembaliMenu() {
	char kembali;

    cout << "\nApakah Anda ingin kembali ke menu utama? (Y/N): ";
	cin >> kembali;
				
    if (kembali == 'y' || kembali == 'Y') {
		ulang = true;
		system("cls");
	} else {
		system("cls");
		cout << "\nAnda keluar dari program, Terimakasih...\n" << endl;
		exit(0);
	}
}
