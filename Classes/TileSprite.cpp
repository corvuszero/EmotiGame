//
//  TileNode.cpp
//  GoobGame
//
//  Created by Alan Morales on 7/20/15.
//
//

#include "GraphicUtils.h"
#include "TileConfig.h"
#include "TileSprite.h"

USING_NS_CC;

TileSprite::TileSprite() {}
TileSprite::~TileSprite() {
  delete this->config;
}

TileSprite* TileSprite::create(TileClass tileClass) {
  TileSprite *pSprite = new TileSprite();
  
  if (pSprite) {
    pSprite->initOptions(tileClass);
    pSprite->setEvents();

    pSprite->autorelease();

    return pSprite;
  }
  
  CC_SAFE_DELETE(pSprite);
  
  return NULL;
}

void TileSprite::initOptions(TileClass tileClass) {
  this->config = TileConfig::create(tileClass);
  this->currentState = this->config->getState();

  this->setSystemFontName("Arial");
  this->setSystemFontSize(70);
  this->setString(this->config->getSymbol());
  
  this->setAnchorPoint(GraphicUtils::ALIGN_BOTTOM_LEFT);
  this->calculateValue();
}

void TileSprite::setBoardPosition(float row, float column) {
  this->setPosition(Vec2(
    this->getContentSize().width * column,
    this->getContentSize().height * row
  ));
  
  this->boardPosition = Vec2(column, row);
}

// private
void TileSprite::calculateValue() {
  int random = RandomHelper::random_int(1, 90);
  
  if (random < 30) {
    this->value = TileValues::ROCK;
    return;
  }
  
  if (random < 60) {
    this->value = TileValues::PAPER;
    return;
  }
  
  this->value = TileValues::SCISSORS;
}

void TileSprite::setEvents() {
  auto listener = EventListenerTouchOneByOne::create();
  listener->setSwallowTouches(true);
  
  listener->onTouchBegan = [&](Touch* touch, Event* event) {
    if (this->getParent() == nullptr) {
      return false;
    }

    Vec2 p = this->getParent()->convertToNodeSpace(touch->getLocation());
    if (this->getBoundingBox().containsPoint(p)) {
      return true;
    }

    return false;
  };
  
  listener->onTouchEnded = [=](Touch *touch, Event* event) {
    this->touchEvent(touch);
  };
  
  Director::getInstance()->getEventDispatcher()
    ->addEventListenerWithFixedPriority(listener, 30);
}

void TileSprite::touchEvent(Touch* touch) {
  CCLOG("Clicked [%f %f]", this->boardPosition.y, this->boardPosition.x);
}