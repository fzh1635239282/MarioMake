#ifndef __superMario__OperateLayer__
#define __superMario__OperateLayer__

#include <iostream>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
class OperateLayer :public Layer {
public:
	CREATE_FUNC(OperateLayer);
	virtual bool init();

	void touchCallBack(Ref * sender, Widget::TouchEventType controlEvent);
};

#endif // !__superMario__OperateLayer__
