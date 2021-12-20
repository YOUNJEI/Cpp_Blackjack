#ifndef __TABLE_H__
#define __TABLE_H__

#include "Player.h"

class Table {
public:
	Deck* deck;
	Player* dealer;
	Player* p1;
	Table(Deck* d, Player* dl, Player* i_p1);
};

#endif
