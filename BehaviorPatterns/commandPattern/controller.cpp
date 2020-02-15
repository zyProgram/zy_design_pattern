//
// Created by mars on 2020/2/15.
//

#include "controller.h"

void zy::commandPattern::controller::setExcute(zy::commandPattern::command *_cmd) {
     cmd = _cmd;
}

void zy::commandPattern::controller::excute()  {
    cmd->press();
};
