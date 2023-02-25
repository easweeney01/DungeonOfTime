#pragma once
#include "Object.h"
#include "Event.h"
#include <Vector.h>
#include "Bullet.h"
#include <EventStep.h>

class Turret : public df::Object {
private:
	int hearts;
	int inv;
	int fire_slowdown;
	int fire_countdown;

	df::Vector target;

public:
	Turret();
	~Turret();

	int getHearts();
	void setHearts(int newH);

	int getInv();
	void setInv(int newI);

	int eventHandler(const df::Event* p_e) override;
	void step();

	void fire();
};