# Day 12: STL — "C++의 만능 도구 상자!" 🧰

## 📚 학습 목표
- STL(Standard Template Library)의 개념 이해
- `vector`, `map`, `set` 등 핵심 컨테이너 활용
- 반복자(iterator)와 범위 기반 for문 사용
- `algorithm` 헤더의 주요 함수 활용
- 파일 입출력(fstream) 기초

## ⏰ 시간 배분 (3시간)
| 시간 | 내용 | 이론 | 실습 |
|------|------|------|------|
| 50분 | **1교시**: vector & 컨테이너 — 마법 가방 | 20분 | 30분 |
| 10분 | 휴식 | - | - |
| 50분 | **2교시**: map, set & algorithm | 20분 | 30분 |
| 10분 | 휴식 | - | - |
| 50분 | **3교시**: 파일 I/O & 종합 실습 | 15분 | 35분 |
| 10분 | Q&A 및 정리 | - | - |

---

## 🎯 1교시: vector & 컨테이너 — "마법 가방" 🎒 (50분)

### 📖 이론 (20분)

#### 1.1 STL이란?

**STL = C++에 내장된 만능 도구 상자** 🧰

| 구분 | 설명 | 예시 |
|------|------|------|
| **컨테이너** | 데이터를 담는 자료구조 | `vector`, `map`, `set` |
| **반복자** | 컨테이너를 순회하는 도구 | `begin()`, `end()` |
| **알고리즘** | 정렬, 검색 등 편리한 함수 | `sort()`, `find()` |

#### 1.2 vector — "크기가 자동으로 늘어나는 배열!"

```cpp
#include <vector>

// 배열: int arr[5];  ← 크기 고정!
// vector: 크기 자동 조절!

vector<int> v;           // 빈 벡터
vector<int> v2(5);       // 크기 5, 모두 0
vector<int> v3(5, 10);   // 크기 5, 모두 10
vector<int> v4 = {1, 2, 3, 4, 5};  // 초기값 지정
```

**vector 주요 함수:**

```cpp
vector<int> v = {10, 20, 30};

v.push_back(40);    // 뒤에 추가 → {10, 20, 30, 40}
v.pop_back();        // 뒤에서 제거 → {10, 20, 30}
v.size();            // 크기: 3
v.empty();           // 비었나? false
v[0];                // 첫 번째: 10
v.at(1);             // 두 번째: 20 (범위 검사!)
v.front();           // 첫 번째: 10
v.back();            // 마지막: 30
v.clear();           // 전부 삭제
```

#### 1.3 범위 기반 for문 (Range-based for)

```cpp
vector<int> v = {10, 20, 30, 40, 50};

// 일반 for문
for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
}

// 범위 기반 for문 — 더 깔끔!
for (int x : v) {
    cout << x << " ";
}

// 참조로 값 변경
for (int &x : v) {
    x *= 2;  // 모든 값 2배!
}
```

---

### 💻 실습 (30분)

#### 💻 실습 12-1: vector 기본 활용 (10분)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> scores;
    int n, input;
    
    cout << "학생 수: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "번 학생 점수: ";
        cin >> input;
        scores.push_back(input);
    }
    
    // 합계 & 평균
    int sum = 0;
    for (int s : scores) sum += s;
    
    cout << "\n=== 📊 결과 ===" << endl;
    cout << "학생 수: " << scores.size() << "명" << endl;
    cout << "합계: " << sum << endl;
    cout << "평균: " << (double)sum / scores.size() << endl;
    
    // 최대값
    int maxScore = scores[0];
    for (int s : scores) {
        if (s > maxScore) maxScore = s;
    }
    cout << "최고점: " << maxScore << endl;
    
    return 0;
}
```

---

#### 💻 실습 12-2: vector<string> — 할 일 목록 (20분)

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> todos;
    int choice;
    string task;
    
    do {
        cout << "\n📋 === 할 일 목록 ===" << endl;
        if (todos.empty()) {
            cout << "  (비어있음)" << endl;
        } else {
            for (int i = 0; i < (int)todos.size(); i++) {
                cout << "  " << i + 1 << ". " << todos[i] << endl;
            }
        }
        cout << "총 " << todos.size() << "개" << endl;
        
        cout << "\n1.추가 2.완료(삭제) 3.전체삭제 0.종료\n선택: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "할 일: ";
                cin.ignore();
                getline(cin, task);
                todos.push_back(task);
                cout << "✅ 추가됨!" << endl;
                break;
            case 2:
                if (!todos.empty()) {
                    int idx;
                    cout << "완료할 번호: ";
                    cin >> idx;
                    if (idx >= 1 && idx <= (int)todos.size()) {
                        cout << "🎉 '" << todos[idx-1] << "' 완료!" << endl;
                        todos.erase(todos.begin() + idx - 1);
                    }
                }
                break;
            case 3:
                todos.clear();
                cout << "🗑️ 전부 삭제!" << endl;
                break;
        }
    } while (choice != 0);
    
    cout << "👋 종료!" << endl;
    return 0;
}
```

