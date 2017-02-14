#ifndef __superMario__MarioMap__
#define __superMario__MarioMap__

#include <iostream>
#include "editor-support\cocostudio\CCSGUIReader.h"
#include "cocos2d.h"
#include "SceneManager.h"
#include "ui/CocosGUI.h"
#include "SimpleAudioEngine.h"
#include <fstream>
#define SPRITE_NUMBER 36
using namespace CocosDenshion;
using namespace ui;
using namespace std;

USING_NS_CC;
class MakeMapScene :public Layer {
public:
	CREATE_FUNC(MakeMapScene);
	virtual bool init();
	SceneManager * tsm;

	bool isCanScale = false;//�Ƿ�������ŵ�ͼ
	bool isClearSelect = false;//�Ƿ�ѡ����Ƥ��
	bool isCanMoveMap = true;//�Ƿ�����ƶ���ͼ
	int onSelectedSpriteTag = -1;	//���϶�����ı�ǩ
	int toolsFirstSpriteTag = 100;//��������һ������ı�ǩ,�����°�ť�仯
	float scaleDivisor = 1.0;//��ͼ����������
	float pointDistance = -1.0;//�����¼��У�idΪ0�Ĵ�������idΪ1�Ĵ�����ļ��
	char spriteSheet[SPRITE_NUMBER][30];//�����ӦͼƬ���ļ���
	Point realPoint = Point(0.0, 0.0);//�������꣬Ĭ��ֵΪ0,0
	Point moveBeganPoint = Point(0.0, 0.0);//�����¼��У�idΪ0���������ʼλ��
	Map<int, Sprite*> spriteMap;//��ͼ�Ϸ��õľ���������intֵ��Ϊkey
	Widget* ui;//ʹ��UI�༭���༭��UI�ؼ�

	ImageView* background;
	ImageView* toolsFrame;
	Label* pageFlag;
	Button* buttonClear;
	Button* yuliu;
	Button* buttonPageup;
	Button* buttonPagedown;
	//���Ұ�ť,���水ť,�ƶ���ͼ��ť�͵����Ļ�Ļص�����
	void buttonCallBack(Ref * sender, Widget::TouchEventType controlEvent);
	void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
	void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
	void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
	void touchToolsFrame(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
	Rect getRealRect(int tag);
	void touchAddSprite(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
};
#endif
