#ifndef __DECK_H__
#define __DECK_H__

/*	카드뭉치 (Deck) 구현	*/

#define BLACKJACKCARDSIZE 52			// Card 52장
#define SHUFFLECOUNT 100				// SHUFFLE 상수

#include "Card.h"
#include "Stack.h"

class Deck {
private:
	Stack* MyDeck;

public:
	Deck();
	~Deck();
	void DeckInit(void);
	void Shuffle(void);
	Card Draw(void);
};

#endif
