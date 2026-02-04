# Day 01: C++ 기본 구조 (1) - 확장판

## 📚 학습 목표
- C++의 역사와 특징을 깊이 있게 이해
- C++ 프로그램의 기본 구조와 동작 원리 완벽 파악
- 변수와 자료형의 개념과 활용법 마스터
- 입출력 스트림을 자유자재로 사용
- 실습을 통한 실전 코딩 능력 향상

## ⏰ 시간 배분 (3시간)
| 시간 | 내용 | 세부 내용 |
|-----|------|-----------|
| 50분 | C++ 소개 및 기본 구조 | 역사, 특징, 첫 프로그램, 컴파일 과정 |
| 10분 | 휴식 | |
| 50분 | 변수와 자료형 | 기본 자료형, 초기화 방법, const/constexpr |
| 10분 | 휴식 | |
| 50분 | 입출력 스트림 실습 | cout, cin, 포맷팅, 유효성 검사 |
| 10분 | Q&A 및 정리 | |

---

## 1. C++ 소개 (50분)

### 1.1 C++ 역사와 발전

#### 📖 C++의 탄생 배경

C++ 프로그래밍 언어는 1979년 벨 연구소(Bell Labs)의 **Bjarne Stroustrup**이 개발했습니다. 그는 C 언어에 객체지향 프로그래밍(OOP) 기능을 추가하고자 했고, 이것이 C++의 시작이었습니다.

**왜 "C++"인가?**
- C 언어에는 `++` 연산자가 있습니다 (증가 연산자)
- `x++`는 "x에 1을 더한다"는 의미
- "C++"는 "C 언어를 한 단계 더 발전시킨다"는 의미

#### 📅 C++ 역사 타임라인

```
1979년 - Bjarne Stroustrup이 "C with Classes" 개발 시작
         ↓ (C 언어 + 클래스 개념)

1983년 - "C++"로 이름 변경
         ↓ (++ 연산자: 증가, 발전을 의미)

1985년 - 첫 번째 상업용 C++ 컴파일러 출시

1998년 - C++98 (첫 번째 ISO 표준)
         ↓ (국제 표준화 기구에서 공식 승인)

2003년 - C++03 (C++98 버그 수정)

2011년 - C++11 (Modern C++ 시작) ⭐⭐⭐
         ↓ (대대적인 개선: auto, 람다, 스마트 포인터 등)

2014년 - C++14 (C++11 개선 및 보완)

2017년 - C++17 (filesystem, optional, variant 등 추가)

2020년 - C++20 (대규모 업데이트) ⭐⭐⭐
         ↓ (concepts, ranges, coroutines 등)

2023년 - C++23 (최신 표준)
         ↓ (std::print, ranges 확장 등)

현재   - C++26 준비 중
```

**💡 중요한 버전들:**
- **C++98**: C++의 첫 번째 표준
- **C++11**: 현대적인 C++ 시작 (가장 중요한 업데이트)
- **C++20**: 두 번째 큰 업데이트
- **우리 수업**: C++20 기준으로 학습

---

### 1.2 C++ vs C 비교

#### 📊 주요 차이점 상세 비교

| 특징 | C | C++ | 설명 |
|-----|---|-----|------|
| **패러다임** | 절차적 | 절차적 + 객체지향 + 제네릭 | C++는 다중 패러다임 언어 |
| **입출력** | `printf/scanf` | `cout/cin` (스트림) | C++는 타입 안전한 스트림 사용 |
| **메모리 관리** | `malloc/free` | `new/delete` + 스마트 포인터 | C++는 자동 메모리 관리 가능 |
| **문자열** | `char[]` | `std::string` | C++는 문자열 클래스 제공 |
| **타입 안전성** | 약함 | 강함 | C++는 컴파일 타임에 더 많은 에러 검출 |
| **표준 라이브러리** | 제한적 | STL (풍부함) | C++는 컨테이너, 알고리즘 등 제공 |
| **함수 오버로딩** | ❌ 지원 안 함 | ✅ 지원 | 같은 이름의 함수를 다르게 정의 가능 |
| **네임스페이스** | ❌ 없음 | ✅ 있음 | 이름 충돌 방지 |
| **예외 처리** | ❌ 없음 | ✅ `try-catch` | 에러 처리가 더 체계적 |
| **클래스/객체** | ❌ 없음 | ✅ 핵심 기능 | 객체지향 프로그래밍 가능 |

#### 📝 실제 코드로 비교

**C 언어 방식:**
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // 문자열 처리가 복잡함
    char name[50];
    printf("이름을 입력하세요: ");
    scanf("%s", name);
    
    // 메모리 동적 할당
    int* numbers = (int*)malloc(5 * sizeof(int));
    if (numbers == NULL) {
        return 1;
    }
    
    // 사용 후 반드시 해제
    free(numbers);
    
    return 0;
}
```

**C++ 방식:**
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 문자열 처리가 간편함
    string name;
    cout << "이름을 입력하세요: ";
    cin >> name;
    
    // 자동으로 메모리 관리됨
    vector<int> numbers(5);
    
    // 자동으로 메모리 해제됨 (소멸자)
    
    return 0;
}
```

---

### 1.3 C++의 특징 (상세 설명)

#### ✅ 1. 객체지향 프로그래밍 (OOP)

**객체지향이란?**
- 프로그램을 "객체"들의 모임으로 생각하는 방식
- 현실 세계를 모델링하기 쉬움

**OOP의 4대 특징:**

```cpp
// 1. 캡슐화 (Encapsulation)
// - 데이터와 함수를 하나로 묶음
// - 외부로부터 데이터 보호
class BankAccount {
private:
    int balance;  // 외부에서 직접 접근 불가
    
public:
    void deposit(int amount) {  // 공개 인터페이스
        balance += amount;
    }
};

// 2. 상속 (Inheritance)
// - 기존 클래스의 기능을 물려받아 재사용
class Animal {
public:
    void eat() { cout << "먹는다" << endl; }
};

class Dog : public Animal {  // Animal을 상속
public:
    void bark() { cout << "멍멍!" << endl; }
};

// 3. 다형성 (Polymorphism)
// - 같은 인터페이스, 다른 구현
class Shape {
public:
    virtual void draw() = 0;  // 순수 가상 함수
};

class Circle : public Shape {
public:
    void draw() override { cout << "원 그리기" << endl; }
};

class Square : public Shape {
public:
    void draw() override { cout << "사각형 그리기" << endl; }
};

// 4. 추상화 (Abstraction)
// - 복잡한 세부사항을 숨기고 필요한 것만 노출
```

#### ✅ 2. 제네릭 프로그래밍

**제네릭이란?**
- 타입에 독립적인 코드를 작성하는 기법
- 템플릿(Template)을 사용

```cpp
// 일반 함수 - int만 처리 가능
int add(int a, int b) {
    return a + b;
}

// 제네릭 함수 - 모든 타입 처리 가능
template <typename T>
T add(T a, T b) {
    return a + b;
}

// 사용 예
int result1 = add(10, 20);           // int
double result2 = add(3.14, 2.86);    // double
string result3 = add("Hello", "World");  // string
```

#### ✅ 3. 저수준 메모리 제어

**메모리를 직접 다룰 수 있음:**
```cpp
// 포인터를 통한 직접 메모리 접근
int x = 10;
int* ptr = &x;  // x의 주소를 ptr에 저장
*ptr = 20;      // 포인터를 통해 x의 값 변경

cout << x << endl;  // 20 출력
```

