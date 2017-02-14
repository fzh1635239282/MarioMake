#include "SceneManager.h"
#include "StartScene.h"
#include "InfoScene.h"
#include "GameScene.h"
#include "MakeMapScene.h"
#include "LogScene.h"
//log界面
void SceneManager::createLogScene() {
	logScene = Scene::create();
	LogScene* scene = LogScene::create();
	scene->tsm = this;
	logScene->addChild(scene);
}
//开始界面
void SceneManager::goStartScene() {
	startScene = Scene::create();
	StartScene* scene = StartScene::create();
	scene->tsm = this;
	startScene->addChild(scene);
	//添加转换场景特效
	auto startSceneTrans = TransitionFade::create(1.5f, startScene);
	Director::getInstance()->replaceScene(startSceneTrans);
}
//角色信息界面
void SceneManager::goInfoScene(Mario * mario) {
	infoScene = Scene::create();
	InfoScene* scene = InfoScene::create(mario);
	scene->tsm = this;
	infoScene->addChild(scene);
	Director::getInstance()->replaceScene(infoScene);
}
//游戏界面
void SceneManager::goGameScene(Mario * mario) {
	gameScene = Scene::create();
	GameScene* scene = GameScene::create(mario);
	scene->tsm = this;
	gameScene->addChild(scene);
	Director::getInstance()->replaceScene(gameScene);
}
//制图界面
void SceneManager::goMakeMapScene() {
	makeMapScene = Scene::create();
	MakeMapScene* scene = MakeMapScene::create();
	scene->tsm = this;
	makeMapScene->addChild(scene);
	//添加转换场景特效
	auto makeMapSceneTrans = TransitionFade::create(2.5f, makeMapScene);
	Director::getInstance()->replaceScene(makeMapSceneTrans);
}