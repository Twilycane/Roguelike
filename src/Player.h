#include "Actor.h"

class Player : public Actor{
public:
	static void initPlayer();
	static Player* getPlayer() { return &player; }
	~Player();
protected:
	static Player player;
	Player();
};
