#ifndef __superMario__SceneManager__
#define __superMario__SceneManager__

#include <iostream>
#include "cocos2d.h"
#include "Mario.h"
USING_NS_CC;
class SceneManager {
public:
	Scene* startScene;
	Scene* infoScene;
	Scene* gameScene;
	Scene* makeMapScene;
	Scene* logScene;

	void createLogScene();
	void goStartScene();
	void goInfoScene(Mario * mario);
	void goGameScene(Mario * mario);
	void goMakeMapScene();
};

#endif // !__superMario__SceneManager__
