#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include "Deck.h"

#define MAXCARDARR 30

class Player {
private:
	Card pCardArr[MAXCARDARR];
	int cardCount;
	std::vector<int> score;
	bool hasCardA;
	long long money;
	long long betMoney;
	int winCount;
	int lossCount;

public:
	Player();
	~Player();

	int GetCardCount(void);
	int GetScore(void);
	long long GetMoneyInfo(void);
	void InitforNewGame();
	bool GetCard(Deck* d);
	long long Betting(long long bMoney);
	void ShowCard(int n);
};

#endif
