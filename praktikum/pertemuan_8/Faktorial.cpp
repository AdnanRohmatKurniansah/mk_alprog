#include <iostream>

using namespace std;

int faktorial(int number) {
    if (number <= 1) {
        cout << number << " ";
        return number;
    } else {
        cout << number << " ";
        return number * faktorial(number - 1);
    }
}

int main() {
    int number, result;

    cout << "Menghitung faktorial: ";
    cin >> number;

    result = faktorial(number);
    cout << "\nNilai faktorialnya adalah: " << result << endl;

    return 0;
}
