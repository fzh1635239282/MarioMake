#include "InfoScene.h"
#include "Mario.h"
InfoScene* InfoScene::create(Mario * mario) {
	InfoScene *pRet = new(std::nothrow) InfoScene();
	if (pRet && pRet->init(mario)) {
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return nullptr;
	}
}

bool InfoScene::init(Mario * mario) {
	this->mario = mario;
	Size winSize = Director::getInstance()->getWinSize();
	Label * labelKeyGrade = Label::createWithSystemFont("MARIO","marioFonts.ttf",14);
	labelKeyGrade->setAnchorPoint(Vec2(0, 0));
	labelKeyGrade->setPosition(Vec2(winSize.width * 1.48 / 10, winSize.height * 19 / 20));
	labelKeyGrade->setColor(Color3B::WHITE);
	this->addChild(labelKeyGrade);
	
	char str[7];
	int grade = mario->getGrade();
	for (int i = 0;i < 6;i++) {
		str[5-i] = grade % 10 + 48;
		grade /= 10;
	}
	str[6]='\0';
	Label * labelGrade = Label::createWithSystemFont(str, "marioFonts.ttf", 14);
	labelGrade->setAnchorPoint(Vec2(0, 0));
	labelGrade->setPosition(Vec2(winSize.width * 1.48 / 10, winSize.height * 18 / 20));
	labelGrade->setColor(Color3B::WHITE);
	this->addChild(labelGrade);

	Sprite * money = Sprite::create("money.png");
	money->setAnchorPoint(Vec2(0, 0));
	money->setPosition(Vec2(winSize.width * 3.67 / 10, winSize.height * 18 / 20));
	this->addChild(money);

	int money_number = mario->getMoney();
	str[0] = 'x';
	for (int i = 1;i < 3;i++) {
		str[5 - i] = money_number % 10 + 48;
		money_number /= 10;
	}
	str[3] = '\0';
	Label * labelMoney = Label::createWithSystemFont(str, "marioFonts.ttf", 14);
	labelMoney->setAnchorPoint(Vec2(0, 0));
	labelMoney->setPosition(Vec2(winSize.width * 3.91 / 10, winSize.height * 18 / 20));
	labelMoney->setColor(Color3B::WHITE);
	this->addChild(labelMoney);
	
	Label * labelKeyWorld = Label::createWithSystemFont("WORLD", "marioFonts.ttf", 14);
	labelKeyWorld->setAnchorPoint(Vec2(0, 0));
	labelKeyWorld->setPosition(Vec2(winSize.width * 5.52 / 10, winSize.height * 19 / 20));
	labelKeyWorld->setColor(Color3B::WHITE);
	this->addChild(labelKeyWorld);
	Label * labelKeyWorldBig = Label::createWithSystemFont("WORLD", "marioFonts.ttf", 16);
	labelKeyWorldBig->setAnchorPoint(Vec2(0, 0));
	labelKeyWorldBig->setPosition(Vec2(winSize.width * 3.88 / 10, winSize.height * 13.26 / 20));
	labelKeyWorldBig->setColor(Color3B::WHITE);
	this->addChild(labelKeyWorldBig);


	int world = mario->getWolrd();
	str[0] = world / 10 + 48;
	str[1] = '-';
	str[2] = world % 10 + 48;
	str[3] = '\0';
	Label * labelWorld = Label::createWithSystemFont(str, "marioFonts.ttf", 16);
	labelWorld->setAnchorPoint(Vec2(0, 0));
	labelWorld->setPosition(Vec2(winSize.width * 5 / 10, winSize.height * 18 / 20));
	labelWorld->setColor(Color3B::WHITE);
	this->addChild(labelWorld);
	Label * labelWorldBig = Label::createWithSystemFont(str, "marioFonts.ttf", 14);
	labelWorldBig->setAnchorPoint(Vec2(0, 0));
	labelWorldBig->setPosition(Vec2(winSize.width * 5.28 / 10, winSize.height * 13.26 / 20));
	labelWorldBig->setColor(Color3B::WHITE);
	this->addChild(labelWorldBig);


	Label * labelKeyTime = Label::createWithSystemFont("TIME", "marioFonts.ttf", 14);
	labelKeyTime->setAnchorPoint(Vec2(0, 0));
	labelKeyTime->setPosition(Vec2(winSize.width * 7.4 / 10, winSize.height * 19 / 20));
	labelKeyTime->setColor(Color3B::WHITE);
	this->addChild(labelKeyTime);

	int time = mario->getTime();
	str[0] = time / 100 % 10 + 48;
	str[1] = time / 10 % 10 + 48;
	str[2] = time % 10 + 48;
	str[3] = '\0';
	Label * labelTime = Label::createWithSystemFont(str, "marioFonts.ttf", 14);
	labelTime->setAnchorPoint(Vec2(0, 0));
	labelTime->setPosition(Vec2(winSize.width * 7.55 / 10, winSize.height * 18 / 20));
	labelTime->setColor(Color3B::WHITE);
	this->addChild(labelTime);

	Sprite * infoMario = Sprite::create("marioSmall_default.png");
	infoMario->setAnchorPoint(Vec2(0, 0));
	infoMario->setPosition(Vec2(winSize.width * 3.75 / 10, winSize.height * 10 / 20));
	this->addChild(infoMario);

	int life = mario->getLife();
	str[0] = 'x';
	str[1] = ' ';
	str[2] = life / 10 % 10 >= 1 ? life / 10 % 10 + 48 : ' ';
	str[3] = life % 10 + 48;
	str[4] = '\0';
	Label * labelLife = Label::createWithSystemFont(str, "marioFonts.ttf", 20);
	labelLife->setAnchorPoint(Vec2(0, 0));
	labelLife->setPosition(Vec2(winSize.width * 4.8 / 10, winSize.height * 10 / 20));
	labelLife->setColor(Color3B::WHITE);
	this->addChild(labelLife);


	scheduleOnce(CC_SCHEDULE_SELECTOR(InfoScene::onScheduleOnce), 2);

	return true;
}

void InfoScene::onScheduleOnce(float dt) {

	tsm->goGameScene(mario);
}