//
//  TileNode.cpp
//  GoobGame
//
//  Created by Alan Morales on 7/20/15.
//
//

#include "TileSprite.h"

USING_NS_CC;

TileSprite::TileSprite() : TileSprite("💩") {
}

TileSprite::~TileSprite() {
}

TileSprite::TileSprite(std::string symbol) {
  this->emoji = nullptr;
  this->symbol = symbol;
}

TileSprite* TileSprite::create() {
  return TileSprite::create("💩");
}

TileSprite* TileSprite::create(std::string symbol) {
  TileSprite *pSprite = new TileSprite(symbol);
  
  if (pSprite->init()) {
    pSprite->autorelease();
    pSprite->initOptions();
    
    return pSprite;
  }
  
  CC_SAFE_DELETE(pSprite);
  
  return NULL;
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
                         )
                    );
}

// private
void TileSprite::updateLabel() {
  if (this->emoji == nullptr) {
    this->emoji = Label::createWithSystemFont(this->symbol, "Arial", 70);
  }
  
  this->emoji->setString(this->symbol);
}