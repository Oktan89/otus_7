#pragma once
#include <memory>

#define EXITSUCES  0
#define EXITFAILURE 1 

struct IViewObserver
{
    virtual void update() = 0;
    ~IViewObserver() = default;
};

struct IModelObservable
{
    virtual void addObserver(std::shared_ptr<IViewObserver>) = 0;
    virtual void removeObserver(std::shared_ptr<IViewObserver>) = 0;
    virtual void notify() = 0;
    virtual void push(const std::string&) = 0;
    virtual bool getStatus() const noexcept = 0;
    ~IModelObservable() = default;
};
class Model;

class __BaseState
{
protected:
    std::shared_ptr<Model> _modelContext;

public:
    
    void setModelContext(std::shared_ptr<Model> model)
    {   
        _modelContext = model;
    }
    virtual void ReadBlock() = 0;
    virtual void EndBlock() = 0;
    virtual void StartBlock() = 0;
    virtual void Exit() = 0;
    ~__BaseState() = default;
};