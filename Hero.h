#pragma once

#include "GameManager.h"

#include "Object.h"

#include "Event.h"
#include "EventMouse.h"
#include "EventKeyboard.h"
#include "EventStep.h"

class Hero : public df::Object {
	private:
		int hearts;
		int inv;
		int dir;

	public:
		Hero();
		~Hero();

		int getHearts();
		void setHearts(int newH);

		int getInv();
		void setInv(int newI);

		int eventHandler(const df::Event* p_e) override;
		void mouse(const df::EventMouse* p_mouse_event);
		void kbd(const df::EventKeyboard* p_keyboard_event);
		void step();

		void moveX(float dy);
		void moveY(float dy);
};



