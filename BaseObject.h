#ifndef __forMine__BaseObject__
#define __forMine__BaseObject__

#include "cocos2d.h"
#include "BaseAI.h"
#include "BaseFSM.h"
USING_NS_CC;

class BaseFSM;
class BaseAI;
typedef enum {
	TYPE_HERO = 1,
	TYPE_NPC,
	TYPE_BOX,
}OBJECT_TYPE;

typedef enum {
	OBJECT_DEFAULT = 1,
	OBJECT_ATTACK,
	OBJECT_MOVE,
	OBJECT_DEAD,
	OBJECT_FREE,
	OBJECT_TALK,
}OBJECT_STATE;

typedef enum {
	FACE_RANDOM,
	FACE_LEFT,
	FACE_RIGHT,
	FACE_UP,
	FACE_DOWN,
}OBJECT_FACE;

class BaseObject :public Node {
public:
	static BaseObject * createWithProperty(int ID);
	bool init(int ID);

	OBJECT_TYPE type;
	OBJECT_STATE state;
	OBJECT_FACE face;
	CC_SYNTHESIZE(BaseFSM*, baseFSM, BaseFSM);
	CC_SYNTHESIZE(BaseAI*, baseAI, BaseAI);
};

#endif // !__forMine__BaseObject__