---

## 🎯 2교시: map, set & algorithm (50분)

### 📖 이론 (20분)

#### 2.1 map — "사전처럼 키-값 쌍!"

```cpp
#include <map>

map<string, int> ages;    // 키: string, 값: int

ages["홍길동"] = 25;       // 추가
ages["김철수"] = 30;
ages["이영희"] = 22;

cout << ages["홍길동"];     // 25

// 순회
for (auto &p : ages) {
    cout << p.first << ": " << p.second << endl;
}
// first = 키, second = 값
```

#### 2.2 set — "중복 없는 집합!"

```cpp
#include <set>

set<int> s;
s.insert(3);
s.insert(1);
s.insert(4);
s.insert(1);  // 중복! → 무시됨

// s = {1, 3, 4} ← 자동 정렬 + 중복 제거!

for (int x : s) cout << x << " ";  // 1 3 4
```

#### 2.3 algorithm — 편리한 함수들

```cpp
#include <algorithm>
#include <vector>

vector<int> v = {5, 3, 8, 1, 9, 2};

// 정렬
sort(v.begin(), v.end());     // {1, 2, 3, 5, 8, 9}

// 역순 정렬
sort(v.begin(), v.end(), greater<int>());  // {9, 8, 5, 3, 2, 1}

// 뒤집기
reverse(v.begin(), v.end());

// 최대/최소
auto maxIt = max_element(v.begin(), v.end());
auto minIt = min_element(v.begin(), v.end());
cout << "최대: " << *maxIt << ", 최소: " << *minIt << endl;

// 검색
auto it = find(v.begin(), v.end(), 5);
if (it != v.end()) cout << "있다!" << endl;

// 개수 세기
int cnt = count(v.begin(), v.end(), 3);
```

---

### 💻 실습 (30분)

#### 💻 실습 12-3: map — 전화번호부 (15분)

```cpp
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> phonebook;
    int choice;
    string name, phone;
    
    do {
        cout << "\n📱 === 전화번호부 ===" << endl;
        cout << "1.추가 2.검색 3.목록 4.삭제 0.종료\n선택: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "이름: "; cin >> name;
                cout << "번호: "; cin >> phone;
                phonebook[name] = phone;
                cout << "✅ 저장!" << endl;
                break;
            case 2:
                cout << "이름: "; cin >> name;
                if (phonebook.count(name)) {
                    cout << "📞 " << name << ": " << phonebook[name] << endl;
                } else {
                    cout << "❌ 없는 이름입니다." << endl;
                }
                break;
            case 3:
                cout << "\n--- 전체 목록 ---" << endl;
                for (auto &p : phonebook) {
                    cout << "  " << p.first << " : " << p.second << endl;
                }
                cout << "총 " << phonebook.size() << "명" << endl;
                break;
            case 4:
                cout << "이름: "; cin >> name;
                if (phonebook.erase(name)) {
                    cout << "🗑️ 삭제됨!" << endl;
                } else {
                    cout << "❌ 없는 이름" << endl;
                }
                break;
        }
    } while (choice != 0);
    
    return 0;
}
```

---

#### 💻 실습 12-4: algorithm — 정렬 & 검색 (15분)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {64, 25, 12, 22, 11, 90, 45};
    
    cout << "원래 배열: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    
    // 정렬
    sort(v.begin(), v.end());
    cout << "오름차순: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    
    // 역순
    sort(v.begin(), v.end(), greater<int>());
    cout << "내림차순: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    
    // 최대/최소
    cout << "최대: " << *max_element(v.begin(), v.end()) << endl;
    cout << "최소: " << *min_element(v.begin(), v.end()) << endl;
    
    // 검색
    int target = 25;
    sort(v.begin(), v.end());  // 이진 탐색은 정렬 필요
    if (binary_search(v.begin(), v.end(), target)) {
        cout << target << " 발견! ✅" << endl;
    }
    
    return 0;
}
```

---

## 🎯 3교시: 파일 I/O & 종합 실습 (50분)

### 📖 이론 (15분)

#### 3.1 파일 입출력 (fstream)

```cpp
#include <fstream>

// 파일 쓰기
ofstream fout("data.txt");
fout << "Hello, File!" << endl;
fout << 42 << " " << 3.14 << endl;
fout.close();

