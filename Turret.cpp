#include "Turret.h"

#include "EventStop.h"
#include "EventStart.h"

Turret::Turret() {
	setSprite("turret");
	setType("Turret");

	hearts = 2;
	inv = 15;
	pause = false;

	fire_slowdown = 15;
	fire_countdown = fire_slowdown;

	registerInterest(df::STEP_EVENT);

	registerInterest(ZAWARUDO_EVENT);
	registerInterest(TIMESTART_EVENT);
}

Turret::~Turret() {

}

int Turret::getHearts() {
	return hearts;
}

void Turret::setHearts(int newH) {
	hearts = newH;
}

int Turret::getInv() {
	return inv;
}

void Turret::setInv(int newI) {
	inv = newI;
}

void Turret::step() {
	
	if ( inv > 0 ) {
		inv--;
	}

	//fire_countdown--;
	//if ( fire_countdown < 0 ) {
	//	fire_countdown = fire_slowdown;
	//}
}

void Turret::fire() {
	if ( pause ) {
		return;
	}
	//if ( fire_countdown > 0 ) {
	//	return;
	//}
	//fire_countdown = fire_slowdown;

	// Fire Bullet towards target.
	// Compute normalized vector to position, then scale by speed (1).
	df::Vector v = target - getPosition();
	v.normalize();
	v.scale(1);
	Bullet* p = new Bullet(getPosition());
	p->setAlly(false);
	p->setVelocity(v);
}

int Turret::eventHandler(const df::Event* p_e) {
	//LM.writeLog("Event Recieved");
	if ( p_e->getType() == df::STEP_EVENT ) {
		step();
		return 1;
	}

	if ( p_e->getType() == ZAWARUDO_EVENT ) {
		pause = true;
		return 1;
	}

	if ( p_e->getType() == TIMESTART_EVENT ) {
		pause = false;
		return 1;
	}

	return 0;
}

void Turret::setTarget(df::Vector pos) {
	target = pos;
	fire();
}