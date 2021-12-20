#include "Table.h"

Table::Table(Deck* d, Player* dl, Player* i_p1) {
	this->deck = d;
	this->dealer = dl;
	this->p1 = i_p1;
}