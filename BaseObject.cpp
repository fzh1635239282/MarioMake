#include "BaseObject.h"
BaseObject * BaseObject::createWithProperty(int ID) {
	BaseObject* object = new BaseObject();
	if (object && object->init(ID)) {
		object->autorelease();
	}
	else {
		CC_SAFE_DELETE(object);
		return nullptr;
	}
	return object;
}
bool BaseObject::init(int ID) {
	switch (ID) {
	case 1:type = TYPE_HERO; break;
	case 2:type = TYPE_NPC; break;
	case 3:type = TYPE_BOX; break;
	default:type = TYPE_HERO;
	}
	state = OBJECT_DEFAULT;
	face = FACE_RANDOM;
	return true;
}
