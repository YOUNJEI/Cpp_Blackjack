#include "Card.h"
#include <iostream>

using namespace std;

// Card 클래스 기본 생성자 (Default: 0 | Heart)
Card::Card() {
	this->cardValue = 0;
	this->cType = Heart;
}

// Card 클래스 생성자 (멤버변수 초기화)
Card::Card(int cV, int cT) {
	this->cardValue = cV;
	this->cType = cT;
}

// Card 클래스 복사 생성자
Card::Card(const Card& origin) {
	this->cardValue = origin.cardValue;
	this->cType = origin.cType;
}

// Card 클래스 소멸자
Card::~Card() {};

// 멤버변수 cardValue Set 함수
void Card::SetValue(int v) {
	this->cardValue = v;
}

// 멤버변수 cType Set 함수
void Card::SetType(int v) {
	this->cType = v;
}

// 멤버변수 cardValue Get 함수
int Card::GetValue(void) {
	return this->cardValue;
}

// 멤버변수 cType Get 함수
int Card::GetType(void) {
	return this->cType;
}

// Card 출력 함수 (format eg) "하트1"
void Card::Print(void) {
	switch (cType) {
	case 1:
		cout << "하트";
		break;

	case 2:
		cout << "다이아";
		break;

	case 3:
		cout << "클로버";
		break;

	case 4:
		cout << "스페이드";
		break;

	default:
		cout << "X";
		break;
	}

	cout << cardValue;
}