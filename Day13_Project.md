# Day 13: 종합 프로젝트 — "나만의 작품을 만들자!" 🏆

## 📚 학습 목표
- 13일간 배운 C/C++ 지식을 활용하여 미니 프로젝트 완성
- 클래스 설계, 상속, STL, 파일 I/O를 종합적으로 적용
- 코드 리뷰를 통해 좋은 코드 습관 형성
- 전체 커리큘럼 총정리

## ⏰ 시간 배분 (3시간)
| 시간 | 내용 |
|------|------|
| 50분 | **1교시**: 프로젝트 설계 & 코딩 시작 |
| 10분 | 휴식 |
| 50분 | **2교시**: 프로젝트 코딩 & 완성 |
| 10분 | 휴식 |
| 50분 | **3교시**: 코드 리뷰 & 전체 총정리 |
| 10분 | Q&A 및 수료식 🎓 |

---

## 🎯 1교시: 프로젝트 설계 & 코딩 시작 (50분)

### 프로젝트 선택 (3가지 중 택 1)

---

### 🅰️ 프로젝트 A: 📋 학생 성적 관리 시스템

**난이도**: ⭐⭐ (기본)

**사용 개념**: 클래스, vector, sort, 파일 I/O, 캡슐화

**요구 기능**:
1. 학생 추가 (이름, 국영수 점수)
2. 전체 학생 목록 출력 (총점, 평균, 등급 포함)
3. 이름순 / 평균순 정렬
4. 학생 검색 (이름)
5. 파일 저장 / 불러오기

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Student {
private:
    string name;
    int kor, eng, math;
    
public:
    Student() : name(""), kor(0), eng(0), math(0) {}
    Student(string n, int k, int e, int m) : name(n), kor(k), eng(e), math(m) {}
    
    string getName() const { return name; }
    int getTotal() const { return kor + eng + math; }
    double getAvg() const { return getTotal() / 3.0; }
    
    char getGrade() const {
        double avg = getAvg();
        if (avg >= 90) return 'A';
        if (avg >= 80) return 'B';
        if (avg >= 70) return 'C';
        if (avg >= 60) return 'D';
        return 'F';
    }
    
    void print() const {
        cout << "│ " << name << "\t│ " << kor << "\t│ " << eng << "\t│ "
             << math << "\t│ " << getTotal() << "\t│ " << getAvg()
             << "\t│ " << getGrade() << " │" << endl;
    }
    
    // 파일 저장/읽기용
    friend ofstream& operator<<(ofstream &fout, const Student &s) {
        fout << s.name << " " << s.kor << " " << s.eng << " " << s.math;
        return fout;
    }
    
    void loadFrom(ifstream &fin) {
        fin >> name >> kor >> eng >> math;
    }
};

class GradeManager {
private:
    vector<Student> students;
    string filename;
    
public:
    GradeManager(string fname = "students.txt") : filename(fname) {}
    
    void addStudent() {
        string name;
        int k, e, m;
        cout << "이름: "; cin >> name;
        cout << "국어 영어 수학: "; cin >> k >> e >> m;
        students.push_back(Student(name, k, e, m));
        cout << "✅ 추가 완료!" << endl;
    }
    
    void printAll() {
        if (students.empty()) {
            cout << "📭 등록된 학생이 없습니다." << endl;
            return;
        }
        cout << "\n┌────────┬──────┬──────┬──────┬──────┬──────┬────┐" << endl;
        cout << "│ 이름\t│ 국어\t│ 영어\t│ 수학\t│ 총점\t│ 평균\t│등급│" << endl;
        cout << "├────────┼──────┼──────┼──────┼──────┼──────┼────┤" << endl;
        for (auto &s : students) s.print();
        cout << "└────────┴──────┴──────┴──────┴──────┴──────┴────┘" << endl;
        cout << "총 " << students.size() << "명" << endl;
    }
    
    void sortByName() {
        sort(students.begin(), students.end(),
             [](const Student &a, const Student &b) {
                 return a.getName() < b.getName();
             });
        cout << "📝 이름순 정렬 완료!" << endl;
    }
    
