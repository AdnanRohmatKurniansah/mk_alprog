#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
    FILE *pf; // pointer file
    char kar;

    if ((pf = fopen("coba.txt", "a")) == NULL) //ciptakan file
    {
        cout << "File tdk dpt diciptakan! \r\n";
        exit(1); 
    }
    
    while ((kar = getchar()) != EOF) { // baca karakter dari keyboard
        fputc(kar, pf); // tulis ke file
    }
    
    fclose(pf); // tutup file

    return 0;
}