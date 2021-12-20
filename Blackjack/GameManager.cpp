#include "GameManager.h"
#include <iostream>

using namespace std;

void GameManager::GameStart(Table* t) {
	t->dealer->InitforNewGame();
	t->p1->InitforNewGame();
	t->deck->Shuffle();

	while(!GetBetting(t->p1));
	DealCards(t);
	// 구현 필요합니다
}

bool GameManager::GetBetting(Player* p1) {
	long long bMoney;
	cout << "보유현금: " << p1->GetMoneyInfo() << endl;

	cout << "배팅금액: ";
	cin >> bMoney;
	bMoney = p1->Betting(bMoney);

	if (bMoney < 0) {
		cout << "보유현금 부족" << endl << endl;
		return false;
	}
	else if (bMoney == 0) {
		cout << "배팅금액은 0원보다 커야합니다." << endl << endl;
		return false;
	}
	else {
		return true;
	}
}

void GameManager::DealCards(Table* t) {
	t->p1->GetCard(t->deck);
	
	cout << "My Card:";
	t->p1->ShowCard(t->p1->GetCardCount());
	cout << endl;

	t->dealer->GetCard(t->deck);
	
	cout << "Dealer Card:";
	t->dealer->ShowCard(1);
	cout << endl;
}