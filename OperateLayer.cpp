#include "OperateLayer.h"
#include "StartScene.h"
bool OperateLayer::init() {
	Size winSize = Director::getInstance()->getWinSize();

	Button * buttonAtk = Button::create();
	buttonAtk->loadTextures("atk.png", "");
	buttonAtk->setPosition(Vec2(winSize.width * 5 / 8, winSize.height * 3 / 20));
	buttonAtk->setTag(50);
	this->addChild(buttonAtk);

	Button * buttonJump = Button::create();
	buttonJump->loadTextures("jump.png", "");
	buttonJump->setPosition(Vec2(winSize.width * 7 / 8, winSize.height * 3 / 20));
	buttonJump->setTag(51);
	this->addChild(buttonJump);


	buttonAtk->addTouchEventListener(CC_CALLBACK_2(OperateLayer::touchCallBack,
		this));
	buttonJump->addTouchEventListener(CC_CALLBACK_2(OperateLayer::touchCallBack,
		this));
	return true;
}

void OperateLayer::touchCallBack(Ref * sender, Widget::TouchEventType
	controlEvent) {
	if (controlEvent == Widget::TouchEventType::ENDED) {
		auto button = static_cast<Button*>(sender);
		if (button->getTag() == 51) {
			
		}
	}
}