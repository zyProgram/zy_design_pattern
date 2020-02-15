//
// Created by mars on 2020/2/15.
//

#ifndef DESIGNPATTERN_DEVICE_H
#define DESIGNPATTERN_DEVICE_H

namespace zy{
    namespace commandPattern{
        class device {
        public:
            virtual void on() = 0;
            virtual void off() = 0;
        };
        class tvDevice: public device {
        public:
            void on();
            void off();
        };
        class computerDevice:public device {
        public:
            void on();
            void off();
        };
        class lightDevice:public device {
        public:
            void on();
            void off();
        };
    }

}


#endif //DESIGNPATTERN_DEVICE_H
