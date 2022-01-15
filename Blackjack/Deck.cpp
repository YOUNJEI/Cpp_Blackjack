#include "Deck.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <time.h>

Deck::Deck() {
	MyDeck = new Stack(BLACKJACKCARDSIZE);
	DeckInit();
}

Deck::~Deck() {
	delete MyDeck;
}

void Deck::DeckInit(void) {
	for (int i = 0; i < 10; i++) {
		MyDeck->Push(Card(i+1, Heart));		// 하트카드 생성
		MyDeck->Push(Card(i+1, Dia));		// 다이아카드 생성
		MyDeck->Push(Card(i+1, Club));		// 클로버카드 생성
		MyDeck->Push(Card(i+1, Spade));		// 스페이드카드 생성
	}
	for (int i = 0; i < 3; i++) {
		MyDeck->Push(Card(10, Heart));		// 하트카드 생성
		MyDeck->Push(Card(10, Dia));		// 다이아카드 생성
		MyDeck->Push(Card(10, Club));		// 클로버카드 생성
		MyDeck->Push(Card(10, Spade));		// 스페이드카드 생성
	}
}

void Deck::Shuffle(void) {
	// index 값을 난수로 추출하여 Shuffle

	Card temp;
	int x, y;
	srand((unsigned int)time(NULL));

	for (int i = 0; i < SHUFFLECOUNT; i++) {
		x = rand() % BLACKJACKCARDSIZE;
		y = rand() % BLACKJACKCARDSIZE;

		if (x != y) {
			temp = MyDeck->GetCardInfo(x);
			MyDeck->SetCardInfo(x, MyDeck->GetCardInfo(y));
			MyDeck->SetCardInfo(y, temp);
		}
	}
}

Card Deck::Draw(void) {
	Card temp = MyDeck->Pop();
	
	// 카드 전부 소진 시, 새로운 카드세트 생성 후 리턴
	if (temp.GetValue() == 0 && temp.GetType() == 0) {
		std::cout << "카드가 소진되었습니다!" << std::endl;
		std::cout << "새로운 트럼프 카드 사용!" << std::endl;
		this->DeckInit();
		this->Shuffle();

		temp = MyDeck->Pop();

		return temp;
	}
	return temp;
}