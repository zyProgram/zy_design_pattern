//
// Created by mars on 2020/2/14.
//
#include <iostream>

class abstractClass{
public:
    virtual void request()=0;
};
class realSub:public abstractClass{
public:
    void request(){
        std::cout<<"real request"<<std::endl;
    }
};
class proxy:public abstractClass{
private:
    realSub r;
public:
    proxy(realSub _r){
        r = _r;
    }
    void proxyOperate(){
        std::cout<<"proxy operate, ";
    }
    void request(){
        proxyOperate();
        r.request();
    }
};
int main(){
    realSub r;
    proxy p(r);
    p.request();
    return 0;
}