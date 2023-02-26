//
// game.cpp
// 

// Engine includes.
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"

#include "Saucer.h"

#include "Hero.h"
#include "Wall.h"
#include "Door.h"
#include "Switch.h"
#include "Ball.h"


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
}

// Populate world with some objects.
void populateWorld(void) {
  new Hero;

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
      w->setPosition(df::Vector(i, 24));
  }
  for ( int i = 1; i < 25; i++ ) {
      Wall* w = new Wall();
      w->setPosition(df::Vector(79, 0 + i));
  }
  

  for (int i = 0; i < 10; i++) {
      Wall* w = new Wall();
      w->setPosition(df::Vector(30, 1+i));
      w->setWallType(1);
  }

  Door* door = new Door(df::Vector(50,10));
  Switch* swtc = new Switch(door);
  swtc->setPosition(df::Vector(50,20));

  Ball* ball = new Ball(df::Vector(20,20));
}