    void sortByAvg() {
        sort(students.begin(), students.end(),
             [](const Student &a, const Student &b) {
                 return a.getAvg() > b.getAvg();
             });
        cout << "📊 성적순 정렬 완료!" << endl;
    }
    
    void search() {
        string keyword;
        cout << "검색할 이름: "; cin >> keyword;
        bool found = false;
        for (auto &s : students) {
            if (s.getName() == keyword) {
                s.print();
                found = true;
            }
        }
        if (!found) cout << "❌ 찾을 수 없습니다." << endl;
    }
    
    void saveToFile() {
        ofstream fout(filename);
        for (auto &s : students) {
            fout << s << endl;
        }
        fout.close();
        cout << "💾 저장 완료! (" << filename << ")" << endl;
    }
    
    void loadFromFile() {
        ifstream fin(filename);
        if (!fin.is_open()) {
            cout << "❌ 파일을 찾을 수 없습니다." << endl;
            return;
        }
        students.clear();
        Student s;
        while (!fin.eof()) {
            s.loadFrom(fin);
            if (fin.good()) students.push_back(s);
        }
        fin.close();
        cout << "📂 불러오기 완료! (" << students.size() << "명)" << endl;
    }
};

int main() {
    GradeManager mgr;
    int choice;
    
    do {
        cout << "\n📚 === 성적 관리 시스템 ===" << endl;
        cout << "1.추가 2.목록 3.이름순 4.성적순 5.검색 6.저장 7.불러오기 0.종료" << endl;
        cout << "선택: ";
        cin >> choice;
        
        switch (choice) {
            case 1: mgr.addStudent(); break;
            case 2: mgr.printAll(); break;
            case 3: mgr.sortByName(); mgr.printAll(); break;
            case 4: mgr.sortByAvg(); mgr.printAll(); break;
            case 5: mgr.search(); break;
            case 6: mgr.saveToFile(); break;
            case 7: mgr.loadFromFile(); break;
        }
    } while (choice != 0);
    
    cout << "👋 종료!" << endl;
    return 0;
}
```

---

### 🅱️ 프로젝트 B: 🎮 RPG 던전 탐험 게임

**난이도**: ⭐⭐⭐ (중급)

**사용 개념**: 상속, 다형성, vector, 랜덤, 캡슐화, 파일 I/O

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

// === 아이템 ===
class Item {
public:
    string name;
    string type;  // "potion", "weapon"
    int value;
    
    Item(string n, string t, int v) : name(n), type(t), value(v) {}
};

// === 캐릭터 베이스 ===
class Character {
protected:
    string name;
    int hp, maxHp, attack, defense;
    
public:
    Character(string n, int h, int a, int d)
        : name(n), hp(h), maxHp(h), attack(a), defense(d) {}
    
    virtual ~Character() {}
    
    string getName() { return name; }
    bool isAlive() { return hp > 0; }
    
    virtual int doAttack() {
        int dmg = attack + rand() % 5;
        return dmg;
    }
    
    void takeDamage(int dmg) {
        int real = dmg - defense;
        if (real < 1) real = 1;
        hp -= real;
        if (hp < 0) hp = 0;
        cout << "  " << name << " → " << real << " 피해! (HP: " << hp << ")" << endl;
    }
    
    void heal(int amount) {
        hp += amount;
        if (hp > maxHp) hp = maxHp;
    }
    
    virtual void showStatus() {
        cout << name << " [HP: " << hp << "/" << maxHp
             << " ATK: " << attack << " DEF: " << defense << "]" << endl;
    }
};

// === 플레이어 ===
class Player : public Character {
    int gold;
    int level;
    vector<Item> inventory;
    
public:
    Player(string n) : Character(n, 100, 15, 8), gold(50), level(1) {}
    
    void showStatus() override {
        cout << "\n╔═══════════════════════════╗" << endl;
        cout << "║ ⚔️ " << name << " (Lv." << level << ")" << endl;
        cout << "║ ❤️ HP: " << hp << "/" << maxHp << endl;
        cout << "║ ⚔️ ATK: " << attack << " 🛡️ DEF: " << defense << endl;
        cout << "║ 💰 Gold: " << gold << endl;
        cout << "║ 🎒 아이템: " << inventory.size() << "개" << endl;
        cout << "╚═══════════════════════════╝" << endl;
    }
    
    void addGold(int g) { gold += g; }
    
    void addItem(Item item) {
        inventory.push_back(item);
        cout << "  🎁 " << item.name << " 획득!" << endl;
    }
    
    void usePotion() {
        for (int i = 0; i < (int)inventory.size(); i++) {
            if (inventory[i].type == "potion") {
                heal(inventory[i].value);
                cout << "  💊 " << inventory[i].name << " 사용! (HP: " << hp << ")" << endl;
                inventory.erase(inventory.begin() + i);
                return;
            }
        }
        cout << "  ❌ 포션이 없습니다!" << endl;
    }
    
    void levelUp() {
        level++;
        maxHp += 15;
        attack += 3;
        defense += 2;
        hp = maxHp;
        cout << "  🎉 레벨 업! → Lv." << level << endl;
    }
    
    void showInventory() {
        cout << "🎒 === 인벤토리 ===" << endl;
        if (inventory.empty()) {
            cout << "  (비어있음)" << endl;
        } else {
            for (auto &item : inventory) {
                cout << "  • " << item.name << " (" << item.type << ")" << endl;
            }
        }
    }
};

// === 몬스터 ===
class Monster : public Character {
    int expReward;
    int goldReward;
    
public:
    Monster(string n, int h, int a, int d, int exp, int gold)
        : Character(n, h, a, d), expReward(exp), goldReward(gold) {}
    
    int getExpReward() { return expReward; }
    int getGoldReward() { return goldReward; }
};

// === 전투 함수 ===
bool battle(Player &player, Monster &monster) {
    cout << "\n⚔️ === " << monster.getName() << " 출현! === ⚔️" << endl;
    
    while (player.isAlive() && monster.isAlive()) {
        cout << "\n[1.공격 2.포션 3.상태]  선택: ";
        int choice;
        cin >> choice;
        
        if (choice == 2) {
            player.usePotion();
        } else if (choice == 3) {
            player.showStatus();
            continue;
        } else {
            // 플레이어 공격
            int dmg = player.doAttack();
            cout << "  ⚔️ " << player.getName() << "의 공격!" << endl;
            monster.takeDamage(dmg);
        }
        
        if (!monster.isAlive()) {
            cout << "\n  🎉 " << monster.getName() << " 처치!" << endl;
            return true;
        }
        
        // 몬스터 공격
        int mdmg = monster.doAttack();
        cout << "  👹 " << monster.getName() << "의 공격!" << endl;
        player.takeDamage(mdmg);
    }
    
    return false;
}

int main() {
    srand(time(0));
    
    string name;
    cout << "🎮 === RPG 던전 탐험 === 🎮" << endl;
    cout << "용사의 이름: ";
    cin >> name;
    
    Player player(name);
    player.addItem(Item("작은 포션", "potion", 30));
    player.addItem(Item("작은 포션", "potion", 30));
    player.showStatus();
    
    // 던전 스테이지
    vector<Monster> dungeon = {
        Monster("🟢 슬라임", 30, 5, 2, 20, 10),
        Monster("🔵 고블린", 50, 10, 5, 30, 20),
        Monster("🟡 오크", 80, 15, 8, 40, 30),
        Monster("🔴 드래곤", 130, 22, 12, 60, 50)
    };
    
    int stage = 0;
    for (auto &monster : dungeon) {
        stage++;
        cout << "\n═══ STAGE " << stage << "/" << dungeon.size() << " ═══" << endl;
        
        if (battle(player, monster)) {
            player.addGold(monster.getGoldReward());
            cout << "  💰 +" << monster.getGoldReward() << " Gold" << endl;
            
            if (rand() % 2 == 0) {
                player.addItem(Item("포션", "potion", 40));
            }
            
            player.levelUp();
        } else {
            cout << "\n💀 게임 오버..." << endl;
            player.showStatus();
            return 0;
        }
    }
    
    cout << "\n🏆🎉 축하합니다! 던전 클리어! 🎉🏆" << endl;
    player.showStatus();
    player.showInventory();
    
    return 0;
}
```

