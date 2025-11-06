#include <iostream>

using namespace std;

int b = 1;
void uas(int a, int *c);

int main() {
    int a, c;
    a = 3;
    b = 1;
    c = 2;
    cout << a << " " << b << " " << c << " " << endl;
    uas(a, &c);
    cout << a << " " << b << " " << c << " " << endl;
    a = 2;
    b = 4;
    c = 3;
    cout << a << " " << b << " " << c << " " << endl;
    uas(c, &a);
    cout << a << " " << b << " " << c << " " << endl;

    return 0;
}

void uas(int a, int *c) {
    a = b + *c;
    *c = 10 + b;
    b = 5-*c;
}