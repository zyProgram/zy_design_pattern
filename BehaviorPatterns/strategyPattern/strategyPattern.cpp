//
// Created by mars on 2020/2/16.
//
#include "context.h"
#include "strategy.h"
#include <common.h>

static int intRange = 1000;
void generateInt(int *num,int total){
    for(int i =0;i<total;i++){
        num[i] = rand()%(intRange+1);
    }
}

int main(){
    auto bubble = UNIQUEPTR(zy::strategyPattern::bubbleSort<int>);
    auto insert = UNIQUEPTR(zy::strategyPattern::insertSort<int>);
    int total = rand()%intRange;
    std::cout<<"total:"<<total<<std::endl;
    auto numUptr = std::unique_ptr<int>(new int[total]);
    int *num = numUptr.get();
    auto ctx = UNIQUEPTR_WITH_PARM(zy::strategyPattern::context<int>,num,total);

    auto testLamda = [&](zy::strategyPattern::strategy<int> *sty){
        generateInt(num,total);
        ctx.get()->setStrategy(sty);
        ctx.get()->show();
        ctx.get()->sort();
        ctx.get()->show();
        std::cout<<"finish"<<std::endl;
    };

    testLamda(bubble.get());
    testLamda(insert.get());

    return 0;
}
