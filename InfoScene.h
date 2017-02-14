#ifndef __superMario__InfoScene__
#define __superMario__InfoScene__

#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"
#include "Mario.h"
USING_NS_CC;
class InfoScene :public Layer {
public:
	static InfoScene* create(Mario * mario);
	virtual bool init(Mario * mario);

	int nextMap[30][500];
	Mario * mario;
	SceneManager* tsm;
	void onScheduleOnce(float dt);
};

#endif