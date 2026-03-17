#include <iostream>

using namespace std;

struct Senjata {
    string id_senjata;
    string nama_senjata;
    string tipe;
    double base_damage;
};

bool ulang = false;

void kembaliMenu();
void lihatSenjata(Senjata senjata[50], int *jmlSenjata);
void tambahSenjata(Senjata senjata[50], int *jmlSenjata);
void cariSenjata(Senjata senjata[50], int *jmlSenjata);

double levelUp(double baseDamage, int levelSenjata);

int main() {
    Senjata senjata[50];
    int pilMenu;
    int jmlSenjata = 0;
   
    do {
        cout << "== Menu ==" << endl;
        cout << "1. Tambah Senjata" << endl;
        cout << "2. Lihat Inventory" << endl;
        cout << "3. Cari Senjata" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih Menu: ";
        cin >> pilMenu;

        cin.ignore();

        switch (pilMenu) {
            case 1:
                system("cls");
                ulang = false;

                tambahSenjata(senjata, &jmlSenjata);

                kembaliMenu();
                break;
            case 2:
                system("cls");
                ulang = false;

                lihatSenjata(senjata, &jmlSenjata);

                kembaliMenu();
                break;
            case 3: 
                system("cls");
                ulang = false;

                cariSenjata(senjata, &jmlSenjata);
                break;
            case 4:
                system("cls");
                ulang = false;

                cout << "\nTelah keluar dari program...\n" << endl;
                exit(0);

                break;
            default:
                ulang = true;
                system("cls");
                cout << "Menu tdk tersedia, Ulangi...\n" << endl;
                break;
        }
    } while (ulang == true);

    return 0;
}

void lihatSenjata(Senjata senjata[50], int *jmlSenjata) {
    cout << "== Lihat Inventory ==" << endl;

    if (*jmlSenjata != 0) {
        for (int i = 0; i < *jmlSenjata; i++) {
            cout << "Senjata ke-" << i+1 << endl;
            cout << "---------------" << endl;
            cout << "Id Senjata : " << senjata[i].id_senjata << endl;
            cout << "Nama Senjata : " << senjata[i].nama_senjata << endl;
            cout << "Tipe : " << senjata[i].tipe << endl;
            cout << "Base Damage: " << senjata[i].base_damage << endl;
            cout << endl;
        }
    } else {
        cout << "Inventory masih kosong.." << endl;
        cout << "Silahkan tambah dulu.." << endl;
    }
}

void tambahSenjata(Senjata senjata[50], int *jmlSenjata) {
    cout << "== Tambah Senjata ==" << endl;

    if (*jmlSenjata >= 50) {
        cout << "Inventory penuh! Maksimum 50 senjata." << endl;
    } else {
        cout << "Senjata ke-" << *jmlSenjata+1 << endl;
        cout << "---------------" << endl;
        cout << "Id Senjata : ";
        getline(cin, senjata[*jmlSenjata].id_senjata);
        cout << "Nama Senjata : ";
        getline(cin, senjata[*jmlSenjata].nama_senjata);
        cout << "Tipe (Melee/Ranged) : ";
        getline(cin, senjata[*jmlSenjata].tipe);
        cout << "Base Damage : ";
        cin >> senjata[*jmlSenjata].base_damage;
        cin.ignore();
    
        cout << endl;
    
        *jmlSenjata += 1;
    
        cout << "Berhasil menambahkan senjata..." << endl;
    }
}

void cariSenjata(Senjata senjata[50], int *jmlSenjata) {
    int i = 0;
    int levelSenjata = 1;
    double finalDamage;
    string id_pencarian;
    bool found = false;

    cout << "== Cari Senjata ==" << endl;

    if (*jmlSenjata != 0) {
        cout << "Masukkan 'id senjata' yg dicari : ";
        getline(cin, id_pencarian);

        while (i < *jmlSenjata && !found) {
            if (senjata[i].id_senjata == id_pencarian) {
                found = true;

                cout << "\nSenjata ditemukan :" << endl;
                cout << "Id Senjata : " << senjata[i].id_senjata << endl;
                cout << "Nama Senjata : " << senjata[i].nama_senjata << endl;
                cout << "Tipe : " << senjata[i].tipe << endl;
                cout << "Base Damage : " << senjata[i].base_damage << endl;

                cout << "\n== Up Level Senjata ==" << endl;
                cout << "Masukkan Level Upgrade : ";
                cin >> levelSenjata;
                cin.ignore();

                finalDamage = levelUp(senjata[i].base_damage, levelSenjata);

                cout << "\nDamage setelah upgrade level " << levelSenjata << " = " << finalDamage << endl;
            } else {
                i++;
            }
        }

        if (!found) {
            cout << "\nSenjata dgn 'id senjata' " << id_pencarian << " tdk ditemukan!!" << endl;
        }
    } else {
        cout << "Inventory masih kosong.." << endl;
        cout << "Silahkan tambah dulu.." << endl;
    }

    kembaliMenu();
}

double levelUp(double baseDamage, int levelSenjata) {
    if (levelSenjata == 1) return baseDamage;
    
    double prevDamage = levelUp(baseDamage, levelSenjata - 1);

    return prevDamage + (prevDamage * 0.10) + 50;
}

void kembaliMenu() {
	char kembali;

    cout << "\nKembali ke menu utama? (Y/N): ";
	cin >> kembali;
				
    if (kembali == 'y' || kembali == 'Y') {
		ulang = true;
		system("cls");
	} else {
		system("cls");
		cout << "\nTelah keluar dari program...\n" << endl;
		exit(0);
	}
}