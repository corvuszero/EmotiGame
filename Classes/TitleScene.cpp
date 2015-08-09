//
//  TitleScene.cpp
//  GoobGame
//
//  Created by Alan Morales on 7/12/15.
//
//

#include "TitleScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* TitleScene::createScene() {
  auto scene = Scene::create();
  auto layer = TitleScene::create();
  scene->addChild(layer);
    
  return scene;
}

bool TitleScene::init() {
  if (!Layer::init()) {
    return false;
  }
    
  Size visibleSize = Director::getInstance()->getVisibleSize();
  
  // Title and Disclaimer
  auto title = Label::createWithTTF("Goob Game", "fonts/PrintChar21.ttf", 70);
  title->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
  this->addChild(title, 0);
  
  auto demoLabel = Label::createWithTTF("Demo", "fonts/PrintChar21.ttf", 35);
  demoLabel->setPosition(Vec2(
    title->getPosition().x,
    title->getPosition().y -
      (title->getContentSize().height / 2) -
      (demoLabel->getContentSize().height / 2) -
      10
  ));
  this->addChild(demoLabel, 0);
  
  // Menu
  auto startLabel = Label::createWithTTF("Start", "fonts/PrintChar21.ttf", 40);
  auto startItem = MenuItemLabel::create(startLabel, [&](Ref* sender) {
    auto gameScene = GameScene::createScene();
    Director::getInstance()->replaceScene(gameScene);
  });
  
  auto mainMenu = Menu::create(startItem, NULL);
  mainMenu->setPosition(Vec2(
    visibleSize.width / 2,
    demoLabel->getPosition().y -
    (demoLabel->getContentSize().height / 2) -
    startLabel->getContentSize().height -
    10
  ));
  
  this->addChild(mainMenu, 0);
  
  return true;
}