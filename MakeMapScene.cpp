#include "MakeMapScene.h"

bool MakeMapScene::init() {
	//������Ч
	SimpleAudioEngine::sharedEngine()->preloadEffect("makeMap1.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("makeMap2.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("makeMap3.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("makeMap4.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("makeMap5.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("makeMap6.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect("makeMap7.mp3");
/**************************����UI������UI����������Ϊfalse������UI��������Ļ�Ĵ����¼�**************************/
	ui = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("MakeMapScene_1.ExportJson");
	ui->setSwallowTouches(false);
	this->addChild(ui);
	background = (ImageView*)Helper::seekWidgetByName(ui, "background");
	toolsFrame = (ImageView*)Helper::seekWidgetByName(ui, "toolsFrame");
	Button* buttonSave = (Button*)Helper::seekWidgetByName(ui, "buttonSave");
	Button* buttonReturn = (Button*)Helper::seekWidgetByName(ui, "buttonReturn");
	buttonClear = (Button*)Helper::seekWidgetByName(ui, "buttonClear");
	yuliu = (Button*)Helper::seekWidgetByName(ui, "yuliu");
	buttonPageup = (Button*)Helper::seekWidgetByName(ui, "buttonPageup");
	buttonPagedown = (Button*)Helper::seekWidgetByName(ui, "buttonPagedown");
	buttonPageup->setEnabled(false);
	//����ť��ӻص�����
	buttonSave->addTouchEventListener(CC_CALLBACK_2(MakeMapScene::buttonCallBack, this));
	buttonReturn->addTouchEventListener(CC_CALLBACK_2(MakeMapScene::buttonCallBack, this));
	buttonClear->addTouchEventListener(CC_CALLBACK_2(MakeMapScene::buttonCallBack, this));
	yuliu->addTouchEventListener(CC_CALLBACK_2(MakeMapScene::buttonCallBack, this));
	buttonPageup->addTouchEventListener(CC_CALLBACK_2(MakeMapScene::buttonCallBack, this));
	buttonPagedown->addTouchEventListener(CC_CALLBACK_2(MakeMapScene::buttonCallBack, this));
	//��ӹ�����ҳ����ǩ
	pageFlag = Label::create("1", "marioFonts.ttf", 20);
	pageFlag->setPosition(Vec2(295, 290));
	pageFlag->setColor(Color3B(0, 255, 255));
	this->addChild(pageFlag, 2, 97);
	//��Ӳü�ģ��
	auto stencil = Sprite::create("toolsClipping.png");
	auto cli = ClippingNode::create();
	cli->setStencil(stencil);
	cli->setInverted(false);
	cli->setAlphaThreshold(1);
	this->addChild(cli,2,96);
	auto content = Sprite::create("toolsBackground.png");
	cli->addChild(content);
	cli->setPosition(Vec2(160, 290));
	content->setPosition(Vec2(0, -125));
	content->setTag(95);
	//��Ӿ��鱻ѡ��ʱ�ı�־����
	auto frame = Sprite::create("frame.png");
	frame->setPositionY(290);
	frame->setVisible(false);
	this->addChild(frame, 2, 94);
	//�����嵥��ȡ
	ifstream reader;
	reader.open("makeMapSceneToolsFrameSpriteSheet.txt");
	for (int i = 0; i < SPRITE_NUMBER; i++) {
		reader >> spriteSheet[i];
	}
	reader.close();
	//����һ����㴥�������¼�
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(MakeMapScene::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(MakeMapScene::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(MakeMapScene::onTouchesEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}
//���UI�ؼ���ռ�ľ��η�Χ
Rect MakeMapScene::getRealRect(int tag) {
	auto sprite = (Node*)Helper::seekWidgetByTag(ui,tag);
	Rect realRect = Rect(sprite->getPositionX() - sprite->getContentSize().width / 2, sprite->getPositionY() -
		sprite->getContentSize().height / 2, sprite->getContentSize().width, sprite->getContentSize().height);
	return realRect;
}
//���������
void MakeMapScene::touchToolsFrame(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) {
	if (isCanMoveMap) {
		onSelectedSpriteTag = toolsFirstSpriteTag + (int)(moveBeganPoint.x - 40) / 40;
		auto frame = (Sprite*)this->getChildByTag(94);
		frame->setPositionX(60 + (int)(moveBeganPoint.x - 40) / 40 * 40);
		frame->setVisible(true);
		isCanMoveMap = false;
		isClearSelect = false;
		buttonClear->loadTextures("clear.png", "");
	}
	else {
		if (onSelectedSpriteTag == (toolsFirstSpriteTag + (int)(moveBeganPoint.x - 40) / 40)) {
			onSelectedSpriteTag = -1;
			auto frame = (Sprite*)this->getChildByTag(94);
			frame->setVisible(false);
			isCanMoveMap = true;
		}
		else {
			onSelectedSpriteTag = toolsFirstSpriteTag + (int)(moveBeganPoint.x - 40) / 40;
			auto frame = (Sprite*)this->getChildByTag(94);
			frame->setPositionX(60 + (int)(moveBeganPoint.x - 40) / 40 * 40);
			frame->setVisible(true);
		}
		isClearSelect = false;
		buttonClear->loadTextures("clear.png", "");
	}
}
//�����Ļ��Ӿ���
void MakeMapScene::touchAddSprite(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) {
	Point point = Director::getInstance()->convertToGL(touches.at(0)->getStartLocationInView());
	if (isCanMoveMap == 0 && isClearSelect == 0 && !getRealRect(99).containsPoint(point) &&
		!getRealRect(52).containsPoint(point) && !getRealRect(53).containsPoint(point) && 
		!getRealRect(54).containsPoint(point) && !getRealRect(55).containsPoint(point) && 
		!getRealRect(56).containsPoint(point) && !getRealRect(57).containsPoint(point)) {
		for (auto touch : touches) {
			auto onTouchSprite = Sprite::create(spriteSheet[onSelectedSpriteTag-100]);
			int onTouchSpriteX = (int)onTouchSprite->getContentSize().width / 32;
			int onTouchSpriteY = (int)onTouchSprite->getContentSize().height / 32;
			int isExist = 0;
			int maxTag = 5000;
			int minTag = 35500;
			for (int i = 0; i < onTouchSpriteX; i++) {
				for (int j = 0; j < onTouchSpriteY; j++) {
					int tag;
					if ((int)(realPoint.y + point.y) / 16 % 2 == 1) {
						if ((int)(realPoint.x + point.x) / 16 % 2 == 1) {
							tag = ((int)(realPoint.y + point.y) / 32 + 5 + i) * 1000 + (int)(realPoint.x + point.x) / 32 + j;
						}
						else {
							tag = ((int)(realPoint.y + point.y) / 32 + 5 + i) * 1000 + (int)(realPoint.x + point.x) / 32 - j;
						}
					}
					else {
						if ((int)(realPoint.x + point.x) / 16 % 2 == 1) {
							tag = ((int)(realPoint.y + point.y) / 32 + 5 - i) * 1000 + (int)(realPoint.x + point.x) / 32 + j;
						}
						else {
							tag = ((int)(realPoint.y + point.y) / 32 + 5 - i) * 1000 + (int)(realPoint.x + point.x) / 32 - j;
						}
					}
					if (maxTag < tag)
						maxTag = tag;
					if (minTag > tag)
						minTag = tag;
					auto sprite = (Sprite*)this->getChildByTag(tag);
					if (sprite != nullptr)
						isExist = 1;
				}
			}
			if (isExist == 0) {
				for (int i = 0; i < onTouchSpriteX; i++) {
					for (int j = 0; j < onTouchSpriteY; j++) {
						int tag;
						if ((int)(realPoint.y + point.y) / 16 % 2 == 1) {
							if ((int)(realPoint.x + point.x) / 16 % 2 == 1) {
								tag = ((int)(realPoint.y + point.y) / 32 + 5 + i) * 1000 + (int)(realPoint.x + point.x) / 32 + j;
							}
							else {
								tag = ((int)(realPoint.y + point.y) / 32 + 5 + i) * 1000 + (int)(realPoint.x + point.x) / 32 - j;
							}
						}
						else {
							if ((int)(realPoint.x + point.x) / 16 % 2 == 1) {
								tag = ((int)(realPoint.y + point.y) / 32 + 5 - i) * 1000 + (int)(realPoint.x + point.x) / 32 + j;
							}
							else {
								tag = ((int)(realPoint.y + point.y) / 32 + 5 - i) * 1000 + (int)(realPoint.x + point.x) / 32 - j;
							}
						}
						if (onTouchSpriteX == 1 && onTouchSpriteY == 1) {
							auto newSprite = Sprite::create(onTouchSprite->getResourceName());
							newSprite->setPosition(Vec2(tag % 1000 * 32 + newSprite->getContentSize().width / 2 - realPoint.x, (tag / 1000 - 5) * 32 + newSprite->getContentSize().height / 2 - realPoint.y));
							newSprite->setTag(tag);
							this->addChild(newSprite);
						}
						else {
							if (maxTag == tag) {
								auto newSprite = Sprite::create(onTouchSprite->getResourceName());
								newSprite->setPosition(Vec2(minTag % 1000 * 32 + newSprite->getContentSize().width / 2 - realPoint.x, (minTag / 1000 - 5) * 32 + newSprite->getContentSize().height / 2 - realPoint.y));
								newSprite->setTag(tag);
								this->addChild(newSprite);
							}
							else {
								auto newSprite = Sprite::create("lucency.png");
								newSprite->setPosition(Vec2(tag % 1000 * 32 + newSprite->getContentSize().width / 2 - realPoint.x, (tag / 1000 - 5) * 32 + newSprite->getContentSize().height / 2 - realPoint.y));
								newSprite->setTag(tag);
								this->addChild(newSprite);
							}
						}
					}
				}
			}
		}
	}
}

void MakeMapScene::onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) {
	Touch* touch = touches.at(0);
	moveBeganPoint = Director::getInstance()->convertToGL(touch->getStartLocationInView());
	if (toolsFrame->getBoundingBox().containsPoint(moveBeganPoint) && moveBeganPoint.x >= 40.0 && moveBeganPoint.x <= 280) {
		this->touchToolsFrame(touches, event);//�����toolsFrame
	}
	else {
		if (!isCanMoveMap && !isClearSelect) {//�ڵ�ͼ����Ӿ���
			this->touchAddSprite(touches, event);
		}
	}	
}
void MakeMapScene::onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) {
	//�������ƶ���ͼʱ�Ĵ��������Ͳ������ƶ���ͼʱ�Ĵ�������
	if (isCanMoveMap) {
		if (touches.size() == 1) {//��ȷ����Ļ��ֻ��һ��������ʱ���ƶ���ͼλ��
			//��ȡidΪ0�Ĵ����㣻�����������ꡢ��ͼλ�á�����λ�ò��ƶ��¼��տ�ʼ������
			Touch* touch = touches.at(0);
			float x = (moveBeganPoint.x - Director::getInstance()->convertToGL(touch->getLocationInView()).x) / scaleDivisor;
			float y = (moveBeganPoint.y - Director::getInstance()->convertToGL(touch->getLocationInView()).y) / scaleDivisor;
			if ((realPoint.x + x) < 0) {
				realPoint.x = 0;
			}
			else if ((realPoint.x + x) > 15520) {
				realPoint.x = 15520;
			}
			else {
				realPoint.x += x;
			}
			if ((realPoint.y + y) < 0) {
				realPoint.y = 0;
			}
			else if ((realPoint.y + y) > 1280) {
				realPoint.y = 1280;
			}
			else {
				realPoint.y += y;
			}
			background->setPosition(Vec2(-(realPoint.x - (int)realPoint.x / 32 * 32)*scaleDivisor, -(realPoint.y - (int)realPoint.y / 32 * 32)*scaleDivisor));
			moveBeganPoint = Director::getInstance()->convertToGL(touch->getLocationInView());
			for (auto key : spriteMap.keys()) {
				spriteMap.at(key)->setPosition((Vec2(key % 1000 * 32 + 16, (key - 5000) / 1000 * 32 + 16) - realPoint)*scaleDivisor);
			}
		}
		else {//����ͼ�����������������ϵĴ�����ʱ����ȡidΪ0��idΪ1�Ĵ����㣬�������ʵ����ָ����Ч��
			Touch* touch0 = touches.at(0);
			Touch* touch1 = touches.at(1);
			float currentPointDistance;
			currentPointDistance = Director::getInstance()->convertToGL(touch0->getLocationInView()).getDistance(Director::getInstance()->convertToGL(touch1->getLocationInView()));
			if (pointDistance <= 0) {
				pointDistance = currentPointDistance;
			}
			if ((scaleDivisor - (pointDistance - currentPointDistance) * 0.004) > 1.0) {
				scaleDivisor = 1.0;
			}
			else if ((scaleDivisor - (pointDistance - currentPointDistance) * 0.004) < 0.5) {
				scaleDivisor = 0.5;
			}
			else {
				scaleDivisor -= (pointDistance - currentPointDistance) * 0.004;
			}
			pointDistance = currentPointDistance;
			background->setScale(scaleDivisor);//���±�����ͼ�����Ŵ�С��λ���Լ���������Ŵ�С��λ��
			background->setPosition(Vec2(-(realPoint.x - (int)realPoint.x / 32 * 32)*scaleDivisor, -(realPoint.y - (int)realPoint.y / 32 * 32)*scaleDivisor));
			for (auto key : spriteMap.keys()) {
				spriteMap.at(key)->setScale(scaleDivisor);
			}
			for (auto key : spriteMap.keys()) {
				spriteMap.at(key)->setPosition((Vec2(key % 1000 * 32 + 16, (key - 5000) / 1000 * 32 + 16) - realPoint)*scaleDivisor);
			}
		}
	}
	else {//�ڵ�ͼ����Ӿ���
		if (!isClearSelect) {
			this->touchAddSprite(touches, event);
		}
	}
}
void MakeMapScene::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event) {
	pointDistance = -1.0;
}

void MakeMapScene::buttonCallBack(Ref * sender, Widget::TouchEventType
	controlEvent) {
	if (controlEvent == Widget::TouchEventType::ENDED &&
		((Button*)sender)->getTag() == 52) {//�������Ϸ���ť
		SimpleAudioEngine::sharedEngine()->playEffect("makeMap5.mp3", false);
		auto  cli = (ClippingNode*)this->getChildByTag(96);
		cli->getChildByTag(95)->runAction(MoveBy::create(0.8f, Vec2(0, -50)));
		toolsFirstSpriteTag -= 6;
		if (onSelectedSpriteTag != -1) {
			onSelectedSpriteTag -= 6;
		}
		char c[2];
		c[0] = (toolsFirstSpriteTag - 100) / 6 + 1 + 48;
		c[1] = '\0';
		pageFlag->setString(c);
		if (toolsFirstSpriteTag == 100)
			buttonPageup->setEnabled(false);
		if (toolsFirstSpriteTag < 130)
			buttonPagedown->setEnabled(true);
	}
	else if (controlEvent == Widget::TouchEventType::ENDED &&
		((Button*)sender)->getTag() == 53) {//�������·���ť
		SimpleAudioEngine::sharedEngine()->playEffect("makeMap5.mp3", false);
		auto  cli = (ClippingNode*)this->getChildByTag(96);
		cli->getChildByTag(95)->runAction(MoveBy::create(0.8f, Vec2(0, 50)));
		toolsFirstSpriteTag += 6;
		if (onSelectedSpriteTag != -1) {
			onSelectedSpriteTag += 6;
		}
		char c[2];
		c[0] = (toolsFirstSpriteTag - 100) / 6 + 1 + 48;
		c[1] = '\0';
		pageFlag->setString(c);
		if (toolsFirstSpriteTag == 130)
			buttonPagedown->setEnabled(false);
		if (toolsFirstSpriteTag > 100)
			buttonPageup->setEnabled(true);
	}
	else if (controlEvent == Widget::TouchEventType::ENDED &&
		((Button*)sender)->getTag() == 54) {//�����ͼ��ť
	}
	else if (controlEvent == Widget::TouchEventType::ENDED &&
		((Button*)sender)->getTag() == 55) {//���ذ�ť���£��ص���ʼ��Ϸ����
		tsm->goStartScene();
	}
	else if (controlEvent == Widget::TouchEventType::ENDED &&
		((Button*)sender)->getTag() == 56) {//�����ť�����ڲ������о���
		SimpleAudioEngine::sharedEngine()->playEffect("makeMap4.mp3", false);
		if (isClearSelect) {
			isClearSelect = false;
			isCanMoveMap = true;
			buttonClear->loadTextures("clear.png", "");
		}
		else {
			isClearSelect = true;
			isCanMoveMap = false;
			buttonClear->loadTextures("clear_select.png", "");
		}
		auto frame = (Sprite*)this->getChildByTag(94);
		frame->setVisible(false);
		onSelectedSpriteTag = -1;
	}
	else if (controlEvent == Widget::TouchEventType::ENDED &&
		((Button*)sender)->getTag() == 57) {//Ԥ����ť
	}
}