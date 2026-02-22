# Day 08: C++ 입문 — "C에서 C++로 업그레이드!" 🚀

## 📚 학습 목표
- C와 C++의 차이점 이해하기
- `cout` / `cin`으로 입출력하기
- `string` 클래스로 편하게 문자열 다루기
- 참조 변수(`&`)와 함수 오버로딩 이해하기

## ⏰ 시간 배분 (3시간)
| 시간 | 내용 | 이론 | 실습 |
|------|------|------|------|
| 50분 | **1교시**: C vs C++ — 뭐가 다를까? | 20분 | 30분 |
| 10분 | 휴식 | - | - |
| 50분 | **2교시**: string & bool — 편리한 도구들 | 15분 | 35분 |
| 10분 | 휴식 | - | - |
| 50분 | **3교시**: 참조 & 함수 오버로딩 & 종합 | 20분 | 30분 |
| 10분 | Q&A 및 정리 | - | - |

> **강사 노트**: C++는 "C의 확장판"입니다. C에서 불편했던 것들이 얼마나 편해지는지 비교하며 설명하세요.

---

## 🎯 1교시: C vs C++ — "뭐가 다를까?" (50분)

### 📖 이론 (20분)

#### 1.1 C++ = C의 업그레이드 버전

```
C 언어      →      C++
──────            ──────
printf          cout
scanf           cin
char[]          string
struct          class
malloc/free     new/delete
```

> **핵심**: C에서 배운 모든 것은 C++에서도 동작합니다!
> C++는 거기에 **편리한 기능**을 추가한 것입니다.

#### 1.2 첫 번째 차이: 입출력

```c
// C 스타일 (printf / scanf)
#include <stdio.h>

int main() {
    int age;
    printf("나이: ");
    scanf("%d", &age);
    printf("당신은 %d살입니다.\n", age);
    return 0;
}
```

```cpp
// C++ 스타일 (cout / cin) — 형식 지정자 필요 없음!
#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "나이: ";
    cin >> age;
    cout << "당신은 " << age << "살입니다." << endl;
    return 0;
}
```

| 비교 | C | C++ |
|------|---|-----|
| 헤더 | `#include <stdio.h>` | `#include <iostream>` |
| 출력 | `printf("값: %d", x);` | `cout << "값: " << x;` |
| 입력 | `scanf("%d", &x);` | `cin >> x;` |
| 형식 지정자 | `%d, %f, %s` 직접 지정 | 자동 인식! ✅ |

#### 1.3 namespace와 using

```cpp
// 방법 1: std:: 매번 붙이기
std::cout << "Hello" << std::endl;

// 방법 2: using으로 생략 (수업에서 주로 사용)
using namespace std;
cout << "Hello" << endl;
```

#### 1.4 C++ 컴파일

```bash
# C 컴파일
gcc hello.c -o hello

# C++ 컴파일
g++ hello.cpp -o hello
```

---

### 💻 실습 (30분)

#### 💻 실습 8-1: Hello World (C++ 버전) (5분)

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "🎉 Hello, C++ World!" << endl;
    cout << "C++의 세계에 오신 것을 환영합니다!" << endl;
    return 0;
}
```

---

#### 💻 실습 8-2: C 코드를 C++로 변환! (10분)

**Before (C)**:
```c
#include <stdio.h>

int main() {
    char name[20];
    int age;
    double height;
    
    printf("이름: ");
    scanf("%s", name);
    printf("나이: ");
    scanf("%d", &age);
    printf("키(cm): ");
    scanf("%lf", &height);
    
    printf("\n=== 프로필 ===\n");
    printf("이름: %s\n", name);
    printf("나이: %d살\n", age);
    printf("키: %.1f cm\n", height);
    
    return 0;
}
```

**After (C++)** — 직접 변환해보세요!:
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;    // char[] 대신 string!
    int age;
    double height;
    
    cout << "이름: ";
    cin >> name;          // 형식 지정자 필요 없음!
    cout << "나이: ";
    cin >> age;           // & 안 붙여도 됨!
    cout << "키(cm): ";
    cin >> height;
    
    cout << "\n=== 프로필 ===" << endl;
    cout << "이름: " << name << endl;
    cout << "나이: " << age << "살" << endl;
    cout << "키: " << height << " cm" << endl;
    
    return 0;
}
```

---

