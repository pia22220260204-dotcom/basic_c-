# Day 00: VSCode C++ 실습환경 구축

## 📋 목차
1. [필수 소프트웨어 설치](#1-필수-소프트웨어-설치)
2. [VSCode 확장 프로그램 설치](#2-vscode-확장-프로그램-설치)
3. [컴파일러 설정](#3-컴파일러-설정)
4. [프로젝트 설정 파일 구성](#4-프로젝트-설정-파일-구성)
5. [첫 번째 프로그램 테스트](#5-첫-번째-프로그램-테스트)
6. [문제 해결](#6-문제-해결)

---

## 1. 필수 소프트웨어 설치

### 1.1 Visual Studio Code 설치
- **다운로드**: https://code.visualstudio.com/
- **버전**: 최신 안정 버전 (2024년 기준 1.85+)
- 설치 시 다음 옵션 체크:
  - ✅ "PATH에 추가" 
  - ✅ "코드로 열기" 컨텍스트 메뉴 추가

### 1.2 MinGW-w64 (GCC 컴파일러) 설치

#### 방법 1: MSYS2를 통한 설치 (권장)

**1. MSYS2 다운로드 및 설치**
- 공식 사이트: https://www.msys2.org/
- 최신 버전: msys2-x86_64-20251213.exe (또는 최신 버전)
- 설치 경로: 기본값 `C:\msys64` 권장
- 설치 완료 후 자동으로 UCRT64 터미널 실행됨

**2. GCC 컴파일러 설치**

MSYS2 UCRT64 터미널에서 다음 명령어 실행:

```bash
# GCC 컴파일러 설치 (C++17/20/23 지원)
pacman -S mingw-w64-ucrt-x86_64-gcc

# 설치 확인 메시지가 나오면 Enter 키 입력
# Proceed with installation? [Y/n] Y
```

**3. 추가 개발 도구 설치 (선택사항)**

```bash
# GDB 디버거 설치
pacman -S mingw-w64-ucrt-x86_64-gdb

# Make 도구 설치
pacman -S mingw-w64-ucrt-x86_64-make
```

**중요:** MSYS2 설치 후 컴파일러는 `C:\msys64\ucrt64\bin\` 폴더에 설치됩니다.

#### 방법 2: WinLibs 직접 다운로드
- **다운로드**: https://winlibs.com/
- **권장 버전**: GCC 13.2.0 + MinGW-w64 11.0.1 (UCRT)
- 압축 해제 후 `C:\mingw64` 폴더에 배치

### 1.3 환경 변수 설정

**Windows 환경 변수에 컴파일러 경로 추가:**

1. **시스템 속성** → **고급** → **환경 변수** 열기
   - 또는 `Win + R` → `sysdm.cpl` 실행 → **고급** 탭
2. **시스템 변수** 영역에서 `Path` 선택 → **편집** 클릭
3. **새로 만들기** 클릭 후 다음 경로 추가:
   - **MSYS2**: `C:\msys64\ucrt64\bin`
   - **WinLibs**: `C:\mingw64\bin` (WinLibs 사용 시)
4. **확인** 클릭하여 저장
5. **모든 터미널 창 닫기** (재시작 필요)

### 1.4 설치 확인

**새 PowerShell 또는 CMD 창을 열고** 다음 명령어 실행:

```powershell
# GCC 컴파일러 버전 확인
g++ --version

# GDB 디버거 버전 확인 (설치한 경우)
gdb --version
```

**예상 출력:**
```
g++ (Rev2, Built by MSYS2 project) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

**GDB 출력:**
```
GNU gdb (GDB) 14.1
Copyright (C) 2023 Free Software Foundation, Inc.
...
```

**오류 발생 시:**
- `'g++'은(는) 내부 또는 외부 명령... 아닙니다` 메시지가 나오면:
  - 환경 변수 Path에 `C:\msys64\ucrt64\bin` 추가 확인
  - 모든 터미널 창을 닫고 새로 열기
  - 컴퓨터 재시작

---

## 2. VSCode 확장 프로그램 설치

### 확장 프로그램이 하는 일

**중요:** 확장 프로그램은 VSCode에 기능을 추가해줄 뿐, **설정 파일(tasks.json, launch.json)을 자동으로 만들어주지 않습니다!**

| 확장 프로그램이 제공하는 것 | 여전히 수동으로 해야 하는 것 |
|--------------------------|--------------------------|
| C++ 문법 하이라이팅 (색상 표시) | tasks.json 생성 (빌드 설정) |
| IntelliSense 자동완성 기능 | launch.json 생성 (디버그 설정) |
| 오류 감지 및 표시 | c_cpp_properties.json 생성 (IntelliSense 설정) |
| F5 디버깅 기능 | 컴파일러 설치 (MinGW/GCC) |
| 코드 포맷팅 | 환경 변수 PATH 설정 |

### 2.1 필수 확장 프로그램

| 확장 프로그램 | ID | 설명 |
|-------------|-----|------|
| **C/C++** | ms-vscode.cpptools | 핵심 기능: IntelliSense, 디버깅, 코드 탐색 |
| **C/C++ Extension Pack** | ms-vscode.cpptools-extension-pack | 위 확장 + 추가 도구들을 한 번에 설치하는 묶음 팩 |
| **CMake Tools** | ms-vscode.cmake-tools | CMake 프로젝트 지원 (고급, 지금은 불필요) |

**C/C++ Extension Pack에 포함된 확장들:**
- C/C++ (핵심)
- C/C++ Themes
- CMake Tools
- CMake Language Support

**권장 설치:** `C/C++ Extension Pack` 하나만 설치하면 위 확장들이 모두 설치됩니다.

**중요:** 확장 프로그램을 설치해도 다음은 여전히 필요합니다!
- ✅ MinGW (GCC 컴파일러) 설치
- ✅ 환경 변수 PATH 설정
- ✅ tasks.json 파일 생성 (Ctrl+Shift+B를 위해)
- ✅ launch.json 파일 생성 (F5 디버깅을 위해)
- ✅ c_cpp_properties.json 파일 생성 (정확한 IntelliSense를 위해)

### 2.2 권장 확장 프로그램

| 확장 프로그램 | ID | 설명 |
|-------------|-----|------|
| **Code Runner** | formulahendry.code-runner | 빠른 코드 실행 |
| **Error Lens** | usernamehue.errorlens | 인라인 에러 표시 |
| **Better Comments** | aaron-bond.better-comments | 주석 하이라이팅 |
| **Bracket Pair Colorizer** | 내장 기능 | 괄호 색상 구분 |

### 2.3 확장 프로그램 설치 방법
```
Ctrl + Shift + X → 확장 프로그램 검색 → Install
```

---

## 3. 컴파일러 설정

### 3.1 C++ 표준 버전 선택 가이드

| 표준 | 플래그 | 주요 기능 | 권장 대상 |
|-----|-------|---------|----------|
| C++17 | `-std=c++17` | filesystem, optional, variant | 안정적 실무 |
| C++20 | `-std=c++20` | concepts, ranges, coroutines | 최신 기능 학습 |
| C++23 | `-std=c++23` | std::print, ranges 확장 | 실험적 |

### 3.2 GCC 버전별 C++ 표준 지원

| GCC 버전 | C++17 | C++20 | C++23 |
|---------|-------|-------|-------|
| 11.x | ✅ 완전 | ✅ 부분 | ❌ |
| 12.x | ✅ 완전 | ✅ 완전 | ✅ 부분 |
| 13.x | ✅ 완전 | ✅ 완전 | ✅ 대부분 |
| 14.x | ✅ 완전 | ✅ 완전 | ✅ 완전 |

---

## 4. 프로젝트 설정 파일 구성

### 설정 파일 필요성 요약

| 파일 | 필요성 | 목적 | 없으면? |
|-----|-------|------|---------|
| **tasks.json** | 필수 | Ctrl+Shift+B 빌드 자동화 | 터미널에서 수동으로 `g++` 명령 입력 필요 |
| **launch.json** | 선택 | F5 디버깅, Ctrl+F5 실행 | 터미널에서 수동으로 `.exe` 실행 필요 |
| **c_cpp_properties.json** | 권장 | IntelliSense 자동완성, 오류 표시 | 빨간 밑줄 오류, 자동완성 부정확 |

**권장사항**: 세 파일 모두 생성하면 편리한 개발 환경 구축

### 4.1 작업 폴더 구조
```
📁 C:\11.C_Lec\
├── 📁 .vscode\
│   ├── tasks.json        # 빌드 설정 (Ctrl+Shift+B)
│   ├── launch.json       # 디버그 설정 (F5, Ctrl+F5)
│   └── c_cpp_properties.json  # IntelliSense 설정
├── 📁 Day01\
├── 📁 Day02\
└── ...
```

### 4.2 tasks.json (빌드 설정)

**⚠️ 중요: MSYS2 환경에서의 설정**

PowerShell에서 g++를 직접 호출하면 문제가 발생할 수 있습니다. MSYS2를 통해 실행하는 것이 안정적입니다.

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "C++ Build (Single File)",
            "type": "shell",
            "command": "C:\\msys64\\msys2_shell.cmd",
            "args": [
                "-ucrt64",
                "-defterm",
                "-here",
                "-no-start",
                "-c",
                "g++ -fdiagnostics-color=always -g -std=c++20 -Wall -Wextra ${fileBasename} -o ${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": ["$gcc"],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "C++20 표준으로 단일 파일 컴파일"
        },
        {
            "label": "C++ Build (All cpp in folder)",
            "type": "shell",
            "command": "C:\\msys64\\msys2_shell.cmd",
            "args": [
                "-ucrt64",
                "-defterm",
                "-here",
                "-no-start",
                "-c",
                "g++ -fdiagnostics-color=always -g -std=c++20 -Wall -Wextra *.cpp -o ${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": ["$gcc"],
            "group": "build",
            "detail": "폴더 내 모든 cpp 파일 컴파일"
        }
    ]
}
```

**설정 설명:**
- `type`: `shell` (PowerShell/cmd에서 실행)
- `command`: `C:\\msys64\\msys2_shell.cmd` (MSYS2 쉘 실행)
- `args`: MSYS2 bash 환경에서 g++ 컴파일
  - `-ucrt64`: UCRT64 환경 사용
  - `-defterm`: 기본 터미널 사용
  - `-here`: 현재 디렉터리에서 실행
  - `-no-start`: 새 창 열지 않음
  - `-c`: bash 명령 실행
- `${fileBasename}`: 현재 파일명 (예: test.cpp)
- `${fileBasenameNoExtension}`: 확장자 제외 파일명 (예: test)

### 4.3 launch.json (디버그 설정)

**목적**: F5(디버깅), Ctrl+F5(실행) 단축키 사용

**이 파일이 없으면:**
- Ctrl+F5나 F5를 누를 때마다 "디버거 선택" 화면이 나옴
- 매번 C++ (GDB/LLDB)를 선택해야 함

**이 파일이 있으면:**
- 자동으로 GDB 디버거 사용
- Ctrl+F5로 빠른 실행
- F5로 디버깅 (브레이크포인트, 변수 감시)

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "C++ Debug",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "gdb",
            "setupCommands": [
                {
                    "description": "gdb pretty printing",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C++ Build (Single File)"
        }
    ]
}
```

**설정 설명:**
- `externalConsole`: `false` (VS Code 내장 터미널 사용)
  - `true`로 설정하면 외부 cmd 창이 열림
  - `false`가 더 편리함 (VS Code 내에서 출력 확인)
- `miDebuggerPath`: `gdb` (PATH에 gdb가 있으면 자동 인식)
- `preLaunchTask`: 실행 전 자동으로 빌드 작업 실행

### 4.4 c_cpp_properties.json (IntelliSense 설정)

**목적**: VSCode의 IntelliSense (자동완성, 오류 표시) 기능 향상

**이 파일이 없으면:**
- `#include <vector>` 등에 빨간 밑줄 표시 (실제로는 정상)
- 자동완성이 부정확하거나 작동 안 함
- C++20 문법을 인식 못함

**이 파일이 있으면:**
- 정확한 자동완성
- 정확한 오류 표시
- C++ 표준에 맞는 IntelliSense

```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:/msys64/ucrt64/include/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "compilerPath": "C:/msys64/ucrt64/bin/g++.exe",
            "cStandard": "c17",
            "cppStandard": "c++20",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
}
```

---

## 5. 첫 번째 프로그램 테스트

### 5.1 테스트 파일 생성
`test_setup.cpp` 파일 생성:

```cpp
// test_setup.cpp - 환경 설정 테스트
#include <iostream>
#include <string>
#include <vector>

int main() {
    // 기본 출력 테스트
    std::cout << "=== C++ 환경 설정 테스트 ===" << std::endl;
    
    // C++20 기본 출력 테스트
    std::string name = "C++ Learner";
    int year = 2024;
    std::cout << "Hello, " << name << "! Welcome to C++ in " << year << "!" << std::endl;
    
    // 벡터 테스트
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Vector elements: ";
    for (const auto& n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    // 컴파일러 정보
    std::cout << "\n=== Compiler Info ===" << std::endl;
    std::cout << "__cplusplus: " << __cplusplus << std::endl;
    
    #ifdef __GNUC__
    std::cout << "GCC version: " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << std::endl;
    #endif
    
    std::cout << "\n환경 설정이 정상적으로 완료되었습니다!" << std::endl;
    
    return 0;
}
```

**참고:** `std::format`은 GCC 13+에서도 완전히 지원되지 않을 수 있습니다. 기본 출력으로 테스트합니다.

### 5.2 빌드 및 실행

#### 방법 1: VSCode 단축키 사용 (tasks.json + launch.json 필요)

**빌드 (컴파일)**
1. **Ctrl + Shift + B** - 빌드만 실행 (.exe 파일 생성)
   - tasks.json에 정의된 g++ 명령 자동 실행
   - 컴파일 오류가 있으면 문제 패널에 표시

**실행**
2. **Ctrl + F5** - 디버깅 없이 실행
   - 자동으로 빌드 후 실행
   - launch.json의 preLaunchTask 설정 필요
   
3. **F5** - 디버깅 모드로 실행
   - 브레이크포인트, 변수 감시 가능
   - launch.json 필요

**디버거 선택 화면이 나올 때:**

launch.json이 없으면 Ctrl+F5나 F5를 누를 때 "디버거 선택" 화면이 나옵니다.

| 디버거 | 설명 | 언제 선택? |
|-------|------|----------|
| **C++ (GDB/LLDB)** | MinGW/GCC 컴파일러용 디버거 | MSYS2/MinGW 설치했으면 이것 선택 ✅ |
| **C++ (Windows)** | Visual Studio 컴파일러(MSVC)용 | Visual Studio 설치했으면 이것 선택 |

**우리 환경에서는 C++ (GDB/LLDB) 선택!**
- 이유: MinGW-w64 (GCC) 컴파일러를 사용하므로
- GDB = GNU Debugger (GCC와 함께 사용하는 디버거)

**디버거 선택 화면 안 나오게 하려면:**
- launch.json 파일을 생성하면 자동으로 GDB 사용

#### 방법 2: 터미널에서 수동 실행 (설정 파일 불필요)

```powershell
# 1. 빌드 (컴파일)
g++ test_setup.cpp -o test_setup.exe -std=c++20

# 2. 실행
.\test_setup.exe

# 또는 한 번에
g++ test_setup.cpp -o test_setup.exe -std=c++20 && .\test_setup.exe
```

**장단점 비교:**
| 방법 | 장점 | 단점 |
|-----|------|------|
| VSCode 단축키 | 편리, 자동화, 디버깅 가능 | 설정 파일 필요 |
| 터미널 수동 | 간단, 설정 불필요 | 매번 명령 입력, 디버깅 어려움 |

### 5.3 예상 출력
```
=== C++ 환경 설정 테스트 ===
Hello, C++ Learner! Welcome to C++ in 2024!
Vector elements: 1 2 3 4 5 

=== Compiler Info ===
__cplusplus: 25.2.0

환경 설정이 정상적으로 완료되었습니다!
```

**버전 정보:**
- `__cplusplus: 202002` → C++20 표준 사용 중
- GCC 버전은 설치한 버전에 따라 다름 (13.x ~ 15.x)설정이 정상적으로 완료되었습니다!
```

---

## 6. 문제 해결

### 6.1 자주 발생하는 오류

#### ❌ 'g++' is not recognized
```
원인: 환경 변수 설정 안됨
해결: Path에 MinGW bin 폴더 추가 후 터미널 재시작
```

#### ❌ fatal error: format: No such file or directory
```
원인: C++20 이전 컴파일러 또는 플래그 미설정
해결: -std=c++20 플래그 확인, GCC 13+ 사용
```

#### ❌ IntelliSense 오류 (빨간 밑줄)
```
원인: c_cpp_properties.json 설정 오류
해결: compilerPath와 cppStandard 확인
```

#### ❌ 디버거 연결 실패
```
원인: GDB 미설치 또는 경로 오류
해결: gdb --version 확인, miDebuggerPath 경로 확인
```

### 6.2 유용한 단축키

| 단축키 | 기능 |
|-------|------|
| `Ctrl + Shift + B` | 빌드 |
| `F5` | 디버그 시작 |
| `Ctrl + F5` | 디버깅 없이 실행 |
| `F9` | 브레이크포인트 설정 |
| `F10` | Step Over |
| `F11` | Step Into |
| `Shift + F11` | Step Out |
| `Ctrl + Space` | IntelliSense 트리거 |

---

## 📌 체크리스트

- [ ] Visual Studio Code 설치 완료
- [ ] MinGW-w64 (GCC 13+) 설치 완료
- [ ] 환경 변수 설정 완료
- [ ] `g++ --version` 확인 완료
- [ ] C/C++ 확장 프로그램 설치 완료
- [ ] .vscode 폴더 설정 파일 생성 완료
- [ ] 테스트 프로그램 빌드/실행 성공
- [ ] 디버거 동작 확인 완료

---

## 다음 단계
✅ 환경 구축 완료 후 **Day 01: C++ 기본 구조**로 진행
