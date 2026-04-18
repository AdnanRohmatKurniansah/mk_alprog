/*
 * ============================================================
 *   DUNGEON QUEST - Text RPG Game in C++
 * ============================================================
 * Materi yang diterapkan:
 *  - Function        : fungsi modular untuk setiap fitur
 *  - Struct          : Hero, Monster, Item, ScoreEntry
 *  - Array           : inventory, monster pool, leaderboard
 *  - Sorting         : bubble sort leaderboard, selection sort inventory
 *  - Search          : linear search inventory, binary search shop
 *  - File I/O        : simpan/load hero (save.dat), leaderboard (scores.txt)
 *  - Pointer         : pass-by-pointer untuk modifikasi Hero & Monster
 *  - Rekursif        : exploreDungeon (floor ke floor), calcExpNeeded
 * ============================================================
 */

#include <iostream>
#include <fstream>       // <-- FILE I/O
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

// ============================================================
// STRUCT
// ============================================================
struct Item {
    string name;
    int healAmount;
    int attackBonus;
    int defenseBonus;
};

struct Hero {
    string name;
    int hp, maxHp;
    int attack, defense;
    int gold, score;
    int level, exp;
    Item inventory[5];
    int itemCount;
};

struct Monster {
    string name;
    int hp, maxHp;
    int attack, defense;
    int expReward, goldReward;
};

struct ScoreEntry {
    string heroName;
    int score;
    int floor;
};

// ============================================================
// GLOBAL DATA
// ============================================================
const int MAX_SCORES = 5;
const string SAVE_FILE  = "save.dat";
const string SCORE_FILE = "scores.txt";

Monster monsterPool[6] = {
    {"Goblin",       20,  20,  5,  2,  10,  5},
    {"Orc",          40,  40, 10,  5,  25, 15},
    {"Skeleton",     30,  30,  8,  3,  15,  8},
    {"Dark Mage",    35,  35, 14,  1,  30, 20},
    {"Troll",        60,  60, 12,  8,  40, 25},
    {"Dragon Boss", 100, 100, 20, 10, 100, 80},
};

Item shopItems[5] = {
    {"Health Potion",  30, 0, 0},
    {"Great Potion",   60, 0, 0},
    {"Iron Sword",      0, 5, 0},
    {"Steel Shield",    0, 0, 4},
    {"Power Elixir",    0, 3, 3},
};
int shopPrices[5] = {20, 40, 50, 45, 80};

// ============================================================
// UTILITY
// ============================================================
void printLine(char c = '-', int n = 50) {
    for (int i = 0; i < n; i++) cout << c;
    cout << "\n";
}
void printTitle(const string& t) {
    printLine('=');
    cout << "  " << t << "\n";
    printLine('=');
}
int randInt(int lo, int hi) { return lo + rand() % (hi - lo + 1); }
void pause() {
    cout << "\n  [Tekan ENTER lanjut...]";
    cin.ignore(); cin.get();
}

// ============================================================
// FILE I/O — SAVE HERO
// Binary write seluruh struct Hero ke file
// ============================================================
void saveHero(const Hero* hero) {
    ofstream f(SAVE_FILE, ios::binary);
    if (!f) {
        cout << "  [!] Gagal membuka file untuk simpan.\n";
        return;
    }
    f.write(reinterpret_cast<const char*>(hero), sizeof(Hero));
    f.close();
    cout << "  [✓] Game tersimpan ke '" << SAVE_FILE << "'!\n";
}

// ============================================================
// FILE I/O — LOAD HERO
// Binary read struct Hero dari file; return false jika gagal
// ============================================================
bool loadHero(Hero* hero) {
    ifstream f(SAVE_FILE, ios::binary);
    if (!f) return false;
    f.read(reinterpret_cast<char*>(hero), sizeof(Hero));
    bool ok = f.good();
    f.close();
    return ok;
}

