#pragma once
#include "Object.h"
#include <EventKeyboard.h>
#include <EventStep.h>
#include "GameManager.h"
#include "WorldManager.h"

class GameStart : public df::Object {
	public:
		GameStart();
		int loadLvl(int lvl);
		int nextLvl();

		int eventHandler(const df::Event* p_e) override;
		void kbd(const df::EventKeyboard* p_keyboard_event);
	private:
		int time_before_switch;
		int lvl;
		void clearAllEntities();
		bool started;
		
		//Makes box around screen
		void makeBox();
		//Creates a row of terrain down or right, starting at a given position up to a given length.
		void makeRow(int X, int Y, bool vertical, int length, int type = 0);
};