---

### 🅲️ 프로젝트 C: 📒 주소록 관리 프로그램

**난이도**: ⭐⭐ (기본)

**사용 개념**: 클래스, map, vector, 파일 I/O, string

```cpp
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;
    string group;   // 가족, 친구, 직장 등
    
    Contact() {}
    Contact(string n, string p, string e, string g)
        : name(n), phone(p), email(e), group(g) {}
    
    void print() {
        cout << "  📇 " << name << endl;
        cout << "     📱 " << phone << endl;
        cout << "     📧 " << email << endl;
        cout << "     📁 " << group << endl;
    }
};

class AddressBook {
private:
    map<string, Contact> contacts;  // 이름 → 연락처
    string filename;
    
public:
    AddressBook(string fname = "contacts.txt") : filename(fname) {
        load();
    }
    
    void add() {
        string n, p, e, g;
        cout << "이름: "; cin >> n;
        cout << "전화번호: "; cin >> p;
        cout << "이메일: "; cin >> e;
        cout << "그룹(가족/친구/직장): "; cin >> g;
        contacts[n] = Contact(n, p, e, g);
        save();
        cout << "✅ 추가 완료!" << endl;
    }
    
    void search() {
        string keyword;
        cout << "검색 이름: "; cin >> keyword;
        if (contacts.count(keyword)) {
            contacts[keyword].print();
        } else {
            cout << "❌ 찾을 수 없습니다." << endl;
        }
    }
    
    void listAll() {
        cout << "\n📒 === 전체 연락처 (" << contacts.size() << "명) ===" << endl;
        for (auto &p : contacts) {
            p.second.print();
            cout << endl;
        }
    }
    
    void listByGroup() {
        string g;
        cout << "그룹 이름: "; cin >> g;
        cout << "\n📁 === " << g << " 그룹 ===" << endl;
        bool found = false;
        for (auto &p : contacts) {
            if (p.second.group == g) {
                p.second.print();
                cout << endl;
                found = true;
            }
        }
        if (!found) cout << "  (해당 그룹 없음)" << endl;
    }
    
    void remove() {
        string name;
        cout << "삭제할 이름: "; cin >> name;
        if (contacts.erase(name)) {
            save();
            cout << "🗑️ 삭제 완료!" << endl;
        } else {
            cout << "❌ 찾을 수 없습니다." << endl;
        }
    }
    
private:
    void save() {
        ofstream fout(filename);
        for (auto &p : contacts) {
            Contact &c = p.second;
            fout << c.name << " " << c.phone << " " << c.email << " " << c.group << endl;
        }
        fout.close();
    }
    
    void load() {
        ifstream fin(filename);
        string n, p, e, g;
        while (fin >> n >> p >> e >> g) {
            contacts[n] = Contact(n, p, e, g);
        }
        fin.close();
    }
};

int main() {
    AddressBook book;
    int choice;
    
    do {
        cout << "\n📒 === 주소록 관리 ===" << endl;
        cout << "1.추가 2.검색 3.전체목록 4.그룹별 5.삭제 0.종료" << endl;
        cout << "선택: ";
        cin >> choice;
        
        switch (choice) {
            case 1: book.add(); break;
            case 2: book.search(); break;
            case 3: book.listAll(); break;
            case 4: book.listByGroup(); break;
            case 5: book.remove(); break;
        }
    } while (choice != 0);
    
    cout << "👋 종료!" << endl;
    return 0;
}
```

