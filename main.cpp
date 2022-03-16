#include <iostream>
#include <memory>
#include "model.h"
#include "console_view.h"
#include "controller.h"


int main(int argc, char* argv[])
{

    auto proc = std::make_shared<Model>(argc, argv);
    
    auto cli = CliView::create(proc);
    
    Processing processing(proc);
     
    return processing.start();
}

