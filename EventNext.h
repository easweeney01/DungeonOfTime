#pragma once
#include "Event.h"

const std::string NEXTLVL_EVENT = "Event_LVL";

class EventNext : public df::Event {

public:
    //Sets the level to the next one.
    EventNext();
};