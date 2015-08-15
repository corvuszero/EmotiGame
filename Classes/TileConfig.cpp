//
//  TileConfig.cpp
//  GoobGame
//
//  Created by Alan Morales on 8/14/15.
//
//

#include "TileConfig.h"

USING_NS_CC;

const std::string TileConfig::SYMBOL_DEFAULT = "🔒";
const std::string TileConfig::SYMBOL_GOAL = "💰";
const std::string TileConfig::SYMBOL_PLAYER = "😊";

TileConfig::TileConfig(TileClass tileClass, TileState state) {
  this->tileClass = tileClass;
  this->state = state;
}

TileConfig::~TileConfig() {}

TileConfig* TileConfig::create(TileClass tileClass) {
  switch (tileClass) {
    case TileClass::PRIZE:
      return new TileConfig(tileClass, TileState::COVERED);
      
    case TileClass::PLAYER:
      return new TileConfig(tileClass, TileState::NEUTRAL);
      
    default:
      return new TileConfig(tileClass, TileState::COVERED);
  }
}

std::string TileConfig::getSymbol() {
  switch (this->tileClass) {
    case TileClass::PRIZE:
      return TileConfig::SYMBOL_GOAL;
      
    case TileClass::PLAYER:
      return TileConfig::SYMBOL_PLAYER;
      
    default:
      return TileConfig::SYMBOL_DEFAULT;
  }
}