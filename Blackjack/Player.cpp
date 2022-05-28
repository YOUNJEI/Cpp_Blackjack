#include "Player.h"

Player::Player() {
	this->cardCount = 0;
	this->score.push_back(0);
	this->hasCardA = false;
	this->money = 1000000;
	this->winCount = 0;
	this->lossCount = 0;
	this->betMoney = 0;
}

Player::~Player() {};

void Player::InitforNewGame(void) {
	cardCount = 0;
	betMoney = 0;
	hasCardA = false;
	for (int i = score.size()-1; i > 0; i--)	score.pop_back();
	score[0] = 0;
}

int Player::GetCardCount(void) {
	return cardCount;
}

int Player::GetScore(void) {
	if (this->hasCardA == true) {
		if (score[1] > 21)	return score[0];
		else return score[1];
	}
	else return score[0];
}

bool Player::GethasCardA(void) {
	return this->hasCardA;
}

long long Player::GetMoneyInfo(void) {
	return money;
}

long long Player::GetBetMoneyInfo(void) {
	return betMoney;
}

int Player::GetwinCount(void) {
	return winCount;
}

int Player::GetlossCount(void) {
	return lossCount;
}

void Player::SetMoneyInfo(long long m) {
	this->money = m;
}

void Player::SetwinCount(int w) {
	this->winCount = w;
}

void Player::SetlossCount(int l) {
	this->lossCount = l;
}

void Player::AddMoney(int m) {
	this->money += m;
}

bool Player::GetCard(Deck* d) {
	/* 21 이상이면 bust*/

	pCardArr[cardCount] = d->Draw();

	// A카드 일경우 +1 or +11 고려하여 점수 계산
	if (pCardArr[cardCount].GetValue() == 1) {
		if (score.size() == 1) { 
			score.push_back(score[0]);
		}

		if (!(this->hasCardA)) {
			score[0] += 1;
			score[1] += 11;
			this->hasCardA = true;
		}
		else {
			score[0] += 1;
			score[1] += 1;
		}
	}
	else {
		score[0] += pCardArr[cardCount].GetValue();
		if (this->hasCardA)	score[1] += pCardArr[cardCount].GetValue();
	}

	cardCount++;

	if (score[0] > 21)	return true;
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

void Player::AddwinCount(void) {
	this->winCount++;
}

void Player::AddlossCount(void) {
	this->lossCount++;
}