#pragma once
#include <memory>
#include "interface.h"

#define EXITSUCES  0
#define EXITFAILURE 1 

class Processing
{
    std::shared_ptr<IModelObservable> _model;

public:
    explicit Processing(std::shared_ptr<IModelObservable> model) : _model(model){}
    
    int start();
};