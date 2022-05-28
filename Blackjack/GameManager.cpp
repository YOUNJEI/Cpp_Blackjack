#include <iostream>
#include <vector>
#include <Windows.h>
#include "GameManager.h"

using namespace std;

void GameManager::GameStart(Table* t) {
	char c;
	int game_result;
	bool _flagblackjack = false;
	bool _escapeflag = true;				// escapeflag for loop in bankrupt condition

	t->dealer->InitforNewGame();
	t->p1->InitforNewGame();

	// 파산시 신규게임 or 게임종료
	if (t->p1->GetMoneyInfo() <= 0) {
		
		cout << "현금이 부족합니다" << endl;
		
		do {
			_escapeflag = true;
			cout << "게임을 초기화 하시겠습니까? (Y/N)";
			cin >> c;

			switch (c) {
			case 'y':
			case 'Y':
				t->p1->SetMoneyInfo(1000000);
				t->p1->SetwinCount(0);
				t->p1->SetlossCount(0);
				_escapeflag = false;
				break;

			case 'n':
			case 'N':
				exit(-1);
				break;
			}
		} while (_escapeflag);
	}

	t->deck->Shuffle();

	while(!GetBetting(t->p1));			// 배팅
	cout << endl;
	
	/* 배팅 후 2장 */
	for(int i=0; i<2; i++)	DealCards(t);

	cout << "My Card:";
	t->p1->ShowCard(t->p1->GetCardCount());
	cout << endl;

	cout << "Dealer Card:";
	t->dealer->ShowCard(1);
	cout << endl;
	
	/* Stand or Hit */
	do {
		_flagblackjack = false;							// flag 변수 true인 상태로, player 승리시 블랙잭 보너스 수령

		if (CheckBlackJack(t)) {
			
			// player가 블랙잭 승리조건을 갖추었는지 확인하는 부분
			if (t->p1->GetScore() == 21)
				_flagblackjack = true;

			cout << "BlackJack!!" << endl;
			Sleep(2000);
			game_result = OpenCard(t);
			break;
		}

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

	switch (game_result) {
	case 1:					// 플레이어 승리
		cout << "배팅한 금액: " << t->p1->GetBetMoneyInfo() << endl;
		
		// If player win with blackjack --> reward *1.5
		if (_flagblackjack) {
			cout << t->p1->GetBetMoneyInfo() * 2.5 << "획득!" << endl;
			t->p1->AddMoney(t->p1->GetBetMoneyInfo() * 2.5);
		}
		// if player win with non-blackjack --> reward *1
		else {
			cout << t->p1->GetBetMoneyInfo() * 2 << "획득!" << endl;
			t->p1->AddMoney(t->p1->GetBetMoneyInfo() * 2);
		}
		t->p1->AddwinCount();
		break;

	case 0:
		cout << "무승부!" << endl;
		cout << "배팅한 금액: " << t->p1->GetBetMoneyInfo() << endl;
		t->p1->AddMoney(t->p1->GetBetMoneyInfo());
		break;

	case -1:
		cout << "배팅한 금액: " << t->p1->GetBetMoneyInfo() << endl;
		cout << t->p1->GetBetMoneyInfo() << "잃음!" << endl;
		t->p1->AddlossCount();
		break;
	}
}

bool GameManager::GetBetting(Player* p1) {
	long long bMoney;
	cout << "보유현금: " << p1->GetMoneyInfo() << endl;
	cout << "배팅금액: ";
	cin >> bMoney;
	
	// cin 입력오류로 인한 무한루프 방지코드
	if (cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		bMoney = 0;
	}

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
	cout << "********Card Open********" << endl;	Sleep(2000);
	cout << "Your Card: ";	t->p1->ShowCard(t->p1->GetCardCount()); cout << endl;
	cout << "Your Score: " << t->p1->GetScore() << endl	<<	endl;	Sleep(2000);

	if (t->dealer->GetScore() < 17 && CheckBlackJack(t) == false) {
		cout << "Dealer:" << t->dealer->GetScore() << " ("; t->dealer->ShowCard(t->dealer->GetCardCount());	cout << ")" << endl;	Sleep(2000);
		while (t->dealer->GetScore() < 17) {
			cout << "Dealer New Card!" << endl;	Sleep(2000);
			if (t->dealer->GetCard(t->deck)) {
				cout << "Dealer Card: ";	t->dealer->ShowCard(t->dealer->GetCardCount());	cout << endl << endl;	Sleep(2000);
				cout << "Dealer bust!!" << endl;
				return 1;
			}
			else
			{
				cout << t->dealer->GetScore() << endl;
			}
		}
	}
	
	Sleep(2000);
	cout << "Dealer Card: ";	t->dealer->ShowCard(t->dealer->GetCardCount());	cout << endl;
	cout << "Dealer Score: " << t->dealer->GetScore() << endl << endl;
	Sleep(2000);

	if (t->p1->GetScore() > t->dealer->GetScore()) {
		cout << "You Win!!" << endl;
		return 1;
	}
	else if (t->p1->GetScore() == t->dealer->GetScore()) {
		if (CheckBlackJack(t) == true) {
			if (t->p1->GetCardCount() < t->dealer->GetCardCount()) {
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
		else
			return 0;
	}
	else {
		cout << "Dealer Win!!" << endl;
		return -1;
	}
}

int GameManager::Hit(Table* t) {
	/* HIT									*/
	/* OVER 21 (BUST) return -1				*/
	/* If score is 21, return OpenCard		*/
	/* else return 2 (nothing, keep going)	*/

	t->p1->GetCard(t->deck);
	
	cout << endl;
	cout << t->p1->GetScore() << endl;

	if (t->p1->GetScore() > 21) {
		cout << "You Bust!!" << endl;
		return -1;
	}
	else if (t->p1->GetScore() == 21) return OpenCard(t);
	else return 2;
}

bool GameManager::CheckBlackJack(Table* t) {
	/* Check BlackJack */
	/* If dealer or player get a BlackJack, return true */
	/* else return false */

	if (t->dealer->GethasCardA()) {
		if (t->dealer->GetScore() == 21 && t->dealer->GetCardCount() == 2)	return true;
	}

	if (t->p1->GethasCardA()) {
		if (t->p1->GetScore() == 21 && t->p1->GetCardCount() == 2)	return true;
	}

	return false;
}