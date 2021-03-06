#pragma once
#include <memory>
#include "interface.h"

class Model;

class Processing
{
    
    std::shared_ptr<Model> _model;

public:
    explicit Processing(std::shared_ptr<Model> model) : _model(model){}

    void setModelState();
    
    int start();
};