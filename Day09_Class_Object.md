# Day 09: 클래스 & 객체 — "로봇 설계도 만들기" 🤖

## 📚 학습 목표
- 클래스의 개념 이해 (설계도 = 클래스, 제품 = 객체)
- 멤버 변수와 멤버 함수 정의
- 접근 제어자(`public`, `private`) 이해
- 생성자와 소멸자 활용
- getter/setter로 캡슐화 구현

## ⏰ 시간 배분 (3시간)
| 시간 | 내용 | 이론 | 실습 |
|------|------|------|------|
| 50분 | **1교시**: 클래스 = 설계도 | 25분 | 25분 |
| 10분 | 휴식 | - | - |
| 50분 | **2교시**: 생성자와 소멸자 | 20분 | 30분 |
| 10분 | 휴식 | - | - |
| 50분 | **3교시**: 캡슐화 & 종합 실습 | 15분 | 35분 |
| 10분 | Q&A 및 정리 | - | - |

> **강사 노트**: "설계도(클래스) → 제품(객체)" 비유를 일관되게 사용합니다. 구조체와의 차이를 비교하며 설명하세요.

---

## 🎯 1교시: 클래스 = 설계도 (50분)

### 📖 이론 (25분)

#### 1.1 클래스란?

**클래스 = 로봇 설계도** 🤖  
**객체 = 설계도로 만든 실제 로봇**

```
설계도 (Class)           실제 제품 (Object)
┌──────────────┐        ┌──────────────┐
│  Robot       │  ───►  │ robot1       │
│  - name      │  ───►  │ name="아이언맨"│
│  - power     │  ───►  │ power=100    │
│  + attack()  │        │              │
│  + speak()   │        └──────────────┘
└──────────────┘        ┌──────────────┐
 하나의 설계도로    ───►  │ robot2       │
 여러 제품을            │ name="범블비" │
 만들 수 있다!          │ power=85     │
                        └──────────────┘
```

#### 1.2 구조체 vs 클래스

```cpp
// C 구조체: 데이터만 묶음
struct Dog_C {
    char name[20];
    int age;
};

// C++ 클래스: 데이터 + 기능(함수)을 묶음!
class Dog {
public:
    string name;
    int age;
    
    void bark() {           // 기능(함수)도 포함!
        cout << name << ": 멍멍!" << endl;
    }
};
```

> **핵심 차이**: struct는 기본 `public`, class는 기본 `private`

#### 1.3 클래스 기본 구조

```cpp
class 클래스이름 {
private:       // 외부에서 접근 불가 (비밀!)
    // 멤버 변수
    
public:        // 외부에서 접근 가능
    // 멤버 함수
};
```

```cpp
class Dog {
private:
    string name;
    int age;
    
public:
    void setInfo(string n, int a) {
        name = n;
        age = a;
    }
    
    void introduce() {
        cout << "🐕 이름: " << name << ", 나이: " << age << "살" << endl;
    }
    
    void bark() {
        cout << name << ": 멍멍! 🐶" << endl;
    }
};
```

#### 1.4 객체 생성과 사용

```cpp
int main() {
    Dog dog1;                    // 객체 생성!
    dog1.setInfo("멍이", 3);     // 멤버 함수 호출
    dog1.introduce();            // 🐕 이름: 멍이, 나이: 3살
    dog1.bark();                 // 멍이: 멍멍! 🐶
    
    Dog dog2;
    dog2.setInfo("초코", 2);
    dog2.introduce();
    
    return 0;
}
```

---

### 💻 실습 (25분)

#### 💻 실습 9-1: Dog 클래스 만들기 (10분)

```cpp
#include <iostream>
#include <string>
using namespace std;

class Dog {
private:
    string name;
    string breed;
    int age;
    
public:
    void setInfo(string n, string b, int a) {
        name = n;
        breed = b;
        age = a;
    }
    
    void introduce() {
        cout << "┌──────────────────┐" << endl;
        cout << "│ 🐕 강아지 카드    │" << endl;
        cout << "│ 이름: " << name << endl;
        cout << "│ 견종: " << breed << endl;
        cout << "│ 나이: " << age << "살" << endl;
        cout << "└──────────────────┘" << endl;
    }
    
    void bark() {
        cout << name << ": 멍멍! 🐶" << endl;
    }
    
    void sit() {
        cout << name << ": (앉아!) 🐕" << endl;
    }
};

int main() {
    Dog d1, d2;
    
    d1.setInfo("멍이", "시바견", 3);
    d2.setInfo("초코", "푸들", 2);
    
    d1.introduce();
    d1.bark();
    
    cout << endl;
    
    d2.introduce();
    d2.sit();
    
    return 0;
}
```

