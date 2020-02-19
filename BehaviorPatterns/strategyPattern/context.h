//
// Created by mars on 2020/2/16.
//

#ifndef DESIGNPATTERN_CONTEXT_H
#define DESIGNPATTERN_CONTEXT_H

#include "strategy.h"
#include <iostream>
namespace zy{
    namespace strategyPattern{
        template <typename T>
        class context{
        private:
            T *data;
            strategy<T> *sty;
            int size;
        public:
            context(T *_data,int _s){
                data = _data;
                size = _s;
            }
            void setStrategy(strategy<T> *_sty){
                sty = _sty;
            }
            void show(){
                std::cout<<"data:";
                for(int i = 0;i<size;i++){
                    std::cout<<data[i]<<" ";
                }
                std::cout<<std::endl;
            }
            void sort(){
                sty->excute(data,size);
            }
        };
    }
}

#endif //DESIGNPATTERN_CONTEXT_H
