# Day 10: 상속 — "부모에게 물려받는 능력!" 👨‍👩‍👧

## 📚 학습 목표
- 상속의 개념 이해 (부모 → 자식)
- `protected` 접근 제어자 이해
- 생성자/소멸자 호출 순서 파악
- 함수 오버라이딩과 `virtual` 맛보기
- 상속을 활용한 설계 능력 기르기

## ⏰ 시간 배분 (3시간)
| 시간 | 내용 | 이론 | 실습 |
|------|------|------|------|
| 50분 | **1교시**: 상속 개념 — 부모의 능력을 물려받자 | 25분 | 25분 |
| 10분 | 휴식 | - | - |
| 50분 | **2교시**: 생성자 호출 & 오버라이딩 | 20분 | 30분 |
| 10분 | 휴식 | - | - |
| 50분 | **3교시**: 종합 실습 — RPG 직업 시스템 | 15분 | 35분 |
| 10분 | Q&A 및 정리 | - | - |

---

## 🎯 1교시: 상속 개념 — "부모의 능력을 물려받자" (50분)

### 📖 이론 (25분)

#### 1.1 상속이란?

**상속 = 부모의 능력을 자식이 물려받는 것** 👨‍👩‍👧

```
       Animal (부모 클래스)
       ├── name, age
       └── eat(), sleep()
          │
     ┌────┴────┐
    Dog       Cat    (자식 클래스)
    bark()    meow()  ← 자기만의 능력 추가!
```

- **부모(Base)**: 공통 속성/기능 정의
- **자식(Derived)**: 부모의 것 + 추가 기능

#### 1.2 상속 문법

```cpp
class Animal {  // 부모 클래스
public:
    string name;
    int age;
    
    void eat() {
        cout << name << "이(가) 밥을 먹습니다 🍚" << endl;
    }
    
    void sleep() {
        cout << name << "이(가) 잠을 잡니다 😴" << endl;
    }
};

// Dog는 Animal을 상속받는다!
class Dog : public Animal {
public:
    void bark() {
        cout << name << ": 멍멍! 🐶" << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << name << ": 야옹~ 🐱" << endl;
    }
};
```

```cpp
int main() {
    Dog d;
    d.name = "멍이";  // 부모에게 물려받은 속성
    d.age = 3;
    d.eat();           // 부모에게 물려받은 함수
    d.bark();          // 자기만의 함수
    
    Cat c;
    c.name = "나비";
    c.eat();
    c.meow();
}
```

#### 1.3 접근 제어자: protected

| 접근 제어자 | 같은 클래스 | 자식 클래스 | 외부 |
|------------|-----------|-----------|------|
| `public` | ✅ | ✅ | ✅ |
| `protected` | ✅ | ✅ | ❌ |
| `private` | ✅ | ❌ | ❌ |

```cpp
class Animal {
protected:      // 자식은 접근 가능, 외부는 불가!
    string name;
    int age;
    
public:
    void setInfo(string n, int a) {
        name = n;
        age = a;
    }
};

class Dog : public Animal {
public:
    void introduce() {
        // ✅ protected 멤버에 접근 가능!
        cout << name << ", " << age << "살" << endl;
    }
};
```

---

### 💻 실습 (25분)

#### 💻 실습 10-1: Animal → Dog, Cat (15분)

```cpp
#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    int age;
    
public:
    Animal(string n, int a) : name(n), age(a) {}
    
    void eat() { cout << name << "이(가) 밥을 먹습니다 🍚" << endl; }
    void sleep() { cout << name << "이(가) 잠을 잡니다 😴" << endl; }
    
    void showInfo() {
        cout << "이름: " << name << ", 나이: " << age << "살" << endl;
    }
};

class Dog : public Animal {
private:
    string breed;
public:
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {}
    
    void bark() { cout << name << ": 멍멍! 🐶" << endl; }
    void fetch() { cout << name << ": 공 물어오기! 🎾" << endl; }
    
    void showAll() {
        showInfo();
        cout << "견종: " << breed << endl;
    }
};

class Cat : public Animal {
private:
    bool isIndoor;
public:
    Cat(string n, int a, bool indoor) : Animal(n, a), isIndoor(indoor) {}
    
    void meow() { cout << name << ": 야옹~ 🐱" << endl; }
    
    void showAll() {
        showInfo();
        cout << (isIndoor ? "실내 고양이" : "실외 고양이") << endl;
    }
};

int main() {
    Dog d("멍이", 3, "시바견");
    Cat c("나비", 2, true);
    
    cout << "=== 🐕 강아지 ===" << endl;
    d.showAll();
    d.eat();
    d.bark();
    d.fetch();
    
    cout << "\n=== 🐱 고양이 ===" << endl;
    c.showAll();
    c.eat();
    c.meow();
    
    return 0;
}
```

