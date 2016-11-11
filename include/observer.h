#pragma once
#include "model.h"
class IObserver
{
public:
    virtual void handleEvent(const Model&) = 0;
};
