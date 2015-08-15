//
//  BoardSprite.cpp
//  GoobGame
//
//  Created by Alan Morales on 8/2/15.
//
//

#include "BoardSprite.h"
#include "TileConfig.h"
#include "TileSprite.h"

USING_NS_CC;


BoardSprite::BoardSprite(int sizeX, int sizeY) {
  this->sizeX = (sizeX % 2 == 0)? sizeX + 1 : sizeX;
  this->sizeY = (sizeY % 2 == 0)? sizeY + 1 : sizeY;
}

BoardSprite::BoardSprite() : BoardSprite(BOARD_WIDTH, BOARD_HEIGHT) {
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
  return BoardSprite::create(BOARD_WIDTH, BOARD_HEIGHT);
}

void BoardSprite::initOptions() {
  int totalSize = this->sizeX * this->sizeY;
  int middle =  totalSize / 2;
  
  int playerLeft = middle - (this->sizeX / 2);
  int playerRight = middle + (this->sizeX / 2);

  this->board = Vector<TileSprite*>(totalSize);
  for (int i = 0; i < totalSize; i++) {
    TileSprite* tile;
    if (i != middle) {
      tile = TileSprite::create(TileConfig::SYMBOL_DEFAULT);
    }
    
    if (i == middle) {
      tile = TileSprite::create(TileConfig::SYMBOL_GOAL);
    }
    
    if (i == playerLeft || i == playerRight) {
      tile = TileSprite::create(TileConfig::SYMBOL_PLAYER);
    }
    
    float row = i / this->sizeX;
    float column = i % this->sizeX;
    tile->setBoardPosition(row, column);
    
    this->board.pushBack(tile);
    this->addChild(tile);
  }
  
  TileSprite* sampleBoard = this->board.front();
  this->setContentSize(Size(
    sampleBoard->getContentSize().width * this->sizeX,
    sampleBoard->getContentSize().height * this->sizeY
  ));
}