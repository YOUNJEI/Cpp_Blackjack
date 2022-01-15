/* Blackjack ver 0.4.1 */
// 파산시 게임초기화 구현
// Future -> 더블다운 구현
// Future2 -> GUI 구현
/* 최종업데이트 2022.01.15 */

#include <iostream>
#include <Windows.h>
#include "GameManager.h"
#include "SaveHelper.h"

using namespace std;

int main(void) {
	Deck d;
	Player dealer, p1;
	Table t1(&d, &dealer, &p1);
	GameManager Handle;
	SaveHelper sH("savedata.txt");
	char c;

	cout << "Blackjack ver 0.4.1" << endl;
	cout << "저장데이터를 불러옵니다.." << endl;
	
	if (sH.LoadData(&p1) == false)
		cout << "데이터 불러오기 실패" << endl;
	else {
		cout << "데이터를 불러왔습니다." << endl;
		cout << "승리: " << p1.GetwinCount() << "\t" << "패배: " << p1.GetlossCount() << endl;
		cout << "승률: ";
		if (p1.GetwinCount() + p1.GetlossCount() != 0)
			cout << ((double)p1.GetwinCount() / (p1.GetwinCount() + p1.GetlossCount())) * 100 << "%" << endl << endl;
		else
			cout << "0.00%" << endl << endl;
	}
	
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

	sH.SaveData(&p1);

	return 0;
}