//
// Created by mars on 2020/2/15.
//

#ifndef DESIGNPATTERN_CONTROLLER_H
#define DESIGNPATTERN_CONTROLLER_H

#include <queue>
#include "command.h"
namespace zy{
    namespace commandPattern{
        class controller {
        protected:
            command *cmd;
        public:
            virtual void setExcute(command *_cmd);
            virtual void excute();
        };
    }
}



#endif //DESIGNPATTERN_CONTROLLER_H