---

#### 💻 실습 9-2: Phone 클래스 (15분)

```cpp
#include <iostream>
#include <string>
using namespace std;

class Phone {
private:
    string brand;
    string model;
    int battery;  // 0~100
    
public:
    void setInfo(string b, string m) {
        brand = b;
        model = m;
        battery = 100;  // 처음엔 완충!
    }
    
    void showStatus() {
        cout << "[📱 " << brand << " " << model << "] 배터리: ";
        cout << battery << "% ";
        if (battery > 50) cout << "🟢" << endl;
        else if (battery > 20) cout << "🟡" << endl;
        else cout << "🔴" << endl;
    }
    
    void call(string who) {
        if (battery >= 10) {
            cout << "📞 " << who << "에게 전화 중..." << endl;
            battery -= 10;
        } else {
            cout << "🔋 배터리 부족! 충전하세요." << endl;
        }
    }
    
    void charge() {
        battery = 100;
        cout << "⚡ 충전 완료!" << endl;
    }
};

int main() {
    Phone myPhone;
    myPhone.setInfo("Samsung", "Galaxy");
    myPhone.showStatus();
    
    myPhone.call("엄마");
    myPhone.call("친구");
    myPhone.showStatus();
    
    myPhone.charge();
    myPhone.showStatus();
    
    return 0;
}
```

---

## 🎯 2교시: 생성자와 소멸자 (50분)

### 📖 이론 (20분)

#### 2.1 생성자 — "태어날 때 초기화!"

지금까지 `setInfo()`로 값을 넣었는데, 생성자를 쓰면 **만들 때 바로 초기화!**

```cpp
class Dog {
private:
    string name;
    int age;
    
public:
    // 생성자: 클래스 이름과 같음, 반환타입 없음!
    Dog(string n, int a) {
        name = n;
        age = a;
        cout << name << " 탄생! 🎉" << endl;
    }
    
    void introduce() {
        cout << name << ", " << age << "살" << endl;
    }
};

int main() {
    Dog d1("멍이", 3);    // 만들면서 바로 초기화!
    Dog d2("초코", 2);
    
    d1.introduce();
    d2.introduce();
}
```

#### 2.2 생성자 오버로딩

```cpp
class Dog {
public:
    string name;
    int age;
    
    // 기본 생성자
    Dog() {
        name = "이름없음";
        age = 0;
    }
    
    // 매개변수 생성자
    Dog(string n, int a) {
        name = n;
        age = a;
    }
};

Dog d1;             // 기본 생성자 → "이름없음", 0
Dog d2("멍이", 3);  // 매개변수 생성자
```

#### 2.3 초기화 리스트 — 더 세련된 방식

```cpp
class Student {
private:
    string name;
    int score;
    
public:
    // 초기화 리스트 (: 뒤에 초기화!)
    Student(string n, int s) : name(n), score(s) {
        // 추가 코드 (필요 시)
    }
};
```

#### 2.4 소멸자 — "사라질 때 정리!"

```cpp
class Dog {
public:
    string name;
    
    Dog(string n) : name(n) {
        cout << name << " 생성! 🎉" << endl;
    }
    
    ~Dog() {  // 소멸자: ~클래스이름()
        cout << name << " 소멸... 👋" << endl;
    }
};
// 프로그램 끝나면 자동으로 소멸자 호출!
```

#### 2.5 this 포인터

```cpp
class Dog {
private:
    string name;
    
public:
    Dog(string name) {
        this->name = name;  // this = "나 자신"을 가리키는 포인터
    }
};
```

---

### 💻 실습 (30분)

#### 💻 실습 9-3: Student 클래스 (생성자 + 초기화 리스트) (15분)

