#ifndef __superMario__StartScene__
#define __superMario__StartScene__

#include <iostream>
#include "cocos2d.h"
#include "editor-support\cocostudio\CCSGUIReader.h"
#include "SceneManager.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;
using namespace std;

class StartScene :public Layer {
public:
	CREATE_FUNC(StartScene);
	virtual bool init();
	SceneManager* tsm;

	ImageView* _selectIcon;
	TextField* play;
	TextField* make;

	int optionFlag = 1;
	int isVisible = 1;

	void updateCustom(float dt);
	void buttonCallBack(Ref * sender, Widget::TouchEventType controlEvent);
};

#endif // !__superMario__StartScene__

