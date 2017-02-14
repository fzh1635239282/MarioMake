#include "Mario.h"
bool Mario::init() {

	setLife(3);
	setHP(1);
	setGrade(0);
	setMoney(0);
	setSpeed(2);
	setGetHitRect(Rect(40,-40,40,40));
	setGetHitPoint(getGetHitRect().origin);
	setWolrd(11);
	setTime(250);

	return true;
}