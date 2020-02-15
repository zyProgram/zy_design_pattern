//
// Created by mars on 2020/2/14.
//

#include <iostream>
#include <string>
class abstractSubject{
public:
    virtual void operate() = 0;
};

class lol:public abstractSubject{
public:
    void operate(){
        std::cout<<"lol win"<<std::endl;
    }
};

class decorator:public abstractSubject{
protected:
    abstractSubject *sub;
public:
    decorator(abstractSubject *s){
        sub = s;
    }
};

class realDecorator:public decorator{
private:
    void addOperate(){
        std::cout<<"add something"<<std::endl;
    }
public:
    realDecorator(abstractSubject *s):decorator(s){}
    void operate(){
        addOperate();
        sub->operate();
    }
};

int main(){
    auto *p = new lol;
    realDecorator realDecorator(p);
    p->operate();
    realDecorator.operate();
    return 0;
}