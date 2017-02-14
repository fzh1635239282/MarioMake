#ifndef __superMario__Mario__
#define __superMario__Mario__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

typedef enum {
	FACE_RIGHT = 1,
	FACE_LEFT,
	FACE_DOWN,
}MARIO_FACE;

class Mario : public Node {
public:
	CREATE_FUNC(Mario);
	virtual bool init();

	MARIO_FACE face = FACE_RIGHT;
	//属性
	CC_SYNTHESIZE(int, Life, Life);
	CC_SYNTHESIZE(int, HP, HP);
	CC_SYNTHESIZE(int, Grade, Grade);
	CC_SYNTHESIZE(int, Money, Money);
	CC_SYNTHESIZE(int, Speed, Speed);

	//受击框及起始坐标
	CC_SYNTHESIZE(Rect, GetHitRect, GetHitRect);
	CC_SYNTHESIZE(Point, GetHitPoint, GetHitPoint);

	CC_SYNTHESIZE(int, Wolrd, Wolrd);
	CC_SYNTHESIZE(int, Time, Time);
};
#endif // !__superMario__Mario__
