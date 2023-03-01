#pragma once
#include "Object.h"
#include <EventStep.h>
#include <EventCollision.h>

class Door : public df::Object {
	private:
		//Whether or not door is open.
		bool open;
		int closeIn;
	public:
		Door();
		//Creates door at specific location.
		Door(df::Vector v);
		void setOpen(bool open);
		bool getOpen();
		int eventHandler(const df::Event* p_e);
		void hit(const df::EventCollision* p_ce);
};

