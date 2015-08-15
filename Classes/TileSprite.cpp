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

TileSprite::TileSprite() : TileSprite(TileClass::BOARD) {
}

TileSprite::~TileSprite() {
}

TileSprite::TileSprite(TileClass tileClass) {
  this->emoji = nullptr;
  this->config = TileConfig::create(tileClass);
  this->currentState = this->config->getState();
}

TileSprite* TileSprite::create() {
  return TileSprite::create(TileClass::BOARD);
}

TileSprite* TileSprite::create(TileClass tileClass) {
  TileSprite *pSprite = new TileSprite(tileClass);
  
  if (pSprite->init()) {
    pSprite->autorelease();
    pSprite->initOptions();
    
    return pSprite;
  }
  
  CC_SAFE_DELETE(pSprite);
  
  return NULL;
}

Vec2 TileSprite::getBoardPosition() {
  return this->boardPosition;
}

const Size& TileSprite::getContentSize() {
  return this->emoji->getContentSize();
}

void TileSprite::initOptions() {
  this->updateLabel();
  this->addChild(this->emoji, 0);
  
  this->calculateValue();
}

void TileSprite::setBoardPosition(float row, float column) {
  this->setPosition(Vec2(
    this->emoji->getContentSize().width * column,
    this->emoji->getContentSize().height * row
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

void TileSprite::updateLabel() {
  if (this->emoji == nullptr) {
    this->emoji = Label::createWithSystemFont(
      this->config->getSymbol(),
      "Arial",
      70
    );
    this->emoji->setAnchorPoint(GraphicUtils::ALIGN_BOTTOM_LEFT);
    return;
  }
  
  this->emoji->setString(this->config->getSymbol());
}