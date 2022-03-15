#include "controller.h"
#include <iostream>
#include <string>


int Processing::start()
{
    std::string input;
    do
    {
        std::getline(std::cin, input);
        _model->push(input);
        
    }while (_model->getStatus());
    

    return EXITSUCES;
}