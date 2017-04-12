#include "BaseFSM.h"
BaseFSM * BaseFSM::createFSM(BaseObject * object) {
	BaseFSM* baseFSM = new BaseFSM();
	if (baseFSM && baseFSM->init(object)) {
		baseFSM->autorelease();
	}
	else {
		CC_SAFE_DELETE(baseFSM);
		return nullptr;
	}

	return baseFSM;
}
bool BaseFSM::init(BaseObject * object) {
	baseObject = object;

	return true;
}
void BaseFSM::changeToDefault() {
}
void BaseFSM::changeToAttack() {
}
void BaseFSM::changeToMove() {
}
void BaseFSM::changeToDead() {
}
void BaseFSM::changeToFree() {
}
void BaseFSM::changeToTalk() {
}
void BaseFSM::changeToLeft() {
}
void BaseFSM::changeToRight() {
}
void BaseFSM::changeToUp() {
}
void BaseFSM::changeToDown() {
}
void BaseFSM::purge() {
}