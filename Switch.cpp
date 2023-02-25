#include "Switch.h"

Switch::Switch(Door* d) {
	door = d;
	onFor = 0;
	pause = 0;

	setSolidness(df::SOFT);
	setSprite("switch0");
	setType("Switch");
	registerInterest(df::STEP_EVENT);
}

int Switch::eventHandler(const df::Event* p_e) {
	if ( p_e->getType() == df::STEP_EVENT ) {
		if (pause = 0) {
		} else if (onFor > 0) {
			onFor -= 1;
		} else if ( onFor < 0 || onFor == 0) {
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

	std::string tsp = "Event_TS_Stop";
	if (p_e->getType()== tsp) {
		LM.writeLog("Switch Stopped");
		pause = true;
		return 1;
	}

	return 0;
}

void Switch::hit(const df::EventCollision* p_ce) {
	if ( p_ce->getObject1()->getType() == "Hero" || p_ce->getObject2()->getType() == "Hero" ) {
		door->setOpen(true);
		setSprite("switch1");
		onFor = 30;
	}
}