// ============================================================
// FILE I/O — SAVE LEADERBOARD
// Tulis ScoreEntry[] ke file teks baris per baris
// ============================================================
void saveScores(const ScoreEntry lb[], int n) {
    ofstream f(SCORE_FILE);
    if (!f) { cout << "  [!] Gagal menyimpan leaderboard.\n"; return; }
    f << n << "\n";
    for (int i = 0; i < n; i++) {
        f << lb[i].heroName << "\n"
          << lb[i].score    << "\n"
          << lb[i].floor    << "\n";
    }
    f.close();
}

// ============================================================
// FILE I/O — LOAD LEADERBOARD
// Baca baris per baris dari file teks ke ScoreEntry[]
// ============================================================
void loadScores(ScoreEntry lb[], int& n) {
    n = 0;
    ifstream f(SCORE_FILE);
    if (!f) return;
    f >> n;
    f.ignore();
    for (int i = 0; i < n; i++) {
        getline(f, lb[i].heroName);
        f >> lb[i].score >> lb[i].floor;
        f.ignore();
    }
    f.close();
}

// ============================================================
// SORTING — Bubble Sort leaderboard descending by score
// Swap dilakukan via pointer
// ============================================================
void swapEntry(ScoreEntry* a, ScoreEntry* b) {
    ScoreEntry tmp = *a; *a = *b; *b = tmp;
}

void bubbleSortScores(ScoreEntry lb[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (lb[j].score < lb[j+1].score)
                swapEntry(&lb[j], &lb[j+1]);
}

// ============================================================
// SORTING — Selection Sort inventory ascending by healAmount
// ============================================================
void selectionSortInventory(Hero* hero) {
    int n = hero->itemCount;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (hero->inventory[j].healAmount < hero->inventory[minIdx].healAmount)
                minIdx = j;
        if (minIdx != i) {
            Item tmp = hero->inventory[i];
            hero->inventory[i] = hero->inventory[minIdx];
            hero->inventory[minIdx] = tmp;
        }
    }
}

// ============================================================
// SEARCH — Linear Search: cari item di inventory by name
// ============================================================
int linearSearchInventory(const Hero* hero, const string& name) {
    for (int i = 0; i < hero->itemCount; i++)
        if (hero->inventory[i].name == name) return i;
    return -1;
}

// ============================================================
// SEARCH — Binary Search: cari item di toko by name
// (shop array sudah diurutkan abjad sebelum dipanggil)
// ============================================================
int binarySearchShop(const string& name) {
    int lo = 0, hi = 4;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if      (shopItems[mid].name == name) return mid;
        else if (shopItems[mid].name  < name) lo = mid + 1;
        else                                  hi = mid - 1;
    }
    return -1;
}

// Sort shop items by name (prerequisite binary search)
void sortShopByName() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4 - i; j++)
            if (shopItems[j].name > shopItems[j+1].name) {
                Item ti = shopItems[j]; shopItems[j] = shopItems[j+1]; shopItems[j+1] = ti;
                int  tp = shopPrices[j]; shopPrices[j] = shopPrices[j+1]; shopPrices[j+1] = tp;
            }
}

// ============================================================
// REKURSIF 1 — Hitung EXP yang dibutuhkan naik level
// expNeeded(level) = 30 + expNeeded(level-1)
// ============================================================
int calcExpNeeded(int level) {
    if (level <= 1) return 30;
    return 30 + calcExpNeeded(level - 1);
}

// ============================================================
// HERO FUNCTIONS
// ============================================================
void initHero(Hero* h, const string& name) {
    h->name      = name;
    h->hp = h->maxHp = 80;
    h->attack    = 12;
    h->defense   = 5;
    h->gold      = 30;
    h->score     = 0;
    h->level     = 1;
    h->exp       = 0;
    h->itemCount = 1;
    h->inventory[0] = {"Health Potion", 30, 0, 0};
}