---

## 🎯 2교시: 프로젝트 코딩 & 완성 (50분)

> 자유 코딩 시간! 선택한 프로젝트를 완성하세요.
> 
> **도전 과제** (시간이 남는 학생):
> - 프로젝트 A: 과목별 평균/최고점 통계 추가
> - 프로젝트 B: 상점 시스템 (무기/방어구 구매) 추가
> - 프로젝트 C: CSV 형식 내보내기 기능 추가

---

## 🎯 3교시: 코드 리뷰 & 전체 총정리 (50분)

### 📖 코드 리뷰 체크리스트 (15분)

| 항목 | 자가 점검 |
|------|----------|
| 변수명이 의미를 잘 전달하나? | ☐ |
| 함수가 하나의 역할만 하나? | ☐ |
| 중복 코드가 없나? | ☐ |
| 접근 제어자를 적절히 사용했나? | ☐ |
| 에러 처리를 했나? (입력 검증 등) | ☐ |
| 주석이 적절한가? | ☐ |

---

### 📖 13일간 배운 내용 총정리 (20분)

```
🗺️ C / C++ 학습 로드맵

📌 PART 1: C 언어 기초 (Day 01~02)
   ✅ 변수, 자료형, 입출력
   ✅ 연산자, 조건문, 반복문

📌 PART 2: C 언어 심화 (Day 04~07)
   ✅ 반복문 심화 (for, while, 중첩)
   ✅ 함수 (매개변수, 반환값, 재귀)
   ✅ 배열 & 문자열
   ✅ 포인터 & 구조체

📌 PART 3: C++ 전환 (Day 08)
   ✅ cout/cin, string, bool
   ✅ 참조, 함수 오버로딩

📌 PART 4: C++ 핵심 (Day 09~11)
   ✅ 클래스 & 객체
   ✅ 상속
   ✅ 다형성, 템플릿

📌 PART 5: STL (Day 12)
   ✅ vector, map, set
   ✅ algorithm, 파일 I/O

📌 PART 6: 종합 프로젝트 (Day 13)
   ✅ 미니 프로젝트 완성!
```

