#include <iostream>
#include <iomanip>
using namespace std;

float kubus(int p);
float balok(int p, int l, int t);
float tabung(int r, int t);
float bola(int r);
float kerucut(int r, int t);
float limassegitiga(int a, int l, int t);
float limaspersegi(int p, int l, int t);
float prismasegitiga(int a, int l, int t);

float persegi(int p);
float persegipanjang(int p, int l);
float segitiga(int a, int t);
float lingkaran(int r);
float jajargenjang(int p, int l);
float belahketupat(int d1, int d2);
float layanglayang(int d1, int d2);
float trapesium(int a1, int a2, int t);

void menu(int pill);

int main(){
    cout << setw(70) << setfill('-') << " " << endl;
    string nama, nim;
    cout << setw(10) << setfill(' ') << " " << "NAMA ANDA : ";
    getline(cin, nama);
    cout << setw(10) << setfill(' ') << " " << "NIM       : ";
    cin >> nim;
    cout << setw(70) << setfill('-') << " " << endl;
    int pill;
    cout << "program menghitung luas bangun datar atau volume bangun ruang" << endl;
    cout << "bangun datar [1] / ruang[2] : ";
    cin >> pill;
    menu(pill);

}

float kubus(int p){
    float volume;
    cout << "masukan panjang sisi kubus : ";
    cin >> p;
    volume = p*p*p;
    cout << "volume kubus tersebut " << volume;
    return volume;
}

float balok(int p, int l, int t){
    float volume;
    cout << "masukan panjang sisi balok : ";
    cin >> p;
    cout << "masukan lebar sisi balok : ";
    cin >> l;
    cout << "masukan tinggi sisi balok : ";
    cin >> t;
    volume = p*l*t;
    cout << "volume kubus tersebut " << volume << endl;
    return volume;
}

float tabung(int r, int t){
    float volume;
    cout << "masukan jari jari tabung : ";
    cin >> r;
    cout << "masukan tinggi tabung : ";
    cin >> t;
    volume = (r*r*t)*3.14;
    cout << "volume tabung tersebut " << volume << endl;
    return volume;
}



float kerucut(int r, int t){
    float volume;
    cout << "masukan jari jari kerucut : ";
    cin >> r;
    cout << "masukan tinggi kerucut : ";
    cin >> t;
    volume = ((r*r*t)*3.14)/3;
    cout << "volume kerucut tersebut " << volume << endl;
    return volume;
}

float limassegitiga(int a, int l, int t){
    float volume;
    cout << "masukan alas segitiga : ";
    cin >> a;
    cout << "masukan tinggi segitiga : ";
    cin >> l;
    cout << "masukan tinggi limas segitiga : ";
    cin >> t;
    volume = (((a*l)/2)*t)/3;
    cout << "volume limas segitiga tersebut " << volume << endl;
    return volume;
}

float limaspersegi(int p, int l, int t){
    float volume;
    cout << "masukan panjang limas persegi : ";
    cin >> p;
    cout << "masukan lebar limas persegi : ";
    cin >> l;
    cout << "masukan tinggi limas persegi : ";
    cin >> t;
    volume = (p*l*t)/3;
    cout << "volume limas persegi tersebut " << volume << endl;
    return volume;
}

float prismasegitiga(int a, int l, int t){
    float volume;
    cout << "masukan alas segitiga : ";
    cin >> a;
    cout << "masukan tinggi segitiga : ";
    cin >> l;
    cout << "masukan tinggi prisma segitiga : ";
    cin >> t;
    volume = (((a*l)/2)*t);
    cout << "volume prisma segitiga tersebut " << volume << endl;
    return volume;
}

float persegi(int p){
    float luas;
    cout << "masukan panjang sisi peregi : ";
    cin >> p;
    luas = p*p;
    cout << "persegi tersebut " << luas;
    return luas;
}

float jajargenjang(int p, int l){
    float luas;
    cout << "masukan alas jajar genjang : ";
    cin >> p;
    cout << "masukan lebar jajar genjang : ";
    cin >> l;
    luas = p*l;
    cout << "luas jajar genjang tersebut " << luas << endl;
    return luas;
}

