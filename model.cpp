#include "model.h"
#include "state.h"
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <ctime>

void __baseModel::addObserver(std::shared_ptr<IViewObserver> observer) 
{
    __observer.emplace_back(observer);
}

void __baseModel::removeObserver(std::shared_ptr<IViewObserver> observer)
{
    auto it = std::find_if(__observer.cbegin(), __observer.cend(), [&](const std::weak_ptr<IViewObserver>& sub){
            auto itr = sub.lock();
            return itr == observer;
        });
        if(it != __observer.end())
            __observer.erase(it);
}

void __baseModel::notify()
{
    for(auto it = __observer.begin(); it != __observer.end(); ++it)
    {
        auto ptr = it->lock();
        if(ptr)
            ptr->update();
        else
            __observer.erase(it++);
    }    
}

Model::Model(int argc, char* argv[])
{
    if(argc <= 1)
    {
        std::cout << "The block size parameter is required \n" 
            <<"Usage: "<< argv[0] << " [arg] \n";
        exit(EXITFAILURE);
    }
    else
    {
        if(__isdigit(*argv[1]) && *argv[1] >= '1')
        {
                _batch_size = std::atoi(argv[1]);
                _batch.reserve(_batch_size);
        }
        else 
        {
            std::cout << "Invalid parameter [arg], must be greater than: >=1\n"
                <<"Usage example: "<< argv[0] << " 3 \n";
            exit(EXITFAILURE);
        }
    }
  
}


bool Model::__isdigit(char ch)
{
    return std::isdigit(static_cast<unsigned char>(ch));
}

std::size_t Model::get_batch_size() const noexcept
{
    return _batch_size;
}

void Model::TransitionTo(std::unique_ptr<__BaseState>& state)
{
    _state = std::move(state);
    _state->setModelContext(shared_from_this());
}

void Model::push(const std::string& com)
{
    if(com == protocol::eof)
    {
        _state->Exit();
    }
    else if(com == protocol::start)
    {
        _state->StartBlock();
    }
    else if(com == protocol::end)
    {
        _state->EndBlock();
    }
    else
    {
        _batch.emplace_back(com);
        _state->ReadBlock();
    }
   
}

bool Model::getStatus() const noexcept
{
    return status;
}

std::vector<std::string>& Model::getData()
{
    return _batch;
}

void Model::setTimeStartBlock()
{
    _t = std::chrono::system_clock::now();
}

Model::model_time Model::getTimeStartBlock() const noexcept
{
    return _t;
}

Model::model_time Model::getTime()
{
    return std::chrono::system_clock::now();
}