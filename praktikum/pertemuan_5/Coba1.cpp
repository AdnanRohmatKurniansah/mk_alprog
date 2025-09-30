#include <iostream>
using namespace std;

int main() {
    string username = "admin";
    string password = "12345";
    string usernameInput, passwordInput;
    char filmChoosed;

    do {
        system("cls");
        cout << "=== Masukkan Credentials ===" << endl;
        cout << "\nMasukkan Username: ";
        getline(cin, usernameInput);
        cout << "Masukkan Password: ";
        getline(cin, passwordInput);

        if (username == usernameInput && password == passwordInput) {
            do {
                cout << "\n== Tiket Bioskop == " << endl;
                cout << "1. Chainsawman" << endl;
                cout << "2. G-30S PKIS" << endl;
                
                cout << "\nPilih film: ";
                cin >> filmChoosed;

                switch (filmChoosed) {
                case '1':
                    cout << "Anda memilih Chainsawman" << endl;
                    break;
                case '2':
                    cout << "Anda memilih G-30S PKIS" << endl;
                    break;
                default:
                    cout << "Menu tidak ada dalam daftar" << endl; 
                    break;
                }
                system("pause");
            } while (false);
        }
    } while (username != usernameInput || password != passwordInput);
    
    return 0;
}

