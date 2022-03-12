#include "console_view.h"
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
    std::cout << _model->get_batch_size() << std::endl;
}