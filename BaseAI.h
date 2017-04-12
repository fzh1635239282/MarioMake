#ifndef __forMine__BaseAI__
#define __forMine__BaseAI__

#include "cocos2d.h"
#include "BaseObject.h"
#include "HRocker.h"
USING_NS_CC;

class BaseAI :public Ref {
public:
	static BaseAI * createAI(BaseObject* object, HRocker* rocker);
	bool init(BaseObject* object, HRocker* rocker);
	void startRoleAI();
	void stopRoleAI();
	void updateFunc(float dt);
	void purge();

public:
	BaseObject* baseObject;
	HRocker* baseRocker;
};

#endif // !__forMine__BaseAI__
