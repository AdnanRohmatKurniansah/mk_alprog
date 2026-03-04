#include <iostream>

using namespace std;

int main() {
    int A[3][2];

    cout << "== Menampilkan Matriks Transpose ==" << endl;
    cout << "Input nilai matriks:" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Masukkan nilai, baris ke-" << i+1 << " , kolom ke-" << j+1 << " : ";
            cin >> A[i][j];
        }
        
    }

    system("cls");

    cout << "\nMatriks Asli (3x2):" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
           cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "\nMatriks Transpose (2x3):" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           cout << A[j][i] << " ";
        }
        cout << endl;
    }
    

    return 0;
}