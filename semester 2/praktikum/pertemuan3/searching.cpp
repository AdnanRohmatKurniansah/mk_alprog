#include <iostream>
using namespace std;

int binarySearch(int data[], int size, int target)
{
    int indeks_kiri, indeks_kanan, pivot;
    indeks_kiri = 0;
    indeks_kanan = size - 1;
    bool found = false;
    // true && false = false
    while ((!found) && (indeks_kiri <= indeks_kanan))
    {
        pivot = indeks_kiri + (indeks_kanan - indeks_kiri) / 2;
        // pivot = (indeks_kanan + indeks_kiri) / 2; // cara ke dua
        if (data[pivot] == target)
        {
            return pivot;
        }
        else
        {
            if (data[pivot] > target)
            {
                indeks_kanan = pivot - 1;
            }
            else // opsional if (data[pivot] < target)
            {
                indeks_kiri = pivot + 1;
            }
        }
    }
    return -1; // ketemu
}

int LinSearch(int arr[], int size, int target)
{
    int index_target = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            index_target = i;
            break;
        }
    }
    return index_target;
}

int LinSearchSum(int arr[], int size, int target)
{
    int jumlahTarget = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            jumlahTarget++;
        }
    }
    return jumlahTarget;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 10, 12, 15, 19, 20};
    int indeks_cari = binarySearch(arr, 12, 15);
    cout << indeks_cari << endl;
}
