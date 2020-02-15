//
// Created by mars on 2020/2/15.
//

#include "device.h"
#include <iostream>
void zy::commandPattern::tvDevice::on() {
    std::cout<<"tv on"<<std::endl;
}
void zy::commandPattern::tvDevice::off() {
    std::cout<<"tv off"<<std::endl;
}

void zy::commandPattern::computerDevice::on() {
    std::cout<<"computer on"<<std::endl;
}
void zy::commandPattern::computerDevice::off() {
    std::cout<<"computer off"<<std::endl;
}

void zy::commandPattern::lightDevice::off() {
std::cout<<"light off"<<std::endl;
}
void zy::commandPattern::lightDevice::on() {
std::cout<<"light on"<<std::endl;
}