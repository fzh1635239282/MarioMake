#ifndef __superMario__HRocker__
#define __superMario__HRocker__

#include <iostream>
#include "cocos2d.h"
#include "StartScene.h"
USING_NS_CC;
//用于标示摇杆和摇杆背景
typedef enum {
	tag_rocker,
	tag_rockerBG
}tagForHRocker;
typedef enum {
	rocker_stay = 0,	//摇杆待机，上下左右
	rocker_right,
	rocker_up,
	rocker_left,
	rocker_down,
}tagDirection;

class HRocker : public Layer {
public://创建摇杆对象的静态方法
	static HRocker * createHRocker(const char * rockerImagName,const char *
		rockerBGImagName,Vec2 position);
	//启动与停止摇杆的监听方法
	void startRocker(bool _isStopOther);
	void stopRocker();

	int rockerDirection;	//摇杆朝向
	bool rockerRun;			//当前人物朝向
	CREATE_FUNC(HRocker);
private://摇杆初始化
	void rockerInit(const char * rockerImagName,const char *
		rockerBGImagName, Vec2 position);

	bool isCanMove;
	//获取当前摇杆和当前触摸点角度的方法
	float getRad(Vec2 pos1, Vec2 pos2);
	//摇杆背景坐标与半径
	Vec2 rockerBGPosition;
	float rockerBGR;

	//触摸事件与回调方法
	bool onTouchBegan(Touch * touch, Event * unused_event);
	void onTouchMoved(Touch * touch, Event * unused_event);
	void onTouchEnded(Touch * touch, Event * unused_event);
};

#endif // !__superMario__HRocker__