---

#### 💻 실습 10-2: Vehicle → Car, Bicycle (10분)

```cpp
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string name;
    int speed;
    int maxSpeed;
    
public:
    Vehicle(string n, int ms) : name(n), speed(0), maxSpeed(ms) {}
    
    void accelerate(int amount) {
        speed += amount;
        if (speed > maxSpeed) speed = maxSpeed;
        cout << name << " 가속! 현재 속도: " << speed << " km/h" << endl;
    }
    
    void brake() {
        speed = 0;
        cout << name << " 정지! 🛑" << endl;
    }
};

class Car : public Vehicle {
    int fuel;
public:
    Car(string n) : Vehicle(n, 200), fuel(100) {}
    
    void honk() { cout << name << ": 빵빵! 🚗" << endl; }
    
    void showStatus() {
        cout << "[🚗 " << name << "] 속도: " << speed
             << " km/h, 연료: " << fuel << "%" << endl;
    }
};

class Bicycle : public Vehicle {
public:
    Bicycle(string n) : Vehicle(n, 40) {}
    
    void ringBell() { cout << name << ": 따르릉! 🚲" << endl; }
};

int main() {
    Car car("소나타");
    Bicycle bike("내 자전거");
    
    car.honk();
    car.accelerate(80);
    car.showStatus();
    
    cout << endl;
    
    bike.ringBell();
    bike.accelerate(20);
    
    return 0;
}
```

---

## 🎯 2교시: 생성자 호출 & 오버라이딩 (50분)

### 📖 이론 (20분)

#### 2.1 생성자/소멸자 호출 순서

```
생성 순서: 부모 먼저 → 자식
소멸 순서: 자식 먼저 → 부모 (반대!)
```

```cpp
class Animal {
public:
    Animal() { cout << "[Animal 생성]" << endl; }
    ~Animal() { cout << "[Animal 소멸]" << endl; }
};

class Dog : public Animal {
public:
    Dog() { cout << "[Dog 생성]" << endl; }
    ~Dog() { cout << "[Dog 소멸]" << endl; }
};

int main() {
    Dog d;
}
// 출력:
// [Animal 생성]  ← 부모 먼저!
// [Dog 생성]
// [Dog 소멸]     ← 자식 먼저 소멸!
// [Animal 소멸]
```

#### 2.2 부모 생성자에 값 전달

```cpp
class Animal {
protected:
    string name;
public:
    Animal(string n) : name(n) {
        cout << name << " 탄생!" << endl;
    }
};

class Dog : public Animal {
    string breed;
public:
    // 부모 생성자를 초기화 리스트에서 호출!
    Dog(string n, string b) : Animal(n), breed(b) {
        cout << breed << " " << name << " 준비 완료!" << endl;
    }
};
```

#### 2.3 함수 오버라이딩 — "부모 능력을 재정의!"

```cpp
class Animal {
public:
    string name;
    
    void speak() {
        cout << name << ": ..." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() {  // 부모의 speak()을 재정의!
        cout << name << ": 멍멍!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() {
        cout << name << ": 야옹~" << endl;
    }
};
```

#### 2.4 virtual 맛보기 — "진짜 다형성"

```cpp
class Animal {
public:
    string name;
    virtual void speak() {  // virtual 추가!
        cout << name << ": ..." << endl;
    }
};

// 이제 포인터로도 올바른 함수가 호출됨!
Animal *a = new Dog();
a->speak();  // "멍멍!" (virtual 덕분!)
```

> **virtual은 Day 11에서 자세히 배웁니다!**

---

### 💻 실습 (30분)

#### 💻 실습 10-3: Person → Student, Teacher (15분)

