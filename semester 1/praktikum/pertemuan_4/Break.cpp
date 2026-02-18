#include <iostream>
using namespace std;

int main() {
    int i = 0;

    // break

    // while (true) {
    //     cout << i << endl;
    //     if (i == 5) {
    //         break;
    //     }         
    //     i++;
    // }

    while (i < 10) {
        i++;
        if (i == 5) {
            continue;
        }         
        cout << i << endl;
    }

    return 0;
}