//
// Created by mars on 2020/2/16.
//

#ifndef DESIGNPATTERN_COMMON_H
#define DESIGNPATTERN_COMMON_H
#include <bits/unique_ptr.h>
#define UNIQUEPTR(TYPE) std::unique_ptr<TYPE>(new TYPE)
#define UNIQUEPTR_WITH_PARM(TYPE,...) std::unique_ptr<TYPE>(new TYPE(__VA_ARGS__))
#endif //DESIGNPATTERN_COMMON_H
