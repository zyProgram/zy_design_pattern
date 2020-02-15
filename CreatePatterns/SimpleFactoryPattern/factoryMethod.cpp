//
// Created by mars on 2020/2/13.
//
/*****************************
 *      工厂方法模式
 *         具有抽象工厂和抽象产品
 *         用户只需通过工厂产生对应产品
 *         如果实现简单 可用宏 实现
 *         易于扩展
 *
 */
#include <iostream>
#include <string>

#define PRODUCT_TEMPLATE(NAME) \
    class NAME##Product:public abstractProduct{\
    public:\
        void what(){\
            std::cout<<#NAME<<std::endl;\
        }\
    }

#define FACTORY_TEMPLATE(NAME)\
    class NAME##Factory:public abstractFactory{\
        public:\
            abstractProduct * produce() {\
                return new NAME##Product;\
            }\
    }\

class abstractProduct{
public:
    virtual void what() = 0;
};

class abstractFactory{
public:
    virtual abstractProduct * produce() = 0;
};

#define PRODUCT_FACTORY_TEMPLATE(NAME)\
PRODUCT_TEMPLATE(NAME);\
FACTORY_TEMPLATE(NAME);\

PRODUCT_FACTORY_TEMPLATE(cloth)
PRODUCT_FACTORY_TEMPLATE(computer)
PRODUCT_FACTORY_TEMPLATE(water)

template <typename T>
inline void test(){
    T factory;
    auto *product = factory.produce();
    product->what();
    delete(product);
}

int main(){
   test<clothFactory>();
   test<computerFactory>();
   test<waterFactory>();
   return 0;
}
