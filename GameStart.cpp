#include "GameStart.h"
#include "Hero.h"
#include "Door.h"
#include "Switch.h"
#include "Turret.h"
#include "Ball.h"
#include "flag.h"

GameStart::GameStart() {
	lvl = 1;
	setPosition(df::Vector(40,12));
	started = false;
	setAltitude(0);
	setType("GameStart");
	setSprite("title");
	setSolidness(df::SPECTRAL);

	registerInterest(df::KEYBOARD_EVENT);
	registerInterest(df::STEP_EVENT);
}

int GameStart::nextLvl() {
	lvl += 1;
	loadLvl(lvl);
	return 0;
}

int GameStart::loadLvl(int lvl) {
	setVisible(false);
	clearAllEntities();
	started = true;
	this->lvl = lvl;

	if ( lvl == 1 ) {
		makeBox();
		Hero* h2 = new Hero;
		h2->setPosition(df::Vector(15,3));

		Door* door2 = new Door(df::Vector(30, 3));
		Switch* swtc2 = new Switch(door2);
		swtc2->setPosition(df::Vector(5, 4));

		Ball* b2 = new Ball(df::Vector(63,2));

		Door* door2b = new Door(df::Vector(62, 7));
		Switch* swtc2b = new Switch(door2b);
		swtc2b->setPosition(df::Vector(76, 3));

		
		Turret* t2 = new Turret();
		t2->setPosition(df::Vector(10,12));

		Ball* b2b = new Ball(df::Vector(50, 12));
		makeRow(55,10,true,5,1);
		Door* door2c = new Door(df::Vector(50, 17));
		Switch* swtc2c = new Switch(door2c);
		swtc2c->setPosition(df::Vector(15, 12));
		Door* door2d = new Door(df::Vector(50, 20));
		Switch* swtc2d = new Switch(door2d);
		swtc2d->setPosition(df::Vector(15, 12));

		Flag* f = new Flag(df::Vector(40,19));

		makeRow(0,6,false,40);
		makeRow(40, 6, true, 5);
		makeRow(60, 5, false, 20);
		makeRow(60, 1, true, 4,1);
		makeRow(0,10, false, 62);

		makeRow(0, 15, false, 52);

		for ( int i = 0; i < 14; i++ ) {
			makeRow(1 + 3 * i, 6, true,5);
		}

		for ( int i = 0; i < 7; i++ ) {
			makeRow(2, 16 + i, false, 30,1);
		}
		makeRow(32,16,true,7);


		return 2;
	} 
	else if ( lvl == 3 ) {
		LM.writeLog("Level 2");
		Hero* h = new Hero;

		makeBox();

		makeRow(60,18,false,20);
		//for ( int i = 1; i < 20; i++ ) {
			//Wall* w = new Wall();
			//w->setPosition(df::Vector(60 + i, 18));
		//}
		makeRow(50,6,false,30);
		/*for ( int i = 1; i < 30; i++ ) {
			Wall* w = new Wall();
			w->setPosition(df::Vector(50 + i, 6));
		}*/
		makeRow(30,1,true,17,1);
		/*for ( int i = 0; i < 17; i++ ) {
			Wall* w = new Wall();
			w->setPosition(df::Vector(30, 1 + i));
			w->setWallType(1);
		}*/

		makeRow(30, 18, false,30,1);
		/*for ( int i = 0; i < 30; i++ ) {
			Wall* w = new Wall();
			w->setPosition(df::Vector(30 + i, 18));
			w->setWallType(1);
		}*/

		makeRow(30,13,false,30,1);
		/*for ( int i = 0; i < 30; i++ ) {
			Wall* w = new Wall();
			w->setPosition(df::Vector(30 + i, 13));
			w->setWallType(1);
		}*/

		Door* door = new Door(df::Vector(70, 20));
		Switch* swtc = new Switch(door);
		swtc->setPosition(df::Vector(68, 3));

		Turret* turret = new Turret();
		turret->setPosition(df::Vector(75, 8));

		Ball* ball = new Ball(df::Vector(40, 15));

		Turret* turretB = new Turret();
		turretB->setPosition(df::Vector(75, 3));

		Flag* flag = new Flag(df::Vector(74, 20));
		return 1;
	}
	

	return 0;
}