void printHeroStats(const Hero* h) {
    printLine();
    cout << "  Hero   : " << h->name << "  (Level " << h->level << ")\n";
    cout << "  HP     : " << h->hp << "/" << h->maxHp << "\n";
    cout << "  ATK    : " << h->attack << "   DEF: " << h->defense << "\n";
    cout << "  Gold   : " << h->gold  << "   Score: " << h->score  << "\n";
    cout << "  EXP    : " << h->exp   << "/" << calcExpNeeded(h->level) << "\n";
    printLine();
}

void gainExp(Hero* h, int exp) {
    h->exp += exp;
    int needed = calcExpNeeded(h->level); // rekursif
    if (h->exp >= needed) {
        h->exp -= needed;
        h->level++;
        h->maxHp  += 15; h->hp = h->maxHp;
        h->attack += 3;  h->defense += 1;
        cout << "\n  *** LEVEL UP! Level " << h->level << " ***\n";
    }
}

// ============================================================
// ITEM
// ============================================================
void useItem(Hero* h, int idx) {
    Item& it = h->inventory[idx];
    if (it.healAmount > 0) {
        int heal = min(it.healAmount, h->maxHp - h->hp);
        h->hp += heal;
        cout << "  Pakai " << it.name << " -> HP +" << heal
             << " (HP: " << h->hp << ")\n";
    } else {
        h->attack  += it.attackBonus;
        h->defense += it.defenseBonus;
        cout << "  Pakai " << it.name << " -> ATK +" << it.attackBonus
             << " DEF +" << it.defenseBonus << "\n";
    }
    for (int i = idx; i < h->itemCount - 1; i++)
        h->inventory[i] = h->inventory[i+1];
    h->itemCount--;
}

void showInventory(Hero* h) {
    selectionSortInventory(h); // sort sebelum tampil
    printTitle("INVENTORY");
    if (h->itemCount == 0) { cout << "  (kosong)\n"; return; }
    for (int i = 0; i < h->itemCount; i++) {
        cout << "  [" << i+1 << "] " << left << setw(18) << h->inventory[i].name;
        if (h->inventory[i].healAmount > 0)
            cout << "Heal +" << h->inventory[i].healAmount;
        else
            cout << "ATK +" << h->inventory[i].attackBonus
                 << " DEF +" << h->inventory[i].defenseBonus;
        cout << "\n";
    }
    cout << "  [0] Batal\n  Gunakan item ke: ";
    int ch; cin >> ch;
    if (ch >= 1 && ch <= h->itemCount) useItem(h, ch - 1);
}

// ============================================================
// SHOP
// ============================================================
void visitShop(Hero* h) {
    sortShopByName(); // sort dulu agar binary search valid

    printTitle("TOKO BARANG");
    cout << "  Gold kamu: " << h->gold << "\n\n";
    for (int i = 0; i < 5; i++) {
        cout << "  [" << i+1 << "] " << left << setw(18) << shopItems[i].name
             << "  " << shopPrices[i] << " gold\n";
    }

    // Demo binary search
    int found = binarySearchShop("Iron Sword");
    if (found != -1)
        cout << "\n  [Binary Search] 'Iron Sword' ada di slot " << found << "\n";

    cout << "\n  Beli item (1-5, 0=batal): ";
    int ch; cin >> ch;
    if (ch >= 1 && ch <= 5) {
        int idx = ch - 1;
        if (h->gold < shopPrices[idx])
            cout << "  Gold tidak cukup!\n";
        else if (h->itemCount >= 5)
            cout << "  Inventory penuh!\n";
        else {
            // Cek duplikat dengan linear search
            int dup = linearSearchInventory(h, shopItems[idx].name);
            if (dup != -1 && shopItems[idx].healAmount == 0)
                cout << "  Item equipment ini sudah kamu punya.\n";
            else {
                h->gold -= shopPrices[idx];
                h->inventory[h->itemCount++] = shopItems[idx];
                cout << "  Berhasil membeli " << shopItems[idx].name << "!\n";
            }
        }
    }
}

