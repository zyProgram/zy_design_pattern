//
// Created by mars on 2020/2/14.
//
#include <iostream>
#include <string>
class singleton{
private:
    static singleton* single;
    class garbgeCollector {
    public:
        ~garbgeCollector() {
            if (single != nullptr) {
                delete (single);
            }
        }
    };
    static garbgeCollector gc;
    int number;
public:
    static singleton* getInstance() {
        if(single == nullptr){
            single = new singleton;
        }
    }
    singleton(int num = 0) {
        number = num;
    }
    void updateNum(int num){
        if(number!=num) {
            number = num;
        }
    }
    void printNum() {
        std::cout<<"singleton num:"<<number<<std::endl;
    }
};
singleton * singleton::single = nullptr;
int main(){
    auto *p = singleton::getInstance();
    p->printNum();
    p->updateNum(2);
    p->printNum();
}
