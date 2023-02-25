#include "Object.h"
#include "Door.h"
#include <EventStep.h>
#include <EventCollision.h>
#include <LogManager.h>

class Switch : public df::Object {
	private:
		int onFor;
		Door* door;

		bool pause;
	public:
		Switch(Door* d);
		int eventHandler(const df::Event* p_e) override;
		void hit(const df::EventCollision* p_ce);
};