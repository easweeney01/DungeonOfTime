#pragma once
#include "Object.h"
class Door : public df::Object {
	private:
		//Whether or not door is open.
		bool open;
	public:
		Door();
		//Creates door at specific location.
		Door(df::Vector v);
		void setOpen(bool open);
		bool getOpen();
};

