#include "model.h"
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <algorithm>

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
        exit(0);
    }
    else
    {
        if(__isdigit(*argv[1]) && *argv[1] >= '1')
        {
                _batch_size = std::atoi(argv[1]);
        }
        else 
        {
            std::cout << "Invalid parameter [arg], must be greater than: >=1\n"
                <<"Usage example: "<< argv[0] << " 3 \n";
            exit(0);
        }
    }    
}

void Model::print()
{
    notify();
}

bool Model::__isdigit(char ch)
{
    return std::isdigit(static_cast<unsigned char>(ch));
}

int Model::get_batch_size() const noexcept
{
    return _batch_size;
}