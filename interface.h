#pragma once
#include <memory>

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

class __BaseState
{
    std::shared_ptr<IModelObservable> _modelContext;

public:
    __BaseState(std::shared_ptr<IModelObservable> model) : _modelContext(model) {}
    
    void setModelContext(std::shared_ptr<IModelObservable> model)
    {
        _modelContext = model;
    }
    virtual void ReadBlock() = 0;
    virtual void EndBlock() = 0;
    virtual void StartBlock() = 0;
    ~__BaseState() = default;
};