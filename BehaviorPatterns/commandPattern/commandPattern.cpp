//
// Created by mars on 2020/2/15.
//
#include <string>
#include <iostream>
#include "command.h"
#include "controller.h"
#include "device.h"
#include <bits/unique_ptr.h>
#include "common.h"
int main(){
    auto ctrl = UNIQUEPTR(zy::commandPattern::controller);

    auto tv = UNIQUEPTR(zy::commandPattern::tvDevice);
    auto light = UNIQUEPTR( zy::commandPattern::lightDevice);

    auto lightOnButton = UNIQUEPTR( zy::commandPattern::openComand);
    auto lightOffButton = UNIQUEPTR(zy::commandPattern::closeComand);

    auto tvOnButton =  UNIQUEPTR( zy::commandPattern::openComand);
    auto tvOffButton =  UNIQUEPTR( zy::commandPattern::closeComand);

    lightOnButton.get()->setDev(light.get());
    lightOffButton.get()->setDev(light.get());

    tvOnButton.get()->setDev(tv.get());
    tvOffButton.get()->setDev(tv.get());

    lightOnButton.get()->press();
    tvOnButton.get()->press();
    return 0;
}