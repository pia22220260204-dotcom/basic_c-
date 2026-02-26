#include <iostream>
#include <string>
using namespace std;

class Person{
    public:
        int price = 10000;
        string name;
        Person(string name) : name(name){}
        virtual int calc_price() = 0;       
};
class Child : public Person{
    public:  
        Child(string name):Person(name){}
        int calc_price(){return price*0.2;}
};
class TeenAger:public Person{
    public:        
        TeenAger(string name):Person(name){}
        int calc_price(){ return price*0.5;}
};
class Adult:public Person{
    public:        
        Adult(string name):Person(name){}
        int calc_price(){ return price;}
};

int main(){
    Person *person[] = {
        new Child("a"), new Child("b"), new TeenAger("c"), new Adult("d")
    };
    int totalprice = 0;
    for(int i=0; i< 4; i++){
        totalprice += person[i]->calc_price();
    }
    cout<<"총 가격 : " << totalprice <<endl;
    
    return 0;
}
