#ifndef __superMario__GameScene__
#define __superMario__GameScene__

#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"
#include "HRocker.h"
#include "OperateLayer.h"

USING_NS_CC;
class GameScene :public Layer {
public:
	static GameScene* create(Mario * mario);
	virtual bool init(Mario * mario);
	int map[30][500];

	SceneManager * tsm;
	HRocker * rocker;
	OperateLayer * operateLayer;

	void update(float dt);
	void buttonCallBack(Ref * sender, Widget::TouchEventType
		controlEvent);
};
#endif // !__superMario__GameScene__