#### 💻 실습 8-3: 자기소개 프로그램 (C++) (15분)

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, hobby;
    int age;
    
    cout << "===== 🪪 자기소개 카드 =====" << endl;
    cout << "이름: ";
    cin >> name;
    cout << "나이: ";
    cin >> age;
    cout << "취미: ";
    cin >> hobby;
    
    cout << "\n┌──────────────────────────┐" << endl;
    cout << "│   🌟 자기소개 카드 🌟     │" << endl;
    cout << "├──────────────────────────┤" << endl;
    cout << "│ 이름: " << name << endl;
    cout << "│ 나이: " << age << "살" << endl;
    cout << "│ 취미: " << hobby << endl;
    cout << "└──────────────────────────┘" << endl;
    
    if (age < 20)
        cout << "💪 열정 가득한 10대!" << endl;
    else if (age < 30)
        cout << "🔥 에너지 넘치는 20대!" << endl;
    else
        cout << "😎 경험 풍부한 어른!" << endl;
    
    return 0;
}
```

---

## 🎯 2교시: string & bool — "편리한 도구들" (50분)

### 📖 이론 (15분)

#### 2.1 string 클래스 — char[] 안녕! 👋

```cpp
#include <string>

// C: char name[20] = "Hello"; (크기 제한, 불편)
// C++:
string name = "Hello";  // 크기 자동, 편리!
```

**string의 편리한 기능들:**

```cpp
string s1 = "Hello";
string s2 = "World";

// 길이
s1.length();     // 5 (또는 s1.size())

// 이어 붙이기 — + 연산자로!
string s3 = s1 + " " + s2;  // "Hello World"

// 비교 — == 연산자로!
if (s1 == "Hello") { ... }   // C에서는 strcmp 썼는데!

// 부분 문자열
s1.substr(0, 3);    // "Hel"

// 문자 접근
s1[0];              // 'H'
s1.at(1);           // 'e'

// 검색
s3.find("World");   // 6 (위치 반환)
```

#### 2.2 bool 타입

```cpp
bool is_adult = true;   // C에서는 int로 0/1 사용했는데!
bool is_male = false;

if (is_adult) {
    cout << "성인입니다" << endl;
}
```

#### 2.3 auto 키워드 — "타입 자동 추론"

```cpp
auto x = 10;         // int
auto y = 3.14;       // double
auto name = "Hello"; // const char*
auto s = string("Hi"); // string
```

---

### 💻 실습 (35분)

#### 💻 실습 8-4: string 활용 — 이름 뒤집기 (10분)

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    cout << "단어 입력: ";
    cin >> word;
    
    // 방법 1: 역순 반복
    string reversed = "";
    for (int i = word.length() - 1; i >= 0; i--) {
        reversed += word[i];
    }
    
    cout << "원래: " << word << endl;
    cout << "뒤집기: " << reversed << endl;
    
    // 회문(팰린드롬) 검사
    if (word == reversed) {
        cout << "✅ 회문입니다! (앞뒤가 같아요)" << endl;
    } else {
        cout << "❌ 회문이 아닙니다" << endl;
    }
    
    return 0;
}
```

---

#### 💻 실습 8-5: 문자열 분석기 (15분)

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    cout << "문장을 입력하세요: ";
    getline(cin, text);  // 공백 포함 입력!
    
    int letters = 0, digits = 0, spaces = 0, others = 0;
    int upper = 0, lower = 0;
    
    for (char c : text) {   // 범위 기반 for문! (C++ 전용)
        if (c >= 'A' && c <= 'Z') { upper++; letters++; }
        else if (c >= 'a' && c <= 'z') { lower++; letters++; }
        else if (c >= '0' && c <= '9') digits++;
        else if (c == ' ') spaces++;
        else others++;
    }
    
    cout << "\n=== 📊 문자열 분석 결과 ===" << endl;
    cout << "전체 길이: " << text.length() << endl;
    cout << "알파벳: " << letters << " (대문자 " << upper
         << ", 소문자 " << lower << ")" << endl;
    cout << "숫자: " << digits << endl;
    cout << "공백: " << spaces << endl;
    cout << "기타: " << others << endl;
    
    return 0;
}
```

---

#### 💻 실습 8-6: bool 활용 — 로그인 시스템 (10분)

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string correct_id = "admin";
    string correct_pw = "1234";
    
    string id, pw;
    bool logged_in = false;
    
    for (int attempt = 1; attempt <= 3; attempt++) {
        cout << "\n=== 🔐 로그인 (시도 " << attempt << "/3) ===" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "PW: ";
        cin >> pw;
        
        if (id == correct_id && pw == correct_pw) {
            logged_in = true;
            break;
        }
        cout << "❌ 로그인 실패!" << endl;
    }
    
    if (logged_in) {
        cout << "\n✅ 환영합니다, " << id << "님!" << endl;
    } else {
        cout << "\n🚫 로그인 3회 실패. 계정이 잠겼습니다." << endl;
    }
    
    return 0;
}
```

---

## 🎯 3교시: 참조 & 함수 오버로딩 & 종합 (50분)

### 📖 이론 (20분)

#### 3.1 참조 변수 (&) — "별명 지어주기"

