#include "Door.h"

Door::Door() {
	setSprite("door0");
	setSolidness(df::HARD);
	setType("Door");
	open = false;
}

Door::Door(df::Vector v) {
	setSprite("door0");
	setSolidness(df::HARD);
	setType("Door");
	setPosition(v);
	open = false;
}

bool Door::getOpen() {
	return open;
}

void Door::setOpen(bool open) {
	this->open = open;
	setAltitude(0);

	if ( open ) {
		setSprite("door1");
		setSolidness(df::SPECTRAL);
	}
	else {
		setSprite("door0");
		setSolidness(df::HARD);
	}
}