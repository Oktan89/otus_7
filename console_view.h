#pragma once
#include "interface.h"
#include <iostream>

class CliView : public IViewObserver, public std::enable_shared_from_this<CliView>
{
public:
    using model =  std::shared_ptr<class Model>;
private:
    model _model;

    CliView() = default;
public:
    
    static std::shared_ptr<CliView> create(model mod)
    {
        auto ptr =  std::shared_ptr<CliView>(new CliView());
        ptr->setModel(mod);
        return ptr;
    }

    std::shared_ptr<CliView> getptr();

    void setModel(model& model);

    void update() override;

    ~CliView() = default;

};
