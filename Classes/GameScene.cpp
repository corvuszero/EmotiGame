//
//  GameScene.cpp
//  GoobGame
//
//  Created by Alan Morales on 7/12/15.
//
//

#include "BoardSprite.h"
#include "GameScene.h"
#include "GraphicUtils.h"

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

  auto board = BoardSprite::create();
  board->setPosition(GraphicUtils::screenCenter());
  this->addChild(board);
  
  return true;
}