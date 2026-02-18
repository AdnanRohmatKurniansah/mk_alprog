#include <iostream>

using namespace std;

int ubahA(int &a) {
    a = a + 2;
    return a;
}


int main() {
    int a = 5;
    cout << "nilai a dari main: " << a << endl;
    cout << "nilai a dari tambahA: " << ubahA(a) << endl;
    cout << "nilai a dari main: " << a << endl;
    return 0;
}