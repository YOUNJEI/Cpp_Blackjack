#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "Table.h"

class GameManager {
public:
	void GameStart(Table* t);
	bool GetBetting(Player* p1);
	void DealCards(Table* t);
};

#endif