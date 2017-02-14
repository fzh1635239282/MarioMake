#include "GameScene.h"
#include "HRocker.h"
#include "OperateLayer.h"
GameScene* GameScene::create(Mario * mario) {
	GameScene *pRet = new(std::nothrow) GameScene();
	if (pRet && pRet->init(mario)) {
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return nullptr;
	}
}

bool GameScene::init(Mario * mario) {

	Size winSize = Director::getInstance()->getWinSize();

	auto background = Sprite::create("makeMapBackground.png");
	background->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	this->addChild(background);

	rocker = HRocker::createHRocker("myRocker.png", "myRockerBackground.png", 
		Vec2(winSize.width / 6, winSize.height / 4));
	rocker->startRocker(true);
	this->addChild(rocker);

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

	Button * buttonReturn = Button::create();
	buttonReturn->loadTextures("return.png", "");
	buttonReturn->setPosition(Vec2(winSize.width * 15 / 16,
		winSize.height * 9 / 10));
	buttonReturn->setTag(52);
	this->addChild(buttonReturn);

	buttonAtk->addTouchEventListener(CC_CALLBACK_2(GameScene::buttonCallBack,
		this));
	buttonJump->addTouchEventListener(CC_CALLBACK_2(GameScene::buttonCallBack,
		this));
	buttonReturn->addTouchEventListener(CC_CALLBACK_2(GameScene::buttonCallBack,
		this));

	Director::getInstance()->getScheduler()->schedule(schedule_selector
		(GameScene::update), this, (float)1 / 60, false);

	return true;
}

void GameScene::update(float dt) {

}
void GameScene::buttonCallBack(Ref * sender, Widget::TouchEventType
	controlEvent) {
	if (controlEvent == Widget::TouchEventType::ENDED &&
		((Button*)sender)->getTag() == 52) {
		tsm->goStartScene();
	}
}