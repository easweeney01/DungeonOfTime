#include "Reticle.h"
Reticle::Reticle() {
	setSolidness(df::SPECTRAL);
	setAltitude(0);
	registerInterest(df::MSE_EVENT);
	setSprite("reticle");
}

int Reticle::eventHandler(const df::Event* p_e) {
    if ( p_e->getType() == df::MSE_EVENT ) {
        const df::EventMouse* p_mouse_event = dynamic_cast < const df::EventMouse* > ( p_e );
        if (p_mouse_event->getMouseAction() == df::MOVED ) {
            // Change location to new mouse position.
            setPosition(p_mouse_event->getMousePosition());
            return 1;
        }
    }

    // If get here, have ignored this event.
    return 0;
}