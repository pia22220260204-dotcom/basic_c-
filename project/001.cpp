#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream> // file input/output
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

    // getters for persistence
    string getName() const { return name; }
    int getKor() const { return scores.at("kor"); }
    int getEng() const { return scores.at("eng"); }
    int getMath() const { return scores.at("math"); }

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


// load existing student records from disk
vector<Student> loadStudents(const string& filename) {
    vector<Student> list;
    ifstream fin(filename);
    if (!fin) return list; // file may not exist yet
    string name;
    int kor, eng, math;
    while (fin >> name >> kor >> eng >> math) {
        list.emplace_back(name, kor, eng, math);
    }
    return list;
}

// save all student records to disk
void saveStudents(const vector<Student>& list, const string& filename) {
    ofstream fout(filename);
    for (const auto& s : list) {
        fout << s.getName() << ' ' << s.getKor() << ' ' << s.getEng() << ' ' << s.getMath() << '\n';
    }
}

int main(){
    const string filename = "students.txt";
    vector<Student> students = loadStudents(filename);
    cout << "Loaded " << students.size() << " student(s) from file." << endl;
    for (auto& st : students) {
        st.printInfo();
        cout << "---\n";
    }

    while(true){
        cout<<"1. 입력 2. 종료\n";
        int choice;
        cin >> choice;
        string name;
        int kor, eng, math;
        switch(choice){
            case 1:                
                cout<<"학생 정보를 입력하세요(이름 국어 영어 수학)\n";                
                if (cin >> name >> kor >> eng >> math) {
                    students.emplace_back(name, kor, eng, math);
                }
                break;            
            case 2:
                saveStudents(students, filename);
                cout << "Saved " << students.size() << " student(s) to file. Exiting." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter 1 or 2.\n";
        }
    }

    return 0;

}
