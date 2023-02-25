#pragma once

#include "Object.h"
#include "EventMouse.h"

class Reticle : df::Object {
    public:
        Reticle();
        int eventHandler(const df::Event* p_e) override;
};