```cpp
int num = 10;
int &ref = num;  // ref는 num의 별명!

ref = 20;
cout << num;  // 20! (같은 변수를 가리킴)
```

**포인터 vs 참조:**

| 항목 | 포인터 (*) | 참조 (&) |
|------|-----------|---------|
| 선언 | `int *ptr = &num;` | `int &ref = num;` |
| 사용 | `*ptr = 20;` | `ref = 20;` |
| NULL | 가능 | 불가능 |
| 재지정 | 가능 | 불가능 |
| 편리함 | ★★☆ | ★★★ |

#### 3.2 참조로 swap — 포인터보다 깔끔!

```cpp
// C 방식 (포인터)
void swap_c(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
swap_c(&x, &y);  // 호출할 때 & 필요

// C++ 방식 (참조) — 더 깔끔!
void swap_cpp(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
swap_cpp(x, y);  // 호출이 단순!
```

#### 3.3 함수 오버로딩 — "같은 이름, 다른 능력!"

```cpp
// C에서는 불가능했던 것!
// C++에서는 매개변수가 다르면 같은 이름 OK!

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

string add(string a, string b) {
    return a + b;
}

// 호출
add(3, 5);          // int 버전 → 8
add(1.5, 2.3);      // double 버전 → 3.8
add("Hi", " C++");  // string 버전 → "Hi C++"
```

#### 3.4 디폴트 매개변수

```cpp
void greet(string name, string msg = "안녕하세요!") {
    cout << name << "님, " << msg << endl;
}

greet("홍길동");                // "홍길동님, 안녕하세요!"
greet("김철수", "반갑습니다!");   // "김철수님, 반갑습니다!"
```

---

### 💻 실습 (30분)

#### 💻 실습 8-7: 참조로 swap (5분)

```cpp
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "교환 전: x=" << x << ", y=" << y << endl;
    swap(x, y);  // 깔끔한 호출!
    cout << "교환 후: x=" << x << ", y=" << y << endl;
    return 0;
}
```

---

#### 💻 실습 8-8: 오버로딩 덧셈 함수 (10분)

```cpp
#include <iostream>
#include <string>
using namespace std;

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << "정수 덧셈: " << add(3, 5) << endl;
    cout << "실수 덧셈: " << add(1.5, 2.7) << endl;
    cout << "세 수 덧셈: " << add(1, 2, 3) << endl;
    return 0;
}
```

---

#### 💻 종합 실습 8-9: 🎮 C++ 숫자 맞추기 게임 (15분)

```cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string get_hint(int guess, int answer) {
    if (guess > answer) return "⬇️ DOWN! 더 작은 수입니다.";
    if (guess < answer) return "⬆️ UP! 더 큰 수입니다.";
    return "🎉 정답!";
}

int main() {
    srand(time(0));
    int answer = rand() % 100 + 1;
    int guess, attempts = 0;
    bool won = false;
    
    cout << "🎮 === 숫자 맞추기 게임 (C++ 버전) ===" << endl;
    cout << "1~100 사이의 숫자를 맞춰보세요!" << endl;
    
    while (!won) {    // bool 활용!
        cout << "\n추측: ";
        cin >> guess;
        attempts++;
        
        string hint = get_hint(guess, answer);
        cout << hint << endl;
        
        if (guess == answer) {
            won = true;
        }
    }
    
    cout << "\n" << attempts << "번 만에 맞췄습니다! ";
    if (attempts <= 5) cout << "🏆 천재!" << endl;
    else if (attempts <= 10) cout << "👍 훌륭해요!" << endl;
    else cout << "💪 다음엔 더 잘할 수 있어요!" << endl;
    
    return 0;
}
```

---

## 📝 핵심 정리 — C vs C++ 비교

| 기능 | C | C++ |
|------|---|-----|
| 출력 | `printf("값: %d", x)` | `cout << "값: " << x` |
| 입력 | `scanf("%d", &x)` | `cin >> x` |
| 문자열 | `char s[20]` | `string s` |
| 참/거짓 | `int (0/1)` | `bool (true/false)` |
| 참조 | 포인터 `*ptr` | 참조 `&ref` |
| 같은 이름 함수 | ❌ 불가 | ✅ 오버로딩 |
| 기본 매개변수 | ❌ 불가 | ✅ 디폴트 매개변수 |

---

## 📝 과제

### 과제 1: Day04 C 코드 → C++ 변환
Day04에서 만든 구구단 프로그램과 가위바위보를 C++ 스타일로 변환하세요.
- `printf/scanf` → `cout/cin`
- `char[]` → `string`
- 함수 오버로딩이나 참조를 활용해보세요

### 과제 2: 문자열 퀴즈 게임 (C++)
Day06의 단어 퀴즈 게임을 C++ `string`으로 재작성하세요.
