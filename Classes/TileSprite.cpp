//
//  TileNode.cpp
//  GoobGame
//
//  Created by Alan Morales on 7/20/15.
//
//

#include "GraphicUtils.h"
#include "TileSprite.h"

USING_NS_CC;

const std::string TileSprite::DEFAULT_EMOJI = "💩";
const std::string TileSprite::GOAL_EMOJI = "💎";

TileSprite::TileSprite() : TileSprite(TileClass::PLAYER) {
}

TileSprite::~TileSprite() {
}

TileSprite::TileSprite(TileClass tileClass) {
  this->emoji = nullptr;
  this->symbol = TileSprite::getSymbolForClass(tileClass);
}

TileSprite* TileSprite::create() {
  return TileSprite::create(TileClass::PLAYER);
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

std::string TileSprite::getSymbolForClass(TileClass tileClass) {
  switch (tileClass) {
    case TileClass::GOAL:
      return TileSprite::GOAL_EMOJI;
      break;
      
    default:
      return TileSprite::DEFAULT_EMOJI;
      break;
  }
}

void TileSprite::initOptions() {
  this->updateLabel();
  this->addChild(this->emoji, 0);
}

void TileSprite::setSymbol(std::string emoji) {
  this->symbol = emoji;
  this->updateLabel();
}

void TileSprite::setBoardPosition(float row, float column) {
  this->setPosition(Vec2(
    this->emoji->getContentSize().width * column,
    this->emoji->getContentSize().height * row
  ));
  
  this->boardPosition = Vec2(column, row);
}

// private
void TileSprite::updateLabel() {
  if (this->emoji == nullptr) {
    this->emoji = Label::createWithSystemFont(this->symbol, "Arial", 70);
    this->emoji->setAnchorPoint(GraphicUtils::ALIGN_BOTTOM_LEFT);
  }
  
  this->emoji->setString(this->symbol);
}