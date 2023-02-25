#pragma once
#include "Object.h"
class Door : public df::Object {
	private:
		bool open;
	public:
		Door();
		Door(df::Vector v);
		void setOpen(bool open);
		bool getOpen();
};

