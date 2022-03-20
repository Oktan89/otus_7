#include "console_view.h"
#include <vector>
#include <chrono>
#include <ctime>
#include <fstream>
#include <string>
#include "model.h"

std::shared_ptr<CliView> CliView::getptr()
{
    return shared_from_this();
}

void CliView::setModel(model &model)
{
    if (_model)
        _model->removeObserver(shared_from_this());
    _model = model;
    _model->addObserver(shared_from_this());
}

void CliView::update()
{
    std::vector<std::string>& data = _model->getData();
    
    for(auto it = data.cbegin(); it != data.cend(); ++it)
    {
        if(it != data.begin())
        {
            std::cout << ", ";
        }
        else
        {
            std::cout << "bulk: ";
        }
        std::cout << *it;
    }
        
    if(data.size() != 0) 
        std::cout << std::endl;
}

std::shared_ptr<FileView> FileView::getptr()
{
    return shared_from_this();
}

void FileView::setModel(model &model)
{
    if (_model)
        _model->removeObserver(shared_from_this());
    _model = model;
    _model->addObserver(shared_from_this());
}

void FileView::update()
{
    std::vector<std::string>& data = _model->getData();
    
    Model::model_time t = _model->getTimeStartBlock();
    
    std::string file_name = "bulk" + 
        std::to_string(std::chrono::system_clock::to_time_t(t)) +
        ".log";

    if(std::ifstream(file_name))
    {
        auto nano = std::chrono::duration_cast<std::chrono::nanoseconds>(_model->getTime() - t);
        file_name = file_name + "_" + std::to_string(nano.count()); //todo добавить милисекунды или нано
    }
    std::ofstream file(file_name, std::ios::app);
    
    for(auto it = data.cbegin(); it != data.cend(); ++it)
    {
        if(it != data.begin())
        {
            file << ", ";
        }
        else
        {
            file << "bulk: ";
        }
        file << *it;
    }
        
    if(data.size() != 0) 
        file << std::endl;
    file.close();
}