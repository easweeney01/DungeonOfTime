#include "Event.h"
#include <Vector.h>

const std::string TARGET_EVENT = "Event_Target";

class EventTarget : public df::Event {
    private:
        df::Vector pos;
    public:
        //This isn't used lol
        EventTarget(df::Vector v);
        void setTarget(df::Vector v);
        const df::Vector getTarget();
};