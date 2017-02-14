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

	bool isCanScale = false;//是否可以缩放地图
	bool isClearSelect = false;//是否选中橡皮擦
	bool isCanMoveMap = true;//是否可以移动地图
	int onSelectedSpriteTag = -1;	//被拖动精灵的标签
	int toolsFirstSpriteTag = 100;//工具栏第一个精灵的标签,随上下按钮变化
	float scaleDivisor = 1.0;//地图的缩放因子
	float pointDistance = -1.0;//触摸事件中，id为0的触碰点与id为1的触碰点的间距
	char spriteSheet[SPRITE_NUMBER][30];//精灵对应图片的文件名
	Point realPoint = Point(0.0, 0.0);//世界坐标，默认值为0,0
	Point moveBeganPoint = Point(0.0, 0.0);//触摸事件中，id为0触碰点的起始位置
	Map<int, Sprite*> spriteMap;//地图上放置的精灵容器，int值作为key
	Widget* ui;//使用UI编辑器编辑的UI控件

	ImageView* background;
	ImageView* toolsFrame;
	Label* pageFlag;
	Button* buttonClear;
	Button* yuliu;
	Button* buttonPageup;
	Button* buttonPagedown;
	//左右按钮,保存按钮,移动地图按钮和点击屏幕的回调函数
	void buttonCallBack(Ref * sender, Widget::TouchEventType controlEvent);
	void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
	void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
	void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
	void touchToolsFrame(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
	Rect getRealRect(int tag);
	void touchAddSprite(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
};
#endif