```cpp
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int kor, eng, math;
    
public:
    // 초기화 리스트 사용!
    Student(string n, int k, int e, int m)
        : name(n), kor(k), eng(e), math(m) {}
    
    int getTotal() { return kor + eng + math; }
    double getAvg() { return getTotal() / 3.0; }
    
    char getGrade() {
        double avg = getAvg();
        if (avg >= 90) return 'A';
        if (avg >= 80) return 'B';
        if (avg >= 70) return 'C';
        if (avg >= 60) return 'D';
        return 'F';
    }
    
    void print() {
        cout << "│ " << name << "\t│ "
             << kor << "\t│ " << eng << "\t│ " << math << "\t│ "
             << getTotal() << "\t│ " << getAvg() << "\t│ "
             << getGrade() << " │" << endl;
    }
};

int main() {
    Student students[] = {
        Student("홍길동", 95, 88, 92),
        Student("김철수", 72, 85, 68),
        Student("이영희", 88, 92, 95)
    };
    
    cout << "┌────────┬──────┬──────┬──────┬──────┬──────┬────┐" << endl;
    cout << "│ 이름\t│ 국어\t│ 영어\t│ 수학\t│ 총점\t│ 평균\t│등급│" << endl;
    cout << "├────────┼──────┼──────┼──────┼──────┼──────┼────┤" << endl;
    for (int i = 0; i < 3; i++) {
        students[i].print();
    }
    cout << "└────────┴──────┴──────┴──────┴──────┴──────┴────┘" << endl;
    
    return 0;
}
```

---

#### 💻 실습 9-4: BankAccount 클래스 (15분)

```cpp
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string owner;
    int balance;
    
public:
    BankAccount(string name, int money = 0)
        : owner(name), balance(money) {
        cout << "💳 " << owner << "님의 계좌 개설! (잔액: "
             << balance << "원)" << endl;
    }
    
    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
            cout << "💰 " << amount << "원 입금 → 잔액: "
                 << balance << "원" << endl;
        }
    }
    
    void withdraw(int amount) {
        if (amount > balance) {
            cout << "❌ 잔액 부족! (잔액: " << balance << "원)" << endl;
        } else {
            balance -= amount;
            cout << "💸 " << amount << "원 출금 → 잔액: "
                 << balance << "원" << endl;
        }
    }
    
    void showBalance() {
        cout << "📊 " << owner << "님 잔액: " << balance << "원" << endl;
    }
};

int main() {
    BankAccount acc("홍길동", 10000);
    
    acc.deposit(5000);
    acc.withdraw(3000);
    acc.withdraw(20000);  // 잔액 부족!
    acc.showBalance();
    
    return 0;
}
```

---

## 🎯 3교시: 캡슐화 & 종합 실습 (50분)

### 📖 이론 (15분)

#### 3.1 캡슐화 — "내부를 숨기고, 인터페이스만 공개!"

```
┌─────────────────────────┐
│     BankAccount         │
│  ┌───────────────────┐  │
│  │ private:          │  │  ← 비밀! 외부 접근 불가
│  │   balance = 10000 │  │
│  └───────────────────┘  │
│  ┌───────────────────┐  │
│  │ public:           │  │  ← 공개! 외부에서 사용
│  │   deposit()       │  │
│  │   withdraw()      │  │
│  │   getBalance()    │  │
│  └───────────────────┘  │
└─────────────────────────┘
```

#### 3.2 getter / setter 패턴

```cpp
class Person {
private:
    string name;
    int age;
    
public:
    // Getter — 값을 읽기만
    string getName() { return name; }
    int getAge() { return age; }
    
    // Setter — 값을 쓰기 (검증 가능!)
    void setAge(int a) {
        if (a >= 0 && a <= 150) {  // 유효성 검사!
            age = a;
        } else {
            cout << "❌ 잘못된 나이!" << endl;
        }
    }
};
```

---

### 💻 종합 실습 (35분)

#### 💻 종합 실습 9-5: 🎮 RPG Player 클래스 (35분)

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
private:
    string name;
    string job;
    int hp, maxHp;
    int attack, defense;
    int level, exp;
    int gold;
    
