#include "Door.h"
#include <LogManager.h>


Door::Door() {
	setSprite("door0");
	setSolidness(df::HARD);
	setType("Door");
	open = false;
	closeIn = 0;
	registerInterest(df::STEP_EVENT);
	registerInterest(df::COLLISION_EVENT);
	setVelocity(df::Vector(0.00001, 0));
}

Door::Door(df::Vector v) {
	setSprite("door0");
	setSolidness(df::HARD);
	setType("Door");
	setPosition(v);
	open = false;
	closeIn = 0;
	registerInterest(df::STEP_EVENT);
	registerInterest(df::COLLISION_EVENT);
	setVelocity(df::Vector(0.00001, 0));
}

bool Door::getOpen() {
	return open;
}

void Door::setOpen(bool open) {
	this->open = open;
	setAltitude(0);

	if ( open ) {
		closeIn = 0;
		setSprite("door1");
		setSolidness(df::SOFT);
	}
	else {
		closeIn = 3;
	}
}

int Door::eventHandler(const df::Event* p_e) {
	if ( p_e->getType() == df::STEP_EVENT ) {
		setVelocity(df::Vector(-1 * getVelocity().getX(), getVelocity().getY()));

		if ( closeIn > 1 ) {
			closeIn -= 1;
		}
		else if ( closeIn == 1 ) {
			closeIn = 0; //Activates the door lock 
			setSprite("door0");
			setSolidness(df::HARD);
		}

		return 1;
	}

	if ( p_e->getType() == df::COLLISION_EVENT ) {
		const df::EventCollision* p_collision_event = dynamic_cast < const df::EventCollision* > ( p_e );
		hit(p_collision_event);
		return 1;
	}

	return 0;
}

void Door::hit(const df::EventCollision* p_ce) { //Keep the door open juuuust long enough for the person to scrape through
	if ( closeIn > 0 ) {
		if ( p_ce->getObject1()->getType() == "Hero" || p_ce->getObject2()->getType() == "Hero" ) {
			closeIn = 3;
			
		}
		else if ( p_ce->getObject1()->getType() == "Ball" || p_ce->getObject2()->getType() == "Ball" ) {
			closeIn = 3;
			getVelocity().setX(-1 * getVelocity().getX());

		}
	}
}