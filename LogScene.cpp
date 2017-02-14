#include "LogScene.h"
bool LogScene::init() {
	Sprite * flog = Sprite::create("toolPicture3.png");
	flog->setScale(0.5);
	flog->setPosition(Vec2(240, 160));
	this->addChild(flog, 4, 199);

	scheduleOnce(CC_SCHEDULE_SELECTOR(LogScene::onScheduleOnce), 1.5f);

	return true;
}

void LogScene::onScheduleOnce(float dt) {
	tsm->goStartScene();
}