#include <iostream>

using namespace std;

int *fib(int var) {
    int *result = new int[var];
    result[0] = 1;
    result[1] = 2;
    for (int i = 2; i < var; i++)
    {
        result[i] = result[i-1] + result[i-2];
    }
    return result;
}

int main() {
    int len = 10;

    int *b = fib(len);
    for (int i = 0; i < len; i++)
    {
        cout << b[i] << " ";
    }
    

    return 0;
}