#include <iostream>

using namespace std;

int a();
int b();

int a() {
    cout << b();
    return 1;
}

int b()  {
    return 5;
}

int main() {
    a();

    return 0;
}