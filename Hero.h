#pragma once

#include "Object.h"
#include "Event.h"
#include <EventMouse.h>

class Hero : public df::Object {
	private:
		int hearts;
		int inv;
	public:
		Hero();
		~Hero();

		int getHearts();
		void setHearts(int newH);

		int getInv();
		void setInv(int newI);

		int eventHandler(const df::Event* p_e) override;
		void Hero::mouse(const df::EventMouse* p_mouse_event);
		void kbd(const df::EventKeyboard* p_keyboard_event);
};