// 파일 읽기
ifstream fin("data.txt");
string line;
while (getline(fin, line)) {
    cout << line << endl;
}
fin.close();
```

---

### 💻 실습 (35분)

#### 💻 실습 12-5: 파일로 성적 저장/불러오기 (15분)

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string name;
    int score;
};

void saveToFile(vector<Student> &students, string filename) {
    ofstream fout(filename);
    for (auto &s : students) {
        fout << s.name << " " << s.score << endl;
    }
    fout.close();
    cout << "💾 " << filename << "에 저장 완료!" << endl;
}

void loadFromFile(string filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "❌ 파일을 열 수 없습니다." << endl;
        return;
    }
    
    string name;
    int score;
    cout << "\n📂 파일 내용:" << endl;
    while (fin >> name >> score) {
        cout << "  " << name << ": " << score << "점" << endl;
    }
    fin.close();
}

int main() {
    vector<Student> students = {
        {"홍길동", 95},
        {"김철수", 82},
        {"이영희", 91}
    };
    
    saveToFile(students, "scores.txt");
    loadFromFile("scores.txt");
    
    return 0;
}
```

---

#### 💻 종합 실습 12-6: 🎮 단어장 프로그램 (20분)

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

class WordBook {
private:
    map<string, string> words;  // 영어 → 한국어
    string filename;
    
public:
    WordBook(string fname) : filename(fname) {
        load();
    }
    
    void add(string eng, string kor) {
        words[eng] = kor;
        save();
        cout << "✅ 추가: " << eng << " = " << kor << endl;
    }
    
    void list() {
        cout << "\n📖 === 단어장 (" << words.size() << "개) ===" << endl;
        int i = 1;
        for (auto &w : words) {
            cout << "  " << i++ << ". " << w.first << " = " << w.second << endl;
        }
    }
    
    void quiz() {
        if (words.size() < 3) {
            cout << "❌ 단어가 3개 이상 필요합니다." << endl;
            return;
        }
        
        // 랜덤 단어 선택
        vector<string> keys;
        for (auto &w : words) keys.push_back(w.first);
        
        int correct = 0;
        int total = min((int)keys.size(), 5);
        
        random_shuffle(keys.begin(), keys.end());
        
        cout << "\n🎮 === 단어 퀴즈! ===" << endl;
        for (int i = 0; i < total; i++) {
            string &eng = keys[i];
            string answer;
            cout << "Q" << i + 1 << ". " << eng << " = ? ";
            cin >> answer;
            
            if (answer == words[eng]) {
                cout << "✅ 정답!" << endl;
                correct++;
            } else {
                cout << "❌ 오답! 정답: " << words[eng] << endl;
            }
        }
        cout << "\n점수: " << correct << "/" << total << endl;
    }
    
private:
    void save() {
        ofstream fout(filename);
        for (auto &w : words) {
            fout << w.first << " " << w.second << endl;
        }
        fout.close();
    }
    
    void load() {
        ifstream fin(filename);
        string eng, kor;
        while (fin >> eng >> kor) {
            words[eng] = kor;
        }
        fin.close();
    }
};

int main() {
    srand(time(0));
    WordBook book("wordbook.txt");
    int choice;
    string eng, kor;
    
    do {
        cout << "\n📚 === 나만의 단어장 ===" << endl;
        cout << "1.추가 2.목록 3.퀴즈 0.종료\n선택: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "영어: "; cin >> eng;
                cout << "한국어: "; cin >> kor;
                book.add(eng, kor);
                break;
            case 2: book.list(); break;
            case 3: book.quiz(); break;
        }
    } while (choice != 0);
    
    return 0;
}
```

---

## 📝 핵심 정리

| STL 요소 | 설명 | 헤더 |
|----------|------|------|
| `vector` | 동적 배열 | `<vector>` |
| `map` | 키-값 사전 | `<map>` |
| `set` | 중복 없는 집합 | `<set>` |
| `sort()` | 정렬 | `<algorithm>` |
| `find()` | 검색 | `<algorithm>` |
| `reverse()` | 뒤집기 | `<algorithm>` |
| `ofstream` | 파일 쓰기 | `<fstream>` |
| `ifstream` | 파일 읽기 | `<fstream>` |

---

## 📝 과제

### 과제 1: 학생 성적 관리 (STL 종합)
- `vector<Student>` + `sort()` + 파일 저장/불러오기
- 이름순, 점수순 정렬 기능

### 과제 2: 영한 사전 확장
- 단어 삭제 기능 추가
- 검색 기능 (부분 일치) 추가
