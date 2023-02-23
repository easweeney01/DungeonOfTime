#include "Hero.h"

#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

Hero::Hero() {
	hearts = 3;
	inv = 30;

	// Setup "saucer" sprite.
	setSprite("heroR");
	dir = 1; //1 is right, -1 is left

	// Set object type.
	setType("Hero");

	// Set speed in horizontal direction.
	setVelocity(df::Vector(0.0, 0)); // 1 space left every 4 steps

	// Set starting location in middle of window.                             
	int world_horiz = (int)WM.getBoundary().getHorizontal();
	int world_vert = (int)WM.getBoundary().getVertical();
	df::Vector p((float) world_horiz / 4, (float) world_vert / 4);
	setPosition(p);
	
	setSolidness(df::HARD);

	//Activates Interest
	registerInterest(df::KEYBOARD_EVENT);
	registerInterest(df::STEP_EVENT);
	registerInterest(df::MSE_EVENT);
}

Hero::~Hero() {

}

//Mouse, Keyboard, and 
int Hero::eventHandler(const df::Event* p_e) {
	LM.writeLog("Event Recieved");
	if (p_e->getType() == df::KEYBOARD_EVENT) {

		const df::EventKeyboard* p_keyboard_event = dynamic_cast <const df::EventKeyboard*> (p_e);
		kbd(p_keyboard_event);
		return 1;
	}

	if (p_e->getType() == df::STEP_EVENT) {
		LM.writeLog("Stepping");
		step();
		return 1;
	}

	if (p_e->getType() == df::MSE_EVENT) {
		const df::EventMouse* p_mouse_event =
			dynamic_cast <const df::EventMouse*> (p_e);
		mouse(p_mouse_event);
		return 1;
	}

	return 0;
}

void Hero::kbd(const df::EventKeyboard* p_keyboard_event) {
	bool down = (p_keyboard_event->getKeyboardAction() == df::KEY_DOWN);
	bool press = (p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED);
	bool release = (p_keyboard_event->getKeyboardAction() == df::KEY_RELEASED);

	if (down) {
		LM.writeLog("down");
		switch (p_keyboard_event->getKey()) {
		case df::Keyboard::W:       // up
			moveY(-0.25);
			break;

		case df::Keyboard::S:       // down
			moveY(0.25);
			break;

		case df::Keyboard::A:       // left
			moveX(-0.5);

			if (dir != -1) { setSprite("heroL"); }
			dir = -1;
			break;
		case df::Keyboard::D:       // right
			moveX(0.5);
			if (dir != 1) { setSprite("heroR"); }
			dir = 1;
			break;
		}
	} else if (press) { //
		LM.writeLog("press");
		switch (p_keyboard_event->getKey()) {
		case df::Keyboard::SPACE:       //Space (Time Stop)
			LM.writeLog("ZA WARUDO!");
			break;
		}
	}

	return;
}

void Hero::mouse(const df::EventMouse* p_mouse_event) {

}

void Hero::moveX(float dx) {
	// If stays on window, allow move.
	df::Vector new_pos(getPosition().getX() + dx, getPosition().getY());
	if ((new_pos.getX() > 3) && (new_pos.getX() < WM.getBoundary().getHorizontal() - 1))
		WM.moveObject(this, new_pos);
		LM.writeLog("Attempting to move");

	// If stays on window, allow move.
	if ((new_pos.getX() > 3) && (new_pos.getX() < WM.getBoundary().getHorizontal()))
		WM.moveObject(this, new_pos);
		LM.writeLog("Attempting to move");
}

void Hero::moveY(float dy) {
	// If stays on window, allow move.
	df::Vector new_pos(getPosition().getX(), getPosition().getY() + dy);
	if ((new_pos.getY() > 3) &&
		(new_pos.getY() < WM.getBoundary().getVertical() - 1))
		WM.moveObject(this, new_pos);

	// If stays on window, allow move.
	if ((new_pos.getY() > 3) && (new_pos.getY() < WM.getBoundary().getVertical()))
		WM.moveObject(this, new_pos);
}

void Hero::step() {
	if (inv > 0) {
		inv--;
	}

	//df::Vector v = df::Vector(10,1);
	//this->moveTo(v);
}

//Hearts and Invincible Frames
int Hero::getHearts() {
	return hearts;
}

void Hero::setHearts(int newH) {
	hearts = newH;
}

int Hero::getInv() {
	return inv;
}

void Hero::setInv(int newI) {
	inv = newI;
}