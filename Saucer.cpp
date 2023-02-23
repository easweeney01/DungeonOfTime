//
// Saucer.cpp
//
 
// Engine includes.
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

// Game includes.
#include "Saucer.h"

Saucer::Saucer() {

  // Setup "saucer" sprite.
  setSprite("saucer");

  // Set object type.
  setType("Saucer");

  // Set speed in horizontal direction.
  setVelocity(df::Vector(-0.25,0)); // 1 space left every 4 steps

  // Set starting location in middle of window.                             
  int world_horiz = (int) WM.getBoundary().getHorizontal();
  int world_vert = (int) WM.getBoundary().getVertical();  
  df::Vector p(world_horiz/2, world_vert/2);                   
  setPosition(p);                                
}