public:
    Player(string n, int jobChoice) : name(n), level(1), exp(0), gold(100) {
        switch (jobChoice) {
            case 1:
                job = "전사"; maxHp = 120; attack = 15; defense = 10;
                break;
            case 2:
                job = "마법사"; maxHp = 80; attack = 25; defense = 5;
                break;
            default:
                job = "궁수"; maxHp = 100; attack = 18; defense = 7;
        }
        hp = maxHp;
    }
    
    string getName() { return name; }
    bool isAlive() { return hp > 0; }
    
    void showStatus() {
        cout << "\n╔═══════════════════════╗" << endl;
        cout << "║ 🪪 " << name << " (" << job << ") Lv." << level << endl;
        cout << "║ ❤️ HP: " << hp << "/" << maxHp << endl;
        cout << "║ ⚔️ ATK: " << attack << "  🛡️ DEF: " << defense << endl;
        cout << "║ ⭐ EXP: " << exp << "/100  💰 " << gold << "G" << endl;
        cout << "╚═══════════════════════╝" << endl;
    }
    
    int doAttack() {
        int dmg = attack + rand() % 5;
        cout << "  ⚔️ " << name << "의 공격! " << dmg << " 데미지!" << endl;
        return dmg;
    }
    
    void takeDamage(int dmg) {
        int real = dmg - defense;
        if (real < 1) real = 1;
        hp -= real;
        if (hp < 0) hp = 0;
        cout << "  💥 " << name << " → " << real << " 피해 (HP: " << hp << ")" << endl;
    }
    
    void gainExp(int e) {
        exp += e;
        gold += 50;
        cout << "  📈 +" << e << " EXP, +50 Gold" << endl;
        if (exp >= 100) {
            levelUp();
        }
    }
    
    void heal() {
        hp = maxHp;
        cout << "  💊 체력 완전 회복!" << endl;
    }
    
private:
    void levelUp() {
        level++;
        exp -= 100;
        maxHp += 10;
        attack += 3;
        defense += 2;
        hp = maxHp;
        cout << "  🎉 레벨 업! → Lv." << level << endl;
    }
};

int main() {
    srand(time(0));
    
    string name;
    int jobChoice;
    
    cout << "🎮 === RPG 어드벤처 === 🎮" << endl;
    cout << "캐릭터 이름: ";
    cin >> name;
    cout << "직업 선택 (1.전사 2.마법사 3.궁수): ";
    cin >> jobChoice;
    
    Player player(name, jobChoice);
    player.showStatus();
    
    // 몬스터 이름 배열
    string monsters[] = {"슬라임", "고블린", "오크", "드래곤"};
    int monsterHp[] = {30, 50, 80, 120};
    int monsterAtk[] = {8, 12, 18, 25};
    
    for (int stage = 0; stage < 4; stage++) {
        cout << "\n═══ STAGE " << stage + 1 << " ═══" << endl;
        cout << "🐉 " << monsters[stage] << " 출현!" << endl;
        
        int mHp = monsterHp[stage];
        
        while (player.isAlive() && mHp > 0) {
            // 플레이어 공격
            int dmg = player.doAttack();
            mHp -= dmg;
            if (mHp < 0) mHp = 0;
            cout << "  [" << monsters[stage] << " HP: " << mHp << "]" << endl;
            
            if (mHp <= 0) {
                cout << "  🎉 " << monsters[stage] << " 처치!" << endl;
                player.gainExp(30);
                player.heal();
                break;
            }
            
            // 몬스터 공격
            player.takeDamage(monsterAtk[stage]);
        }
        
        if (!player.isAlive()) {
            cout << "\n💀 게임 오버..." << endl;
            return 0;
        }
    }
    
    cout << "\n🏆 축하합니다! 모든 스테이지를 클리어했습니다!" << endl;
    player.showStatus();
    
    return 0;
}
```

---

## 📝 핵심 정리

| 개념 | 설명 | 예시 |
|------|------|------|
| **class** | 설계도 | `class Dog { ... };` |
| **객체** | 설계도로 만든 제품 | `Dog d1;` |
| **public** | 외부 접근 가능 | 멤버 함수 |
| **private** | 외부 접근 불가 | 멤버 변수 |
| **생성자** | 객체 생성 시 초기화 | `Dog(string n)` |
| **소멸자** | 객체 소멸 시 정리 | `~Dog()` |
| **this** | 자기 자신 포인터 | `this->name` |
| **getter/setter** | 캡슐화 접근 방법 | `getName()`, `setAge()` |

---

## 📝 과제

### 과제 1: Car 클래스
- 속성: 브랜드, 모델, 현재 속도, 최대 속도
- 기능: 가속(`accelerate`), 감속(`brake`), 상태 출력
- 최대 속도 이상 가속 불가!

### 과제 2: Clock 클래스
- 속성: 시, 분, 초
- 기능: 시간 설정, 1초 증가(`tick`), 현재 시간 출력
- 59초 → 0초 + 1분 증가, 59분 → 0분 + 1시 증가 처리
