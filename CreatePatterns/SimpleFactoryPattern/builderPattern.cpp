//
// Created by mars on 2020/2/13.
//

/***
 *  产品是组合的，如 meal 是water + food
 *  生产产品 依靠 后厨builder
 *  前台 有个waiter 设置 builder ，并将产品返回给用户
 *
 *  应用主要在大型游戏中 生产不同的地形 怪物
 */
#include <iostream>
#include <string>
class meal{
protected:
    std::string water;
    std::string food;
public:
    void setWater(const std::string &w){
        water = w;
    }
    void  setFood(const std::string &f){
        food = f;
    }
    std::string getWater(){
        return water;
    }
    std::string getFood(){
        return food;
    }
};

class builder{
protected:
    meal m;
public:
    virtual void buildWater() = 0;
    virtual void buildFood() = 0;
    virtual void finsih() {
        std::cout<<"construct finish:"<<m.getFood()<<"+"<<m.getWater()<<std::endl;
    }
};
class builderA:public builder{
public:
    void buildWater(){
        m.setWater("cola");
    }
    void buildFood() {
        m.setFood("hambuger");
    }
};
class builderB:public builder{
public:
    void buildWater(){
        m.setWater("hot_water");
    }
    void buildFood() {
        m.setFood("rice");
    }
};

class waiter{
private:
    builder *b;
public:
    void setBuilder(builder *pb){
        b = pb;
    }
    void construct(){
        b->buildWater();
        b->buildFood();
        b->finsih();
    };
};

int main(){
    waiter w;
    auto test = [&](builder *p){
        w.setBuilder(p);
        w.construct();
        delete(p);
    };
    test(new builderA);
    test(new builderB);
    return 0;
}