#include "Object.h"
#include "Door.h"
#include <EventStep.h>
#include <EventCollision.h>
#include <LogManager.h>

class Switch : public df::Object {
	private:
		//Time the button will stay pressed
		int onFor;
		Door* door;

		//Whether time is paused.
		bool pause;
	public:
		//Every switch is directly connected to at least one door.
		Switch(Door* d);
		int eventHandler(const df::Event* p_e) override;

		//Can be pressed by ball or player to open door
		void hit(const df::EventCollision* p_ce);
};