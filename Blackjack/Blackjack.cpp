/* Blackjack ver 0.1 */
// 게임시작 후 카드 한장씩 나누어 주는거까지 구현

// Gamemanager.cpp
// DealCards(); 이후로 구현
/* 최종업데이트 2021.12.19 */

#include <iostream>
#include "GameManager.h"

using namespace std;

int main(void) {
	Deck d;
	Player dealer, p1;
	Table t1(&d, &dealer, &p1);
	GameManager Handle;

	cout << "Blackjack ver 0.1" << endl;
	
	Handle.GameStart(&t1);
		
	return 0;
}