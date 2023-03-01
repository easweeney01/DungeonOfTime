#pragma once
#include "Object.h"
class Wall : public df::Object {
	private:
		//0 means regular walls, 1 means walls that bullets can go through, 2 is an unused type of "bouncy wall".
		int wallType;
		int direction; //0 means universal, 1 means horizontal, 2 means vertical
	public:
		Wall();
		Wall(df::Vector v);
		Wall(df::Vector v, int wallType);

		int getWallType();
		void setWallType(int w);
		int getDir();
		void setDir(int d);
};

