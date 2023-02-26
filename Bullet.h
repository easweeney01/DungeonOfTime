#pragma once

#include "Object.h"
#include <EventCollision.h>
#include "Wall.h"

class Bullet : public df::Object {
    private:
        //Describes whether this is an allied or enemy bullet. Will program further parts later.
        bool allegiance;
        //Deletes bullet on offchance it escapes
        void out();
        //Performs collision data
        void hit(const df::EventCollision* p_collision_event);

   public:
        Bullet(df::Vector hero_pos);
        int eventHandler(const df::Event* p_e) override;
        bool getAlly();
        void setAlly(bool a);

};

