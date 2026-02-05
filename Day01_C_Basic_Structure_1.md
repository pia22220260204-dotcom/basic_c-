# Day 01: C 언어 기본 구조 (1)

## 📚 학습 목표
- C 언어의 특징과 첫 프로그램 이해하기
- 변수와 기본 자료형 활용하기
- 콘솔 입출력 다루기
- 간단한 프로그램 직접 만들어보기

## ⏰ 시간 배분 (3시간)
| 시간 | 내용 | 이론 | 실습 |
|------|------|------|------|
| 50분 | **1교시**: C 언어 소개와 첫 프로그램 | 20분 | 30분 |
| 10분 | 휴식 | - | - |
| 50분 | **2교시**: 변수와 기본 자료형 | 20분 | 30분 |
| 10분 | 휴식 | - | - |
| 50분 | **3교시**: 콘솔 입출력과 종합 실습 | 15분 | 35분 |
| 10분 | Q&A 및 정리 | - | - |

> **강사 노트**: 각 교시마다 충분한 실습 시간을 확보합니다. 학습자가 직접 코드를 입력하고 실행하면서 배울 수 있도록 합니다.

---

## 🎯 1교시: C 언어 소개와 첫 프로그램 (50분)

### 📖 이론 (20분)

#### 1.1 C 언어란 무엇인가?

