/* Blackjack ver 0.3 */
// 게임 승패에 따른 보유금액 변동 구현
// 승률 구현
// 콘솔 환경에서의 기타 가독성 패치
// ASAP -> Blackjack (21) 승리 조건 구현 필요.
// Future -> 저장기능 (플레이어 이름, 돈, 승률 등)
/* 최종업데이트 2021.12.30 */

#include <iostream>
#include <Windows.h>
#include "GameManager.h"

using namespace std;

int main(void) {
	Deck d;
	Player dealer, p1;
	Table t1(&d, &dealer, &p1);
	GameManager Handle;
	char c;

	cout << "Blackjack ver 0.3" << endl;
	
	do {
		// 게임 시작
		Handle.GameStart(&t1);

		// 게임 종료 후
		Sleep(2000);
		cout << endl;
		cout << "보유현금: " << p1.GetMoneyInfo() << endl;
		cout << "승리: " << p1.GetwinCount() << "\t" << "패배: " << p1.GetlossCount() << endl;
		cout << "승률: ";
		if (p1.GetwinCount() + p1.GetlossCount() != 0)
			cout << ((double)p1.GetwinCount() / (p1.GetwinCount() + p1.GetlossCount())) * 100 << "%" << endl << endl;
		else
			cout << "0.00%" << endl << endl;

		cout << "****새게임을 시작하시겠습니까?****" << endl;
		cout << "새게임: 1" << endl;
		cout << "게임종료: 2" << endl;
		cin >> c;
		cout << endl;
	} while (c!='2');

	return 0;
}