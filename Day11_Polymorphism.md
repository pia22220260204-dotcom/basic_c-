# Day 11: 다형성 & 템플릿 — "하나의 명령, 다양한 반응!" 🎭

## 📚 학습 목표
- 다형성의 개념과 virtual 함수 이해
- 순수 가상 함수와 추상 클래스 활용
- 연산자 오버로딩 기초
- 템플릿으로 범용 함수/클래스 만들기

## ⏰ 시간 배분 (3시간)
| 시간 | 내용 | 이론 | 실습 |
|------|------|------|------|
| 50분 | **1교시**: 다형성 — 같은 명령, 다른 행동 | 25분 | 25분 |
| 10분 | 휴식 | - | - |
| 50분 | **2교시**: 연산자 오버로딩 — +를 내 맘대로! | 20분 | 30분 |
| 10분 | 휴식 | - | - |
| 50분 | **3교시**: 템플릿 & 종합 실습 | 20분 | 30분 |
| 10분 | Q&A 및 정리 | - | - |

---

## 🎯 1교시: 다형성 — "같은 명령, 다른 행동" 🎭 (50분)

### 📖 이론 (25분)

#### 1.1 다형성이란?

**다형성 = 같은 명령에 각자 다르게 반응하는 것**

```
"소리 내!" 라고 명령하면:
🐕 강아지 → "멍멍!"
🐱 고양이 → "야옹~"
🐸 개구리 → "개굴개굴"

같은 speak() 함수인데 → 각자 다르게 동작!
```

#### 1.2 virtual 함수 — 진짜 다형성

```cpp
class Animal {
public:
    string name;
    
    // virtual이 없으면: 포인터 타입 기준으로 호출 (정적 바인딩)
    // virtual이 있으면: 실제 객체 타입 기준으로 호출 (동적 바인딩)
    virtual void speak() {
        cout << name << ": ..." << endl;
    }
    
    virtual ~Animal() {}  // 가상 소멸자 (중요!)
};

class Dog : public Animal {
public:
    void speak() override {  // override: 오버라이딩 명시
        cout << name << ": 멍멍! 🐶" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << name << ": 야옹~ 🐱" << endl;
    }
};
```

```cpp
int main() {
    // 포인터로 다형성 활용!
    Animal *animals[3];
    
    animals[0] = new Dog();
    animals[0]->name = "멍이";
    
    animals[1] = new Cat();
    animals[1]->name = "나비";
    
    animals[2] = new Dog();
    animals[2]->name = "바둑이";
    
    // 같은 speak() 호출인데 → 각자 다르게 동작!
    for (int i = 0; i < 3; i++) {
        animals[i]->speak();
    }
    
    // 메모리 해제
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }
}
```

**출력:**
```
멍이: 멍멍! 🐶
나비: 야옹~ 🐱
바둑이: 멍멍! 🐶
```

#### 1.3 순수 가상 함수 & 추상 클래스

```cpp
class Shape {
public:
    // 순수 가상 함수 = 0 → 자식이 반드시 구현해야 함!
    virtual double area() = 0;
    virtual void draw() = 0;
    
    virtual ~Shape() {}
};
// Shape는 추상 클래스 → 객체 생성 불가! (설계도만!)
// Shape s; ← ❌ 에러!

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    double area() override {
        return 3.14159 * radius * radius;
    }
    
    void draw() override {
        cout << "⭕ 원 (반지름: " << radius << ")" << endl;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() override {
        return width * height;
    }
    
    void draw() override {
        cout << "🟦 사각형 (" << width << " x " << height << ")" << endl;
    }
};
```

---

### 💻 실습 (25분)

#### 💻 실습 11-1: 도형 다형성 (25분)

```cpp
#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string color;
public:
    Shape(string c) : color(c) {}
    virtual double area() = 0;
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r, string c = "빨강") : Shape(c), radius(r) {}
    
    double area() override { return 3.14159 * radius * radius; }
    
    void draw() override {
        cout << "⭕ " << color << " 원 (반지름 " << radius << ")" << endl;
        cout << "   넓이: " << area() << endl;
    }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h, string c = "파랑")
        : Shape(c), w(w), h(h) {}
    
    double area() override { return w * h; }
    
    void draw() override {
        cout << "🟦 " << color << " 사각형 (" << w << " x " << h << ")" << endl;
        cout << "   넓이: " << area() << endl;
    }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h, string c = "초록")
        : Shape(c), base(b), height(h) {}
    
    double area() override { return 0.5 * base * height; }
    
    void draw() override {
        cout << "🔺 " << color << " 삼각형 (밑변 " << base
             << ", 높이 " << height << ")" << endl;
        cout << "   넓이: " << area() << endl;
    }
};

int main() {
    Shape *shapes[4];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);
    shapes[2] = new Triangle(3, 8);
    shapes[3] = new Circle(10, "노랑");
    
    cout << "=== 🎨 도형 갤러리 ===" << endl;
    double totalArea = 0;
    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
        totalArea += shapes[i]->area();
        cout << endl;
    }
    cout << "📐 전체 넓이 합: " << totalArea << endl;
    
    for (int i = 0; i < 4; i++) delete shapes[i];
    return 0;
}
```