// ============================================================
// LEADERBOARD
// ============================================================
void addScore(const Hero* h, int floor) {
    ScoreEntry lb[MAX_SCORES + 1];
    int n = 0;
    loadScores(lb, n); // FILE I/O: baca dari file

    ScoreEntry entry = {h->name, h->score, floor};
    if (n < MAX_SCORES) {
        lb[n++] = entry;
    } else {
        lb[MAX_SCORES] = entry;
        n = MAX_SCORES + 1;
    }
    bubbleSortScores(lb, n);
    if (n > MAX_SCORES) n = MAX_SCORES;
    saveScores(lb, n); // FILE I/O: simpan ke file
}

void showLeaderboard() {
    ScoreEntry lb[MAX_SCORES];
    int n = 0;
    loadScores(lb, n); // FILE I/O: baca dari file
    bubbleSortScores(lb, n);

    printTitle("LEADERBOARD TOP " + to_string(MAX_SCORES));
    if (n == 0) { cout << "  (Belum ada data)\n"; return; }
    cout << "  " << left << setw(4) << "No"
         << setw(16) << "Nama"
         << setw(10) << "Score"
         << "Lantai\n";
    printLine();
    for (int i = 0; i < n; i++) {
        cout << "  " << left << setw(4) << i+1
             << setw(16) << lb[i].heroName
             << setw(10) << lb[i].score
             << lb[i].floor << "\n";
    }
}

// ============================================================
// COMBAT
// ============================================================
void heroAttack(Hero* h, Monster* m) {
    int dmg = max(1, h->attack - m->defense / 2 + randInt(-2, 3));
    m->hp -= dmg;
    cout << "  >> " << h->name << " menyerang " << m->name << " [" << dmg << " dmg]!\n";
}
void monsterAttack(Monster* m, Hero* h) {
    int dmg = max(1, m->attack - h->defense / 2 + randInt(-2, 3));
    h->hp -= dmg;
    cout << "  << " << m->name << " menyerang balik [" << dmg << " dmg]!\n";
}

bool doBattle(Hero* h, Monster* m) {
    printTitle("PERTEMPURAN!");
    cout << "  " << h->name << " vs " << m->name << "\n";
    printLine();

    while (h->hp > 0 && m->hp > 0) {
        cout << "\n  HP Kamu: " << h->hp << "   HP " << m->name << ": " << m->hp << "\n";
        cout << "  [1] Serang  [2] Pakai Item  [3] Kabur\n  > ";
        int act; cin >> act;

        if (act == 1) {
            heroAttack(h, m);
            if (m->hp <= 0) break;
            monsterAttack(m, h);
        } else if (act == 2) {
            showInventory(h);
        } else {
            cout << "  Kamu kabur!\n";
            return false;
        }
    }

    if (h->hp <= 0) {
        cout << "\n  *** KAMU KALAH! ***\n";
        return false;
    }
    cout << "\n  *** " << m->name << " DIKALAHKAN! ***\n";
    cout << "  +" << m->expReward << " EXP   +" << m->goldReward << " Gold\n";
    h->gold  += m->goldReward;
    h->score += m->expReward * 2;
    gainExp(h, m->expReward);
    return true;
}

