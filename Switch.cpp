#include "Switch.h"
#include "EventStop.h"
#include "EventStart.h"
#include <WorldManager.h>

Switch::Switch(Door* d) {
	setVelocity(df::Vector(0.000001,0));
	door = d;
	onFor = 0;
	pause = false;

	setSolidness(df::SOFT);
	setSprite("switch0");
	setType("Switch");
	setAltitude(0);

	registerInterest(df::STEP_EVENT);
	registerInterest(ZAWARUDO_EVENT);
	registerInterest(TIMESTART_EVENT);

}

int Switch::eventHandler(const df::Event* p_e) {
	if ( p_e->getType() == df::STEP_EVENT ) {
		setVelocity(df::Vector(-1 * getVelocity().getX(), getVelocity().getY()));

		if (pause == true) {
		} else if (onFor > 1) {
			onFor -= 1;
		} else if (onFor == 1) {
			onFor = 0;
			door->setOpen(false);
			setSprite("switch0");
		}

		return 1;
	}

	if ( p_e->getType() == df::COLLISION_EVENT ) {
		const df::EventCollision* p_collision_event = dynamic_cast < const df::EventCollision* > ( p_e );
		hit(p_collision_event);
		return 1;
	}

	LM.writeLog(p_e->getType().c_str());

	if (p_e->getType() == ZAWARUDO_EVENT) {
		LM.writeLog("Switch Stopped");
		pause = true;
		return 1;
	}

	if (p_e->getType() == TIMESTART_EVENT) {
		LM.writeLog("Switch Starts To Move...");
		pause = false;
		return 1;
	}

	return 0;
}

void Switch::hit(const df::EventCollision* p_ce) {
	if ( p_ce->getObject1()->getType() == "Hero" || p_ce->getObject2()->getType() == "Hero" ) {
		door->setOpen(true);
		setSprite("switch1");
		onFor = 30;
		getVelocity().setX(-1 * getVelocity().getX());
	} else if ( p_ce->getObject1()->getType() == "Ball" || p_ce->getObject2()->getType() == "Ball" ) {
		door->setOpen(true);
		setSprite("switch1");
		onFor = 30;
		getVelocity().setX(-1 * getVelocity().getX());
	}
}