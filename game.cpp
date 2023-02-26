//
// game.cpp
// 

// Engine includes.
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"

#include "Hero.h"
#include "Wall.h"
#include "Door.h"
#include "Switch.h"
#include "Ball.h"
#include "Turret.h"
#include "flag.h"


// Function prototypes.
void loadResources(void);
void populateWorld(void);
 
int main(int argc, char *argv[]) {

  // Start up game manager.
  if (GM.startUp())  {
    LM.writeLog("Error starting game manager!");
    GM.shutDown();
    return 1;
  }

  // Set flush of logfile during development (when done, make false).
  LM.setFlush(true);

  // Show splash screen.
  //df::splash();

  // Load game resources.
  loadResources();

  // Populate game world with some objects.
  populateWorld();

  // Run game (this blocks until game loop is over).
  GM.run();
  
  // Shut everything down.
  GM.shutDown();
  
  return 0;
}

// Load resources (sprites, sound effects, music).
void loadResources(void) {
  RM.loadSprite("sprites/saucer-spr.txt", "saucer");
  RM.loadSprite("sprites/heroL-spr.txt", "heroL");
  RM.loadSprite("sprites/heroR-spr.txt", "heroR");

  RM.loadSprite("sprites/wall0-spr.txt", "wall0");
  RM.loadSprite("sprites/wall1-spr.txt", "wall1");
  RM.loadSprite("sprites/wall2-spr.txt", "wall2");

  RM.loadSprite("sprites/door0-spr.txt", "door0");
  RM.loadSprite("sprites/door1-spr.txt", "door1");
  RM.loadSprite("sprites/switch0-spr.txt", "switch0");
  RM.loadSprite("sprites/switch1-spr.txt", "switch1");

  RM.loadSprite("sprites/bullet0-spr.txt", "bullet0");
  RM.loadSprite("sprites/bullet1-spr.txt", "bullet1");
  RM.loadSprite("sprites/reticle-spr.txt", "reticle");

  RM.loadSprite("sprites/ball-spr.txt", "ball");
  RM.loadSprite("sprites/turret-spr.txt", "turret");
  RM.loadSprite("sprites/flag-spr.txt", "flag");
}

// Populate world with some objects.
void populateWorld(void) {
  Hero* h = new Hero;

  for (int i = 0; i < 80; i++) {
      Wall* w = new Wall();
      w->setPosition(df::Vector(i, 0));
  }
  for ( int i = 1; i < 25; i++ ) {
      Wall* w = new Wall();
      w->setPosition(df::Vector(1, 0+i));
  }
  for ( int i = 0; i < 80; i++ ) {
      Wall* w = new Wall();
      w->setPosition(df::Vector(i, 23));
  }
  for ( int i = 1; i < 25; i++ ) {
      Wall* w = new Wall();
      w->setPosition(df::Vector(79, 0 + i));
  }
  for ( int i = 1; i < 20; i++ ) {
      Wall* w = new Wall();
      w->setPosition(df::Vector(60+i, 18));
  }
  for ( int i = 1; i < 30; i++ ) {
      Wall* w = new Wall();
      w->setPosition(df::Vector(50 + i, 6));
  }

  for (int i = 0; i < 17; i++) {
      Wall* w = new Wall();
      w->setPosition(df::Vector(30, 1+i));
      w->setWallType(1);
  }
  for (int i = 0; i < 30; i++ ) {
      Wall* w = new Wall();
      w->setPosition(df::Vector(30+i, 18));
      w->setWallType(1);
  }
  for ( int i = 0; i < 30; i++ ) {
      Wall* w = new Wall();
      w->setPosition(df::Vector(30 + i, 13));
      w->setWallType(1);
  }

  Door* door = new Door(df::Vector(70,20));
  Switch* swtc = new Switch(door);
  swtc->setPosition(df::Vector(68,3));

  Turret* turret = new Turret();
  turret->setPosition(df::Vector(75, 8));

  Ball* ball = new Ball(df::Vector(40,15));

  Turret* turretB = new Turret();
  turretB->setPosition(df::Vector(75,3));

  Flag* flag = new Flag(df::Vector(74, 20));
}
