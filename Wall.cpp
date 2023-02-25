#include "Wall.h"

Wall::Wall() {
	setSprite("wall0");
	setType("Wall");
	setSolidness(df::HARD);

	df::Vector p(0, 0);
	setPosition(p);

	wallType = 0;
	//WallTypes are as follows:
	//0 - Yellow - Ordinary Wall
	//1 - Blue - Does not interact with Bullets
	//2 - Green - Causes Balls to bounce
}

Wall::Wall(df::Vector v) {
	setSprite("wall");
	setType("Wall");
	setSolidness(df::HARD);

	setPosition(v);

	wallType = 0;
	//WallTypes are as follows:
	//0 - Yellow - Ordinary Wall
	//1 - Blue - Does not interact with Bullets
	//2 - Green - Causes Balls to bounce
}

Wall::Wall(df::Vector v, int wallType) {
	setSprite("wall");
	setType("Wall");
	setSolidness(df::HARD);

	setPosition(v);

	this->wallType = 0;
	//WallTypes are as follows:
	//0 - Yellow - Ordinary Wall
	//1 - Blue - Does not interact with Bullets
	//2 - Green - Causes Balls to bounce
}

int Wall::getWallType() {
	return wallType;
}

void Wall::setWallType(int w) {
	wallType = w;
	
	switch (wallType) {
		case (0):
			setSprite("wall0");
		break;

		case (1):
			setSprite("wall1");
		break;

		case (2):
			setSprite("wall2");
		break;
	}
}