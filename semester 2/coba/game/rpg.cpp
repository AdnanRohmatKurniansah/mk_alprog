/*
 * ============================================================
 *   DUNGEON QUEST v2 - Text RPG C++
 * ============================================================
 * Materi:
 *  - Function   : semua fitur terbungkus fungsi modular
 *  - Struct      : Hero, Monster, Item, Skill, ScoreEntry
 *  - Array       : inventory, monster pool, skill list, leaderboard
 *  - Sorting     : bubble sort leaderboard, selection sort inventory
 *  - Search      : linear search inventory/shop, binary search monster
 *  - File I/O    : save/load hero (save.dat), leaderboard (scores.txt)
 *  - Pointer     : modifikasi Hero & Monster via pointer
 *  - Rekursif    : calcExpNeeded, dungeonExplore
 * ============================================================
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <cstring>
using namespace std;

// ─────────────────────────────────────────────
// KONSTANTA
// ─────────────────────────────────────────────
const int MAX_INV       = 10;
const int MAX_SKILL     = 4;
const int MAX_SCORES    = 5;
const int MAX_MON_POOL  = 8;
const int MAX_SHOP_ITEM = 10;
const string SAVE_FILE  = "save.dat";
const string SCORE_FILE = "scores.txt";

// ─────────────────────────────────────────────
// STRUCT
// ─────────────────────────────────────────────

// Tipe item
enum ItemType { ITEM_WEAPON=0, ITEM_ARMOR, ITEM_ACCESSORY, ITEM_POTION, ITEM_MATL };
const string ITEM_TYPE_NAME[] = {"Weapon","Armor","Accessory","Potion","Material"};

struct Item {
    string   name;
    ItemType type;
    int      value;       // harga jual/beli dasar
    // Stat bonus (untuk equipment)
    int      bonusAtk;    // scaling dari STR
    int      bonusDef;    // scaling dari DEF
    int      bonusMAtk;   // scaling dari INT
    int      bonusMDef;
    int      bonusHP;
    int      bonusMP;
    int      healHP;      // untuk potion
    int      healMP;
    bool     equipped;
};

// Stats dasar hero
struct Stats {
    int vit;   // max HP = vit*12
    int mind;  // max MP = mind*8
    int str;   // physical atk scaling
    int def;   // physical def scaling
    int dex;   // crit chance, evasion
    int intel; // magic atk scaling
    int res;   // magic resistance
};

// Skill hero
struct Skill {
    string name;
    int    mpCost;
    // 0=physical, 1=magic
    int    type;
    // multiplier damage (persen dari base atk, misal 150 = 1.5x)
    int    mult;
    string desc;
    // efek tambahan
    bool   canStun;
    bool   canHeal;  // skill heal
    int    healPct;  // persen max HP yang di-heal
};

struct Hero {
    string name;
    string className;   // Knight, Ranger, Mage, Warrior, Assassin
    Stats  base;        // stat dasar tanpa equipment
    Stats  total;       // stat setelah equipment
    int    hp, maxHp;
    int    mp, maxMp;
    int    level, exp;
    int    statPoints;  // point untuk naik stat saat level up
    int    gold;
    int    score;
    Item   inventory[MAX_INV];
    int    invCount;
    // slot equipment
    int    eqWeapon;    // index di inventory, -1 jika kosong
    int    eqArmor;
    int    eqAccessory;
    Skill  skills[MAX_SKILL];
    int    skillCount;
    // progress
    int    dungeonFloor;
    int    monstersKilled;
};

struct Monster {
    string name;
    int    hp, maxHp;
    int    mp, maxMp;
    int    atk;
    int    def;
    int    matk;
    int    mdef;
    int    expDrop;
    int    goldDrop;
    int    difficulty; // 1,2,3 (untuk binary search)
    bool   canHeal;
    int    healAmount;
    // item drop
    string dropItemName;
    int    dropChance;  // persen 0-100
    bool   isStunned;
};

struct ScoreEntry {
    char heroName[32];
    char className[16];
    int  level;
    int  gold;
    int  score;
    int  kills;
};

// ─────────────────────────────────────────────
// DATA GLOBAL - SHOP & MONSTER POOL
// ─────────────────────────────────────────────

Item shopCatalog[MAX_SHOP_ITEM] = {
    // name,            type,         val,  bAtk,bDef,bMAtk,bMDef,bHP,bMP,hHP,hMP,eq
    {"Health Potion",   ITEM_POTION,   30,   0,0,0,0,0,0, 40,0, false},
    {"Ether",           ITEM_POTION,   40,   0,0,0,0,0,0,  0,30, false},
    {"Elixir",          ITEM_POTION,   80,   0,0,0,0,0,0, 80,60, false},
    {"Iron Sword",      ITEM_WEAPON,  120,  15,0,0,0,0,0,  0,0, false},
    {"Steel Sword",     ITEM_WEAPON,  280,  30,0,0,0,0,0,  0,0, false},
    {"Oak Staff",       ITEM_WEAPON,  100,   0,0,18,0,0,0, 0,0, false},
    {"Crystal Staff",   ITEM_WEAPON,  250,   0,0,35,0,0,0, 0,0, false},
    {"Leather Armor",   ITEM_ARMOR,   100,   0,10,0,5,20,0,0,0, false},
    {"Chain Mail",      ITEM_ARMOR,   230,   0,22,0,10,40,0,0,0,false},
    {"Focus Ring",      ITEM_ACCESSORY,90,   5,0, 5,0, 0,15,0,0,false},
};
int shopCount = MAX_SHOP_ITEM;

// Monster pool — diurutkan by difficulty (penting untuk binary search)
Monster monsterPool[MAX_MON_POOL] = {
    //name,              hp,maxhp, mp,mmp, atk,def,matk,mdef,exp,gold,diff,heal,healAmt, drop,   dropChance
    {"Goblin",           30, 30,  0,  0,  8,  3,  0,  2,  15,  8,  1, false,0,  "Herb",        20},
    {"Forest Wolf",      45, 45,  0,  0, 12,  4,  0,  3,  20, 12,  1, false,0,  "Wolf Pelt",   15},
    {"Orc Warrior",      80, 80,  0,  0, 20,  8,  0,  4,  40, 20,  2, false,0,  "Orc Axe",     10},
    {"Dark Mage",        55, 55, 30, 30, 10,  2, 25,  8,  45, 25,  2,  true,15, "Spell Tome",  12},
    {"Stone Golem",     110,110,  0,  0, 18, 18,  0,  5,  55, 30,  2, false,0,  "Stone Shard", 8 },
    {"Vampire",          80, 80, 20, 20, 25,  5, 20, 10,  65, 35,  3,  true,20, "Blood Gem",   15},
    {"Troll Berserker", 150,150,  0,  0, 35, 12,  0,  5,  80, 45,  3, false,0,  "Troll Club",  8 },
    {"Lich King",       200,200, 80, 80, 30, 10, 50, 20, 120, 70,  3,  true,40, "Lich Crown",  20},
};

// ─────────────────────────────────────────────
// UTILITY
// ─────────────────────────────────────────────
void cls() { system("cls||clear"); }

void printLine(char c='-', int n=56) {
    for(int i=0;i<n;i++) cout<<c; cout<<"\n";
}

void header(const string& t) {
    cls();
    printLine('=');
    cout << setw(28+(int)t.size()/2) << t << "\n";
    printLine('=');
}

void pause(const string& msg="  [ENTER untuk lanjut...]") {
    cout << msg; cin.ignore(); cin.get();
}

int rnd(int lo, int hi) { return lo + rand()%(hi-lo+1); }

string itemTypeName(ItemType t) { return ITEM_TYPE_NAME[(int)t]; }

// ─────────────────────────────────────────────
// REKURSIF 1 — EXP threshold per level
// expNeeded(lv) = lv * 50 + expNeeded(lv-1)
// ─────────────────────────────────────────────
int calcExpNeeded(int lv) {
    if (lv <= 1) return 50;
    return lv * 50 + calcExpNeeded(lv - 1);
}

// ─────────────────────────────────────────────
// REKURSIF 2 — Total stat bonus dari level up (akumulatif)
// totalStatBonus(lv) = baseGain + totalStatBonus(lv-1)
// ─────────────────────────────────────────────
int totalStatBonus(int lv, int baseGain) {
    if (lv <= 1) return 0;
    return baseGain + totalStatBonus(lv - 1, baseGain);
}

// ─────────────────────────────────────────────
// FILE I/O
// ─────────────────────────────────────────────

// Save hero — binary write
void saveHero(const Hero* h) {
    ofstream f(SAVE_FILE, ios::binary);
    if (!f) { cout << "  [!] Gagal simpan game.\n"; return; }
    f.write(reinterpret_cast<const char*>(h), sizeof(Hero));
    f.close();
    cout << "  [OK] Game tersimpan ke '" << SAVE_FILE << "'\n";
}

// Load hero — binary read
bool loadHero(Hero* h) {
    ifstream f(SAVE_FILE, ios::binary);
    if (!f) return false;
    f.read(reinterpret_cast<char*>(h), sizeof(Hero));
    bool ok = f.good();
    f.close();
    return ok;
}

// Save leaderboard — text file
void saveScores(const ScoreEntry lb[], int n) {
    ofstream f(SCORE_FILE);
    if (!f) return;
    f << n << "\n";
    for (int i=0;i<n;i++) {
        f << lb[i].heroName  << "\n"
          << lb[i].className << "\n"
          << lb[i].level     << " "
          << lb[i].gold      << " "
          << lb[i].score     << " "
          << lb[i].kills     << "\n";
    }
    f.close();
}

// Load leaderboard — text file
void loadScores(ScoreEntry lb[], int& n) {
    n = 0;
    ifstream f(SCORE_FILE);
    if (!f) return;
    f >> n; f.ignore();
    for (int i=0;i<n;i++) {
        f.getline(lb[i].heroName,  32);
        f.getline(lb[i].className, 16);
        f >> lb[i].level >> lb[i].gold >> lb[i].score >> lb[i].kills;
        f.ignore();
    }
    f.close();
}

// ─────────────────────────────────────────────
// SORTING — Bubble Sort leaderboard desc by score
// ─────────────────────────────────────────────
void swapScore(ScoreEntry* a, ScoreEntry* b) {   // pointer swap
    ScoreEntry t = *a; *a = *b; *b = t;
}
void sortLeaderboard(ScoreEntry lb[], int n) {
    for (int i=0;i<n-1;i++)
        for (int j=0;j<n-i-1;j++)
            if (lb[j].score < lb[j+1].score)
                swapScore(&lb[j], &lb[j+1]);
}

// ─────────────────────────────────────────────
// SORTING — Selection Sort inventory by value asc
// ─────────────────────────────────────────────
void sortInventory(Hero* h) {
    int n = h->invCount;
    for (int i=0;i<n-1;i++) {
        int mi = i;
        for (int j=i+1;j<n;j++)
            if (h->inventory[j].value < h->inventory[mi].value) mi = j;
        if (mi!=i) { Item t=h->inventory[i]; h->inventory[i]=h->inventory[mi]; h->inventory[mi]=t; }
    }
}

// ─────────────────────────────────────────────
// SEARCH — Linear Search item di inventory
// ─────────────────────────────────────────────
int linearSearchInv(const Hero* h, const string& name) {
    for (int i=0;i<h->invCount;i++)
        if (h->inventory[i].name == name) return i;
    return -1;
}

// ─────────────────────────────────────────────
// SEARCH — Binary Search monster by difficulty
// (pool harus terurut by difficulty — sudah diurutkan di data global)
// ─────────────────────────────────────────────
int binarySearchMonster(int diff) {
    // kumpulkan semua index dengan difficulty=diff, return yang pertama
    int lo=0, hi=MAX_MON_POOL-1;
    int result = -1;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (monsterPool[mid].difficulty == diff) { result=mid; break; }
        else if (monsterPool[mid].difficulty < diff) lo=mid+1;
        else hi=mid-1;
    }
    // cari range untuk random
    if (result==-1) return 0;
    int first=result, last=result;
    while (first>0 && monsterPool[first-1].difficulty==diff) first--;
    while (last<MAX_MON_POOL-1 && monsterPool[last+1].difficulty==diff) last++;
    return rnd(first, last);
}

// ─────────────────────────────────────────────
// SETUP CLASS
// ─────────────────────────────────────────────

// Inisialisasi stats & skills berdasarkan class
void applyClass(Hero* h, int classChoice) {
    // Reset skills
    h->skillCount = 0;

    if (classChoice == 1) {  // Knight
        h->className = "Knight";
        h->base = {10,4,8,12,4,2,6};  // vit,mind,str,def,dex,int,res
        // Starter item
        Item sw = {"Iron Sword",   ITEM_WEAPON,120,15,0,0,0,0,0,0,0,false};
        Item sh = {"Leather Armor",ITEM_ARMOR, 100, 0,10,0,5,20,0,0,0,false};
        Item hp = {"Health Potion",ITEM_POTION, 30, 0,0,0,0,0,0,40,0,false};
        h->inventory[0]=sw; h->inventory[1]=sh; h->inventory[2]=hp;
        h->invCount=3; h->eqWeapon=0; h->eqArmor=1;
        // Skills
        h->skills[0]={"Shield Bash", 8,0,120,"Pukul dengan perisai, chance stun.", true, false,0};
        h->skills[1]={"Power Slash", 12,0,180,"Tebasan kuat dengan pedang.",       false,false,0};
        h->skills[2]={"Guard Stance",6,0,  0,"Kurangi damage 40% ronde ini.",      false,false,0};
        h->skills[3]={"War Cry",    10,0,  0,"Tingkatkan ATK sementara.",           false,false,0};
        h->skillCount=4;

    } else if (classChoice == 2) {  // Ranger
        h->className = "Ranger";
        h->base = {7,5,6,5,14,4,4};
        Item bw = {"Short Bow",    ITEM_WEAPON,110,12,0,0,0,0,0,0,0,false};
        Item la = {"Leather Armor",ITEM_ARMOR, 100, 0,10,0,5,20,0,0,0,false};
        Item hp = {"Health Potion",ITEM_POTION, 30, 0,0,0,0,0,0,40,0,false};
        Item et = {"Ether",        ITEM_POTION, 40, 0,0,0,0,0,0, 0,30,false};
        h->inventory[0]=bw; h->inventory[1]=la; h->inventory[2]=hp; h->inventory[3]=et;
        h->invCount=4; h->eqWeapon=0; h->eqArmor=1;
        h->skills[0]={"Rapid Shot",  10,0,140,"Tembak cepat 2x, DEX scaling.",    false,false,0};
        h->skills[1]={"Poison Arrow",12,0,100,"Panah beracun, damage terus.",      false,false,0};
        h->skills[2]={"Eagle Eye",    8,0,  0,"Next attack crit pasti.",           false,false,0};
        h->skills[3]={"Evasive Roll", 5,0,  0,"Hindari serangan berikutnya.",      false,false,0};
        h->skillCount=4;

    } else if (classChoice == 3) {  // Mage
        h->className = "Mage";
        h->base = {5,14,2,3,5,16,8};
        Item st = {"Oak Staff",    ITEM_WEAPON,100,0,0,18,0,0,0,0,0,false};
        Item rb = {"Focus Ring",   ITEM_ACCESSORY,90,5,0,5,0,0,15,0,0,false};
        Item hp = {"Health Potion",ITEM_POTION, 30, 0,0,0,0,0,0,40,0,false};
        Item et = {"Ether",        ITEM_POTION, 40, 0,0,0,0,0,0,0,30,false};
        Item et2= {"Ether",        ITEM_POTION, 40, 0,0,0,0,0,0,0,30,false};
        h->inventory[0]=st; h->inventory[1]=rb; h->inventory[2]=hp; h->inventory[3]=et; h->inventory[4]=et2;
        h->invCount=5; h->eqWeapon=0; h->eqAccessory=1;
        h->skills[0]={"Fireball",    14,1,200,"Bola api, INT scaling.",            false,false,0};
        h->skills[1]={"Frost Nova",  18,1,160,"Beku musuh, stun 1 ronde.",        true, false,0};
        h->skills[2]={"Arcane Surge",20,1,250,"Ledakan aura, damage tinggi.",     false,false,0};
        h->skills[3]={"Mana Shield", 10,1,  0,"Konversi 30 MP jadi barrier HP.",  false,true, 30};
        h->skillCount=4;

    } else if (classChoice == 4) {  // Warrior
        h->className = "Warrior";
        h->base = {9,3,14,8,6,2,4};
        Item ax = {"Battle Axe",   ITEM_WEAPON,130,18,0,0,0,0,0,0,0,false};
        Item cm = {"Chain Mail",   ITEM_ARMOR, 230, 0,22,0,10,40,0,0,0,false};
        Item hp = {"Health Potion",ITEM_POTION, 30, 0,0,0,0,0,0,40,0,false};
        Item hp2= {"Health Potion",ITEM_POTION, 30, 0,0,0,0,0,0,40,0,false};
        h->inventory[0]=ax; h->inventory[1]=cm; h->inventory[2]=hp; h->inventory[3]=hp2;
        h->invCount=4; h->eqWeapon=0; h->eqArmor=1;
        h->skills[0]={"Reckless Strike",10,0,220,"ATK tinggi, abaikan DEF.",      false,false,0};
        h->skills[1]={"Whirlwind",      15,0,160,"Putar senjata, multi-hit.",      false,false,0};
        h->skills[2]={"Battle Roar",     8,0,  0,"Naik ATK+DEF 1 ronde.",         false,false,0};
        h->skills[3]={"Berserker",      12,0,  0,"Makin rendah HP makin kuat.",    false,false,0};
        h->skillCount=4;

    } else {  // Assassin
        h->className = "Assassin";
        h->base = {6,6,10,4,16,6,4};
        Item dk = {"Dark Dagger",  ITEM_WEAPON,115,14,0,0,0,0,0,0,0,false};
        Item la = {"Leather Armor",ITEM_ARMOR, 100, 0,10,0,5,20,0,0,0,false};
        Item rb = {"Focus Ring",   ITEM_ACCESSORY,90,5,0,5,0,0,15,0,0,false};
        Item hp = {"Health Potion",ITEM_POTION, 30, 0,0,0,0,0,0,40,0,false};
        Item et = {"Ether",        ITEM_POTION, 40, 0,0,0,0,0,0,0,30,false};
        h->inventory[0]=dk; h->inventory[1]=la; h->inventory[2]=rb; h->inventory[3]=hp; h->inventory[4]=et;
        h->invCount=5; h->eqWeapon=0; h->eqArmor=1; h->eqAccessory=2;
        h->skills[0]={"Backstab",       10,0,200,"Serangan dari belakang, crit.",  false,false,0};
        h->skills[1]={"Shadow Step",     8,0,  0,"Hindari 1 serangan.",            false,false,0};
        h->skills[2]={"Toxic Blade",    12,0,140,"Racun + damage fisik.",          false,false,0};
        h->skills[3]={"Death Mark",     15,0,  0,"Mark musuh, bonus damage 50%.",  false,false,0};
        h->skillCount=4;
    }
}

// Hitung total stats (base + equipment bonus)
void recalcStats(Hero* h) {
    h->total = h->base;

    auto applyItem = [&](int idx) {
        if (idx < 0 || idx >= h->invCount) return;
        Item& it = h->inventory[idx];
        h->total.str   += it.bonusAtk  / 2;
        h->total.def   += it.bonusDef  / 3;
        h->total.intel += it.bonusMAtk / 2;
        h->total.res   += it.bonusMDef / 3;
        h->total.vit   += it.bonusHP   / 12;
        h->total.mind  += it.bonusMP   / 8;
        h->total.dex   += 0;
    };
    applyItem(h->eqWeapon);
    applyItem(h->eqArmor);
    applyItem(h->eqAccessory);

    int prevMaxHp __attribute__((unused)) = h->maxHp;
    int prevMaxMp __attribute__((unused)) = h->maxMp;
    h->maxHp = h->total.vit  * 12;
    h->maxMp = h->total.mind * 8;

    // Jaga HP/MP proporsional
    if (h->hp > h->maxHp) h->hp = h->maxHp;
    if (h->mp > h->maxMp) h->mp = h->maxMp;
}

// Init hero baru
void initHero(Hero* h, const string& name, int classChoice) {
    h->name          = name;
    h->level         = 1;
    h->exp           = 0;
    h->statPoints    = 0;
    h->gold          = 60;
    h->score         = 0;
    h->dungeonFloor  = 0;
    h->monstersKilled= 0;
    h->invCount      = 0;
    h->eqWeapon      = -1;
    h->eqArmor       = -1;
    h->eqAccessory   = -1;
    h->skillCount    = 0;

    applyClass(h, classChoice);
    recalcStats(h);
    h->hp = h->maxHp;
    h->mp = h->maxMp;
}

// ─────────────────────────────────────────────
// DISPLAY
// ─────────────────────────────────────────────
void printHeroStatus(const Hero* h) {
    printLine();
    cout << "  " << h->name << " [" << h->className << "] Lv." << h->level << "\n";
    cout << "  HP: " << h->hp  << "/" << h->maxHp
         << "  MP: " << h->mp  << "/" << h->maxMp << "\n";
    cout << "  Gold: " << h->gold << "   Score: " << h->score
         << "   Kills: " << h->monstersKilled << "\n";
    cout << "  EXP: " << h->exp << "/" << calcExpNeeded(h->level) << "\n";
    printLine();
}

void printStats(const Hero* h) {
    cout << "\n  ─── STATS (base / total) ───\n";
    cout << "  VIT  : " << h->base.vit   << " / " << h->total.vit   << "  (MaxHP)\n";
    cout << "  MIND : " << h->base.mind  << " / " << h->total.mind  << "  (MaxMP)\n";
    cout << "  STR  : " << h->base.str   << " / " << h->total.str   << "  (Phys ATK)\n";
    cout << "  DEF  : " << h->base.def   << " / " << h->total.def   << "  (Phys DEF)\n";
    cout << "  DEX  : " << h->base.dex   << " / " << h->total.dex   << "  (Crit/EVA)\n";
    cout << "  INT  : " << h->base.intel << " / " << h->total.intel << "  (Magic ATK)\n";
    cout << "  RES  : " << h->base.res   << " / " << h->total.res   << "  (Magic DEF)\n";
    if (h->statPoints > 0)
        cout << "\n  >>> " << h->statPoints << " Stat Point tersedia! <<<\n";
}

void printInventory(const Hero* h, bool showEquip=true) {
    cout << "\n  INVENTORY (" << h->invCount << "/" << MAX_INV << "):\n";
    printLine();
    for (int i=0;i<h->invCount;i++) {
        const Item& it = h->inventory[i];
        cout << "  [" << i+1 << "] " << left << setw(16) << it.name
             << " " << setw(10) << itemTypeName(it.type)
             << " Val:" << setw(5) << it.value;
        if (it.type != ITEM_POTION) {
            if (it.bonusAtk > 0)  cout << " ATK+" << it.bonusAtk;
            if (it.bonusDef > 0)  cout << " DEF+" << it.bonusDef;
            if (it.bonusMAtk > 0) cout << " MATK+" << it.bonusMAtk;
            if (it.bonusMDef > 0) cout << " MDEF+" << it.bonusMDef;
            if (it.bonusHP > 0)   cout << " HP+" << it.bonusHP;
        } else {
            if (it.healHP > 0) cout << " HealHP+" << it.healHP;
            if (it.healMP > 0) cout << " HealMP+" << it.healMP;
        }
        if (showEquip && it.equipped) cout << " [EQ]";
        cout << "\n";
    }
    printLine();
}

// ─────────────────────────────────────────────
// LEVEL UP & STAT ALLOCATION
// ─────────────────────────────────────────────
void allocateStats(Hero* h) {
    while (h->statPoints > 0) {
        header("STAT ALLOCATION");
        printStats(h);
        cout << "\n  Stat Point: " << h->statPoints << "\n";
        cout << "  [1]VIT [2]MIND [3]STR [4]DEF [5]DEX [6]INT [7]RES  [0]Selesai\n  > ";
        int ch; cin >> ch;
        if (ch==0) break;
        if (ch<1||ch>7) continue;
        int* ptr[] = {&h->base.vit,&h->base.mind,&h->base.str,
                      &h->base.def,&h->base.dex,&h->base.intel,&h->base.res};
        (*ptr[ch-1])++;
        h->statPoints--;
        recalcStats(h);
        // Restore HP/MP saat VIT/MIND naik
        h->hp = h->maxHp;
        h->mp = h->maxMp;
        cout << "  Stat naik!\n";
    }
}

void checkLevelUp(Hero* h) {
    int needed = calcExpNeeded(h->level); // rekursif
    while (h->exp >= needed) {
        h->exp -= needed;
        h->level++;
        h->statPoints += 3;
        cout << "\n  ✦ LEVEL UP! Sekarang Level " << h->level << " ✦\n";
        cout << "  +3 Stat Point untuk dialokasikan!\n";
        recalcStats(h);
        h->hp = h->maxHp;
        h->mp = h->maxMp;
        needed = calcExpNeeded(h->level);
    }
    if (h->statPoints > 0) allocateStats(h);
}

// ─────────────────────────────────────────────
// EQUIPMENT MANAGEMENT
// ─────────────────────────────────────────────
void equipItem(Hero* h, int idx) {
    if (idx<0||idx>=h->invCount) return;
    Item& it = h->inventory[idx];

    if (it.type == ITEM_POTION || it.type == ITEM_MATL) {
        cout << "  Item ini tidak bisa di-equip.\n"; return;
    }

    // Unequip slot yang sama
    int* slot = nullptr;
    if (it.type==ITEM_WEAPON)    slot=&h->eqWeapon;
    if (it.type==ITEM_ARMOR)     slot=&h->eqArmor;
    if (it.type==ITEM_ACCESSORY) slot=&h->eqAccessory;

    if (*slot >= 0) h->inventory[*slot].equipped = false;
    *slot = idx;
    it.equipped = true;
    recalcStats(h);
    cout << "  " << it.name << " di-equip!\n";
}

void unequipItem(Hero* h, int idx) {
    if (idx<0||idx>=h->invCount) return;
    Item& it = h->inventory[idx];
    if (!it.equipped) { cout << "  Item tidak sedang di-equip.\n"; return; }
    it.equipped = false;
    if (h->eqWeapon==idx)    h->eqWeapon=-1;
    if (h->eqArmor==idx)     h->eqArmor=-1;
    if (h->eqAccessory==idx) h->eqAccessory=-1;
    recalcStats(h);
    cout << "  " << it.name << " di-unequip.\n";
}

void equipMenu(Hero* h) {
    while(true) {
        header("EQUIPMENT");
        cout << "  Slot Weapon    : " << (h->eqWeapon>=0 ? h->inventory[h->eqWeapon].name : "(kosong)") << "\n";
        cout << "  Slot Armor     : " << (h->eqArmor>=0  ? h->inventory[h->eqArmor].name  : "(kosong)") << "\n";
        cout << "  Slot Accessory : " << (h->eqAccessory>=0 ? h->inventory[h->eqAccessory].name : "(kosong)") << "\n";
        printStats(h);
        printInventory(h);
        cout << "  [Nomor] Equip/Unequip  [0] Kembali\n  > ";
        int ch; cin >> ch;
        if (ch==0) break;
        if (ch<1||ch>h->invCount) continue;
        int idx = ch-1;
        if (h->inventory[idx].equipped) unequipItem(h, idx);
        else equipItem(h, idx);
        pause();
    }
}

// ─────────────────────────────────────────────
// ITEM USAGE (in battle or town)
// ─────────────────────────────────────────────
bool usePotion(Hero* h, int idx) {
    if (idx<0||idx>=h->invCount) return false;
    Item& it = h->inventory[idx];
    if (it.type != ITEM_POTION) { cout << "  Bukan potion!\n"; return false; }

    if (it.healHP > 0) {
        int healed = min(it.healHP, h->maxHp - h->hp);
        h->hp += healed;
        cout << "  Pakai " << it.name << " -> HP +" << healed
             << " (HP: " << h->hp << "/" << h->maxHp << ")\n";
    }
    if (it.healMP > 0) {
        int restored = min(it.healMP, h->maxMp - h->mp);
        h->mp += restored;
        cout << "  Pakai " << it.name << " -> MP +" << restored
             << " (MP: " << h->mp << "/" << h->maxMp << ")\n";
    }
    // Hapus dari inventory
    for (int i=idx;i<h->invCount-1;i++) h->inventory[i]=h->inventory[i+1];
    // Update equip index
    if (h->eqWeapon>idx)    h->eqWeapon--;
    if (h->eqArmor>idx)     h->eqArmor--;
    if (h->eqAccessory>idx) h->eqAccessory--;
    h->invCount--;
    return true;
}

// ─────────────────────────────────────────────
// SHOP
// ─────────────────────────────────────────────

void shopMenu(Hero* h) {
    while(true) {
        header("TOKO DESA");
        cout << "  Gold kamu: " << h->gold << " G\n\n";
        cout << "  ── Beli ──\n";
        for (int i=0;i<shopCount;i++) {
            Item& it = shopCatalog[i];
            cout << "  [" << i+1 << "] " << left << setw(16) << it.name
                 << setw(10) << itemTypeName(it.type)
                 << " Harga: " << it.value << " G";
            if (it.type==ITEM_POTION) {
                if (it.healHP>0) cout << "  HealHP+" << it.healHP;
                if (it.healMP>0) cout << "  HealMP+" << it.healMP;
            } else {
                if (it.bonusAtk>0)  cout << " ATK+" << it.bonusAtk;
                if (it.bonusDef>0)  cout << " DEF+" << it.bonusDef;
                if (it.bonusMAtk>0) cout << " MATK+" << it.bonusMAtk;
            }
            cout << "\n";
        }

        // Demo: linear search item di toko
        int found = -1;
        for (int i=0;i<shopCount;i++)
            if (shopCatalog[i].name == "Elixir") { found=i; break; }
        if (found!=-1)
            cout << "\n  [LinearSearch] 'Elixir' ada di slot " << found << "\n";

        cout << "\n  [B] Beli  [J] Jual  [0] Kembali\n  > ";
        char cmd; cin >> cmd;

        if (cmd=='0') break;

        if (cmd=='B'||cmd=='b') {
            cout << "  Pilih item (1-" << shopCount << "): ";
            int ch; cin >> ch;
            if (ch<1||ch>shopCount) continue;
            Item& it = shopCatalog[ch-1];
            if (h->gold < it.value) {
                cout << "  Gold tidak cukup!\n";
            } else if (h->invCount >= MAX_INV) {
                cout << "  Inventory penuh!\n";
            } else {
                // Cek duplikat equipment via linear search
                int dup = linearSearchInv(h, it.name);
                if (dup!=-1 && it.type!=ITEM_POTION) {
                    cout << "  Kamu sudah punya equipment ini.\n";
                } else {
                    h->gold -= it.value;
                    h->inventory[h->invCount++] = it;
                    cout << "  Membeli " << it.name << "!\n";
                }
            }
        } else if (cmd=='J'||cmd=='j') {
            sortInventory(h); // sort inventory sebelum jual
            printInventory(h);
            cout << "  Jual item (nomor, 0=batal): ";
            int ch; cin >> ch;
            if (ch<1||ch>h->invCount) { cout << "  Batal.\n"; continue; }
            int idx = ch-1;
            if (h->inventory[idx].equipped) {
                cout << "  Lepas equip dulu!\n";
            } else {
                int sell = h->inventory[idx].value / 2;
                cout << "  Jual " << h->inventory[idx].name << " -> +" << sell << " G. Yakin? (y/n): ";
                char c; cin >> c;
                if (c=='y'||c=='Y') {
                    h->gold += sell;
                    for (int i=idx;i<h->invCount-1;i++) h->inventory[i]=h->inventory[i+1];
                    if (h->eqWeapon>idx)    h->eqWeapon--;
                    if (h->eqArmor>idx)     h->eqArmor--;
                    if (h->eqAccessory>idx) h->eqAccessory--;
                    h->invCount--;
                    cout << "  Terjual!\n";
                }
            }
        }
        pause();
    }
}

// ─────────────────────────────────────────────
// BATTLE SYSTEM
// ─────────────────────────────────────────────

// Hitung physical damage hero
int heroPhysDmg(const Hero* h) {
    // base = STR * 3 + weapon bonus
    int base = h->total.str * 3;
    if (h->eqWeapon>=0) base += h->inventory[h->eqWeapon].bonusAtk;
    return base;
}

// Hitung magic damage hero
int heroMagDmg(const Hero* h) {
    int base = h->total.intel * 3;
    if (h->eqWeapon>=0) base += h->inventory[h->eqWeapon].bonusMAtk;
    return base;
}

// Damage reduction dari DEF
int physReduction(int def) { return def * 2; }
int magReduction(int res)  { return res * 2; }

// Crit check (DEX based)
bool isCrit(int dex) { return rnd(1,100) <= (dex * 3); }

// Evasion check
bool isEvaded(int dex) { return rnd(1,100) <= (dex * 2); }

// Monster behavior: semakin rendah HP -> lebih sering heal
void monsterTurn(Monster* m, Hero* h) {
    // Hitung HP % monster
    int hpPct = (m->hp * 100) / m->maxHp;

    // Peluang heal naik seiring HP turun
    int healChance = 0;
    if (m->canHeal) {
        if (hpPct < 20)      healChance = 70;
        else if (hpPct < 40) healChance = 45;
        else if (hpPct < 60) healChance = 20;
        else                 healChance = 5;
    }

    if (m->canHeal && rnd(1,100) <= healChance) {
        int healed = min(m->healAmount, m->maxHp - m->hp);
        m->hp += healed;
        cout << "  " << m->name << " menyembuhkan diri sendiri! (+" << healed << " HP)\n";
        return;
    }

    // Serangan biasa atau magic
    if (m->matk > 0 && rnd(1,2)==1) {
        int dmg = max(1, m->matk - magReduction(h->total.res) + rnd(-3,5));
        h->hp -= dmg;
        cout << "  " << m->name << " menggunakan serangan sihir! [" << dmg << " dmg]\n";
    } else {
        if (isEvaded(h->total.dex)) {
            cout << "  " << h->name << " menghindar dari serangan " << m->name << "!\n";
            return;
        }
        int dmg = max(1, m->atk - physReduction(h->total.def) + rnd(-3,5));
        h->hp -= dmg;
        cout << "  " << m->name << " menyerang! [" << dmg << " dmg]\n";
    }
}

// Terapkan skill hero
void useSkill(Hero* h, Monster* m, int skillIdx, bool& defended) {
    Skill& sk = h->skills[skillIdx];
    if (h->mp < sk.mpCost) {
        cout << "  MP tidak cukup! (perlu " << sk.mpCost << " MP)\n"; return;
    }
    h->mp -= sk.mpCost;
    cout << "  " << h->name << " menggunakan " << sk.name << "!\n";

    if (sk.mult == 0) {
        // Skill tanpa damage (buff / defensive)
        if (sk.canHeal && sk.healPct > 0) {
            int heal = (h->maxHp * sk.healPct) / 100;
            h->hp = min(h->maxHp, h->hp + heal);
            cout << "  HP +" << heal << " (HP: " << h->hp << "/" << h->maxHp << ")\n";
        }
        if (sk.name == "Guard Stance" || sk.name == "Evasive Roll" || sk.name == "Shadow Step") {
            defended = true;
            cout << "  Kamu bersiap mengurangi damage berikutnya!\n";
        }
        if (sk.name == "Battle Roar" || sk.name == "War Cry") {
            cout << "  ATK meningkat ronde ini!\n";
        }
        if (sk.name == "Eagle Eye" || sk.name == "Death Mark") {
            cout << "  Serangan berikutnya pasti critical!\n";
        }
        if (sk.name == "Berserker") {
            int hpPct = (h->hp*100)/h->maxHp;
            int bonus = (100 - hpPct) / 5;
            cout << "  Berserker! Bonus ATK +" << bonus << " ronde ini!\n";
        }
        if (sk.name == "Mana Shield") {
            int barrier = 30;
            h->hp = min(h->maxHp, h->hp + barrier);
            cout << "  Barrier HP +" << barrier << "\n";
        }
    } else {
        // Skill damage
        int baseDmg = (sk.type==0) ? heroPhysDmg(h) : heroMagDmg(h);
        int reduction = (sk.type==0) ? physReduction(m->def) : magReduction(m->mdef);
        int dmg = max(1, (baseDmg * sk.mult / 100) - reduction + rnd(-2,6));

        // Crit check
        if (isCrit(h->total.dex)) {
            dmg = dmg * 3 / 2;
            cout << "  ★ CRITICAL! ";
        }

        m->hp -= dmg;
        cout << "  Damage: " << dmg << "\n";

        if (sk.canStun && !m->isStunned && rnd(1,100)<=40) {
            m->isStunned = true;
            cout << "  " << m->name << " terstun!\n";
        }
    }
}

// Main battle loop
// return: true = menang, false = kabur/mati
bool doBattle(Hero* h, Monster& enemy) {
    header("PERTEMPURAN!");
    cout << "  " << h->name << " [" << h->className << "] vs " << enemy.name << "\n";
    printLine();

    enemy.isStunned = false;
    int poisonTurns = 0;
    bool deathMark  = false;

    while (h->hp > 0 && enemy.hp > 0) {
        // Status bar
        cout << "\n  [" << h->name << "] HP:" << h->hp << "/" << h->maxHp
             << "  MP:" << h->mp << "/" << h->maxMp << "\n";
        cout << "  [" << enemy.name << "] HP:" << enemy.hp << "/" << enemy.maxHp << "\n";
        if (poisonTurns > 0) cout << "  (Musuh keracunan: " << poisonTurns << " ronde)\n";
        printLine('-', 40);

        cout << "  [1] Serang    [2] Skill    [3] Bertahan\n";
        cout << "  [4] Item      [5] Kabur\n  > ";

        int act; cin >> act;
        bool defended = false;

        if (act == 5) {
            cout << "  " << h->name << " melarikan diri!\n";
            return false;
        }

        // --- AKSI HERO ---
        if (act == 1) {
            // Serangan biasa: STR*3 + weapon bonus
            int baseDmg = heroPhysDmg(h);
            if (deathMark) { baseDmg = baseDmg * 150 / 100; deathMark=false; }
            int dmg = max(1, baseDmg - physReduction(enemy.def) + rnd(-3,6));
            bool crit = isCrit(h->total.dex);
            if (crit) dmg = dmg * 3 / 2;
            enemy.hp -= dmg;
            cout << "  " << h->name << " menyerang" << (crit?" [CRIT!]":"") << ": " << dmg << " dmg!\n";

        } else if (act == 2) {
            // Pilih skill
            cout << "\n  ── SKILL ──\n";
            for (int i=0;i<h->skillCount;i++) {
                cout << "  [" << i+1 << "] " << left << setw(16) << h->skills[i].name
                     << " MP:" << h->skills[i].mpCost
                     << "  " << h->skills[i].desc << "\n";
            }
            cout << "  [0] Batal\n  > ";
            int sc; cin >> sc;
            if (sc>=1 && sc<=h->skillCount) {
                // Toxic Blade special: set poison
                if (h->skills[sc-1].name == "Toxic Blade") poisonTurns = 3;
                // Death Mark special
                if (h->skills[sc-1].name == "Death Mark") { deathMark=true; }
                useSkill(h, &enemy, sc-1, defended);
            }

        } else if (act == 3) {
            // Bertahan: DEF naik 40%, musuh tetap menyerang
            defended = true;
            cout << "  " << h->name << " bersiap bertahan!\n";

        } else if (act == 4) {
            // Pakai item
            bool hasPotion = false;
            for (int i=0;i<h->invCount;i++)
                if (h->inventory[i].type==ITEM_POTION) { hasPotion=true; break; }
            if (!hasPotion) { cout << "  Tidak ada potion!\n"; continue; }

            cout << "\n  ── ITEM ──\n";
            for (int i=0;i<h->invCount;i++) {
                if (h->inventory[i].type==ITEM_POTION)
                    cout << "  [" << i+1 << "] " << h->inventory[i].name
                         << "  HP+" << h->inventory[i].healHP
                         << "  MP+" << h->inventory[i].healMP << "\n";
            }
            cout << "  [0] Batal\n  > ";
            int ic; cin >> ic;
            if (ic>=1 && ic<=h->invCount && h->inventory[ic-1].type==ITEM_POTION) {
                usePotion(h, ic-1);
            }
            // Item usage tidak menghabiskan giliran musuh (item selesai, musuh tetap menyerang)
        }

        if (enemy.hp <= 0) break;

        // Efek racun
        if (poisonTurns > 0) {
            int pdmg = rnd(5,12);
            enemy.hp -= pdmg;
            poisonTurns--;
            cout << "  [Racun] " << enemy.name << " terkena racun: " << pdmg << " dmg!\n";
        }

        // --- GILIRAN MUSUH ---
        if (enemy.isStunned) {
            cout << "  " << enemy.name << " masih terstun, tidak bisa bergerak!\n";
            enemy.isStunned = false;
        } else if (enemy.hp > 0) {
            if (defended) {
                // Kurangi damage 40% + DEF
                Monster tempM = enemy;
                tempM.atk  = tempM.atk  * 60 / 100;
                tempM.matk = tempM.matk * 60 / 100;
                monsterTurn(&tempM, h);
                cout << "  (Bertahan mengurangi damage!)\n";
            } else {
                monsterTurn(&enemy, h);
            }
        }
    }

    if (h->hp <= 0) {
        h->hp = 0;
        cout << "\n  ✦ KAMU KALAH! ✦\n";
        return false;
    }

    // Menang
    cout << "\n  ✦ " << enemy.name << " DIKALAHKAN! ✦\n";
    h->monstersKilled++;
    h->score += enemy.expDrop * 2;

    // EXP & Gold drop
    int expGain  = enemy.expDrop  + rnd(0, 5);
    int goldGain = enemy.goldDrop + rnd(0, 5);
    cout << "  +" << expGain  << " EXP   +" << goldGain << " Gold\n";
    h->exp  += expGain;
    h->gold += goldGain;

    // Item drop (jackpot)
    if (!enemy.dropItemName.empty() && rnd(1,100) <= enemy.dropChance) {
        cout << "  ★ ITEM DROP: " << enemy.dropItemName << "!\n";
        if (h->invCount < MAX_INV) {
            Item drop;
            drop.name       = enemy.dropItemName;
            drop.type       = ITEM_MATL;
            drop.value      = rnd(20,60);
            drop.bonusAtk   = 0; drop.bonusDef=0; drop.bonusMAtk=0;
            drop.bonusMDef  = 0; drop.bonusHP=0; drop.bonusMP=0;
            drop.healHP     = 0; drop.healMP=0; drop.equipped=false;
            h->inventory[h->invCount++] = drop;
        } else {
            cout << "  (Inventory penuh, item terbuang)\n";
        }
    }

    // Cek jackpot (1%)
    if (rnd(1,100) == 1) {
        int jackpot = rnd(50,200);
        cout << "  ★★ JACKPOT! Bonus gold +" << jackpot << " G! ★★\n";
        h->gold += jackpot;
    }

    // Level up check
    checkLevelUp(h);
    return true;
}

// ─────────────────────────────────────────────
// DUNGEON (REKURSIF)
// ─────────────────────────────────────────────
void dungeonExplore(Hero* h, int floor, int maxFloor);

void dungeonExplore(Hero* h, int floor, int maxFloor) {
    // Base case
    if (h->hp <= 0 || floor > maxFloor) {
        if (floor > maxFloor && h->hp > 0) {
            cout << "\n  ✦✦ DUNGEON TAKLUK! Semua lantai selesai! ✦✦\n";
            h->score += 500;
            cout << "  Bonus Score +500!\n";
        }
        return;
    }

    // Pilih monster via binary search
    int diff = 1;
    if (floor >= 4)  diff = 2;
    if (floor >= 7)  diff = 3;
    int mIdx = binarySearchMonster(diff); // binary search
    Monster enemy = monsterPool[mIdx];

    // Reset HP monster untuk variasi
    enemy.hp = enemy.maxHp + rnd(-5,10);
    enemy.maxHp = enemy.hp;
    enemy.atk += (floor-1);

    header("DUNGEON LANTAI " + to_string(floor) + " / " + to_string(maxFloor));
    printHeroStatus(h);
    cout << "\n  Musuh muncul: " << enemy.name << "\n";
    cout << "  (HP:" << enemy.hp << " ATK:" << enemy.atk
         << " DEF:" << enemy.def;
    if (enemy.matk>0) cout << " MATK:" << enemy.matk;
    if (enemy.canHeal) cout << " [bisa heal]";
    cout << ")\n\n";

    cout << "  [1] Bertarung\n";
    cout << "  [2] Toko" << (floor%3==0 ? " (tersedia!)" : " (N/A)") << "\n";
    cout << "  [3] Status & Stats\n";
    cout << "  [4] Simpan game\n";
    cout << "  [5] Kembali ke Town\n  > ";
    int ch; cin >> ch;

    if (ch==2) {
        if (floor%3==0) shopMenu(h);
        else cout << "  Tidak ada toko di lantai ini.\n";
        pause();
    } else if (ch==3) {
        printHeroStatus(h);
        printStats(h);
        printInventory(h);
        pause();
    } else if (ch==4) {
        saveHero(h);
        pause();
    } else if (ch==5) {
        return;
    }

    // Battle
    bool won = doBattle(h, enemy);
    h->dungeonFloor = floor;

    if (!won) {
        if (h->hp <= 0) {
            cout << "\n  Kamu pingsan dan dikirim kembali ke Town...\n";
            h->hp = h->maxHp / 4; // selamat dengan sedikit HP
        }
        pause();
        return; // tidak lanjut ke lantai berikutnya
    }

    // Tampilkan opsi setelah menang
    cout << "\n  [1] Lanjut ke lantai " << floor+1 << "\n";
    cout << "  [2] Kembali ke Town\n  > ";
    int choice; cin >> choice;

    if (choice==1) {
        pause();
        dungeonExplore(h, floor+1, maxFloor); // REKURSIF
    }
    // else: kembali ke town
}

// ─────────────────────────────────────────────
// LEADERBOARD
// ─────────────────────────────────────────────
void addScore(const Hero* h) {
    ScoreEntry lb[MAX_SCORES+1];
    int n=0;
    loadScores(lb, n); // FILE I/O baca

    ScoreEntry e;
    strncpy(e.heroName,  h->name.c_str(), 31); e.heroName[31]=0;
    strncpy(e.className, h->className.c_str(), 15); e.className[15]=0;
    e.level = h->level; e.gold = h->gold;
    e.score = h->score; e.kills = h->monstersKilled;

    if (n < MAX_SCORES) lb[n++] = e;
    else { lb[MAX_SCORES]=e; n=MAX_SCORES+1; }

    sortLeaderboard(lb, n);
    if (n>MAX_SCORES) n=MAX_SCORES;
    saveScores(lb, n); // FILE I/O simpan
}

void showLeaderboard() {
    ScoreEntry lb[MAX_SCORES];
    int n=0;
    loadScores(lb, n); // FILE I/O baca
    sortLeaderboard(lb, n);

    header("HALL OF FAME");
    if (n==0) { cout << "  (Belum ada data)\n"; return; }
    cout << "  " << left
         << setw(4)  << "No"
         << setw(14) << "Nama"
         << setw(12) << "Class"
         << setw(6)  << "Lv"
         << setw(8)  << "Gold"
         << setw(8)  << "Kills"
         << "Score\n";
    printLine();
    for (int i=0;i<n;i++) {
        cout << "  " << left
             << setw(4)  << i+1
             << setw(14) << lb[i].heroName
             << setw(12) << lb[i].className
             << setw(6)  << lb[i].level
             << setw(8)  << lb[i].gold
             << setw(8)  << lb[i].kills
             << lb[i].score << "\n";
    }
}

// ─────────────────────────────────────────────
// TOWN MENU
// ─────────────────────────────────────────────
void townMenu(Hero* h) {
    while(true) {
        header("KOTA ARVANA");
        printHeroStatus(h);

        if (h->statPoints>0)
            cout << "  !! " << h->statPoints << " Stat Point menunggu alokasi !!\n\n";

        cout << "  [1] Masuk Dungeon\n";
        cout << "  [2] Toko\n";
        cout << "  [3] Equipment\n";
        cout << "  [4] Inventory & Item\n";
        cout << "  [5] Stats Detail\n";
        cout << "  [6] Alokasi Stat Point\n";
        cout << "  [7] Hall of Fame\n";
        cout << "  [8] Simpan Game\n";
        cout << "  [9] Keluar (Simpan & Quit)\n  > ";

        int ch; cin >> ch;

        switch(ch) {
            case 1: {
                cout << "\n  Pilih kedalaman dungeon:\n";
                cout << "  [1] Mudah   (5 lantai)  - diff 1\n";
                cout << "  [2] Normal  (8 lantai)  - diff 1-2\n";
                cout << "  [3] Sulit   (12 lantai) - diff 1-3\n  > ";
                int d; cin >> d;
                int mx = (d==1)?5:(d==2)?8:12;
                cout << "\n  Memasuki dungeon " << mx << " lantai...\n";
                pause();
                dungeonExplore(h, 1, mx); // REKURSIF
                addScore(h); // simpan skor setelah eksplorasi
                cout << "\n  Kembali ke kota.\n";
                pause();
                break;
            }
            case 2:
                shopMenu(h); break;
            case 3:
                equipMenu(h); break;
            case 4:
                header("INVENTORY");
                sortInventory(h);
                printInventory(h);
                cout << "  Pakai item (nomor, 0=batal): ";
                {
                    int ic; cin >> ic;
                    if (ic>=1&&ic<=h->invCount) usePotion(h, ic-1);
                }
                pause(); break;
            case 5:
                header("STATS DETAIL");
                printHeroStatus(h);
                printStats(h);
                cout << "\n  Skills:\n";
                for (int i=0;i<h->skillCount;i++)
                    cout << "  [" << i+1 << "] " << left << setw(16) << h->skills[i].name
                         << " MP:" << setw(4) << h->skills[i].mpCost
                         << h->skills[i].desc << "\n";
                pause(); break;
            case 6:
                if (h->statPoints>0) allocateStats(h);
                else { cout << "  Tidak ada stat point.\n"; pause(); }
                break;
            case 7:
                showLeaderboard(); pause(); break;
            case 8:
                saveHero(h);
                cout << "  Game tersimpan!\n"; pause(); break;
            case 9:
                addScore(h);
                saveHero(h);
                cout << "  Sampai jumpa, " << h->name << "!\n";
                return;
        }
    }
}

// ─────────────────────────────────────────────
// CHARACTER CREATION
// ─────────────────────────────────────────────
void createCharacter(Hero& hero) {
    header("BUAT KARAKTER");
    cout << "  Masukkan nama hero: ";
    cin.ignore(); getline(cin, hero.name);

    header("PILIH CLASS");
    cout << "  [1] Knight    - Tank, DEF & VIT tinggi. Skill: Shield Bash, Guard Stance\n";
    cout << "  [2] Ranger    - Agile, DEX tinggi. Skill: Rapid Shot, Poison Arrow\n";
    cout << "  [3] Mage      - INT & MIND tinggi. Skill: Fireball, Frost Nova\n";
    cout << "  [4] Warrior   - STR tinggi, HP baik. Skill: Reckless Strike, Berserker\n";
    cout << "  [5] Assassin  - DEX & STR, crit build. Skill: Backstab, Shadow Step\n";
    cout << "\n  Pilih class (1-5): ";
    int c; cin >> c;
    if (c<1||c>5) c=1;

    initHero(&hero, hero.name, c);

    header("KARAKTER DIBUAT!");
    cout << "  Nama  : " << hero.name      << "\n";
    cout << "  Class : " << hero.className << "\n";
    printStats(&hero);
    cout << "\n  Starter item:\n";
    printInventory(&hero, true);
    cout << "\n  Skill yang dimiliki:\n";
    for (int i=0;i<hero.skillCount;i++)
        cout << "  [" << i+1 << "] " << hero.skills[i].name
             << " - " << hero.skills[i].desc << "\n";
    pause();
}

// ─────────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────────
int main() {
    srand((unsigned)time(nullptr));
    int choice;

    do {
        cls();
        printLine('=');
        cout << "\n";
        cout << "       ██████  ██    ██ ███    ██  ██████  ███████  ██████  ███    ██ \n";
        cout << "       ██   ██ ██    ██ ████   ██ ██       ██      ██    ██ ████   ██ \n";
        cout << "       ██   ██ ██    ██ ██ ██  ██ ██   ███ █████   ██    ██ ██ ██  ██ \n";
        cout << "       ██   ██ ██    ██ ██  ██ ██ ██    ██ ██      ██    ██ ██  ██ ██ \n";
        cout << "       ██████   ██████  ██   ████  ██████  ███████  ██████  ██   ████ \n";
        cout << "\n                   ██████  ██    ██ ███████ ███████ ████████ \n";
        cout << "                   ██    ██ ██    ██ ██      ██         ██    \n";
        cout << "                   ██    ██ ██    ██ █████   ███████    ██    \n";
        cout << "                   ██    ██ ██    ██ ██           ██    ██    \n";
        cout << "                   ██████   ██████  ███████ ███████    ██    \n\n";
        printLine('=');
        cout << "  [1] Mulai Game Baru\n";
        cout << "  [2] Lanjutkan Game (Load Save)\n";
        cout << "  [3] Hall of Fame\n";
        cout << "  [4] Keluar\n  > ";
        cin >> choice;

        if (choice==1) {
            Hero hero;
            createCharacter(hero);
            townMenu(&hero);

        } else if (choice==2) {
            Hero hero;
            if (!loadHero(&hero)) {    // FILE I/O
                cout << "  [!] File save tidak ditemukan.\n";
                pause();
            } else {
                cout << "  [OK] Data dimuat! Selamat datang kembali, " << hero.name << "!\n";
                pause();
                townMenu(&hero);
            }

        } else if (choice==3) {
            showLeaderboard();
            pause();
        }

    } while (choice!=4);

    cout << "\n  Terima kasih telah bermain Dungeon Quest!\n\n";
    return 0;
}