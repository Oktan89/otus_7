#pragma once
#include <list>
#include <string>
#include <vector>
#include "interface.h"

class __baseModel : public IModelObservable
{
    std::list<std::weak_ptr<ICliViewObserver>> __observer;
public:
    void addObserver(std::shared_ptr<ICliViewObserver> observer) override;

    void removeObserver(std::shared_ptr<ICliViewObserver> observer) override;

    void notify() override;
    
};

class Model : public __baseModel
{
    std::vector<std::string> _batch;
    int _batch_size;

public:
    Model(int argc, char* argv[]);

    void print();

    int get_batch_size() const noexcept;


private:
    bool __isdigit(char ch);
};