```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    
public:
    Person(string n, int a) : name(n), age(a) {}
    
    virtual void introduce() {
        cout << "이름: " << name << ", 나이: " << age << "살" << endl;
    }
};

class Student : public Person {
    string school;
    int grade;
    
public:
    Student(string n, int a, string s, int g)
        : Person(n, a), school(s), grade(g) {}
    
    void introduce() override {
        cout << "🎒 학생: " << name << " (" << age << "살)" << endl;
        cout << "   학교: " << school << ", " << grade << "학년" << endl;
    }
    
    void study() {
        cout << "   " << name << ": 열심히 공부 중! 📚" << endl;
    }
};

class Teacher : public Person {
    string subject;
    
public:
    Teacher(string n, int a, string s)
        : Person(n, a), subject(s) {}
    
    void introduce() override {
        cout << "👨‍🏫 선생님: " << name << " (" << age << "살)" << endl;
        cout << "   과목: " << subject << endl;
    }
    
    void teach() {
        cout << "   " << name << ": " << subject << " 수업 시작!" << endl;
    }
};

int main() {
    Student s("홍길동", 17, "한양고", 2);
    Teacher t("김선생", 35, "C++ 프로그래밍");
    
    s.introduce();
    s.study();
    
    cout << endl;
    
    t.introduce();
    t.teach();
    
    return 0;
}
```

---

#### 💻 실습 10-4: 생성자/소멸자 순서 확인 (15분)

```cpp
#include <iostream>
#include <string>
using namespace std;

class Base {
public:
    Base() { cout << "📦 Base 생성!" << endl; }
    ~Base() { cout << "📦 Base 소멸!" << endl; }
};

class Child : public Base {
public:
    Child() { cout << "🎁 Child 생성!" << endl; }
    ~Child() { cout << "🎁 Child 소멸!" << endl; }
};

class GrandChild : public Child {
public:
    GrandChild() { cout << "🎀 GrandChild 생성!" << endl; }
    ~GrandChild() { cout << "🎀 GrandChild 소멸!" << endl; }
};

int main() {
    cout << "=== 객체 생성 ===" << endl;
    GrandChild gc;
    cout << "\n=== 객체 소멸 ===" << endl;
    return 0;
}
```

**출력:**
```
=== 객체 생성 ===
📦 Base 생성!
🎁 Child 생성!
🎀 GrandChild 생성!

=== 객체 소멸 ===
🎀 GrandChild 소멸!
🎁 Child 소멸!
📦 Base 소멸!
```

---

## 🎯 3교시: 종합 실습 — RPG 직업 시스템 (50분)

### 📖 상속 설계 팁 (15분)

```
"is-a" 관계가 성립하면 상속!

✅ Dog is an Animal  → Dog : public Animal
✅ Student is a Person → Student : public Person
❌ Engine is a Car   → Engine은 Car의 부품! (상속 ✕, 포함 ○)
```

---

### 💻 종합 실습 10-5: 🎮 RPG 직업 시스템 (35분)

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// === 부모 클래스 ===
class Character {
protected:
    string name;
    string job;
    int hp, maxHp;
    int mp, maxMp;
    int attack, defense;
    
public:
    Character(string n, string j, int h, int m, int a, int d)
        : name(n), job(j), hp(h), maxHp(h), mp(m), maxMp(m),
          attack(a), defense(d) {}
    
    bool isAlive() { return hp > 0; }
    string getName() { return name; }
    
    void showStatus() {
        cout << "┌─────────────────────┐" << endl;
        cout << "│ " << job << " " << name << endl;
        cout << "│ ❤️ " << hp << "/" << maxHp
             << "  💧 " << mp << "/" << maxMp << endl;
        cout << "│ ⚔️ " << attack << "  🛡️ " << defense << endl;
        cout << "└─────────────────────┘" << endl;
    }
    
    virtual int doAttack() {
        int dmg = attack + rand() % 5;
        cout << "  " << name << "의 기본 공격! → " << dmg << " 데미지" << endl;
        return dmg;
    }
    
    virtual void useSkill() {
        cout << "  (스킬 없음)" << endl;
    }
    
    void takeDamage(int dmg) {
        int real = dmg - defense;
        if (real < 1) real = 1;
        hp -= real;
        if (hp < 0) hp = 0;
    }
};

