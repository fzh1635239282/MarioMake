#include "BaseAI.h"
BaseAI* BaseAI::createAI(BaseObject* object,HRocker* rocker) {
	BaseAI* ai = new BaseAI();
	if (ai && ai->init(object,rocker)) {
		ai->autorelease();
	}
	else {
		CC_SAFE_DELETE(ai);
		return nullptr;
	}

	return ai;
}
bool BaseAI::init(BaseObject* object, HRocker* rocker) {
	baseObject = object;
	baseRocker = rocker;

	return true;
}
void BaseAI::startRoleAI() {
	Director::getInstance()->getScheduler()->schedule(CC_SCHEDULE_SELECTOR
		(BaseAI::updateFunc), this, (float)1 / 60, false);

}
void BaseAI::stopRoleAI() {
	Director::getInstance()->getScheduler()->unschedule(CC_SCHEDULE_SELECTOR
		(BaseAI::updateFunc), this);
}

void BaseAI::updateFunc(float dt) {
	switch (baseObject->type)
	{
	case 1:
		switch (baseRocker->rockerDirection)
		{
		case 0:break;
		case 1:
			if (baseObject->state != OBJECT_MOVE && baseObject->state != OBJECT_TALK) {
				baseObject->state = OBJECT_MOVE;
				baseObject->face = FACE_RIGHT;
				baseObject->getBaseFSM()->changeToMove();
			}
		case 2:break;
		case 3:break;
		case 4:break;
		default:break;
		}
	case 2:
	case 3:
	default:
		break;
	}
}

void BaseAI::purge() {
	stopRoleAI();
	baseObject = nullptr;
	CC_SAFE_RELEASE(this);
}