**하드웨어에 가까운 프로그래밍:**
```cpp
// 메모리 주소 직접 접근 (임베디드 시스템)
unsigned int* gpio_register = (unsigned int*)0x40021000;
*gpio_register = 0xFF;  // GPIO 레지스터 설정
```

#### ✅ 4. 고성능

**Zero-overhead 원칙:**
- "사용하지 않는 기능에 대해서는 비용을 지불하지 않는다"
- C만큼 빠른 성능

```cpp
// 인라인 함수 - 함수 호출 오버헤드 제거
inline int square(int x) {
    return x * x;
}

// 컴파일러가 코드를 직접 삽입
int result = square(5);  // 실제로는 int result = 5 * 5;
```

**컴파일 타임 최적화:**
```cpp
// constexpr - 컴파일 시간에 계산
constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

constexpr int result = factorial(5);  // 컴파일 시 120으로 계산됨
```

#### ✅ 5. 풍부한 표준 라이브러리 (STL)

**STL의 3대 구성 요소:**

```cpp
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    // 1. 컨테이너 (Container) - 데이터 저장
    vector<int> numbers = {5, 2, 8, 1, 9};
    
    // 2. 알고리즘 (Algorithm) - 데이터 처리
    sort(numbers.begin(), numbers.end());
    
    // 3. 반복자 (Iterator) - 데이터 순회
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    
    return 0;
}
```

---

### 1.4 첫 번째 C++ 프로그램 (상세 분석)

#### 📝 Hello World 프로그램

```cpp
// hello.cpp - 첫 번째 C++ 프로그램
#include <iostream>  // ① 헤더 파일 포함

// ② 네임스페이스 사용 선언 (선택사항)
using namespace std;

// ③ main 함수 - 프로그램 진입점
int main() {
    // ④ 출력문
    cout << "Hello, C++!" << endl;
    
    // ⑤ 반환값 (0 = 정상 종료)
    return 0;
}
```

#### 🔍 각 부분 상세 설명

**① `#include <iostream>` - 전처리기 지시문**

```cpp
// #include는 "포함하다"는 의미
// <iostream>은 입출력 스트림(Input/Output Stream) 헤더 파일

// iostream에 포함된 것들:
// - cout: 표준 출력 (console output)
// - cin: 표준 입력 (console input)
// - endl: 줄바꿈 (end line)
// - cerr: 에러 출력
// - clog: 로그 출력
```

**② `using namespace std;` - 네임스페이스**

```cpp
// 네임스페이스(Namespace)란?
// - 이름 충돌을 방지하기 위한 영역
// - 같은 이름의 함수/변수가 다른 네임스페이스에 존재 가능

// using namespace std가 없으면:
std::cout << "Hello" << std::endl;  // std:: 접두어 필요

// using namespace std가 있으면:
cout << "Hello" << endl;  // std:: 생략 가능

// ⚠️ 주의: 큰 프로젝트에서는 using namespace std 사용 지양
// 이유: 이름 충돌 가능성
```

**③ `int main()` - main 함수**

```cpp
// main 함수의 역할:
// - 프로그램의 시작점 (Entry Point)
// - 운영체제가 프로그램을 실행할 때 가장 먼저 호출하는 함수
// - 모든 C++ 프로그램은 반드시 main 함수를 가져야 함

// main 함수의 형태:
int main() {           // 1. 매개변수 없음
    return 0;
}

int main(int argc, char* argv[]) {  // 2. 명령줄 인자 받음
    return 0;
}

// int는 반환 타입:
// - 0: 정상 종료
// - 0 이외: 에러 코드
```

**④ `cout << "Hello, C++!" << endl;` - 출력문**

```cpp
// cout (console output): 표준 출력 스트림
// <<: 삽입 연산자 (insertion operator)
// "Hello, C++!": 문자열 리터럴
// endl (end line): 줄바꿈 + 버퍼 플러시

// 동작 원리:
// "Hello, C++!" → cout 스트림 → 화면 출력

// endl vs \n 비교:
cout << "Hello" << endl;  // 줄바꿈 + 버퍼 플러시 (느림)
cout << "Hello\n";        // 줄바꿈만 (빠름)
```

**⑤ `return 0;` - 반환값**

```cpp
// return 0의 의미:
// - 프로그램이 성공적으로 종료되었음을 운영체제에 알림
// - 0: 성공
// - 1~255: 에러 코드

// 예시:
int main() {
    int age;
    cin >> age;
    
    if (age < 0) {
        cerr << "나이는 음수가 될 수 없습니다!" << endl;
        return 1;  // 에러 코드 1 반환
    }
    
    cout << "나이: " << age << endl;
    return 0;  // 정상 종료
}
```

#### 💻 실습: 다양한 출력 방법

```cpp
#include <iostream>
using namespace std;

int main() {
    // 1. 기본 출력
    cout << "Hello, World!" << endl;
    
    // 2. 여러 값 출력
    cout << "이름: " << "홍길동" << ", 나이: " << 25 << endl;
    
    // 3. 여러 줄 출력
    cout << "첫 번째 줄" << endl;
    cout << "두 번째 줄" << endl;
    cout << "세 번째 줄" << endl;
    
    // 4. 연산 결과 출력
    cout << "10 + 20 = " << (10 + 20) << endl;
    
    // 5. 이스케이프 시퀀스
    cout << "따옴표: \"Hello\"" << endl;
    cout << "역슬래시: \\" << endl;
    cout << "탭:\t여기에\t표시" << endl;
    
    return 0;
}
```

---

### 1.5 프로그램 구조 분석 (깊이 있게)

#### 📐 C++ 프로그램의 기본 구조

```cpp
// ========== 1. 전처리기 지시문 영역 ==========
#include <iostream>     // 표준 입출력
#include <string>       // 문자열
#include <vector>       // 동적 배열
#define PI 3.14159     // 매크로 정의

// ========== 2. 네임스페이스 영역 ==========
using namespace std;    // 네임스페이스 사용

// ========== 3. 전역 변수 영역 (권장하지 않음) ==========
int globalVar = 100;    // 프로그램 어디서나 접근 가능

// ========== 4. 함수 선언 영역 ==========
void printMessage();    // 함수 프로토타입 선언
int add(int a, int b);

// ========== 5. main 함수 ==========
int main() {
    // 지역 변수 (local variable)
    int localVar = 50;  // main 함수 내에서만 접근 가능
    
    // 함수 호출
    printMessage();
    int sum = add(10, 20);
    
    cout << "합계: " << sum << endl;
    
    return 0;
}

// ========== 6. 함수 정의 영역 ==========
void printMessage() {
    cout << "메시지 출력" << endl;
}

int add(int a, int b) {
    return a + b;
}
```

#### 🔍 각 영역 상세 설명

**1. 전처리기 지시문**

```cpp
// #으로 시작하는 모든 지시문
// 컴파일 전에 처리됨

#include <iostream>     // 헤더 파일 포함
#include "myheader.h"   // 사용자 정의 헤더 (""사용)

#define MAX_SIZE 100    // 매크로 정의
#define SQUARE(x) ((x)*(x))

#ifdef DEBUG            // 조건부 컴파일
    cout << "디버그 모드" << endl;
#endif

#ifndef VERSION         // 중복 포함 방지
#define VERSION 1
#endif
```

**2. using 선언**

```cpp
// 방법 1: 전체 네임스페이스 사용 (권장하지 않음 - 큰 프로젝트)
using namespace std;

// 방법 2: 특정 항목만 사용 (권장)
using std::cout;
using std::cin;
using std::endl;

// 방법 3: 네임스페이스 별칭
namespace fs = std::filesystem;  // 긴 이름을 짧게
```

