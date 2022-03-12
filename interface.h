#pragma once
#include <memory>

struct ICliViewObserver
{
    virtual void update() = 0;
    ~ICliViewObserver() = default;
};

struct IModelObservable
{
    virtual void addObserver(std::shared_ptr<ICliViewObserver>) = 0;
    virtual void removeObserver(std::shared_ptr<ICliViewObserver>) = 0;
    virtual void notify() = 0;
    ~IModelObservable() = default;
};
