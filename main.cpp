#include <iostream>
#include <iomanip>
#include <memory>
#include "model.h"
#include "console_view.h"

int main(int argc, char* argv[])
{

    auto processing = std::make_shared<Model>(argc, argv);
    
    auto cli = CliView::create(processing);
    
    processing->print();
    
}