**3. 변수의 범위 (Scope)**

```cpp
#include <iostream>
using namespace std;

// 전역 변수 (Global Variable)
int globalCount = 0;  // 프로그램 전체에서 접근 가능

void incrementGlobal() {
    globalCount++;  // 전역 변수 수정 가능
}

int main() {
    // 지역 변수 (Local Variable)
    int localCount = 0;  // main 함수 내에서만 접근 가능
    
    {
        // 블록 범위 변수
        int blockVar = 10;  // 이 블록 내에서만 접근 가능
        cout << blockVar << endl;
    }
    // cout << blockVar << endl;  // ❌ 에러! 범위 벗어남
    
    cout << "전역: " << globalCount << endl;
    cout << "지역: " << localCount << endl;
    
    return 0;
}
```

---

### 1.6 컴파일 과정 (상세)

#### 🔄 소스코드에서 실행파일까지

```
단계 1: 소스코드 작성
┌──────────────────┐
│ hello.cpp        │
│                  │
│ #include <...>   │
│ int main() {     │
│   cout << "Hi";  │
│   return 0;      │
│ }                │
└──────────────────┘
        ↓
        
단계 2: 전처리 (Preprocessing)
┌──────────────────┐
│ hello.i          │  ← #include 처리, #define 치환
│                  │
│ (iostream 내용)  │
│ int main() {     │
│   std::cout ...  │
│ }                │
└──────────────────┘
        ↓
        
단계 3: 컴파일 (Compilation)
┌──────────────────┐
│ hello.s          │  ← 어셈블리어로 변환
│                  │
│ .text            │
│ main:            │
│   push rbp       │
│   mov rbp, rsp   │
└──────────────────┘
        ↓
        
단계 4: 어셈블 (Assembly)
┌──────────────────┐
│ hello.o          │  ← 기계어(오브젝트 파일)
│                  │
│ 0100101010101    │
│ 1101010010110    │
└──────────────────┘
        ↓
        
단계 5: 링킹 (Linking)
┌──────────────────┐
│ hello.exe        │  ← 실행 파일
│                  │
│ (+ 라이브러리)   │
│ (+ startup 코드) │
└──────────────────┘
```

#### 💻 실제 컴파일 명령어

```bash
# 1. 한 번에 컴파일 (일반적)
g++ hello.cpp -o hello.exe

# 2. 단계별로 확인

# 전처리만 수행
g++ -E hello.cpp -o hello.i

# 컴파일만 수행 (어셈블리 생성)
g++ -S hello.cpp -o hello.s

# 어셈블만 수행 (오브젝트 파일 생성)
g++ -c hello.cpp -o hello.o

# 링킹 (오브젝트 파일 → 실행 파일)
g++ hello.o -o hello.exe

# 3. 최적화 옵션
g++ hello.cpp -o hello.exe -O2  # 최적화 레벨 2
g++ hello.cpp -o hello.exe -O3  # 최적화 레벨 3 (가장 빠름)

# 4. 디버그 정보 포함
g++ hello.cpp -o hello.exe -g  # 디버깅 정보 추가

# 5. 경고 활성화
g++ hello.cpp -o hello.exe -Wall -Wextra  # 모든 경고 표시

# 6. C++ 표준 지정
g++ hello.cpp -o hello.exe -std=c++20  # C++20 표준 사용
```

#### 🔍 컴파일 에러 vs 링킹 에러

**컴파일 에러 (Compile Error):**
```cpp
// 문법 오류
int main() {
    cout << "Hello"  // ❌ 세미콜론 누락
    return 0;
}

// 타입 오류
int main() {
    int x = "Hello";  // ❌ 문자열을 int에 대입 불가
    return 0;
}

// 선언되지 않은 변수
int main() {
    cout << y << endl;  // ❌ y가 선언되지 않음
    return 0;
}
```

**링킹 에러 (Linking Error):**
```cpp
// 함수 선언은 있지만 정의가 없음
void printMessage();  // 선언

int main() {
    printMessage();  // ❌ 링킹 에러: printMessage 정의가 없음
    return 0;
}
// void printMessage() { ... }  ← 정의 누락
```

---

## 2. 변수와 자료형 (50분)

### 2.1 변수의 개념

#### 📦 변수란 무엇인가?

**변수(Variable)**는 데이터를 저장하는 메모리 공간에 붙인 이름입니다.

```
┌─────────────────┐
│ 컴퓨터 메모리   │
├─────────────────┤
│ 주소: 0x1000    │ ← int age = 25;
│ 값: 25          │
│ 이름: age       │
└─────────────────┘
```

**변수 명명 규칙:**

```cpp
// ✅ 올바른 변수명
int age;
int user_age;
int userAge;    // camelCase (권장)
int UserAge;    // PascalCase
int AGE_MAX;    // UPPER_CASE (상수)

// ❌ 잘못된 변수명
int 2age;       // 숫자로 시작 불가
int user-age;   // 하이픈 사용 불가
int int;        // 예약어 사용 불가
int user name;  // 공백 사용 불가
```

**변수 명명 관습:**
```cpp
// 일반 변수: camelCase
int studentAge;
string userName;

// 상수: UPPER_CASE
const int MAX_SIZE = 100;
const double PI = 3.14159;

// 클래스: PascalCase
class StudentInfo;
class BankAccount;

// 함수: camelCase
void calculateSum();
int getUserAge();
```

---

### 2.2 기본 자료형 (상세)

#### 📊 정수형 (Integer Types)

```cpp
#include <iostream>
#include <climits>  // 정수형 한계값
using namespace std;

int main() {
    // bool - 논리형 (1 byte)
    bool isTrue = true;
    bool isFalse = false;
    cout << "bool: " << sizeof(bool) << " bytes" << endl;
    cout << "true = " << isTrue << ", false = " << isFalse << endl;
    
    // char - 문자형 (1 byte)
    char letter = 'A';
    char digit = '9';
    cout << "\nchar: " << sizeof(char) << " byte" << endl;
    cout << "letter = " << letter << ", digit = " << digit << endl;
    cout << "letter의 ASCII 값: " << (int)letter << endl;
    
    // short - 짧은 정수 (2 bytes)
    short smallNum = 32000;
    cout << "\nshort: " << sizeof(short) << " bytes" << endl;
    cout << "범위: " << SHRT_MIN << " ~ " << SHRT_MAX << endl;
    
    // int - 일반 정수 (4 bytes)
    int normalNum = 2147483647;
    cout << "\nint: " << sizeof(int) << " bytes" << endl;
    cout << "범위: " << INT_MIN << " ~ " << INT_MAX << endl;
    
    // long - 긴 정수 (4 or 8 bytes, 시스템 의존)
    long bigNum = 1234567890L;
    cout << "\nlong: " << sizeof(long) << " bytes" << endl;
    cout << "범위: " << LONG_MIN << " ~ " << LONG_MAX << endl;
    
    // long long - 매우 긴 정수 (8 bytes)
    long long veryBigNum = 9223372036854775807LL;
    cout << "\nlong long: " << sizeof(long long) << " bytes" << endl;
    cout << "범위: " << LLONG_MIN << " ~ " << LLONG_MAX << endl;
    
    // unsigned - 부호 없는 정수
    unsigned int positiveOnly = 4294967295U;
    cout << "\nunsigned int: " << sizeof(unsigned int) << " bytes" << endl;
    cout << "범위: 0 ~ " << UINT_MAX << endl;
    
    return 0;
}
```