float persegipanjang(int p, int l){
    float luas;
    cout << "masukan panjang sisi persegi panjang : ";
    cin >> p;
    cout << "masukan lebar sisi persegi panjang : ";
    cin >> l;
    luas = p*l;
    cout << "luas persegi panjang tersebut " << luas << endl;
    return luas;
}

float lingkaran(int r){
    float luas;
    cout << "masukan jari jari lingkaran : ";
    cin >> r;
    luas = (r*r)*3.14;
    cout << "luas lingkaran tersebut " << luas << endl;
    return luas;
}

float belahketupat(int d1, int d2){
    float luas;
    cout << "masukan diagonal 1 belah ketupat : ";
    cin >> d1;
    cout << "masukan diagonal 2 belah ketupat : ";
    cin >> d2;
    luas = (d1*d2)/2;
    cout << "luas belah ketupat tersebut tersebut " << luas << endl;
    return luas;
}

float layanglayang(int d1, int d2){
    float luas;
    cout << "masukan diagonal 1 layang layang: ";
    cin >> d1;
    cout << "masukan diagonal 2 layang layang : ";
    cin >> d2;
    luas = (d1*d2)/2;
    cout << "luas layang layang tersebut " << luas << endl;
    return luas;
}

float trapesium(int a1, int a2, int t){
    float luas;
    cout << "masukan alas atas  trapesium : ";
    cin >> a1;
    cout << "masukan alas bawah  trapesium : ";
    cin >> a2;
    cout << "masukan tinggi  trapesium : ";
    cin >> t;
    luas = ((a1 +a2)*t)/2;
    cout << "luas  trapesium tersebut " << luas << endl;
    return luas;
}

float segitiga(int a, int t){
    float luas;
    cout << "masukan alas segitiga : ";
    cin >> a;
    cout << "masukan tinggi segitiga : ";
    cin >> t;
    luas = (a*t)/2;
    cout << "luas  segitiga tersebut " << luas << endl;
    return luas;
}
float bola(int r){
    float volume;
    cout << "masukan jari jari bola : ";
    cin >> r;
    volume = (((r*r*r)*3.14)*4)/3;
    cout << "volume bola tersebut " << volume << endl;
    return volume;
}

void menu(int pill){
    int p, l, t, a, r, d1, d2, a1, a2;
    switch(pill)
    {
    case 1:
        int pilll;
        cout << "menghitung bangun datar"<<endl;
        cout << "1. persegi"<<endl;
        cout << "2. persegi panjang"<<endl;
        cout << "3. segitiga"<<endl;
        cout << "4. lingkaran"<<endl;
        cout << "5. jajar genjang"<<endl;
        cout << "6. belah ketupat"<<endl;
        cout << "7. layang layang"<<endl;
        cout << "8. trapesium"<<endl;
        cout << "masukkan pilihan anda : ";
        cin >> pilll;
        switch (pilll)
        {
        case 1:
            persegi(p);
            break;
        case 2:
            persegipanjang(p,l);
        break;
        case 3:
            segitiga(a,t);
        break;
        case 4:
            lingkaran(r);
        break;
        case 5:
            jajargenjang(p,l);
        break;
        case 6:
            belahketupat(d1,d2);
        break;
        case 7:
            layanglayang(d1,d2);
        break;
        case 8:
            trapesium(a1,a2,t);
        break;
        default:
            break;
        }
    break;
        case 2:
        int pil;
        cout << "menghitung bangun ruang"<<endl;
        cout << "1. kubus"<<endl;
        cout << "2. balok"<<endl;
        cout << "3. tabung"<<endl;
        cout << "4. bola"<<endl;
        cout << "5. kerucut"<<endl;
        cout << "6. limas segitiga"<<endl;
        cout << "7. limas segiempat"<<endl;
        cout << "8. prisma segitiga"<<endl;
        cout << "masukkan pilihan anda : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            kubus(p);
            break;
        case 2:
            balok(p,l, t);
        break;
        case 3:
            tabung(r,t);
        break;
        case 4:
            bola(r);
        break;
        case 5:
            kerucut(r,t);
        break;
        case 6:
            limassegitiga(a, l, t);
        break;
        case 7:
            limaspersegi(p, l, t);
        break;
        case 8:
            prismasegitiga(a, l, t);
        break;
        default:
            break;
        }

    break;
}
}