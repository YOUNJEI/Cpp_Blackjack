#include "GameManager.h"
#include <iostream>
#include <vector>

using namespace std;

void GameManager::GameStart(Table* t) {
	char c;
	int game_result;

	t->dealer->InitforNewGame();
	t->p1->InitforNewGame();
	t->deck->Shuffle();

	while(!GetBetting(t->p1));			// 배팅
	
	/* 배팅 후 2장 */
	for(int i=0; i<2; i++)	DealCards(t);

	cout << "My Card:";
	t->p1->ShowCard(t->p1->GetCardCount());
	cout << endl;

	cout << "Dealer Card:";
	t->dealer->ShowCard(1);
	cout << endl;

	do {
		c = InputAction(t);

		switch (c) {
		case 's':
		case 'S':
			game_result = OpenCard(t);
			break;

		case 'h':
		case 'H':
			game_result = Hit(t);
			break;
		}
	} while (game_result == 2);
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
	t->dealer->GetCard(t->deck);
}

char GameManager::InputAction(Table* t) {
	char c;

	while (true) {
		cout << "S:Stand | H:Hit" << endl;
		cin >> c;

		switch (c) {
		case 's':
		case 'S':
		case 'h':
		case 'H':
			return c;

		default:
			break;
		}
	}
}

int GameManager::OpenCard(Table* t) {
	/* player 승리 시 1 리턴  */
	/* 무승부 0 리턴		  */	
	/* dealer 승리 시 -1 리턴 */
	cout << endl;
	cout << "********Card Open********" << endl;
	cout << "Your Card: ";	t->p1->ShowCard(t->p1->GetCardCount()); cout << endl;
	cout << "Your Score: " << t->p1->GetScore() << endl	<<	endl;

	while (t->dealer->GetScore() < 17) {
		cout << t->dealer->GetScore() << " Dealer new Card!"<<endl;
		if (t->dealer->GetCard(t->deck)) {
			cout << "Dealer Card: ";	t->dealer->ShowCard(t->dealer->GetCardCount());	cout << endl;
			cout << "Dealer bust!!" << endl;
			return 1;
		}
	}
	
	cout << "Dealer Card: ";	t->dealer->ShowCard(t->dealer->GetCardCount());	cout << endl;
	cout << "Dealer Score: " << t->dealer->GetScore() << endl;

	if (t->p1->GetScore() > t->dealer->GetScore()) {
		cout << "You Win!!" << endl;
		return 1;
	}
	else if (t->p1->GetScore() == t->dealer->GetScore()) {
		if (t->p1->GetCardCount() > t->dealer->GetCardCount()) {
			cout << "You Win!!" << endl;
			return 1;
		}
		else if (t->p1->GetCardCount() == t->dealer->GetCardCount()) {
			cout << "Draw!!" << endl;
			return 0;
		}
		else {
			cout << "Dealer Win!!" << endl;
			return -1;
		}
	}
	else {
		cout << "Dealer Win!!" << endl;
		return -1;
	}
}

int GameManager::Hit(Table* t) {
	/* -1 bust*/
	t->p1->GetCard(t->deck);
	cout << t->p1->GetScore() << endl;

	if (t->p1->GetScore() > 21) {
		cout << "You Bust!!" << endl;
		return -1;
	}
	else if (t->p1->GetScore() == 21) return OpenCard(t);
	else return 2;
}