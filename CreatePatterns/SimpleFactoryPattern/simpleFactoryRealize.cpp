//
// Created by mars on 2020/2/13.
//
/***************************
 *     简单工厂模式
 *       使用参数进行产品生产，避免了直接 new proudction这种代码,
 *       通过增加工厂，避免对象的产生和实际逻辑之间的代码
 *
 *       工厂不易扩展，增加if else 代码
 *
 * */
#include <iostream>
#include <string>
class abstractProduct{
public:
    virtual void what()=0;

protected:
    std::string brandName;
};
class productCloth:public abstractProduct{
public:
    productCloth(){
        brandName = "cloth";
    }
    void what(){
        std::cout<<"product name is "<<brandName<<std::endl;
    }
};

class productComputer:public abstractProduct{
public:
    productComputer(){
        brandName = "computer";
    }
    void what(){
        std::cout<<"product name is "<<brandName<<std::endl;
    }
};
class simpleFactory{
public:
    static abstractProduct *produce(const std::string &brandName){
        if(brandName == "computer"){
            return new productComputer;
        }else if(brandName == "cloth"){
            return new productCloth;
        }else{
            return nullptr;
        }
    }
};

int main(){
    auto produceTest = [](const std::string &name){
        auto *p = simpleFactory::produce(name);
        if(p== nullptr){
            std::cout<<"produce fail"<<std::endl;
        }
        else{
            p->what();
            delete(p);
        }
    };
    produceTest("pants");
    produceTest("cloth");
    produceTest("computer");

    return 0;
}