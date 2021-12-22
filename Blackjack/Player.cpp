#include "Player.h"

Player::Player() {
	this->cardCount = 0;
	this->score = 0;

	this->money = 1000000;
	this->winCount = 0;
	this->lossCount = 0;
	this->betMoney = 0;
}

Player::~Player() {};

void Player::InitforNewGame(void) {
	cardCount = 0;
	score = 0;
	betMoney = 0;
}

int Player::GetCardCount(void) {
	return cardCount;
}

int Player::GetScore(void) {
	return score;
}

long long Player::GetMoneyInfo(void) {
	return money;
}

bool Player::GetCard(Deck* d) {
	/* 21 이상이면 bust*/

	pCardArr[cardCount] = d->Draw();
	score += pCardArr[cardCount].GetValue();

	if (score > 21)	return true;

	cardCount++;
	
	return false;
}

long long Player::Betting(long long bMoney) {
	if (bMoney > money)	return -1;
	else if (bMoney <= 0) return 0;
	else {
		money -= bMoney;
		betMoney += bMoney;
		return bMoney;
	}
}

void Player::ShowCard(int n) {
	if (n <= 0)	"카드가 없습니다.";
	else {
		for(int i=0; i<n; i++)	pCardArr[i].Print();
	}
}