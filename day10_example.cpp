#include <iostream>
#include <string>
using namespace std;

class Person{
    protected:
        string name;
        int age;
    public:
        Person(string name, int age):name(name), age(age){}
};

class Student : public Person{
    protected:
        int score;
        char rank;
    public:
        Student(string name, int age, int score,int rank)
        :Person(name,age), score(score), rank(rank){}
};

class ElementSuduent  : public Student{
    private:
        int classnumber;
    public:
        ElementSuduent(string name, int age, int score,int rank, int classnumber)
        :Student(name,age,score,rank), classnumber(classnumber){}
        void setName(string name){
            this->name = name;
        }
        string getName(){
            return name;
        }
};

int main(){
    ElementSuduent el("홍길동",12,95,'A',5);
    return 0;
}
