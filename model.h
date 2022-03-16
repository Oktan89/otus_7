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
    std::size_t _batch_size = 0;
    bool status = true;
  
public:
    Model(int argc, char* argv[]);

    std::size_t get_batch_size() const noexcept;

    std::vector<std::string>& getData();

    void TransitionTo(std::unique_ptr<__BaseState>& state);

    void push(const std::string& com);

    bool getStatus() const noexcept override;
    
    void setStatus(bool stat) { status = stat;} 

private:
    bool __isdigit(char ch);
};

