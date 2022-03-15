#include "console_view.h"
#include <vector>
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
        
    std::cout << std::endl;
}