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

  RM.loadSprite("sprites/bullet0-spr.txt", "bullet0");
  RM.loadSprite("sprites/bullet1-spr.txt", "bullet1");
  RM.loadSprite("sprites/reticle-spr.txt", "reticle");
}

// Populate world with some objects.
void populateWorld(void) {
  new Hero;

  for (int i = 0; i < 10; i++) {
      Wall* w = new Wall();
      w->setPosition(df::Vector(10+i, 10));
  }

  for (int i = 0; i < 10; i++) {
      Wall* w = new Wall();
      w->setPosition(df::Vector(30, 1+i));
      w->setWallType(1);
  }
}