// === 전사 ===
class Warrior : public Character {
public:
    Warrior(string n)
        : Character(n, "⚔️ 전사", 150, 30, 18, 12) {}
    
    int doAttack() override {
        int dmg = attack + rand() % 8;
        cout << "  " << name << "의 검 공격! → " << dmg << " 데미지" << endl;
        return dmg;
    }
    
    void useSkill() override {
        if (mp >= 20) {
            mp -= 20;
            int dmg = attack * 2;
            cout << "  💥 " << name << "의 파워 스트라이크! → " << dmg << " 데미지!" << endl;
        } else {
            cout << "  💧 MP 부족!" << endl;
        }
    }
};

// === 마법사 ===
class Mage : public Character {
public:
    Mage(string n)
        : Character(n, "🔮 마법사", 80, 100, 25, 5) {}
    
    int doAttack() override {
        int dmg = attack + rand() % 10;
        cout << "  " << name << "의 마법 공격! → " << dmg << " 데미지" << endl;
        return dmg;
    }
    
    void useSkill() override {
        if (mp >= 30) {
            mp -= 30;
            int dmg = attack * 3;
            cout << "  🔥 " << name << "의 파이어볼! → " << dmg << " 데미지!" << endl;
        } else {
            cout << "  💧 MP 부족!" << endl;
        }
    }
};

// === 궁수 ===
class Archer : public Character {
public:
    Archer(string n)
        : Character(n, "🏹 궁수", 100, 60, 20, 8) {}
    
    int doAttack() override {
        int dmg = attack + rand() % 6;
        cout << "  " << name << "의 화살 공격! → " << dmg << " 데미지" << endl;
        return dmg;
    }
    
    void useSkill() override {
        if (mp >= 25) {
            mp -= 25;
            int hits = 3;
            int total = 0;
            cout << "  🏹 " << name << "의 연발 사격!" << endl;
            for (int i = 0; i < hits; i++) {
                int dmg = attack / 2 + rand() % 5;
                total += dmg;
                cout << "    → " << dmg << " 데미지!" << endl;
            }
            cout << "    합계: " << total << " 데미지!" << endl;
        } else {
            cout << "  💧 MP 부족!" << endl;
        }
    }
};

int main() {
    srand(time(0));
    
    string name;
    int choice;
    
    cout << "🎮 === RPG 직업 시스템 === 🎮" << endl;
    cout << "이름 입력: ";
    cin >> name;
    cout << "직업 선택 (1.전사 2.마법사 3.궁수): ";
    cin >> choice;
    
    Character *player;
    switch (choice) {
        case 1: player = new Warrior(name); break;
        case 2: player = new Mage(name); break;
        default: player = new Archer(name);
    }
    
    player->showStatus();
    
    cout << "\n=== 전투 시작! ===" << endl;
    cout << "1.기본공격  2.스킬  → ";
    cin >> choice;
    
    if (choice == 1) player->doAttack();
    else player->useSkill();
    
    player->showStatus();
    
    delete player;
    return 0;
}
```

---

## 📝 핵심 정리

| 개념 | 설명 | 예시 |
|------|------|------|
| **상속** | 부모 능력을 자식에게 | `class Dog : public Animal` |
| **protected** | 자식만 접근 가능 | `protected: int hp;` |
| **생성자 순서** | 부모 → 자식 | Base → Derived |
| **소멸자 순서** | 자식 → 부모 | Derived → Base |
| **오버라이딩** | 부모 함수를 재정의 | `void speak() override` |
| **virtual** | 다형성 지원 | `virtual void speak()` |
| **is-a 관계** | 상속 판단 기준 | "Dog is an Animal" |

---

## 📝 과제

### 과제 1: Shape 상속 트리
```
Shape (넓이 계산 함수)
├── Rectangle (가로, 세로)
├── Circle (반지름)
└── Triangle (밑변, 높이)
```
각 도형 클래스에서 `calcArea()` 함수를 오버라이딩하세요.

### 과제 2: RPG 직업 확장
전사/마법사/궁수 외에 **힐러** 클래스를 추가하세요.
- HP가 낮고 공격력이 낮지만, `heal()` 스킬로 HP를 회복할 수 있음
