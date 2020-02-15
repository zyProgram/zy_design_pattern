//
// Created by mars on 2020/2/15.
//

#include <iostream>
#include <string>
class abstractLevel{
protected:
    enum {
        LOW = 1 ,
        MID = 2,
        HIGH = 3
    };
    int level;
    abstractLevel *nextLevel;
    virtual bool satifyOperate(int curLevel){
        if(level>curLevel){
            std::cout<<"level"<<level<<" finish"<<std::endl;
            return true;
        }
        return false;
    }
public:
    virtual void setNext(abstractLevel *n){
        nextLevel = n;
    }

    virtual void localOperate(int curLevel){
        if(!satifyOperate(curLevel)){
            std::cout<<"level"<<level<<" can not finish work"<<std::endl;
            return nextLevel->localOperate(curLevel);
        }
    }
};

class lowLevel:public abstractLevel{
public:
    lowLevel(){
        level = LOW;
    }
};

class midLevel:public abstractLevel{
public:
    midLevel(){
        level = MID;
    }
};

class highLevel:public abstractLevel{
protected:
    bool satifyOperate(int curLevel) override {
        std::cout<<"high must finish,althou level"<<curLevel<<" > "<<level<<std::endl;
        return true;
    }
public:
    highLevel(){
        level = HIGH;
    }
};

int main(){
    auto * low = new lowLevel;
    auto * mid = new midLevel;
    auto * high = new highLevel;
    low -> setNext(mid);
    mid->setNext(high);
    low->localOperate(1);
    low->localOperate(5);
    delete(low); delete(mid); delete(high);
}