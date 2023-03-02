#include "Ball.h"
#include "EventStop.h"
#include "EventStart.h"
#include <ResourceManager.h>

void Ball::hit(const df::EventCollision* p_ce) {
	float bW = 2;

	if ( p_ce->getObject1()->getType() == "Wall" || p_ce->getObject2()->getType() == "Wall" ) {
		float vX = getVelocity().getX();
		float vY = getVelocity().getY();
		float pX = getPosition().getX();
		float pY = getPosition().getY();

		Object* wall = p_ce->getObject2();
		if ( p_ce->getObject1()->getType() == "Wall" ) {
			Object* wall = p_ce->getObject1();
		} 

		//Get Horizontal and Vertical Distances
		float dX = wall->getPosition().getX() - pX; //Positive if wall is right, negative if wall is left
		float dY = wall->getPosition().getY() - pY; //Positive if wall is below, negative if wall is above

		Wall* b_wall = dynamic_cast <Wall* > (wall);

		if ( b_wall->getDir() == 0 ) {
			if ( dX < -1 && vX < 0 ) {
				setVelocity(df::Vector(-vX, vY));
			}
			else if ( dX > 1 && vX > 0 ) {
				setVelocity(df::Vector(-vX, vY));
			}

			if ( dY < -1 && vY < 0 ) {
				setVelocity(df::Vector(vX, -vY));
			}
			else if ( dY > 1 && vY > 0 ) {
				setVelocity(df::Vector(vX, -vY));
			}
		} else if ( b_wall->getDir() == 1 ) {
			if ( dY < -1 && vY < 0 ) {
				setVelocity(df::Vector(vX, -vY));
			}
			else if ( dY > 1 && vY > 0 ) {
				setVelocity(df::Vector(vX, -vY));
			}
		} else if ( b_wall->getDir() == 2 ) {
			if ( dX < -1 && vX < 0 ) {
				setVelocity(df::Vector(-vX, vY));
			}
			else if ( dX > 1 && vX > 0 ) {
				setVelocity(df::Vector(-vX, vY));
			}
		}
		return;
	} else if ( p_ce->getObject1()->getType() == "Turret" || p_ce->getObject2()->getType() == "Turret" || p_ce->getObject1()->getType() == "Door" || p_ce->getObject2()->getType() == "Door" ) {
		float vX = getVelocity().getX();
		float vY = getVelocity().getY();
		float pX = getPosition().getX();
		float pY = getPosition().getY();

		Object* wall = p_ce->getObject2();
		if ( p_ce->getObject1()->getType() == "Turret" || p_ce->getObject1()->getType() == "Door" ) {
			Object* wall = p_ce->getObject1();
		}

		//Get Horizontal and Vertical Distances
		float dX = wall->getPosition().getX() - pX;
		float dY = wall->getPosition().getY() - pY;

		if ( dX < -0.5 && vX < 0 ) {
			setVelocity(df::Vector(-vX, vY));
		}
		else if ( dX > 0.5 && vX > 0 ) {
			setVelocity(df::Vector(-vX, vY));
		}

		if ( dY < -1 && vY < 0 ) {
			setVelocity(df::Vector(vX, -vY));
		}
		else if ( dY > 1 && vY > 0 ) {
			setVelocity(df::Vector(vX, -vY));
		}
		return;
	}

	if ( !pause ) {
		if ( p_ce->getObject1()->getType() == "Bullet" ) {
			float vX = getVelocity().getX();
			float vY = getVelocity().getY();

			float bX = p_ce->getObject1()->getVelocity().getX() / bW;
			float bY = p_ce->getObject1()->getVelocity().getY() / bW;

			vX += bX;
			vY += bY;

			setVelocity(df::Vector(vX, vY));
			df::Sound* p_sound = RM.getSound("whack");
			if ( p_sound ) {
				p_sound->play();
			}

		}
		else if ( p_ce->getObject2()->getType() == "Bullet" ) {
			float vX = getVelocity().getX();
			float vY = getVelocity().getY();

			float bX = p_ce->getObject2()->getVelocity().getX() / bW;
			float bY = p_ce->getObject2()->getVelocity().getY() / bW;

			vX += bX;
			vY += bY;

			setVelocity(df::Vector(vX, vY));

			df::Sound* p_sound = RM.getSound("whack");
			if ( p_sound ) {
				p_sound->play();
			}
		}

		
	}
	else {
		if ( p_ce->getObject1()->getType() == "Bullet" ) {
			float vX = getKinetic().getX();
			float vY = getKinetic().getY();

			float bX = p_ce->getObject1()->getVelocity().getX() / bW;
			float bY = p_ce->getObject1()->getVelocity().getY() / bW;

			vX += bX;
			vY += bY;

			setKinetic(df::Vector(vX, vY));
		}
		else if ( p_ce->getObject2()->getType() == "Bullet" ) {
			float vX = getKinetic().getX();
			float vY = getKinetic().getY();

			float bX = p_ce->getObject2()->getVelocity().getX() / bW;
			float bY = p_ce->getObject2()->getVelocity().getY() / bW;

			vX += bX;
			vY += bY;

			setKinetic(df::Vector(vX, vY));
		}
	}
}

int Ball::eventHandler(const df::Event* p_e) {
	if ( p_e->getType() == df::COLLISION_EVENT ) {
		const df::EventCollision* p_collision_event = dynamic_cast < const df::EventCollision* > ( p_e );
		hit(p_collision_event);
		return 1;
	}

	if ( p_e->getType() == df::STEP_EVENT ) { //Grinds the ball to a halt
		df::Vector v = df::Vector(getVelocity().getX() / 1.1, getVelocity().getY() / 1.1);
		setVelocity(v);

		return 1;
	}

	if ( p_e->getType() == ZAWARUDO_EVENT) { //Grinds the ball to a halt
		pause = true;
		setKinetic(getVelocity());
		setVelocity(df::Vector(0,0));
		return 1;
	}

	if ( p_e->getType() == TIMESTART_EVENT ) { //Grinds the ball to a halt
		pause = false;
		setVelocity(getKinetic());

		if ( kinetic.getMagnitude() >= 0.5 || kinetic.getMagnitude() <= -0.5 ) {
			df::Sound* p_sound = RM.getSound("whack");
			if ( p_sound )
				p_sound->play();
		}
		setKinetic(df::Vector(0, 0));
		return 1;
	}

	return 0;
}

Ball::Ball(df::Vector pos) {
	kinetic = df::Vector(0, 0);
	pause = false;

	setSolidness(df::HARD);
	setType("Ball");
	setSprite("ball");

	//Set starting location, based on hero's position passed in.
	df::Vector p(pos.getX(), pos.getY());
	setPosition(p);

	registerInterest(df::STEP_EVENT);
	registerInterest(ZAWARUDO_EVENT);
	registerInterest(TIMESTART_EVENT);
}

df::Vector Ball::getKinetic() {
	return kinetic;
}

void Ball::setKinetic(df::Vector v) {
	kinetic = v;
}