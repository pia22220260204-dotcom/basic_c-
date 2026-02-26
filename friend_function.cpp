// friend_function.cpp
// 설명: 이 예제는 클래스의 private 멤버에 접근할 수 있도록
//       'friend'로 선언된 일반 함수의 사용법을 보여줍니다.
// 컴파일: g++ -std=c++20 friend_function.cpp -o friend_function.exe

#include <iostream>

class Box {
private:
    int width; // 외부에서 직접 접근 불가

public:
    // 생성자: 너비를 초기화
    Box(int w) : width(w) {}

    // friend 선언: 이 함수를 Box의 private 멤버에 접근하도록 허용
    friend void printWidth(const Box& b);
};

// friend로 선언된 일반 함수는 Box의 private 멤버에 직접 접근 가능
void printWidth(const Box& b) {
    std::cout << "Box width: " << b.width << '\n';
}

int main() {
    Box b(42);
    // printWidth는 Box의 private 멤버를 읽어 출력할 수 있다
    printWidth(b);
    return 0;
}
