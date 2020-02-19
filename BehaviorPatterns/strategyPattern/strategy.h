//
// Created by mars on 2020/2/16.
//

#ifndef DESIGNPATTERN_STRATEGY_H
#define DESIGNPATTERN_STRATEGY_H

#include <functional>

namespace zy{
    namespace strategyPattern{
        template <class T>
        class strategy {
        protected:
            std::function<bool(T,T)> cmp = [](T n1,T n2){
                if(n1<=n2){
                    return true;
                }
                return false;
            };
            virtual void setCmp(std::function<bool(T,T)> _cmp){
                cmp = _cmp;
            }
        public:
            virtual void excute(T *num, int size) = 0;
        };

        template <class T>
        class quickSort:public strategy<T>{
        public:
            void excute(T *num, int size);
        };

        template <class T>
        class insertSort:public strategy<T>{
        public:
            void excute(T *num, int size);
        };

        template <class T>
        class bubbleSort:public strategy<T>{
        public:
            void excute(T *num, int size) override;
        };

        template <class T>
        void numSwap(T &num1, T &num2){
            T num = num1;
            num1 = num2;
            num2 = num;
        }

        template<class T>
        void bubbleSort<T>::excute(T *num, int size)  {
            int i = 0;
            int j = 0;
            for(;i<size-1;i++){
                for(j=i+1;j<size;j++){
                    if(!this->cmp(num[i],num[j])){
                        numSwap(num[i],num[j]);
                    }
                }
            }
        }

        template<class T>
        void quickSort<T>::excute(T *num, int size) {

        }

        template<class T>
        void insertSort<T>::excute(T *num, int size) {
            for(int i =1;i<size;i++){
                int iPostion = i - 1;
                while(iPostion >= 0 && !this->cmp(num[iPostion], num[i])){
                    iPostion--;
                }
                iPostion++;
                T tmp = num[i];
                for(int k = i; k > iPostion; k--){
                    num[k] = num[k-1];
                }
                num[iPostion] = tmp;
            }
        }
    }
}
#endif //DESIGNPATTERN_STRATEGY_H
