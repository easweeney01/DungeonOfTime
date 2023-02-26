#pragma once
#include "Object.h"
#include <EventCollision.h>
#include "Bullet.h"
#include "Wall.h"
#include "EventStep.h"

class Ball : public df::Object {
	private:
		//Whether time is stopped.
		bool pause; 
		//Enables it to bounce off of things and build kinetic energy.
		void hit(const df::EventCollision* p_collision_event);
		//Kinetic Energy Vector for when Time is stopped
		df::Vector kinetic;
	public:
		Ball(df::Vector pos);
		int eventHandler(const df::Event* p_e) override;

		df::Vector getKinetic();
		void setKinetic(df::Vector v);
};