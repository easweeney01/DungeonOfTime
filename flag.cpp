#include "flag.h"

Flag::Flag(df::Vector pos) {
	setSprite("flag");
	setType("Flag");
	setSolidness(df::SOFT);
	setAltitude(0);
	setPosition(pos);
}