#include <iostream>
using namespace std;

int main() {
    string username = "admin";
    string password = "12345";
    string usernameInput, passwordInput;

    cout << "=== Masukkan Credentials ===" << endl;
    do {
        cout << "\nMasukkan Username: ";
        cin >> usernameInput;
        cout << "Masukkan Password: ";
        cin >> passwordInput;
    } while (usernameInput != username && passwordInput != password);
    cout << "\nAnda Berhasil Login";
    

    return 0;
}