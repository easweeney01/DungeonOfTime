#pragma once
#include "Object.h"
class Wall : public df::Object {
	private:
		int wallType;
	public:
		Wall();
		Wall(df::Vector v);
		Wall(df::Vector v, int wallType);

		int getWallType();
		void setWallType(int w);
};

