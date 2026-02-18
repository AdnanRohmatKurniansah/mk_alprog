#include <iostream>

using namespace std;

bool isLogin(string username, string password) {
    if (username == "admin" && password == "12345") {
        return true;
    } else {
        return false;
    }
    
}

int main() {
    string username, password;

    cout << "Masukkan Username: ";
    getline(cin, username);
    cout << "Masukkan Password: ";
    getline(cin, password);

    if (isLogin(username, password)) {
        cout << "User berhasil login" << endl;
    } else {
        cout << "User gagal login" << endl;
    }
    

    return 0;
}