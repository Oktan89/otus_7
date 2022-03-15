#pragma once
#include <list>
#include <string>
#include <vector>
#include "interface.h"

class __baseModel : public IModelObservable
{
    std::list<std::weak_ptr<IViewObserver>> __observer;
public:
    void addObserver(std::shared_ptr<IViewObserver> observer) override;

    void removeObserver(std::shared_ptr<IViewObserver> observer) override;

    void notify() override;
    
};

class Model : public __baseModel, public std::enable_shared_from_this<Model>
{
    std::vector<std::string> _batch;
    std::unique_ptr<__BaseState> _state;
    int _batch_size = 0;
    bool status = true;
  
public:
    Model(int argc, char* argv[]);

    void print();

    int get_batch_size() const noexcept;

    std::vector<std::string>& getData();

    void push(const std::string& com);

    bool getStatus() const noexcept override;

private:
    bool __isdigit(char ch);
};

