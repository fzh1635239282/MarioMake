#ifndef __forMine__BaseFSM__
#define __forMine__BaseFSM__

#include "cocos2d.h"
#include "BaseObject.h"
USING_NS_CC;

class BaseFSM :public Ref {
public:
	static BaseFSM * createFSM(BaseObject * object);
	bool init(BaseObject * object);

public:
	void changeToDefault();
	void changeToAttack();
	void changeToMove();
	void changeToDead();
	void changeToFree();
	void changeToTalk();
	void changeToLeft();
	void changeToRight();
	void changeToUp();
	void changeToDown();
	void purge();
	
public:
	BaseObject * baseObject;
};

#endif // !__forMine__BaseFSM__
