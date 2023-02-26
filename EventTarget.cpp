#include "EventTarget.h"

EventTarget::EventTarget(df::Vector v)
{
	setType(TARGET_EVENT);
	pos = v;
}

const df::Vector EventTarget::getTarget() {
	return pos;
}

void EventTarget::setTarget(df::Vector v) {
	pos = v;
}

