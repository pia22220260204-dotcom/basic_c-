#include <iostream>
using namespace std;

bool is_reverse(string tar1, string tar2){
    return tar1 == tar2 ? true : false ;  // 3항연산자
}
string reverse_words(string str){
    string reverse="";
    for(int i = str.length()-1; i > -1; i--){
        reverse += str.at(i);
    }
    return reverse;
}
int main(){
    string addr1 = "seoul";
    string addr2 = "kang-nam";

    string total_addr = addr1 + " " + addr2;

    cout<<"address = "<<total_addr<<endl;
    cout<<"length : "<<total_addr.length()<<endl;
    cout<<"5번째 문자 : "<<total_addr[4]<<endl;

    string reverse = reverse_words(total_addr);
    cout<< is_reverse(reverse,total_addr);

    return 0;
}
