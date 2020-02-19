cmake_minimum_required(VERSION 3.5)
project(DesignPattern)

set(CMAKE_CXX_STANDARD 11)
include_directories(common)
add_executable(DesignPattern main.cpp)
#创建模式
add_executable(simpleFactory CreatePatterns/SimpleFactoryPattern/simpleFactoryRealize.cpp)
add_executable(factoryMethod CreatePatterns/SimpleFactoryPattern/factoryMethod.cpp)
add_executable(builder CreatePatterns/SimpleFactoryPattern/builderPattern.cpp BehaviorPatterns/strategyPattern/context.h common/common.h)
add_executable(singleton CreatePatterns/SimpleFactoryPattern/singletonPattern.cpp)

#构造模式
add_executable(proxy StructuralPatterns/proxyPattern.cpp)
add_executable(decorator StructuralPatterns/decorator.cpp)

#行为模式
add_executable(observer BehaviorPatterns/observer.cpp)
add_executable(chain BehaviorPatterns/chainPattern.cpp)
add_executable(command BehaviorPatterns/commandPattern/commandPattern.cpp
        BehaviorPatterns/commandPattern/device.cpp BehaviorPatterns/commandPattern/device.h
        BehaviorPatterns/commandPattern/command.cpp BehaviorPatterns/commandPattern/command.h
        BehaviorPatterns/commandPattern/controller.cpp BehaviorPatterns/commandPattern/controller.h)
add_executable(strategy BehaviorPatterns/strategyPattern/context.h BehaviorPatterns/strategyPattern/strategyPattern.cpp BehaviorPatterns/strategyPattern/strategy.h)