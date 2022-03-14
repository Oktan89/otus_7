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
    ~IModelObservable() = default;
};