#### 📊 실수형 (Floating-Point Types)

```cpp
#include <iostream>
#include <cfloat>  // 실수형 한계값
#include <iomanip>  // 출력 포맷
using namespace std;

int main() {
    // float - 단정도 실수 (4 bytes, 7자리 정밀도)
    float pi_f = 3.14159265359f;  // f 접미사
    cout << "float: " << sizeof(float) << " bytes" << endl;
    cout << "정밀도: " << FLT_DIG << " 자리" << endl;
    cout << fixed << setprecision(10);
    cout << "pi (float): " << pi_f << endl;
    
    // double - 배정도 실수 (8 bytes, 15자리 정밀도)
    double pi_d = 3.14159265359;
    cout << "\ndouble: " << sizeof(double) << " bytes" << endl;
    cout << "정밀도: " << DBL_DIG << " 자리" << endl;
    cout << "pi (double): " << pi_d << endl;
    
    // long double - 확장 정밀도 (12~16 bytes)
    long double pi_ld = 3.14159265359L;  // L 접미사
    cout << "\nlong double: " << sizeof(long double) << " bytes" << endl;
    cout << "pi (long double): " << pi_ld << endl;
    
    // 과학적 표기법
    double large = 1.23e10;   // 1.23 × 10^10
    double small = 4.56e-5;   // 4.56 × 10^-5
    cout << "\n과학적 표기법:" << endl;
    cout << "large = " << large << endl;
    cout << "small = " << small << endl;
    
    // 실수 연산 주의사항
    float a = 0.1f;
    float b = 0.2f;
    float c = a + b;
    cout << "\n실수 연산 오차:" << endl;
    cout << setprecision(20);
    cout << "0.1 + 0.2 = " << c << endl;
    // 정확히 0.3이 아닐 수 있음!
    
    return 0;
}
```

#### 📊 자료형 크기 비교표

| 타입 | 크기 | 범위 | 용도 | 예시 |
|------|------|------|------|------|
| `bool` | 1 byte | true/false | 논리값 | `bool isValid = true;` |
| `char` | 1 byte | -128 ~ 127 | 문자, 작은 정수 | `char grade = 'A';` |
| `unsigned char` | 1 byte | 0 ~ 255 | 바이트 데이터 | `unsigned char pixel = 255;` |
| `short` | 2 bytes | -32,768 ~ 32,767 | 작은 정수 | `short year = 2024;` |
| `unsigned short` | 2 bytes | 0 ~ 65,535 | 양의 작은 정수 | `unsigned short port = 8080;` |
| `int` | 4 bytes | -2,147,483,648 ~ 2,147,483,647 | 일반 정수 | `int count = 100;` |
| `unsigned int` | 4 bytes | 0 ~ 4,294,967,295 | 양의 정수 | `unsigned int id = 12345;` |
| `long` | 4/8 bytes | 시스템 의존 | 긴 정수 | `long population = 51000000L;` |
| `long long` | 8 bytes | -9,223,372,036,854,775,808 ~ | 매우 큰 정수 | `long long distance = 1000000000LL;` |
| `float` | 4 bytes | ±3.4×10³⁸ (7자리) | 단정도 실수 | `float pi = 3.14f;` |
| `double` | 8 bytes | ±1.7×10³⁰⁸ (15자리) | 배정도 실수 | `double e = 2.718281828;` |
| `long double` | 12/16 bytes | 확장 정밀도 | 고정밀도 실수 | `long double pi = 3.14159265359L;` |

#### 💻 실습: 자료형 탐색 프로그램

```cpp
#include <iostream>
#include <climits>
#include <cfloat>
#include <iomanip>
using namespace std;

int main() {
    cout << "========== C++ 자료형 탐색기 ==========" << endl;
    
    // 1. 크기 정보
    cout << "\n【자료형 크기】" << endl;
    cout << "bool:        " << sizeof(bool) << " byte(s)" << endl;
    cout << "char:        " << sizeof(char) << " byte(s)" << endl;
    cout << "short:       " << sizeof(short) << " byte(s)" << endl;
    cout << "int:         " << sizeof(int) << " byte(s)" << endl;
    cout << "long:        " << sizeof(long) << " byte(s)" << endl;
    cout << "long long:   " << sizeof(long long) << " byte(s)" << endl;
    cout << "float:       " << sizeof(float) << " byte(s)" << endl;
    cout << "double:      " << sizeof(double) << " byte(s)" << endl;
    cout << "long double: " << sizeof(long double) << " byte(s)" << endl;
    
    // 2. 정수형 범위
    cout << "\n【정수형 범위】" << endl;
    cout << "char:      " << (int)CHAR_MIN << " ~ " << (int)CHAR_MAX << endl;
    cout << "short:     " << SHRT_MIN << " ~ " << SHRT_MAX << endl;
    cout << "int:       " << INT_MIN << " ~ " << INT_MAX << endl;
    cout << "long:      " << LONG_MIN << " ~ " << LONG_MAX << endl;
    cout << "long long: " << LLONG_MIN << " ~ " << LLONG_MAX << endl;
    
    // 3. 실수형 정밀도
    cout << "\n【실수형 정밀도】" << endl;
    cout << "float:       " << FLT_DIG << " 자리 정밀도" << endl;
    cout << "double:      " << DBL_DIG << " 자리 정밀도" << endl;
    cout << "long double: " << LDBL_DIG << " 자리 정밀도" << endl;
    
    // 4. 실제 값 테스트
    cout << "\n【값 표현 테스트】" << endl;
    float pi_f = 3.141592653589793f;
    double pi_d = 3.141592653589793;
    long double pi_ld = 3.141592653589793L;
    
    cout << fixed << setprecision(15);
    cout << "PI (float):       " << pi_f << endl;
    cout << "PI (double):      " << pi_d << endl;
    cout << "PI (long double): " << pi_ld << endl;
    
    return 0;
}
```

---

### 2.3 변수 선언과 초기화 (상세)

#### 📝 변수 선언 vs 초기화

```cpp
// 선언 (Declaration): 변수의 이름과 타입을 알림
int age;  // 메모리 공간 확보, 값은 쓰레기값

// 초기화 (Initialization): 변수를 선언하면서 값 할당
int age = 25;  // 선언 + 초기화
```

