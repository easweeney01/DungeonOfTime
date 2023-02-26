#include "Object.h"

class Flag : public df::Object {
private:

public:
	//Creates an end-goal flag, which instantly shuts down the game.
	Flag(df::Vector pos);
};