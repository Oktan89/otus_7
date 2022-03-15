#pragma once
#include "interface.h"

class StaticBlock : public __BaseState
{

public:
    StaticBlock(std::shared_ptr<IModelObservable> model) : __BaseState(model) {}
  
    void ReadBlock() override {}

    void EndBlock() override {}

    void StartBlock() override {}

    ~StaticBlock() = default;
};

class DinamicBlock : public __BaseState
{

public:
    DinamicBlock(std::shared_ptr<IModelObservable> model) : __BaseState(model) {}
    
    void ReadBlock() override {}

    void EndBlock() override {}

    void StartBlock() override {}


    ~DinamicBlock() = default;
};