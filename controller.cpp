#include "model.h"
#include "state.h"
#include "controller.h"
#include <iostream>
#include <string>


int Processing::start()
{
    std::string input;
    input.reserve(_model->get_batch_size());
    setModelState();
    do
    {
        if(std::getline(std::cin, input))
            _model->push(input);
        else    
            _model->push("EOF");
        
    }while (_model->getStatus());
    
    
    return EXITSUCES;
}

void Processing::setModelState()
{
    std::unique_ptr<__BaseState> state_static = std::make_unique<StaticBlock>();
    _model->TransitionTo(state_static);
}