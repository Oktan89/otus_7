#include <iostream>
#include <memory>
#include "model.h"
#include "console_view.h"
#include "controller.h"

//EOF Ctrl+D
int main(int argc, char* argv[])
{


    auto proc = std::make_shared<Model>(argc, argv);
    
    auto cli = CliView::create(proc);
    auto file = FileView::create(proc);
    
    Processing processing(proc);
     
    return processing.start();
}

