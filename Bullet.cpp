#include "Bullet.h"
#include <WorldManager.h>


Bullet::Bullet(df::Vector hero_pos) {
	setSolidness(df::SOFT);
	setType("Bullet");
	setSprite("bullet0");

	//Set starting location, based on hero's position passed in.
	df::Vector p(hero_pos.getX(), hero_pos.getY());
	setPosition(p);

	// Bullets move 1 space each game loop.
	// The direction is set when the Hero fires.
	setSpeed(1);
}

int Bullet::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::COLLISION_EVENT) {
		const df::EventCollision* p_collision_event = dynamic_cast < const df::EventCollision* > (p_e);
		hit(p_collision_event);
		return 1;
	}

	return 0;
}

// If Bullet moves outside world, mark self for deletion.
void Bullet::out() {
	WM.markForDelete(this);
}

// If Bullet hits Wall and Wall type is not Blue, mark Bullet for deletion.
// If Bullet hits Wall, mark Bullet for deletion and change trajectory of ball slightly.
// If Bullet hits Turret, mark bullet for deletion and decrease HP by one.
void Bullet::hit(const df::EventCollision* p_ce) {
	if (p_ce->getObject1()->getType()=="Wall") {
		Wall* p_wall = dynamic_cast < Wall* > (p_ce->getObject1());
		
		if (p_wall->getWallType() != 1) {
			WM.markForDelete(p_ce->getObject2());
		}
		return;
	} else if (p_ce->getObject2()->getType() == "Wall") {
		Wall* p_wall = dynamic_cast <Wall*> (p_ce->getObject2());

		if (p_wall->getWallType() != 1) {
			WM.markForDelete(p_ce->getObject1());
		}
		return;
	}

	if ( p_ce->getObject1()->getType() == "Ball" ) {
		WM.markForDelete(p_ce->getObject2()); return;
	} else if ( p_ce->getObject2()->getType() == "Ball" ) {
		WM.markForDelete(p_ce->getObject1()); return;
	}
}