#include "StartScene.h"
#include "Mario.h"
bool StartScene::init() {
	auto ui = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("StartScene_1.ExportJson");
	this->addChild(ui);
	Button* atk = (Button*)Helper::seekWidgetByName(ui, "atk");
	Button* jump = (Button*)Helper::seekWidgetByName(ui, "jump");
	Button* close = (Button*)Helper::seekWidgetByName(ui, "close");
	_selectIcon = (ImageView*)Helper::seekWidgetByName(ui, "_selectIcon");
	play = (TextField*)Helper::seekWidgetByName(ui, "play");
	make = (TextField*)Helper::seekWidgetByName(ui, "make");

	atk->addTouchEventListener(CC_CALLBACK_2(StartScene::buttonCallBack, this));
	jump->addTouchEventListener(CC_CALLBACK_2(StartScene::buttonCallBack, this));
	close->addTouchEventListener(CC_CALLBACK_2(StartScene::buttonCallBack, this));

	//每0.6秒触发一次的调度器,用于标题的闪烁
	schedule(CC_SCHEDULE_SELECTOR(StartScene::updateCustom), 0.6f);

	return true;
}

void StartScene::buttonCallBack(Ref * sender, Widget::TouchEventType controlEvent) {
	if (controlEvent == Widget::TouchEventType::ENDED && ((Button*)sender)->getTag() == 51) {
		Mario * mario = Mario::create();
		if (optionFlag == 1)
			tsm->goInfoScene(mario);
		else
			tsm->goMakeMapScene();
	}
	else if (controlEvent == Widget::TouchEventType::ENDED && ((Button*)sender)->getTag() == 50) {
		if (optionFlag == 1) {
			_selectIcon->setPosition(Vec2(145, 128));
			optionFlag = 0;
			isVisible = 1;
			play->setVisible(true);
		}
		else {
			_selectIcon->setPosition(Vec2(145, 154));
			optionFlag = 1;
			isVisible = 1;
			make->setVisible(true);
		}
	}
	else if (controlEvent == Widget::TouchEventType::ENDED && ((Button*)sender)->getTag() == 52) {
		Director::getInstance()->end();
	}
	return;
}

//实现标题的闪烁
void StartScene::updateCustom(float dt) {
	if (optionFlag == 1) {
		if (isVisible == 1) {
			play->setVisible(false);
			isVisible = 0;
		}
		else {
			play->setVisible(true);
			isVisible = 1;
		}
	}
	else {
		if (isVisible == 1) {
			make->setVisible(false);
			isVisible = 0;
		}
		else {
			make->setVisible(true);
			isVisible = 1;
		}
	}

}
