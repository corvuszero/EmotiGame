//
//  BoardSprite.cpp
//  GoobGame
//
//  Created by Alan Morales on 8/2/15.
//
//

#include "BoardSprite.h"
#include "TileSprite.h"

USING_NS_CC;


BoardSprite::BoardSprite(int sizeX, int sizeY) {
  this->sizeX = (sizeX % 2 == 0)? sizeX + 1 : sizeX;
  this->sizeY = (sizeY % 2 == 0)? sizeY + 1 : sizeY;
}

BoardSprite::BoardSprite() : BoardSprite(7, 15) {
}

BoardSprite::~BoardSprite() {
}

BoardSprite* BoardSprite::create(int sizeX, int sizeY) {
  BoardSprite *boardSprite = new BoardSprite(sizeX, sizeY);
  
  if (boardSprite->init()) {
    boardSprite->autorelease();
    boardSprite->initOptions();
    
    return boardSprite;
  }

  CC_SAFE_DELETE(boardSprite);
  
  return NULL;
}

BoardSprite* BoardSprite::create() {
  return BoardSprite::create(13, 5);
}

void BoardSprite::initOptions() {
  int totalSize = this->sizeX * this->sizeY;

  this->board = Vector<TileSprite*>(totalSize);
  for (int i = 0; i < totalSize; i++) {
    auto tile = TileSprite::create();
    
    float row = i / this->sizeX;
    float column = i % this->sizeX;
    tile->setBoardPosition(row, column);
    
    this->board.insert(i, tile);
    this->addChild(tile);
  }
  
  this->setAnchorPoint(Vec2(
                       ));
}