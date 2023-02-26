#pragma once

#include "GameManager.h"

#include "Object.h"

#include "Event.h"
#include "EventMouse.h"
#include "EventKeyboard.h"
#include "EventStep.h"
#include "EventTarget.h"

#include "Bullet.h"
#include "Reticle.h"

class Hero : public df::Object {
	private:
		//Stats such as HP (may be dropped), stun time, direction facing (left or right), fire rate and countdown
		int hearts;
		int inv;
		int dir;
		int fire_slowdown;
		int fire_countdown;
		
		//Time left in TimeStop
		int timeRemain;

		//Reticle
		Reticle* p_reticle;

		//If connects with end-flag, shuts down game.
		void hit(const df::EventCollision* p_collision_event);
	public:
		Hero();
		~Hero();

		int getHearts();
		void setHearts(int newH);

		int getInv();
		void setInv(int newI);

		int eventHandler(const df::Event* p_e) override;
		//Controls aiming for gun
		void mouse(const df::EventMouse* p_mouse_event);
		//Controls movement and time-stop
		void kbd(const df::EventKeyboard* p_keyboard_event);
		void step();

		void moveX(float dx);
		void moveY(float dy);

		void fire(df::Vector target);
		//Calls attention of self to turrets.
		void selfReport();
};