---

## 🎯 2교시: 연산자 오버로딩 — "+를 내 맘대로!" (50분)

### 📖 이론 (20분)

#### 2.1 연산자 오버로딩이란?

```cpp
// 기본: int끼리 + 는 당연하지만...
int a = 3 + 5;  // 8

// 내가 만든 클래스끼리 + 하려면?
// Point p1(1,2) + Point p2(3,4) → Point(4,6) 하고 싶다!
```

```cpp
class Point {
public:
    int x, y;
    
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // + 연산자 오버로딩!
    Point operator+(const Point &other) {
        return Point(x + other.x, y + other.y);
    }
    
    // == 비교 연산자
    bool operator==(const Point &other) {
        return x == other.x && y == other.y;
    }
    
    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};
```

```cpp
Point p1(1, 2);
Point p2(3, 4);
Point p3 = p1 + p2;  // operator+ 호출!
p3.print();           // (4, 6)
```

#### 2.2 << 연산자 오버로딩 (출력)

```cpp
class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // friend: 클래스 외부 함수에서 private에 접근 허용
    friend ostream& operator<<(ostream &out, const Point &p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

Point p(3, 5);
cout << p << endl;  // (3, 5) ← 바로 출력!
```

---

### 💻 실습 (30분)

#### 💻 실습 11-2: Point 클래스 연산자 (15분)

```cpp
#include <iostream>
using namespace std;

class Point {
public:
    int x, y;
    
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    Point operator+(const Point &p) {
        return Point(x + p.x, y + p.y);
    }
    
    Point operator-(const Point &p) {
        return Point(x - p.x, y - p.y);
    }
    
    bool operator==(const Point &p) {
        return x == p.x && y == p.y;
    }
    
    friend ostream& operator<<(ostream &out, const Point &p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

int main() {
    Point a(3, 5);
    Point b(1, 2);
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a == b? " << (a == b ? "같다" : "다르다") << endl;
    
    return 0;
}
```

---

#### 💻 실습 11-3: Fraction (분수) 클래스 (15분)

```cpp
#include <iostream>
using namespace std;

class Fraction {
    int num, den;  // 분자, 분모
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    void simplify() {
        int g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;
        if (den < 0) { num = -num; den = -den; }
    }
    
public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) { simplify(); }
    
    Fraction operator+(const Fraction &f) {
        return Fraction(num * f.den + f.num * den, den * f.den);
    }
    
    Fraction operator*(const Fraction &f) {
        return Fraction(num * f.num, den * f.den);
    }
    
    friend ostream& operator<<(ostream &out, const Fraction &f) {
        if (f.den == 1) out << f.num;
        else out << f.num << "/" << f.den;
        return out;
    }
};

int main() {
    Fraction a(1, 3);  // 1/3
    Fraction b(2, 5);  // 2/5
    
    cout << a << " + " << b << " = " << (a + b) << endl;
    cout << a << " × " << b << " = " << (a * b) << endl;
    
    return 0;
}
```

**출력:**
```
1/3 + 2/5 = 11/15
1/3 × 2/5 = 2/15
```

---

## 🎯 3교시: 템플릿 & 종합 실습 (50분)

### 📖 이론 (20분)

#### 3.1 함수 템플릿 — "타입을 나중에 정하자!"

```cpp
// ❌ 타입마다 함수를 만들어야 할까?
int maxInt(int a, int b) { return a > b ? a : b; }
double maxDouble(double a, double b) { return a > b ? a : b; }

// ✅ 템플릿으로 한 번에!
template <typename T>
T myMax(T a, T b) {
    return a > b ? a : b;
}

myMax(3, 5);       // int 버전 자동 생성
myMax(1.5, 2.7);   // double 버전 자동 생성
myMax('A', 'Z');   // char 버전 자동 생성
```

