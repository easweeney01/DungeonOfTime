#include "Hero.h"

#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

Hero::Hero() {

	// Setup "saucer" sprite.
	setSprite("heroR");

	// Set object type.
	setType("Hero");

	// Set speed in horizontal direction.
	setVelocity(df::Vector(0.0, 0)); // 1 space left every 4 steps

	// Set starting location in middle of window.                             
	int world_horiz = (int)WM.getBoundary().getHorizontal();
	int world_vert = (int)WM.getBoundary().getVertical();
	df::Vector p(world_horiz / 4, world_vert / 4);
	setPosition(p);
	
}

int Hero::eventHandler(const df::Event* p_e) {

}

//Hearts and Invincible Frames
int Hero::getHearts() {
	return hearts;
}

void Hero::setHearts(int newH) {
	hearts = newH;
}

int Hero::getInv() {
	return inv;
}

void Hero::setInv(int newI) {
	inv = newI;
}