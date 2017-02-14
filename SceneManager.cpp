#include "SceneManager.h"
#include "StartScene.h"
#include "InfoScene.h"
#include "GameScene.h"
#include "MakeMapScene.h"
#include "LogScene.h"
//log����
void SceneManager::createLogScene() {
	logScene = Scene::create();
	LogScene* scene = LogScene::create();
	scene->tsm = this;
	logScene->addChild(scene);
}
//��ʼ����
void SceneManager::goStartScene() {
	startScene = Scene::create();
	StartScene* scene = StartScene::create();
	scene->tsm = this;
	startScene->addChild(scene);
	//���ת��������Ч
	auto startSceneTrans = TransitionFade::create(1.5f, startScene);
	Director::getInstance()->replaceScene(startSceneTrans);
}
//��ɫ��Ϣ����
void SceneManager::goInfoScene(Mario * mario) {
	infoScene = Scene::create();
	InfoScene* scene = InfoScene::create(mario);
	scene->tsm = this;
	infoScene->addChild(scene);
	Director::getInstance()->replaceScene(infoScene);
}
//��Ϸ����
void SceneManager::goGameScene(Mario * mario) {
	gameScene = Scene::create();
	GameScene* scene = GameScene::create(mario);
	scene->tsm = this;
	gameScene->addChild(scene);
	Director::getInstance()->replaceScene(gameScene);
}
//��ͼ����
void SceneManager::goMakeMapScene() {
	makeMapScene = Scene::create();
	MakeMapScene* scene = MakeMapScene::create();
	scene->tsm = this;
	makeMapScene->addChild(scene);
	//���ת��������Ч
	auto makeMapSceneTrans = TransitionFade::create(2.5f, makeMapScene);
	Director::getInstance()->replaceScene(makeMapSceneTrans);
}