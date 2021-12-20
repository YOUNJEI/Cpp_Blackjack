#ifndef __STACK_H__
#define __STACK_H__

#include "Card.h"

/*
Deck 구현을 위해 Stack 구조 사용 (배열 기반)
*/

class Stack {
private:
	int Size;
	int cPos;
	Card* stack;

public:
	Stack(int size);
	~Stack();
	bool isFull(void);
	bool isEmpty(void);
	Card Pop(void);
	void Push(Card c);
	int GetSize();
	Card Show();
	
	Card GetCardInfo(int idx);
	void SetCardInfo(int idx, Card c);
};

#endif