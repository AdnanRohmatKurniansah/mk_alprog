#include <iostream>
using namespace std;

int main() {
    string username = "admin";
    string password = "12345";
    string usernameInput, passwordInput;

    cout << "=== Masukkan Credentials ===" << endl;
    do {
        cout << "\nMasukkan Username: ";
        getline(cin, usernameInput);
        cout << "Masukkan Password: ";
        getline(cin, passwordInput);

        if (username != usernameInput || password != passwordInput) {
            cout << "Coba lagi!" << endl;
        }
    } while (username != usernameInput || password != passwordInput);
    cout << "\nAnda Berhasil Login";
    

    return 0;
}