#### 🔢 초기화 방법 4가지 (중요!)

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // ========== 방법 1: C 스타일 초기화 ==========
    // 가장 오래된 방법, C 언어와 호환
    int a = 10;
    double b = 3.14;
    char c = 'A';
    
    cout << "C 스타일: a = " << a << endl;
    
    // ========== 방법 2: 생성자 스타일 초기화 ==========
    // C++의 클래스 생성자 문법과 유사
    int x(20);
    double y(2.718);
    string name("홍길동");
    
    cout << "생성자 스타일: x = " << x << endl;
    
    // ========== 방법 3: 유니폼 초기화 (C++11, 권장!) ==========
    // 중괄호 초기화, 가장 안전한 방법
    int p{30};
    double q{1.414};
    string city{"서울"};
    
    cout << "유니폼 초기화: p = " << p << endl;
    
    // 유니폼 초기화의 장점 1: 축소 변환 방지
    int narrow1 = 3.14;    // ⚠️ 경고만 (3으로 변환됨)
    // int narrow2{3.14};  // ❌ 에러! 컴파일 실패
    
    // 유니폼 초기화의 장점 2: 초기화 없이 선언 가능
    int zero{};  // 0으로 초기화됨
    double zeroDouble{};  // 0.0으로 초기화됨
    string emptyStr{};    // 빈 문자열로 초기화됨
    
    cout << "zero = " << zero << endl;
    
    // ========== 방법 4: auto 타입 추론 (C++11) ==========
    // 컴파일러가 자동으로 타입을 추론
    auto num = 100;        // int로 추론
    auto pi = 3.14159;     // double로 추론
    auto letter = 'Z';     // char로 추론
    auto text = "Hello";   // const char*로 추론
    auto msg = string("World");  // string으로 추론
    
    cout << "auto: num = " << num << " (타입: int)" << endl;
    cout << "auto: pi = " << pi << " (타입: double)" << endl;
    
    // auto의 주의사항
    auto val1 = 10;    // int
    auto val2 = 10u;   // unsigned int
    auto val3 = 10l;   // long
    auto val4 = 10ll;  // long long
    auto val5 = 10.0;  // double
    auto val6 = 10.0f; // float
    
    return 0;
}
```

#### 📚 여러 변수 동시 선언

```cpp
// 같은 타입의 여러 변수 선언
int a, b, c;  // 선언만

int x = 10, y = 20, z = 30;  // 선언 + 초기화

// ⚠️ 주의: 포인터 선언 시
int* p1, p2;   // p1만 포인터, p2는 int
int *p1, *p2;  // 둘 다 포인터
```

#### 💡 초기화하지 않으면?

```cpp
#include <iostream>
using namespace std;

int globalVar;  // 전역 변수: 0으로 자동 초기화

int main() {
    int localVar;  // 지역 변수: 쓰레기 값!
    
    cout << "전역 변수: " << globalVar << endl;  // 0
    cout << "지역 변수: " << localVar << endl;   // ⚠️ 예측 불가!
    
    // 안전한 코딩: 항상 초기화하기!
    int safeVar{};  // 0으로 초기화
    cout << "안전한 변수: " << safeVar << endl;  // 0
    
    return 0;
}
```

---

### 2.4 const와 constexpr (상수)

#### 🔒 const - 런타임 상수

```cpp
#include <iostream>
using namespace std;

int main() {
    // const: 값을 변경할 수 없는 변수
    const int MAX_STUDENTS = 30;
    const double PI = 3.14159265359;
    const string SCHOOL_NAME = "한국대학교";
    
    // MAX_STUDENTS = 40;  // ❌ 에러! const는 변경 불가
    
    // 사용자 입력으로 const 초기화 가능
    int userInput;
    cout << "숫자를 입력하세요: ";
    cin >> userInput;
    
    const int USER_VALUE = userInput;  // ✅ 가능 (런타임에 결정)
    cout << "입력한 값: " << USER_VALUE << endl;
    
    return 0;
}
```

#### ⚡ constexpr - 컴파일타임 상수 (C++11)

```cpp
#include <iostream>
using namespace std;

// constexpr 함수: 컴파일 타임에 계산 가능
constexpr int square(int x) {
    return x * x;
}

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    // constexpr: 컴파일 타임에 값이 결정되어야 함
    constexpr int WIDTH = 800;
    constexpr int HEIGHT = 600;
    constexpr int AREA = WIDTH * HEIGHT;  // 컴파일 시 계산됨
    
    cout << "면적: " << AREA << endl;
    
    // constexpr 함수 호출 (컴파일 타임에 계산)
    constexpr int sq = square(10);        // 100
    constexpr int fact = factorial(5);    // 120
    
    cout << "square(10) = " << sq << endl;
    cout << "factorial(5) = " << fact << endl;
    
    // ❌ constexpr은 런타임 값 불가
    int userInput;
    cin >> userInput;
    // constexpr int USER_VAL = userInput;  // 에러!
    const int USER_VAL = userInput;  // ✅ const는 가능
    
    return 0;
}
```

#### 📊 const vs constexpr 비교

| 특징 | const | constexpr |
|------|-------|-----------|
| **결정 시점** | 런타임 또는 컴파일타임 | 컴파일타임만 |
| **초기화** | 런타임 값 가능 | 컴파일타임 상수만 |
| **용도** | 일반 상수 | 컴파일타임 상수, 최적화 |
| **성능** | 일반 | 더 빠름 (컴파일 시 계산) |

```cpp
// const 사용 예
const int days = 365;
const string name = "홍길동";

int age;
cin >> age;
const int BIRTH_YEAR = 2024 - age;  // ✅ 런타임 값 OK

// constexpr 사용 예
constexpr int ARRAY_SIZE = 100;
constexpr double PI = 3.14159;
constexpr int MAX_VAL = 2 * ARRAY_SIZE;  // ✅ 컴파일타임 계산

int arr[ARRAY_SIZE];  // ✅ 배열 크기로 사용 가능
```

---

### 2.5 문자열 타입 (std::string)

#### 📝 C 스타일 문자열 vs C++ string

```cpp
#include <iostream>
#include <cstring>  // C 스타일 문자열 함수
using namespace std;

int main() {
    // ========== C 스타일 문자열 (char 배열) ==========
    char cStr[50] = "Hello, World!";
    
    cout << "C 스타일: " << cStr << endl;
    cout << "길이: " << strlen(cStr) << endl;  // strlen() 함수 필요
    
    // 문자열 복사 (불편함)
    char copy[50];
    strcpy(copy, cStr);
    
    // 문자열 연결 (불편함)
    char str1[50] = "Hello";
    char str2[] = " World";
    strcat(str1, str2);
    
    // ⚠️ 단점: 버퍼 오버플로우 위험
    // char small[5];
    // strcpy(small, "Very Long String");  // 위험!
    
    // ========== C++ string (권장!) ==========
    string cppStr = "Hello, World!";
    
    cout << "\nC++ 스타일: " << cppStr << endl;
    cout << "길이: " << cppStr.length() << endl;  // 멤버 함수
    
    // 문자열 복사 (간편함)
    string copy2 = cppStr;
    
    // 문자열 연결 (간편함)
    string str3 = "Hello";
    string str4 = " World";
    string result = str3 + str4;  // + 연산자 사용
    
    cout << "연결 결과: " << result << endl;
    
    return 0;
}
```

#### 🎯 string 클래스 주요 기능

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "Hello, C++ Programming!";
    
    // 1. 길이 확인
    cout << "길이: " << str.length() << endl;
    cout << "크기: " << str.size() << endl;     // length()와 동일
    cout << "비어있나? " << (str.empty() ? "Yes" : "No") << endl;
    
    // 2. 문자 접근
    cout << "\n첫 글자: " << str[0] << endl;     // 배열처럼 접근
    cout << "마지막 글자: " << str[str.length()-1] << endl;
    cout << "안전한 접근: " << str.at(6) << endl;  // 범위 체크
    
    // 3. 문자열 수정
    str[0] = 'h';  // 첫 글자를 소문자로
    cout << "\n수정 후: " << str << endl;
    
    // 4. 문자열 연결
    string str2 = " Welcome!";
    str += str2;  // append
    cout << "연결: " << str << endl;
    
    // 5. 부분 문자열 추출
    string sub = str.substr(7, 3);  // 7번째부터 3글자
    cout << "\n부분 문자열: " << sub << endl;
    
    // 6. 문자열 찾기
    size_t pos = str.find("C++");
    if (pos != string::npos) {
        cout << "'C++'의 위치: " << pos << endl;
    }
    
    // 7. 문자열 교체
    str.replace(7, 3, "Python");  // "C++"를 "Python"으로
    cout << "교체 후: " << str << endl;
    
    // 8. 문자열 삽입
    str.insert(7, "the amazing ");
    cout << "삽입 후: " << str << endl;
    
    // 9. 문자열 제거
    str.erase(7, 12);  // 7번째부터 12글자 제거
    cout << "제거 후: " << str << endl;
    
    // 10. 대소문자 변환 (직접 구현)
    string original = "Hello World";
    string upper = original;
    for (char& c : upper) {
        c = toupper(c);
    }
    cout << "\n대문자: " << upper << endl;
    
    // 11. 문자열 비교
    string s1 = "Apple";
    string s2 = "Banana";
    if (s1 < s2) {
        cout << "\n" << s1 << "가 " << s2 << "보다 앞입니다" << endl;
    }
    
    // 12. 문자열 지우기
    str.clear();
    cout << "clear 후 비어있나? " << (str.empty() ? "Yes" : "No") << endl;
    
    return 0;
}
```

