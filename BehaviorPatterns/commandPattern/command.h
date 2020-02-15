//
// Created by mars on 2020/2/15.
//

#ifndef DESIGNPATTERN_COMMAND_H
#define DESIGNPATTERN_COMMAND_H

#include "device.h"
namespace zy{
    namespace commandPattern{
        class command {
        protected:
            device *dev;
            virtual void excute() = 0;
        public:
            virtual void press(){
                excute();
            }
            virtual void setDev(device *_dev){
                dev = _dev;
            }
        };
        class openComand:public command{
        private:
            void excute() override {
                dev->on();
            }
        };
        class closeComand:public command{
        private:
            void excute() override {
                dev->off();
            }
        };
    }
}


#endif //DESIGNPATTERN_COMMAND_H
