#include "Event.h"

const std::string TIMESTART_EVENT = "Event_TS_Start";

class EventStart : public df::Event {

public:
    //This event allows time to continue.
    EventStart();
};