#### 3.2 클래스 템플릿

```cpp
template <typename T>
class Box {
    T data;
public:
    Box(T d) : data(d) {}
    T getData() { return data; }
    void setData(T d) { data = d; }
};

Box<int> intBox(42);
Box<string> strBox("Hello");
Box<double> dblBox(3.14);
```

---

### 💻 실습 (30분)

#### 💻 실습 11-4: 템플릿 함수 (10분)

```cpp
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T myMax(T a, T b) {
    return a > b ? a : b;
}

template <typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "큰 수: " << myMax(10, 20) << endl;
    cout << "큰 수: " << myMax(3.14, 2.71) << endl;
    cout << "큰 문자: " << myMax('A', 'Z') << endl;
    
    int a = 10, b = 20;
    mySwap(a, b);
    cout << "교환 후: a=" << a << ", b=" << b << endl;
    
    int arr[] = {5, 3, 8, 1, 9};
    cout << "배열: ";
    printArray(arr, 5);
    
    return 0;
}
```

---

#### 💻 종합 실습 11-5: 🎮 동물원 다형성 시뮬레이션 (20분)

```cpp
#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;
    string species;
    int hunger;  // 0~100
    
public:
    Animal(string n, string s) : name(n), species(s), hunger(50) {}
    
    virtual void speak() = 0;
    virtual void eat() {
        hunger -= 20;
        if (hunger < 0) hunger = 0;
        cout << "  " << name << "이(가) 밥을 먹었습니다! (배고픔: "
             << hunger << ")" << endl;
    }
    
    void showInfo() {
        cout << species << " " << name << " [배고픔: " << hunger << "]" << endl;
    }
    
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n, "🐕") {}
    void speak() override {
        cout << "  " << name << ": 멍멍!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n, "🐱") {}
    void speak() override {
        cout << "  " << name << ": 야옹~" << endl;
    }
};

class Duck : public Animal {
public:
    Duck(string n) : Animal(n, "🦆") {}
    void speak() override {
        cout << "  " << name << ": 꽥꽥!" << endl;
    }
};

int main() {
    const int SIZE = 4;
    Animal *zoo[SIZE];
    zoo[0] = new Dog("멍이");
    zoo[1] = new Cat("나비");
    zoo[2] = new Duck("꽥돌이");
    zoo[3] = new Dog("바둑이");
    
    int choice;
    do {
        cout << "\n🏠 === 미니 동물원 ===" << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << i + 1 << ". ";
            zoo[i]->showInfo();
        }
        cout << "5. 전체 소리 내기" << endl;
        cout << "6. 전체 먹이 주기" << endl;
        cout << "0. 종료" << endl;
        cout << "선택: ";
        cin >> choice;
        
        if (choice >= 1 && choice <= SIZE) {
            zoo[choice - 1]->speak();
        } else if (choice == 5) {
            cout << "=== 🔊 다 같이 소리! ===" << endl;
            for (int i = 0; i < SIZE; i++) zoo[i]->speak();
        } else if (choice == 6) {
            cout << "=== 🍚 먹이 타임! ===" << endl;
            for (int i = 0; i < SIZE; i++) zoo[i]->eat();
        }
    } while (choice != 0);
    
    for (int i = 0; i < SIZE; i++) delete zoo[i];
    return 0;
}
```

---

## 📝 핵심 정리

| 개념 | 설명 | 예시 |
|------|------|------|
| **다형성** | 같은 호출, 다른 동작 | 부모 포인터로 자식 호출 |
| **virtual** | 동적 바인딩 활성화 | `virtual void speak()` |
| **override** | 오버라이딩 명시 | `void speak() override` |
| **= 0** | 순수 가상 함수 | `virtual void f() = 0;` |
| **추상 클래스** | 순수 가상 함수 포함 | 객체 생성 불가 |
| **operator+** | 연산자 오버로딩 | `Point operator+(...)` |
| **template** | 범용 타입 | `template<typename T>` |

---

## 📝 과제

### 과제 1: 악기 다형성
```
Instrument (추상 클래스)
├── Piano → "도레미파솔~"
├── Guitar → "통통통~"
└── Drum → "둥둥둥!"
```
- `play()` 순수 가상 함수 → 각 악기별 구현

### 과제 2: 템플릿 Stack
`template<typename T>` 클래스로 간단한 스택(push, pop, top, isEmpty) 구현