**C 언어의 탄생**
- **1972년**: Dennis Ritchie가 Bell 연구소에서 개발
- **Unix 운영체제 개발**을 위해 만들어짐
- **1989년**: ANSI C (C89/C90) 표준화
- **1999년**: C99 표준 (inline, // 주석 등 추가)
- **2011년**: C11 표준 (멀티스레딩, 안전 함수 등)

**왜 C 언어를 배우나요?**

| 특징 | 설명 | 활용 분야 |
|------|------|-----------|
| 🚀 **고성능** | 하드웨어를 직접 제어 가능 | 운영체제, 임베디드 |
| 💪 **이식성** | 다양한 플랫폼에서 동작 | 크로스 플랫폼 개발 |
| 🔧 **시스템 프로그래밍** | 메모리 직접 제어 | 드라이버, 펌웨어 |
| 📚 **기초** | 모든 프로그래밍의 기본 | C++, Java 등의 기반 |

**C 언어 프로그램 예시**

```c
// C 언어 기본 프로그램
#include <stdio.h>

int main() {
    char name[50] = "홍길동";
    printf("이름: %s\n", name);
    return 0;
}
```

**주요 특징:**
- 간결하고 명확한 문법
- 포인터를 통한 메모리 직접 제어
- 빠른 실행 속도
- 풍부한 표준 라이브러리

#### 1.2 첫 C 프로그램 분석

```c
#include <stdio.h>         // ① 헤더 파일 포함

int main() {               // ② main 함수 (프로그램 시작점)
    printf("Hello, C!");   // ③ 출력문
    return 0;              // ④ 프로그램 종료
}
```

**코드 한 줄씩 이해하기:**

| 줄 | 코드 | 의미 | 비유 |
|----|------|------|------|
| ① | `#include <stdio.h>` | 표준 입출력 라이브러리 포함 | 공구함에서 도구 꺼내기 |
| ② | `int main() {` | 프로그램 시작점 | 요리 시작 |
| ③ | `printf("문자열");` | 화면에 출력 | 화면에 글씨 쓰기 |
| ④ | `return 0;` | 정상 종료 (0 = 성공) | 작업 완료 보고 |

**왜 `main` 함수가 필요한가요?**
- 프로그램의 **입구** 역할
- 운영체제가 프로그램을 실행할 때 **가장 먼저 찾는 함수**
- `main` 함수가 없으면 프로그램 실행 불가

**stdio.h 헤더 파일**
- `stdio` = **St**andar**d** **I**nput/**O**utput (표준 입출력)
- `printf()`, `scanf()`, `getchar()`, `putchar()` 등의 함수 제공
- C 프로그램에서 가장 많이 사용하는 헤더 파일

#### 1.3 컴파일 과정 (간단히)

```
소스 코드 (.c)  →  [전처리]  →  [컴파일]  →  [링킹]  →  실행 파일 (.exe)
   hello.c          hello.i       hello.s      hello.o      hello.exe
```

**각 단계 설명:**

| 단계 | 작업 | 예시 |
|------|------|------|
| **전처리** | #include 처리, 매크로 확장 | stdio.h 내용 삽입 |
| **컴파일** | C 코드 → 어셈블리 | 기계어로 번역 |
| **어셈블** | 어셈블리 → 기계어 | 0과 1로 변환 |
| **링킹** | 라이브러리 연결 | printf 함수 연결 |

**VS Code에서 컴파일 방법:**
1. C 파일 열기 (`.c` 확장자)
2. `Ctrl + Shift + B` 누르기
3. "C Build (Single File)" 선택
4. 생성된 `.exe` 파일 실행

---

### 💻 실습 (30분)

#### 💻 실습 1-1: 첫 프로그램 작성 (10분)

**목표**: Hello World 출력하기

**코드:**
```c
#include <stdio.h>

int main() {
    printf("Hello, World!");
    return 0;
}
```

**실행 방법:**
1. 새 파일 생성: `hello_world.c`
2. 위 코드 입력
3. `Ctrl + Shift + B`로 빌드
4. 터미널에서 실행: `./hello_world.exe`

**예상 출력:**
```
Hello, World!
```

**도전 과제:**
- 자신의 이름을 출력하도록 수정해보세요
- 여러 줄을 출력해보세요

---

#### 💻 실습 1-2: 여러 줄 출력 (10분)

**목표**: `\n`을 사용하여 여러 줄 출력하기

**코드:**
```c
#include <stdio.h>

int main() {
    printf("======================\n");
    printf("   C 언어 첫 수업\n");
    printf("======================\n");
    printf("강사: 홍길동\n");
    printf("일시: 2026년 2월 5일\n");
    printf("======================\n");
    return 0;
}
```

**실행 결과:**
```
======================
   C 언어 첫 수업
======================
강사: 홍길동
일시: 2026년 2월 5일
======================
```

**핵심 개념:**
- `\n`: 줄바꿈 (newline)
- `printf()`는 자동으로 줄을 바꾸지 않음
- 여러 개의 `printf()`를 연속으로 사용 가능

---

#### 💻 실습 1-3: printf 이해하기 (10분)

**목표**: 다양한 방법으로 출력하기

**코드:**
```c
#include <stdio.h>

int main() {
    // 방법 1: 여러 줄을 한 번에
    printf("안녕하세요\n반갑습니다\n");
    
    // 방법 2: 한 줄씩 출력
    printf("첫 번째 줄\n");
    printf("두 번째 줄\n");
    
    // 방법 3: 여러 문자열 연결
    printf("이것은 " "하나의 " "문장입니다\n");
    
    return 0;
}
```

**실행 결과:**
```
안녕하세요
반갑습니다
첫 번째 줄
두 번째 줄
이것은 하나의 문장입니다
```

---

## 🎯 2교시: 변수와 기본 자료형 (50분)

### 📖 이론 (20분)

#### 2.1 변수란?

**변수의 개념**
- 데이터를 저장하는 **메모리 공간의 이름**
- 값을 저장하고 나중에 사용할 수 있음
- 프로그램 실행 중에 값 변경 가능

**변수 선언 방법:**
```c
자료형 변수명;
자료형 변수명 = 초기값;
```

**예시:**
```c
int age;           // 선언만
int score = 95;    // 선언과 동시에 초기화
```

**변수 명명 규칙:**

| ✅ 올바른 예 | ❌ 잘못된 예 | 이유 |
|--------------|--------------|------|
| `age` | `2age` | 숫자로 시작 불가 |
| `student_name` | `student-name` | `-`는 사용 불가 |
| `totalScore` | `total score` | 공백 불가 |
| `_temp` | `int` | 예약어 사용 불가 |

**권장 명명 스타일:**
```c
int student_count;    // snake_case (C 언어 전통)
int studentCount;     // camelCase (허용됨)
const int MAX_SIZE;   // 상수는 대문자
```

#### 2.2 기본 자료형 (Fundamental Types)

**정수형 (Integers)**

| 타입 | 크기 | 범위 | 용도 |
|------|------|------|------|
| `char` | 1 byte | -128 ~ 127 | 문자, 작은 정수 |
| `short` | 2 bytes | -32,768 ~ 32,767 | 작은 정수 |
| `int` | 4 bytes | -2,147,483,648 ~ 2,147,483,647 | 일반 정수 |
| `long` | 4/8 bytes | (플랫폼 의존) | 큰 정수 |
| `long long` | 8 bytes | ±9.2 × 10¹⁸ | 매우 큰 정수 |

**실수형 (Floating-point)**

| 타입 | 크기 | 정밀도 | 용도 |
|------|------|--------|------|
| `float` | 4 bytes | 소수점 6~7자리 | 단정밀도 실수 |
| `double` | 8 bytes | 소수점 15~16자리 | 배정밀도 실수 |
| `long double` | 10+ bytes | 더 높은 정밀도 | 과학 계산 |

**기타 타입**

| 타입 | 크기 | 값 | 용도 |
|------|------|-----|------|
| `_Bool` (C99) | 1 byte | 0 또는 1 | 논리값 (참/거짓) |
| `unsigned` | 타입별 | 양수만 | 음수 불필요시 |

**예시:**
```c
// 정수형
int age = 25;
short temperature = -5;
long population = 5000000L;

// 실수형
float height = 175.5f;      // f 접미사 필요
double pi = 3.141592653589;

// 문자형
char grade = 'A';
char initial = 'K';

// 논리형 (C99 이상)
#include <stdbool.h>
bool is_student = true;     // stdbool.h 필요
```

#### 2.3 변수 초기화 방법

```c
// 방법 1: 선언과 동시에 초기화 (권장)
int count = 0;

// 방법 2: 선언 후 나중에 할당
int sum;
sum = 100;

// 방법 3: 여러 변수 동시 선언
int a, b, c;

// 방법 4: 여러 변수 동시 선언 및 초기화
int x = 1, y = 2, z = 3;
```

**초기화 안 한 변수의 위험성:**
```c
int value;              // 초기화 안 함
printf("%d", value);    // 쓰레기 값 출력! (예측 불가)

int safe_value = 0;     // 안전하게 초기화
printf("%d", safe_value); // 0 출력
```

> **중요**: 변수는 **항상 초기화**해서 사용하세요!

#### 2.4 상수 (Constants)

**const 키워드 사용:**
```c
const double PI = 3.14159;
const int MAX_STUDENTS = 30;

// PI = 3.14;  // 에러! 상수는 변경 불가
```

**#define 매크로 사용:**
```c
#define PI 3.14159
#define MAX_SIZE 100

int main() {
    printf("PI = %f\n", PI);
    return 0;
}
```

**const vs #define 비교:**

| 구분 | const | #define |
|------|-------|---------|
| 타입 | 있음 | 없음 (단순 치환) |
| 범위 | 블록 범위 | 전역 |
| 디버깅 | 쉬움 | 어려움 |
| 메모리 | 메모리 사용 | 메모리 미사용 |
| 권장 | ✅ 권장 | 레거시 코드용 |

---

### 💻 실습 (30분)

#### 💻 실습 2-1: 변수 선언과 출력 (10분)

**목표**: 다양한 자료형의 변수를 선언하고 출력하기

**코드:**
```c
#include <stdio.h>

int main() {
    // 정수형 변수
    int age = 25;
    short temperature = -10;
    long population = 5000000L;
    
    // 실수형 변수
    float height = 175.5f;
    double weight = 68.5;
    
    // 문자형 변수
    char grade = 'A';
    
    // 출력
    printf("나이: %d세\n", age);
    printf("온도: %d도\n", temperature);
    printf("인구: %ld명\n", population);
    printf("키: %.1f cm\n", height);
    printf("몸무게: %.1f kg\n", weight);
    printf("학점: %c\n", grade);
    
    return 0;
}
```

**실행 결과:**
```
나이: 25세
온도: -10도
인구: 5000000명
키: 175.5 cm
몸무게: 68.5 kg
학점: A
```

**printf 형식 지정자:**
- `%d`: 정수 (int, short)
- `%ld`: long 정수
- `%f`: 실수 (float, double)
- `%.1f`: 소수점 1자리까지 실수
- `%c`: 문자 (char)
- `%s`: 문자열

---

#### 💻 실습 2-2: 자료형 크기 확인 (10분)

**목표**: `sizeof` 연산자로 자료형 크기 확인하기

**코드:**
```c
#include <stdio.h>

int main() {
    printf("=== 자료형 크기 (바이트) ===\n");
    printf("char: %zu 바이트\n", sizeof(char));
    printf("short: %zu 바이트\n", sizeof(short));
    printf("int: %zu 바이트\n", sizeof(int));
    printf("long: %zu 바이트\n", sizeof(long));
    printf("long long: %zu 바이트\n", sizeof(long long));
    printf("float: %zu 바이트\n", sizeof(float));
    printf("double: %zu 바이트\n", sizeof(double));
    
    return 0;
}
```

**실행 결과 (일반적인 경우):**
```
=== 자료형 크기 (바이트) ===
char: 1 바이트
short: 2 바이트
int: 4 바이트
long: 4 바이트
long long: 8 바이트
float: 4 바이트
double: 8 바이트
```

**핵심 개념:**
- `sizeof()`: 자료형이나 변수의 크기를 바이트 단위로 반환
- `%zu`: size_t 타입 출력 (sizeof 결과)
- 1 byte = 8 bits

---

#### 💻 실습 2-3: 변수 값 변경하기 (10분)

**목표**: 변수 값을 변경하고 복합 할당 연산자 사용하기

**코드:**
```c
#include <stdio.h>

int main() {
    int score = 80;
    printf("초기 점수: %d\n", score);
    
    // 값 변경
    score = 90;
    printf("변경된 점수: %d\n", score);
    
    // 복합 할당 연산자
    score += 5;  // score = score + 5
    printf("5점 추가: %d\n", score);
    
    score -= 3;  // score = score - 3
    printf("3점 감점: %d\n", score);
    
    score *= 2;  // score = score * 2
    printf("2배 증가: %d\n", score);
    
    score /= 4;  // score = score / 4
    printf("4로 나눔: %d\n", score);
    
    return 0;
}
```

**실행 결과:**
```
초기 점수: 80
변경된 점수: 90
5점 추가: 95
3점 감점: 92
2배 증가: 184
4로 나눔: 46
```

**복합 할당 연산자:**
- `+=`: 더하기 후 할당
- `-=`: 빼기 후 할당
- `*=`: 곱하기 후 할당
- `/=`: 나누기 후 할당
- `%=`: 나머지 후 할당

---

## 🎯 3교시: 콘솔 입출력과 종합 실습 (50분)

### 📖 이론 (15분)

#### 3.1 출력 함수 (printf)

**기본 사용법:**
```c
printf("형식 문자열", 변수1, 변수2, ...);
```

**형식 지정자:**

| 지정자 | 타입 | 예시 |
|--------|------|------|
| `%d` | int | `printf("%d", 100);` |
| `%ld` | long | `printf("%ld", 1000000L);` |
| `%f` | float, double | `printf("%f", 3.14);` |
| `%c` | char | `printf("%c", 'A');` |
| `%s` | 문자열 | `printf("%s", "Hello");` |
| `%%` | % 기호 | `printf("%%");` |

**실수 출력 옵션:**
```c
double pi = 3.141592;

printf("%f\n", pi);      // 3.141592 (기본 6자리)
printf("%.2f\n", pi);    // 3.14 (소수점 2자리)
printf("%.10f\n", pi);   // 3.1415920000 (10자리)
printf("%10.2f\n", pi);  //       3.14 (전체 10자리, 소수 2자리)
```

**줄바꿈:**
```c
printf("첫 번째 줄\n");   // \n으로 줄바꿈
printf("두 번째 줄\n");
```

#### 3.2 입력 함수 (scanf)

**기본 사용법:**
```c
scanf("형식 문자열", &변수1, &변수2, ...);
```

**주의: `&` (주소 연산자) 필요!**
```c
int age;
scanf("%d", &age);  // ✅ 올바름 (& 필요)
// scanf("%d", age);  // ❌ 에러!
```

**다양한 입력 예시:**
```c
int num;
float score;
char ch;

printf("정수 입력: ");
scanf("%d", &num);

printf("실수 입력: ");
scanf("%f", &score);

printf("문자 입력: ");
scanf(" %c", &ch);  // 공백 주의!
```

#### 3.3 입력 버퍼 문제와 해결

**문제 상황:**
```c
int age;
char name[50];

printf("나이: ");
scanf("%d", &age);

printf("이름: ");
gets(name);  // 입력이 안 됨! (버퍼에 \n이 남아있음)
```

**해결 방법 1: getchar() 사용**
```c
scanf("%d", &age);
getchar();  // 버퍼의 \n 제거
gets(name);
```

**해결 방법 2: fgets() 사용 (권장)**
```c
char name[50];
printf("이름: ");
fgets(name, sizeof(name), stdin);
name[strcspn(name, "\n")] = 0;  // \n 제거
```

**해결 방법 3: scanf 포맷 활용**
```c
scanf("%d", &age);
scanf(" %[^\n]", name);  // 공백 포함 한 줄 읽기
```

---

### 💻 실습 (35분)

#### 💻 실습 3-1: 간단한 입력과 출력 (10분)

**목표**: 사용자로부터 이름과 나이를 입력받아 출력하기

**코드:**
```c
#include <stdio.h>

int main() {
    char name[50];
    int age;
    
    printf("===== 정보 입력 =====\n");
    
    printf("이름을 입력하세요: ");
    scanf("%s", name);  // 문자열은 & 불필요
    
    printf("나이를 입력하세요: ");
    scanf("%d", &age);
    
    printf("\n===== 입력된 정보 =====\n");
    printf("이름: %s\n", name);
    printf("나이: %d세\n", age);
    
    return 0;
}
```

**실행 예시:**
```
===== 정보 입력 =====
이름을 입력하세요: 홍길동
나이를 입력하세요: 25

===== 입력된 정보 =====
이름: 홍길동
나이: 25세
```

**주의사항:**
- `scanf("%s", name)`에서는 `&`를 사용하지 않음 (배열 이름이 이미 주소)
- 공백이 포함된 이름은 읽을 수 없음 (공백 전까지만 읽음)

---

#### 💻 실습 3-2: 두 수의 사칙연산 (15분)

**목표**: 두 수를 입력받아 모든 사칙연산 결과 출력하기

**코드:**
```c
#include <stdio.h>

int main() {
    int num1, num2;
    
    printf("===== 계산기 프로그램 =====\n");
    printf("첫 번째 수: ");
    scanf("%d", &num1);
    
    printf("두 번째 수: ");
    scanf("%d", &num2);
    
    printf("\n===== 계산 결과 =====\n");
    printf("%d + %d = %d\n", num1, num2, num1 + num2);
    printf("%d - %d = %d\n", num1, num2, num1 - num2);
    printf("%d × %d = %d\n", num1, num2, num1 * num2);
    
    // 나눗셈 (0으로 나누기 체크)
    if (num2 != 0) {
        printf("%d ÷ %d = %d (정수 나눗셈)\n", num1, num2, num1 / num2);
        printf("%d ÷ %d = %.2f (실수 나눗셈)\n", num1, num2, (double)num1 / num2);
        printf("%d %% %d = %d (나머지)\n", num1, num2, num1 % num2);
    } else {
        printf("0으로 나눌 수 없습니다!\n");
    }
    
    return 0;
}
```

**실행 예시:**
```
===== 계산기 프로그램 =====
첫 번째 수: 10
두 번째 수: 3

===== 계산 결과 =====
10 + 3 = 13
10 - 3 = 7
10 × 3 = 30
10 ÷ 3 = 3 (정수 나눗셈)
10 ÷ 3 = 3.33 (실수 나눗셈)
10 % 3 = 1 (나머지)
```

**핵심 개념:**
- 정수 나눗셈 vs 실수 나눗셈
- 형변환: `(double)num1 / num2`
- 0으로 나누기 체크

---

#### 💻 실습 3-3: 원의 넓이 계산기 (10분)

**목표**: 반지름을 입력받아 원의 넓이와 둘레 계산하기

**코드:**
```c
#include <stdio.h>

#define PI 3.14159

int main() {
    double radius, area, circumference;
    
    printf("===== 원의 넓이 계산기 =====\n");
    printf("반지름을 입력하세요 (cm): ");
    scanf("%lf", &radius);  // double은 %lf
    
    // 계산
    area = PI * radius * radius;
    circumference = 2 * PI * radius;
    
    // 결과 출력
    printf("\n===== 계산 결과 =====\n");
    printf("반지름: %.2f cm\n", radius);
    printf("넓이: %.2f cm²\n", area);
    printf("둘레: %.2f cm\n", circumference);
    
    return 0;
}
```

**실행 예시:**
```
===== 원의 넓이 계산기 =====
반지름을 입력하세요 (cm): 5.5

===== 계산 결과 =====
반지름: 5.50 cm
넓이: 95.03 cm²
둘레: 34.56 cm
```

**주의사항:**
- `double` 입력 시 `%lf` 사용 (출력은 `%f`)
- 상수 `PI`는 `#define`으로 정의

---

#### 💻 종합 실습: 학생 성적 계산기 (15분)

**목표**: 3과목 점수를 입력받아 총점, 평균, 학점 계산하기

**코드:**
```c
#include <stdio.h>

int main() {
    char name[50];
    int korean, english, math;
    int total;
    double average;
    char grade;
    
    printf("===== 학생 성적 계산기 =====\n");
    
    // 입력
    printf("학생 이름: ");
    scanf("%s", name);
    
    printf("국어 점수: ");
    scanf("%d", &korean);
    
    printf("영어 점수: ");
    scanf("%d", &english);
    
    printf("수학 점수: ");
    scanf("%d", &math);
    
    // 계산
    total = korean + english + math;
    average = total / 3.0;
    
    // 학점 판정
    if (average >= 90) {
        grade = 'A';
    } else if (average >= 80) {
        grade = 'B';
    } else if (average >= 70) {
        grade = 'C';
    } else if (average >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }
    
    // 결과 출력
    printf("\n===== 성적표 =====\n");
    printf("이름: %s\n", name);
    printf("국어: %d점\n", korean);
    printf("영어: %d점\n", english);
    printf("수학: %d점\n", math);
    printf("-------------------\n");
    printf("총점: %d점\n", total);
    printf("평균: %.1f점\n", average);
    printf("학점: %c\n", grade);
    
    return 0;
}
```

**실행 예시:**
```
===== 학생 성적 계산기 =====
학생 이름: 홍길동
국어 점수: 85
영어 점수: 92
수학 점수: 88

===== 성적표 =====
이름: 홍길동
국어: 85점
영어: 92점
수학: 88점
-------------------
총점: 265점
평균: 88.3점
학점: B
```

---

## 📝 핵심 개념 정리

### 오늘 배운 내용

| 주제 | 핵심 키워드 | 예시 코드 |
|------|-------------|-----------|
| **기본 구조** | `#include`, `main()`, `return 0` | `int main() { }` |
| **출력** | `printf()`, 형식 지정자 | `printf("%d", 10);` |
| **입력** | `scanf()`, `&` 연산자 | `scanf("%d", &num);` |
| **변수** | 선언, 초기화, 할당 | `int age = 25;` |
| **자료형** | int, double, char | `double pi = 3.14;` |
| **상수** | `const`, `#define` | `const int MAX = 100;` |

### 필수 암기 패턴

```c
// 1. 기본 프로그램 구조
#include <stdio.h>

int main() {
    // 코드 작성
    return 0;
}

// 2. 변수 선언과 초기화
int number = 10;

// 3. 출력
printf("정수: %d, 실수: %.2f\n", num, pi);

// 4. 입력
scanf("%d", &variable);
```

### C 언어 vs C++ 비교

| 구분 | C 언어 | C++ |
|------|--------|-----|
| 헤더 | `#include <stdio.h>` | `#include <iostream>` |
| 출력 | `printf("Hello")` | `cout << "Hello"` |
| 입력 | `scanf("%d", &n)` | `cin >> n` |
| 불린 | `int` 또는 `_Bool` | `bool` |
| 문자열 | `char[]` | `string` |
| 네임스페이스 | 없음 | `using namespace std` |

---

## 🎯 과제

### 과제 1: 자기소개 프로그램 (필수)

**요구사항:**
- 이름, 나이, 학교/회사, 취미를 입력받기
- 입력받은 정보를 정리해서 출력하기
- 출력 형식을 예쁘게 꾸미기

**예시 출력:**
```
=== 자기소개 ===
이름: 홍길동
나이: 25세
소속: 한국대학교
취미: 코딩, 독서
================
```

---

### 과제 2: 온도 변환 프로그램 (권장)

**요구사항:**
- 섭씨 온도를 입력받기
- 화씨 온도로 변환하여 출력하기
- 공식: F = C × 1.8 + 32

**예시 출력:**
```
섭씨 온도: 25
화씨 온도: 77.00도
```

---

### 과제 3: BMI 계산기 (도전)

**요구사항:**
- 키(cm)와 몸무게(kg)를 입력받기
- BMI 계산하기 (BMI = 몸무게 / (키/100)²)
- BMI에 따른 판정 출력하기
  - 18.5 미만: 저체중
  - 18.5~23: 정상
  - 23~25: 과체중
  - 25 이상: 비만

---

## ❓ FAQ

### Q1: `scanf`에서 왜 `&`를 붙이나요?

**A:** `scanf`는 변수의 **주소**가 필요합니다.
```c
int age;
scanf("%d", &age);  // age의 주소를 전달
```
배열은 이름 자체가 주소이므로 `&` 불필요:
```c
char name[50];
scanf("%s", name);  // name은 이미 주소
```

---

### Q2: `printf`의 `%d`와 `%f`의 차이는?

**A:** 자료형에 따라 다른 형식 지정자를 사용합니다.
```c
int num = 10;
double pi = 3.14;

printf("%d", num);  // 정수형
printf("%f", pi);   // 실수형
```

잘못 사용하면 이상한 값이 출력됩니다!

---

### Q3: `\n`과 `endl`의 차이는?

**A:** C 언어에서는 `\n`만 사용합니다.
```c
printf("Hello\n");  // ✅ C 언어
// cout << "Hello" << endl;  // C++에서만 사용
```

---

### Q4: 변수를 초기화 안 하면 어떻게 되나요?

**A:** **쓰레기 값**이 들어있어 예측 불가능한 동작을 합니다.
```c
int uninitialized;        // 쓰레기 값
int initialized = 0;      // 안전

printf("%d", uninitialized);  // ??? (예측 불가)
printf("%d", initialized);    // 0
```

**항상 초기화하세요!**

---

### Q5: `scanf`로 공백 포함 문자열 입력 방법은?

**A:** `fgets()` 또는 특수 형식 사용:
```c
// 방법 1: fgets (권장)
char name[50];
fgets(name, sizeof(name), stdin);

// 방법 2: scanf 특수 형식
scanf(" %[^\n]", name);
```

---

## 📚 다음 시간 예고

**Day 02: C 언어 기본 구조 (2)**
- 다양한 연산자 (산술, 비교, 논리)
- 조건문 (if, switch)
- 반복문 (for, while, do-while)
- 간단한 게임 만들기

---

## 🔗 추가 학습 자료

- [C 언어 표준 라이브러리 레퍼런스](https://en.cppreference.com/w/c)
- [Learn C - 무료 온라인 튜토리얼](https://www.learn-c.org/)
- [The C Programming Language (K&R 책)](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628)

---

## ✅ 체크리스트

오늘 학습한 내용을 체크하세요:

- [ ] C 언어 첫 프로그램 작성 및 실행
- [ ] `printf()`로 출력하기
- [ ] 변수 선언과 초기화
- [ ] 기본 자료형 이해 (int, double, char)
- [ ] `scanf()`로 입력받기
- [ ] 간단한 계산 프로그램 작성
- [ ] 과제 3개 중 1개 이상 완료

**수고하셨습니다! 다음 시간에 만나요! 🎉**