#### 💻 실습: 문자열 다루기

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "========== 문자열 실습 프로그램 ==========" << endl;
    
    string name, message;
    
    // 1. 이름 입력 (공백 포함)
    cout << "\n이름을 입력하세요 (예: 홍 길동): ";
    getline(cin, name);  // 공백 포함 입력
    
    // 2. 정보 출력
    cout << "\n입력한 이름: " << name << endl;
    cout << "이름 길이: " << name.length() << "글자" << endl;
    
    // 3. 첫 글자와 마지막 글자
    if (!name.empty()) {
        cout << "첫 글자: " << name.front() << endl;
        cout << "마지막 글자: " << name.back() << endl;
    }
    
    // 4. 인사 메시지 만들기
    message = "안녕하세요, " + name + "님! 환영합니다!";
    cout << "\n" << message << endl;
    
    // 5. 문자 개수 세기
    char searchChar;
    cout << "\n찾을 문자를 입력하세요: ";
    cin >> searchChar;
    
    int count = 0;
    for (char c : name) {
        if (c == searchChar) {
            count++;
        }
    }
    cout << "'" << searchChar << "' 문자가 " << count << "개 있습니다." << endl;
    
    // 6. 문자열 역순 출력
    cout << "\n역순: ";
    for (int i = name.length() - 1; i >= 0; i--) {
        cout << name[i];
    }
    cout << endl;
    
    return 0;
}
```

---

## 3. 입출력 스트림 (50분)

### 3.1 cout 출력 스트림 (상세)

#### 💬 cout이란?

**cout (console output)**은 C++의 표준 출력 스트림입니다.
- `std::cout`은 `<iostream>` 헤더에 정의됨
- `<<` 연산자로 데이터를 스트림에 삽입
- 화면(콘솔)에 텍스트를 출력

```
데이터 → << → cout → 화면
  "Hello"      (스트림)   Hello
```

#### 🔢 기본 출력

```cpp
#include <iostream>
using namespace std;

int main() {
    // 1. 문자열 출력
    cout << "Hello, World!" << endl;
    
    // 2. 변수 출력
    int age = 25;
    cout << "나이: " << age << endl;
    
    // 3. 여러 값 연속 출력 (체이닝)
    string name = "홍길동";
    cout << "이름: " << name << ", 나이: " << age << endl;
    
    // 4. 계산 결과 출력
    cout << "10 + 20 = " << (10 + 20) << endl;
    
    // 5. 여러 타입 출력
    int num = 100;
    double pi = 3.14;
    char grade = 'A';
    bool pass = true;
    
    cout << "정수: " << num << endl;
    cout << "실수: " << pi << endl;
    cout << "문자: " << grade << endl;
    cout << "논리: " << pass << endl;  // 1 (true) 또는 0 (false)
    
    // 6. 논리값을 문자로 출력
    cout << boolalpha;  // true/false로 출력
    cout << "논리(문자): " << pass << endl;  // true
    cout << noboolalpha;  // 다시 0/1로 출력
    
    return 0;
}
```

#### 🎨 출력 포맷팅 (iomanip)

```cpp
#include <iostream>
#include <iomanip>  // 출력 조작자
using namespace std;

int main() {
    cout << "========== 출력 포맷팅 ==========" << endl;
    
    // ========== 1. 정수 진법 변환 ==========
    int num = 255;
    
    cout << "\n【정수 진법】" << endl;
    cout << "10진법: " << dec << num << endl;  // 255
    cout << "16진법: 0x" << hex << num << endl;  // 0xff
    cout << "8진법: 0" << oct << num << endl;    // 0377
    cout << dec;  // 10진법으로 복원
    
    // ========== 2. 실수 정밀도 ==========
    double pi = 3.141592653589793;
    
    cout << "\n【실수 정밀도】" << endl;
    cout << "기본: " << pi << endl;
    
    cout << fixed;  // 고정 소수점
    cout << setprecision(2) << "소수점 2자리: " << pi << endl;  // 3.14
    cout << setprecision(5) << "소수점 5자리: " << pi << endl;  // 3.14159
    cout << setprecision(10) << "소수점 10자리: " << pi << endl;
    
    cout << scientific;  // 과학적 표기법
    cout << "과학적 표기: " << pi << endl;  // 3.1415926536e+00
    
    cout << defaultfloat;  // 기본 형식으로 복원
    
    // ========== 3. 너비와 정렬 ==========
    cout << "\n【너비와 정렬】" << endl;
    cout << setw(10) << 123 << endl;           // 오른쪽 정렬 (기본)
    cout << left << setw(10) << 123 << endl;   // 왼쪽 정렬
    cout << right << setw(10) << 123 << endl;  // 오른쪽 정렬
    
    // ========== 4. 채우기 문자 ==========
    cout << "\n【채우기 문자】" << endl;
    cout << setfill('0') << setw(8) << 42 << endl;  // 00000042
    cout << setfill('-') << setw(10) << 123 << endl;  // -------123
    cout << setfill(' ');  // 공백으로 복원
    
    // ========== 5. 테이블 형식 출력 ==========
    cout << "\n【테이블 출력】" << endl;
    cout << left << setfill(' ');
    cout << setw(10) << "이름" << setw(10) << "나이" << setw(10) << "점수" << endl;
    cout << string(30, '-') << endl;
    cout << setw(10) << "홍길동" << setw(10) << 25 << setw(10) << 95.5 << endl;
    cout << setw(10) << "김철수" << setw(10) << 30 << setw(10) << 88.0 << endl;
    cout << setw(10) << "이영희" << setw(10) << 22 << setw(10) << 92.3 << endl;
    
    return 0;
}
```

#### 💻 실습: 성적표 출력 프로그램

```cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    cout << "========== 학생 성적표 ==========" << endl;
    
    string names[] = {"홍길동", "김철수", "이영희", "박민수", "정수진"};
    int korean[] = {90, 85, 95, 78, 88};
    int english[] = {85, 90, 80, 82, 92};
    int math[] = {88, 78, 92, 85, 95};
    
    // 헤더 출력
    cout << "\n" << left;
    cout << setw(10) << "이름"
         << setw(8) << "국어"
         << setw(8) << "영어"
         << setw(8) << "수학"
         << setw(8) << "총점"
         << setw(8) << "평균" << endl;
    cout << string(50, '=') << endl;
    
    // 성적 출력
    cout << fixed << setprecision(1);
    for (int i = 0; i < 5; i++) {
        int total = korean[i] + english[i] + math[i];
        double average = total / 3.0;
        
        cout << setw(10) << names[i]
             << setw(8) << korean[i]
             << setw(8) << english[i]
             << setw(8) << math[i]
             << setw(8) << total
             << setw(8) << average << endl;
    }
    
    cout << string(50, '=') << endl;
    
    return 0;
}
```

---

### 3.2 cin 입력 스트림 (상세)

#### ⌨️ cin이란?

**cin (console input)**은 C++의 표준 입력 스트림입니다.
- `std::cin`은 `<iostream>` 헤더에 정의됨
- `>>` 연산자로 스트림에서 데이터 추출
- 키보드로부터 입력 받음

```
키보드 → cin → >> → 변수
  "123"  (스트림)    int x = 123
