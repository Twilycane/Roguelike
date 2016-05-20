#include "Player.h"

Player Player::player;

Player::Player() : Actor(5,5,64,TCODColor::white)
{
	
}

void Player::initPlayer() {
	player = Player();
}

Player::~Player() {
}