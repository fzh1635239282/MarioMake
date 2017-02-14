#ifndef __superMario__LogScene__
#define __superMario__LogScene__

#include <iostream>
#include "cocos2d.h"
#include "SceneManager.h"
USING_NS_CC;

class LogScene :public Layer {
public:
	CREATE_FUNC(LogScene);
	virtual bool init();
	SceneManager* tsm;

	void onScheduleOnce(float dt);
};


#endif // !__superMario__logScene__