```

#### 🔢 기본 입력

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // 1. 정수 입력
    int age;
    cout << "나이를 입력하세요: ";
    cin >> age;
    cout << "입력한 나이: " << age << endl;
    
    // 2. 실수 입력
    double height;
    cout << "\n키를 입력하세요 (cm): ";
    cin >> height;
    cout << "입력한 키: " << height << "cm" << endl;
    
    // 3. 문자 입력
    char grade;
    cout << "\n학점을 입력하세요 (A-F): ";
    cin >> grade;
    cout << "입력한 학점: " << grade << endl;
    
    // 4. 문자열 입력 (공백 전까지)
    string name;
    cout << "\n이름을 입력하세요 (공백 없이): ";
    cin >> name;
    cout << "입력한 이름: " << name << endl;
    
    // 5. 여러 값 동시 입력
    int x, y, z;
    cout << "\n세 정수를 입력하세요 (공백으로 구분): ";
    cin >> x >> y >> z;
    cout << "입력한 값: " << x << ", " << y << ", " << z << endl;
    
    return 0;
}
```

#### 📝 getline() - 공백 포함 입력

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string fullName, address;
    
    // cin >> 은 공백 전까지만 입력받음
    cout << "이름 (cin): ";
    cin >> fullName;  // "홍길동" OK, "홍 길동" → "홍"만 입력됨
    
    // 버퍼에 남은 개행 문자 제거
    cin.ignore();
    
    // getline()은 한 줄 전체를 입력받음
    cout << "\n주소 (getline): ";
    getline(cin, address);  // 공백 포함 가능
    
    cout << "\n입력한 이름: " << fullName << endl;
    cout << "입력한 주소: " << address << endl;
    
    return 0;
}
```

#### ⚠️ 입력 버퍼 문제와 해결

```cpp
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    int age;
    string name;
    
    // 문제 상황
    cout << "나이: ";
    cin >> age;
    
    // cin >>는 개행 문자(\n)를 버퍼에 남김
    // 다음 getline()이 빈 문자열을 읽어버림!
    
    cout << "이름: ";
    getline(cin, name);  // ❌ 빈 문자열 입력됨!
    
    cout << "나이: " << age << endl;
    cout << "이름: " << name << endl;  // 빈 문자열
    
    return 0;
}
```

**해결 방법:**
```cpp
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    int age;
    string name;
    
    cout << "나이: ";
    cin >> age;
    
    // 방법 1: cin.ignore() - 버퍼 비우기
    cin.ignore();  // 개행 문자 1개 무시
    
    // 방법 2: 전체 버퍼 비우기 (더 안전)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "이름: ";
    getline(cin, name);  // ✅ 정상 작동!
    
    cout << "\n나이: " << age << endl;
    cout << "이름: " << name << endl;
    
    return 0;
}
```

---

### 3.3 입력 유효성 검사 (중요!)

#### 🛡️ 잘못된 입력 처리

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int number;
    
    cout << "정수를 입력하세요: ";
    cin >> number;
    
    // cin.fail(): 입력 실패 여부 확인
    if (cin.fail()) {
        cout << "❌ 잘못된 입력입니다!" << endl;
        
        // 에러 플래그 초기화
        cin.clear();
        
        // 버퍼에 남은 잘못된 입력 제거
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        return 1;
    }
    
    cout << "✅ 입력된 값: " << number << endl;
    
    return 0;
}
```

#### 🔄 반복하여 올바른 입력 받기

```cpp
#include <iostream>
#include <limits>
using namespace std;

int getValidInteger(const string& prompt) {
    int value;
    
    while (true) {
        cout << prompt;
        cin >> value;
        
        if (cin.fail()) {
            cout << "❌ 정수를 입력하세요!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    int age = getValidInteger("나이를 입력하세요: ");
    int score = getValidInteger("점수를 입력하세요: ");
    
    cout << "\n나이: " << age << endl;
    cout << "점수: " << score << endl;
    
    return 0;
}
```

#### 📊 범위 검사

```cpp
#include <iostream>
#include <limits>
using namespace std;

int getIntInRange(const string& prompt, int min, int max) {
    int value;
    
    while (true) {
        cout << prompt << " (" << min << "~" << max << "): ";
        cin >> value;
        
        if (cin.fail()) {
            cout << "❌ 정수를 입력하세요!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (value < min || value > max) {
            cout << "❌ 범위를 벗어났습니다!" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    int age = getIntInRange("나이", 1, 150);
    int score = getIntInRange("점수", 0, 100);
    
    cout << "\n나이: " << age << "세" << endl;
    cout << "점수: " << score << "점" << endl;
    
    return 0;
}
```

---

### 3.4 실전 입출력 프로그램들

#### 💻 실습 1: 계산기 프로그램

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double num1, num2;
    char op;
    
    cout << "========== 간단한 계산기 ==========" << endl;
    cout << "첫 번째 숫자: ";
    cin >> num1;
    
    cout << "연산자 (+, -, *, /): ";
    cin >> op;
    
    cout << "두 번째 숫자: ";
    cin >> num2;
    
    cout << fixed << setprecision(2);
    cout << "\n결과: ";
    
    switch (op) {
        case '+':
            cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
            break;
        case '*':
            cout << num1 << " × " << num2 << " = " << (num1 * num2) << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << num1 << " ÷ " << num2 << " = " << (num1 / num2) << endl;
            } else {
                cout << "❌ 0으로 나눌 수 없습니다!" << endl;
            }
            break;
        default:
            cout << "❌ 잘못된 연산자입니다!" << endl;
    }
    
    return 0;
}
```

#### 💻 실습 2: BMI 계산기

```cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string name;
    double height, weight, bmi;
    
    cout << "========== BMI 계산기 ==========" << endl;
    
    cout << "\n이름을 입력하세요: ";
    getline(cin, name);
    
    cout << "키를 입력하세요 (cm): ";
    cin >> height;
    
    cout << "몸무게를 입력하세요 (kg): ";
    cin >> weight;
    
    // BMI 계산: 몸무게(kg) / (키(m) × 키(m))
    double heightInMeters = height / 100.0;
    bmi = weight / (heightInMeters * heightInMeters);
    
    // 결과 출력
    cout << "\n========== 결과 ==========" << endl;
    cout << "이름: " << name << endl;
    cout << fixed << setprecision(1);
    cout << "키: " << height << " cm" << endl;
    cout << "몸무게: " << weight << " kg" << endl;
    cout << "BMI: " << bmi << endl;
    
    // BMI 판정
    cout << "\n판정: ";
    if (bmi < 18.5) {
        cout << "저체중" << endl;
    } else if (bmi < 23) {
        cout << "정상" << endl;
    } else if (bmi < 25) {
        cout << "과체중" << endl;
    } else if (bmi < 30) {
        cout << "비만" << endl;
    } else {
        cout << "고도비만" << endl;
    }
    
    return 0;
}
```

#### 💻 실습 3: 온도 변환기

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

double celsiusToFahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    int choice;
    double temp, result;
    
    cout << "========== 온도 변환기 ==========" << endl;
    cout << "1. 섭씨 → 화씨" << endl;
    cout << "2. 화씨 → 섭씨" << endl;
    cout << "선택 (1 or 2): ";
    cin >> choice;
    
    cout << "온도를 입력하세요: ";
    cin >> temp;
    
    cout << fixed << setprecision(2);
    
    switch (choice) {
        case 1:
            result = celsiusToFahrenheit(temp);
            cout << "\n" << temp << "°C = " << result << "°F" << endl;
            break;
        case 2:
            result = fahrenheitToCelsius(temp);
            cout << "\n" << temp << "°F = " << result << "°C" << endl;
            break;
        default:
            cout << "❌ 잘못된 선택입니다!" << endl;
    }
    
    return 0;
}
```