int GameStart::eventHandler(const df::Event* p_e) {
	//LM.writeLog("Event Recieved");
	if ( p_e->getType() == df::KEYBOARD_EVENT ) {

		const df::EventKeyboard* p_keyboard_event = dynamic_cast < const df::EventKeyboard* > ( p_e );
		kbd(p_keyboard_event);
		return 1;
	}

	return 0;
}

void GameStart::kbd(const df::EventKeyboard* p_keyboard_event) {
	bool press = ( p_keyboard_event->getKeyboardAction() == df::KEY_PRESSED );

	if ( press ) {
		switch ( p_keyboard_event->getKey() ) {
		case df::Keyboard::SPACE:       // Start Game
			if (!started) {
				loadLvl(3);
			}
			break;

		case df::Keyboard::BACKSPACE:       // End Game
			GM.setGameOver();
			break;
		}

		return;
	}
}

void GameStart::clearAllEntities() {
	LM.writeLog("Clearing All entities");
	df::ObjectList list = WM.getAllObjects();

	df::ObjectListIterator i(&list);
	for ( i.first(); !i.isDone(); i.next() ) {
		df::Object* p_o = i.currentObject();

		//Deletes all
		if ( p_o->getType() == "Hero" ) {
			WM.markForDelete(p_o);
		} else if ( p_o->getType() == "Ball" ) {
			WM.markForDelete(p_o);
		} else if ( p_o->getType() == "Bullet" ) {
			WM.markForDelete(p_o);
		} else if ( p_o->getType() == "Switch" ) {
			WM.markForDelete(p_o);
		} else if ( p_o->getType() == "Door" ) {
			WM.markForDelete(p_o);
		} else if ( p_o->getType() == "Flag" ) {
			WM.markForDelete(p_o);
		} else if ( p_o->getType() == "Reticle" ) {
			WM.markForDelete(p_o);
		} else if ( p_o->getType() == "Turret" ) {
			WM.markForDelete(p_o);
		} else if ( p_o->getType() == "Wall" ) {
			WM.markForDelete(p_o);
		}
	}
}

void GameStart::makeBox() {
	for ( int i = 0; i < 80; i++ ) {
		Wall* w = new Wall();
		w->setPosition(df::Vector(i, 0));
		w->setDir(1);
	}
	for ( int i = 1; i < 25; i++ ) {
		Wall* w = new Wall();
		w->setPosition(df::Vector(1, 0 + i));
		w->setDir(2);
	}
	for ( int i = 0; i < 80; i++ ) {
		Wall* w = new Wall();
		w->setPosition(df::Vector(i, 23));
		w->setDir(1);
	}
	for ( int i = 1; i < 25; i++ ) {
		Wall* w = new Wall();
		w->setPosition(df::Vector(79, 0 + i));
		w->setDir(2);
	}
}

void GameStart::makeRow(int X, int Y, bool vertical, int length, int type) {

	if ( vertical == false ) {
		Wall* wA = new Wall();
		wA->setPosition(df::Vector(X, Y));
		wA->setWallType(type);
		wA->setDir(1);

		for ( int i = 1; i < length-1; i++ ) {
			Wall* w = new Wall();
			w->setPosition(df::Vector(i+X, Y));
			w->setWallType(type);
			w->setDir(1);
		}

		Wall* wB = new Wall();
		wB->setPosition(df::Vector(X+length-1, Y));
		wB->setWallType(type);
		wB->setDir(1);
	} else {
		Wall* wA = new Wall();
		wA->setPosition(df::Vector(X, Y));
		wA->setWallType(type);
		wA->setDir(1);

		for ( int i = 1; i < length-1; i++ ) {
			Wall* w = new Wall();
			w->setPosition(df::Vector(X, i+Y));
			w->setWallType(type);
			w->setDir(2);
		}

		Wall* wB = new Wall();
		wB->setPosition(df::Vector(X, Y+length-1));
		wB->setWallType(type);
		wB->setDir(1);
	}
}