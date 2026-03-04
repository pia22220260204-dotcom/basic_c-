#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// 학생클래스
// 이름, 국 영 수
// 총점 평균 등급

class Student{
    string name;
    map<string, int> scores;
    int total, average;
    char grade;
    void calculateGrade(){
        if(average >= 90) grade = 'A';
        else if(average >= 80) grade = 'B';
        else if(average >= 70) grade = 'C';
        else if(average >= 60) grade = 'D';
        else grade = 'F';
    }

    public:
    Student(string name, int kor=0, int eng=0, int math=0){
        this->name = name;
        this->scores["kor"] = kor;
        this->scores["eng"] = eng;
        this->scores["math"] = math;
        this->total = kor + eng + math;
        this->average = total / 3;
        calculateGrade();
    }
    void printInfo(){
        cout << "Name: " << name << endl;
        cout << "Scores: 국어:" << scores["kor"] << " 영어:" << scores["eng"] << " 수학:" << scores["math"] << endl;
        cout << "Total: " << total << endl;
        cout << "Average: " << average << endl;
        cout << "Grade: " << (char)grade << endl;
    }
    // 기본정렬
    bool operator<(const Student& other) const {
        return this->total > other.total;  // 총점 내림차순 정렬
    }
};


int main(){
    cout<<"학생 정보를 입력하세요(이름 국어 영어 수학)\n";
    string name;
    int kor, eng, math;
    cin >> name >> kor >> eng >> math;
    Student s(name, kor, eng, math);
    s.printInfo();
    return 0;

}
