#include <iostream>

using namespace std;

// void addNum(int *a) {
//     (*a)++;
//     cout << a << endl;
// }
void addNum(int *a) {
    (*a)++;
    cout << a << endl;
}

void changePtr(int *ptr) {
    ptr = (int *)malloc(sizeof(int));
    *ptr =  7;
    cout << &ptr << endl;
    cout << *ptr << endl;
}

int main() {
    // int b = 6;
    // addNum(&b);
    // cout << b << endl;
    int *ptr = (int *)malloc(sizeof(int));
    *ptr =  5;
    changePtr(ptr);
    cout << &ptr << endl;
    cout << *ptr << endl;

    return 0;
}