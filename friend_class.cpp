// friend_class.cpp
// 설명: 이 예제는 하나의 클래스가 다른 클래스 전체를 'friend'로 선언했을 때
//       friend 클래스의 멤버들이 private 멤버에 접근할 수 있음을 보여줍니다.
// 컴파일: g++ -std=c++20 friend_class.cpp -o friend_class.exe

#include <iostream>

class Secret {
private:
    int value; // 외부에서 직접 접근 불가

public:
    Secret(int v) : value(v) {}

    // FriendInspector 클래스를 friend로 선언하면,
    // FriendInspector의 모든 멤버가 Secret의 private에 접근 가능
    friend class FriendInspector;
};

class FriendInspector {
public:
    void reveal(const Secret& s) {
        // FriendInspector는 Secret의 private 멤버 `value`에 직접 접근 가능
        std::cout << "Secret value: " << s.value << '\n';
    }
};

int main() {
    Secret s(12345);
    FriendInspector inspector;
    inspector.reveal(s);
    return 0;
}