// ============================================================
// REKURSIF 2 — Explore Dungeon lantai per lantai
// ============================================================
void exploreDungeon(Hero* h, int floor, int maxFloor) {
    if (h->hp <= 0 || floor > maxFloor) {  // base case
        if (floor > maxFloor) {
            cout << "\n  *** Kamu menaklukkan seluruh dungeon! ***\n";
            h->score += 300;
            cout << "  Bonus score +300!\n";
        }
        return;
    }

    printTitle("DUNGEON LANTAI " + to_string(floor) + " / " + to_string(maxFloor));

    Monster enemy = (floor == maxFloor) ? monsterPool[5] : monsterPool[randInt(0, 4)];
    if (floor == maxFloor) cout << "  !! BOSS FLOOR !!\n";
    cout << "  Musuh: " << enemy.name << " (HP:" << enemy.hp << " ATK:" << enemy.attack << ")\n\n";

    cout << "  [1] Bertarung\n";
    cout << "  [2] Toko" << (floor % 2 == 0 ? "" : " (N/A lantai ini)") << "\n";
    cout << "  [3] Status hero\n";
    cout << "  [4] Simpan game\n";   // FILE I/O dipanggil dari sini
    cout << "  > ";

    int ch; cin >> ch;
    if (ch == 2) {
        if (floor % 2 == 0) visitShop(h);
        else cout << "  Tidak ada toko di lantai ganjil.\n";
    } else if (ch == 3) {
        printHeroStats(h);
    } else if (ch == 4) {
        saveHero(h); // FILE I/O: simpan hero ke binary file
    }

    bool won = doBattle(h, &enemy);
    if (!won && h->hp <= 0) return;

    pause();
    exploreDungeon(h, floor + 1, maxFloor); // REKURSIF
}

// ============================================================
// MAIN MENU
// ============================================================
void startGame() {
    Hero hero;
    cout << "\n  Nama hero: ";
    cin.ignore(); getline(cin, hero.name);
    initHero(&hero, hero.name);

    cout << "\n  Pilih kesulitan:\n";
    cout << "  [1] Mudah  (3 lantai)\n";
    cout << "  [2] Normal (5 lantai)\n";
    cout << "  [3] Sulit  (7 lantai)\n  > ";
    int diff; cin >> diff;
    int maxFloor = (diff == 1) ? 3 : (diff == 2) ? 5 : 7;

    cout << "\n  Selamat datang, " << hero.name << "!\n";
    cout << "  " << maxFloor << " lantai menanti. Boss di lantai terakhir!\n";
    pause();

    exploreDungeon(&hero, 1, maxFloor); // REKURSIF mulai lantai 1

    cout << "\n"; printHeroStats(&hero);
    cout << "  Skor akhir: " << hero.score << "\n";
    addScore(&hero, maxFloor); // simpan ke leaderboard (FILE I/O)
    showLeaderboard();
    pause();
}

void loadAndContinue() {
    Hero hero;
    if (!loadHero(&hero)) { // FILE I/O: baca binary file
        cout << "  [!] File save tidak ditemukan!\n";
        pause();
        return;
    }
    cout << "  [✓] Data dimuat dari '" << SAVE_FILE << "'!\n";
    printHeroStats(&hero);

    cout << "\n  Lanjut dari lantai berapa?\n";
    cout << "  [1] Mudah (3)  [2] Normal (5)  [3] Sulit (7)\n  > ";
    int diff; cin >> diff;
    int maxFloor = (diff == 1) ? 3 : (diff == 2) ? 5 : 7;

    exploreDungeon(&hero, 1, maxFloor);

    addScore(&hero, maxFloor);
    showLeaderboard();
    pause();
}

int main() {
    srand((unsigned)time(nullptr));

    int choice;
    do {
        printLine('=');
        cout << "  *** DUNGEON QUEST - Text RPG C++ ***\n";
        printLine('=');
        cout << "  [1] Main Baru\n";
        cout << "  [2] Load Game      (File I/O: baca save.dat)\n";
        cout << "  [3] Leaderboard    (File I/O: baca scores.txt)\n";
        cout << "  [4] Keluar\n  > ";
        cin >> choice;

        switch (choice) {
            case 1: startGame();       break;
            case 2: loadAndContinue(); break;
            case 3: showLeaderboard(); pause(); break;
            case 4: cout << "  Sampai jumpa!\n"; break;
        }
    } while (choice != 4);

    return 0;
}