---

## 💻 종합 실습 과제

### 📝 과제 1: 학생 정보 관리 프로그램 (필수)

```
요구사항:
1. 학생 이름, 학번, 나이, 세 과목 점수 입력받기
2. 총점, 평균, 학점 계산 (평균: 90이상 A, 80이상 B, ...)
3. 입력 유효성 검사 (점수는 0~100)
4. 결과를 표 형식으로 출력

실습 목표:
- 다양한 자료형 사용
- cin/cout 활용
- 조건문 사용
- 포맷팅 적용
```

### 📝 과제 2: 자료형 크기 비교 프로그램 (필수)

```
요구사항:
1. 모든 기본 자료형의 크기(sizeof) 출력
2. 각 자료형의 최소값, 최대값 출력 (climits, cfloat 사용)
3. 표 형식으로 깔끔하게 출력
4. 실수형의 정밀도 차이 실험

실습 목표:
- sizeof 연산자 사용
- climits, cfloat 헤더 활용
- 출력 포맷팅
```

### 📝 과제 3: 대화형 퀴즈 프로그램 (도전)

```
요구사항:
1. 사용자 이름 입력받기
2. 5개의 간단한 산술 문제 출력
3. 사용자 답변 입력받기
4. 정답 개수 계산
5. 최종 점수와 평가 출력

실습 목표:
- 반복문 사용 (아직 안 배웠지만 도전!)
- 입출력 종합 활용
- 조건문 활용
```

### 📝 과제 4: 환율 계산기 (선택)

```
요구사항:
1. 원화를 입력받아 달러, 엔화, 유로로 변환
2. 현재 환율 정보 표시
3. 변환 결과를 표 형식으로 출력
4. 추가: 역변환 기능

실습 목표:
- 실수 연산
- const 상수 사용
- 포맷팅 활용
```

---

## 📝 핵심 정리

### ✅ 오늘 배운 내용 요약

```
1. C++ 소개
   ✓ C++의 역사: 1979년 탄생, C++11/C++20 주요 버전
   ✓ C vs C++: 객체지향, 타입 안전성, STL
   ✓ C++의 특징: OOP, 제네릭, 저수준 제어, 고성능, STL

2. 프로그램 구조
   ✓ #include <헤더>: 라이브러리 포함
   ✓ using namespace std: 네임스페이스 사용
   ✓ int main(): 프로그램 진입점
   ✓ return 0: 정상 종료

3. 변수와 자료형
   ✓ 기본 타입: bool, char, int, long long, float, double
   ✓ 초기화: C스타일, 생성자, 유니폼{}, auto
   ✓ 상수: const (런타임), constexpr (컴파일타임)
   ✓ 문자열: string 클래스 사용 (C++ 방식)

4. 입출력
   ✓ cout <<: 화면 출력
   ✓ cin >>: 키보드 입력
   ✓ getline(): 한 줄 입력
   ✓ 포맷팅: setw, setprecision, fixed 등
   ✓ 유효성 검사: cin.fail(), cin.clear(), cin.ignore()
```

### 🎯 중요 개념 복습

```cpp
// 1. 기본 프로그램 구조
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, C++!" << endl;
    return 0;
}

// 2. 변수 선언과 초기화 (유니폼 권장)
int age{25};
double height{175.5};
string name{"홍길동"};

// 3. 상수 (const vs constexpr)
const int MAX_SIZE = 100;  // 런타임 상수
constexpr int ARRAY_SIZE = 10;  // 컴파일타임 상수

// 4. 입출력
int number;
cout << "숫자 입력: ";
cin >> number;
cout << "입력한 값: " << number << endl;
```

### 💡 꼭 기억할 것!

1. **유니폼 초기화 `{}` 사용하기** - 가장 안전한 초기화 방법
2. **항상 변수 초기화하기** - 쓰레기 값 방지
3. **const는 상수에, auto는 타입 추론에** 활용
4. **cin 후 getline 사용 시 cin.ignore() 잊지 말기**
5. **입력 유효성 검사 습관화** - cin.fail() 체크

---

## 🔗 다음 시간 예고

**Day 02: C++ 기본 구조 (2)**

```
📚 학습 내용:
1. 연산자와 표현식
   - 산술, 비교, 논리, 비트, 복합 연산자

2. 제어문
   - if/else, switch: 조건에 따라 다르게 실행
   - for, while, do-while: 반복 실행
   - break, continue: 반복 제어

3. 함수의 기초
   - 함수 정의와 호출
   - 매개변수 전달: 값, 참조, 포인터
   - 함수 오버로딩
   - 기본 매개변수

💡 준비사항:
- 오늘 배운 입출력, 변수 개념 복습
- 실습 과제 완성해오기
- 궁금한 점 정리해오기
```

---

## 📚 추가 학습 자료

### 🔍 더 공부하고 싶다면

1. **온라인 리소스**
   - cppreference.com: C++ 레퍼런스
   - cplusplus.com: 튜토리얼 및 레퍼런스
   - learncpp.com: 초보자 친화적 튜토리얼

2. **추천 도서**
   - "C++ Primer" - Stanley Lippman
   - "Effective Modern C++" - Scott Meyers
   - "C++ 기초 플러스" - Stephen Prata (한글)

3. **연습 사이트**
   - Baekjoon Online Judge (백준)
   - Programmers (프로그래머스)
   - LeetCode

### 💬 Q&A

**Q1: auto를 항상 사용해도 되나요?**
A: 타입이 명확할 때는 auto가 편리하지만, 코드 가독성을 위해 명시적 타입을 쓰는 것도 좋습니다.

**Q2: const와 constexpr 중 무엇을 써야 하나요?**
A: 컴파일 타임에 값을 알 수 있으면 constexpr, 런타임에 결정되면 const를 사용하세요.

**Q3: using namespace std를 쓰면 안 좋다고 들었는데?**
A: 작은 프로그램에서는 괜찮지만, 큰 프로젝트에서는 `std::`를 명시하는 것이 이름 충돌을 방지합니다.

**Q4: float vs double, 어떤 것을 써야 하나요?**
A: 특별한 이유가 없다면 double을 사용하세요. 정밀도가 더 높고, 현대 컴퓨터에서는 성능 차이가 거의 없습니다.

**Q5: cin으로 입력받을 때 공백이 포함된 문자열은?**
A: `getline(cin, str)`을 사용하세요. cin >>는 공백 전까지만 입력받습니다.

---

**수고하셨습니다! 다음 시간에 만나요! 🚀**
