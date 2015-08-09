//
//  GameScene.cpp
//  GoobGame
//
//  Created by Alan Morales on 7/12/15.
//
//

#include "GameScene.h"
#include "TileSprite.h"
#include "BoardSprite.h"

USING_NS_CC;

Scene* GameScene::createScene() {
  auto scene = Scene::create();
  auto layer = GameScene::create();
  scene->addChild(layer);
  
  return scene;
}

bool GameScene::init() {
  if (!Layer::init()) {
    return false;
  }

  Size visibleSize = Director::getInstance()->getVisibleSize();
  
  /*
  auto heart = TileSprite::create("❤️");
  heart->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
  this->addChild(heart);
  CCLOG("Agregamos corazon!");
  */
  
  auto board = BoardSprite::create();
  board->setPosition(Vec2(40, 40));
  this->addChild(board);
  
  return true;
}