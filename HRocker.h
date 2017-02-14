#ifndef __superMario__HRocker__
#define __superMario__HRocker__

#include <iostream>
#include "cocos2d.h"
#include "StartScene.h"
USING_NS_CC;
//���ڱ�ʾҡ�˺�ҡ�˱���
typedef enum {
	tag_rocker,
	tag_rockerBG
}tagForHRocker;
typedef enum {
	rocker_stay = 0,	//ҡ�˴�������������
	rocker_right,
	rocker_up,
	rocker_left,
	rocker_down,
}tagDirection;

class HRocker : public Layer {
public://����ҡ�˶���ľ�̬����
	static HRocker * createHRocker(const char * rockerImagName,const char *
		rockerBGImagName,Vec2 position);
	//������ֹͣҡ�˵ļ�������
	void startRocker(bool _isStopOther);
	void stopRocker();

	int rockerDirection;	//ҡ�˳���
	bool rockerRun;			//��ǰ���ﳯ��
	CREATE_FUNC(HRocker);
private://ҡ�˳�ʼ��
	void rockerInit(const char * rockerImagName,const char *
		rockerBGImagName, Vec2 position);

	bool isCanMove;
	//��ȡ��ǰҡ�˺͵�ǰ������Ƕȵķ���
	float getRad(Vec2 pos1, Vec2 pos2);
	//ҡ�˱���������뾶
	Vec2 rockerBGPosition;
	float rockerBGR;

	//�����¼���ص�����
	bool onTouchBegan(Touch * touch, Event * unused_event);
	void onTouchMoved(Touch * touch, Event * unused_event);
	void onTouchEnded(Touch * touch, Event * unused_event);
};

#endif // !__superMario__HRocker__
