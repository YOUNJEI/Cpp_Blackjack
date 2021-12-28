/* Blackjack ver 0.2 */
// A카드 (1 or 11) 예외 사항 구현 완료

// To do -> 게임반복, money, 승률 구현 필요

/* 최종업데이트 2021.12.29 */

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