#include "Deck.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

Deck::Deck() {
	MyDeck = new Stack(BLACKJACKCARDSIZE);
	DeckInit();
}

Deck::~Deck() {
	delete MyDeck;
}

void Deck::DeckInit(void) {
	for (int i = 0; i < 13; i++) {
		MyDeck->Push(Card(i+1, Heart));		// 하트카드 생성
		MyDeck->Push(Card(i+1, Dia));		// 다이아카드 생성
		MyDeck->Push(Card(i+1, Club));		// 클로버카드 생성
		MyDeck->Push(Card(i+1, Spade));		// 스페이드카드 생성
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
	return MyDeck->Pop();
}