### 핵심 개념 비교 카드

| C 언어 | C++ |
|--------|-----|
| `printf` / `scanf` | `cout` / `cin` |
| `char[]` | `string` |
| `struct` | `class` |
| 포인터(`*ptr`) | 참조(`&ref`) |
| `malloc` / `free` | `new` / `delete` |
| 함수 포인터 | 가상 함수(virtual) |
| — | 상속, 다형성 |
| — | 템플릿 |
| — | STL (vector, map...) |
| — | 연산자 오버로딩 |

---

### 🎓 수료 후 추천 학습 경로 (15분)

```
현재 위치: C/C++ 기초 완성! 🎉

선택지 1: 🎮 게임 개발
  → 자료구조 & 알고리즘 → SDL2 / SFML → Unreal Engine (C++)

선택지 2: 💻 시스템 프로그래밍
  → 운영체제 → 네트워크 → 임베디드 (C)

선택지 3: 🤖 코딩 테스트
  → 자료구조 → 알고리즘 → 백준 / 프로그래머스

선택지 4: 🌐 다른 언어
  → Python (AI/데이터) / Java (웹/안드로이드) / Rust (시스템)
```

**추천 도서 & 사이트:**
- 📖 «열혈 C 프로그래밍» — 윤성우
- 📖 «이것이 C++이다» — 최호성
- 🌐 [백준 온라인 저지](https://www.acmicpc.net/) — 알고리즘 연습
- 🌐 [cppreference.com](https://cppreference.com/) — C++ 레퍼런스

---

## 🎉 수료를 축하합니다! 🎓

```
╔═══════════════════════════════════════╗
║                                       ║
║   🎓 C / C++ 13일 커리큘럼 수료!      ║
║                                       ║
║   Day 01~07: C 언어 마스터     ✅     ║
║   Day 08~12: C++ 핵심 학습     ✅     ║
║   Day 13:    종합 프로젝트     ✅     ║
║                                       ║
║   🎉 축하합니다!                      ║
║   이제 여러분은 C/C++ 기초를           ║
║   탄탄하게 다진 개발자입니다!          ║
║                                       ║
╚═══════════════════════════════════════╝
```
