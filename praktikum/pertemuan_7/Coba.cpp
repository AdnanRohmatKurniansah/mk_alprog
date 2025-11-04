#include <iostream>

using namespace std;

bool isLogin(string username, string password) {
    if (username == "admin" && password == "12345") {
        return true;
    } else {
        return false;
    }
    
}

void menuLogin() {
    string inUser, inPass;
    cout << "Username: ";
    getline(cin, inUser);
    cout << "Password: ";
    getline(cin, inPass);
    cout << isLogin(inUser, inPass) << endl;
}


int main() {
    menuLogin();

    return 0;
}