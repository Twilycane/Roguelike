#include "Engine.h"
using namespace std;
void Engine::generateFiles() {
	TCODSystem::createDirectory("../Config");
	string line;
	ifstream iStartup("../Config/startup.txt");
	if (!iStartup.good())
	{
		ofstream startup("../Config/startup.txt");
		startup << "#startup config\n#\n#\n" << "#Set The Resolution\n" << "i:ConsoleWidth=125\n" << "i:ConsoleHeight=75\n\n#";
		startup.close();
	}
	while (getline(iStartup, line))
	{
		if (line.find("i:") == 0)
		{
			if (line.find("ConsoleWidth=") == 2)
			{
				conWidth = stoi(line.substr(line.find("=") + 1, 4));
			}
			else if (line.find("ConsoleHeight=") == 2)
			{
				conHeight = stoi(line.substr(line.find("=") + 1, 4));
			}
		}
	}
	iStartup.close();
}

Engine::Engine() {
	generateFiles();
	printf("Succesfully loaded config!	\nStarting Console With Size %i x %i \n", conWidth, conHeight);
}

void Engine::showMenu() {
	root->setAlignment(TCOD_CENTER);
	root->print(conWidth / 2, conHeight / 4, "[Insert Title Here]\n\n\n\n\n1. Play\n\n\n\n2. Exit");
	root->flush();
	bool startGame = false;
	while (!startGame && !gameOver)
	{
		switch (root->waitForKeypress(true).vk)
		{
		case TCODK_1:	//play
			startGame = true;
			break;
		case TCODK_ESCAPE:
		case TCODK_2:	//exit
			startGame = true;
			gameOver = true;
			break;
		default:
			break;
		}
	}
}

void Engine::init() {
	if (conWidth < 125 || conHeight < 75)
	{
		TCODConsole::initRoot(40, 4, "Error");
		TCODConsole::root->print(0, 0,"Your Chosen Resolution Is Too Low!\n Minimum Resolution Is 125 x 75");
		TCODConsole::root->flush();
		TCODConsole::waitForKeypress(true);
		gameOver = true;
	}
	if (!gameOver)
	{
		TCODConsole::initRoot(conWidth, conHeight, "Roguelike");
		root = TCODConsole::root;
		player =  Player::getPlayer();
		showMenu();
		// Show menu options
		TCODConsole::waitForKeypress(true);
		root->clear();
		root->flush();
	}
}

void Engine::update() {
	TCOD_key_t key;
	TCOD_mouse_t mouse;
	TCOD_event_t ev = TCODSystem::waitForEvent(TCOD_EVENT_ANY, &key, &mouse, true);
	if (ev == TCOD_EVENT_KEY_PRESS) {
		switch (key.vk)
		{
		case TCODK_UP:
			player->y--;
			break;
		case TCODK_DOWN:
			player->y++;
			break;
		case TCODK_LEFT:
			player->x--;
			break;
		case TCODK_RIGHT:
			player->x++;
			break;
		case TCODK_ESCAPE:
			gameOver = true;
			break;
		}
		printf("X: %i	Y: %i \n", player->x, player->y);
		root->clear();
	}
	player->render();
	root->flush();
}

Engine::~Engine() {
	printf("Exiting...");
}