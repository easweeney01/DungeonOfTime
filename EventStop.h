#include "Event.h"

const std::string ZAWARUDO_EVENT = "Event_TS_Stop";

class EventStop : public df::Event {

public:
    //This event stops time for objects. Event Title is reference to Dio Brando's time-stopping ability, The World.
    EventStop();
};