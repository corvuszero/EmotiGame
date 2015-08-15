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
const std::string TileConfig::SYMBOL_GOAL = "💎";
const std::string TileConfig::SYMBOL_PLAYER = "😊";

const std::string TileConfig::STATE_COVERED = "covered";
const std::string TileConfig::STATE_NEUTRAL = "neutral";
const std::string TileConfig::STATE_UNCOVERED = "uncovered";

TileConfig::TileConfig(std::string symbol, std::string intialState) {
  this->symbol = symbol;
  this->initialState = initialState;
  this->state = this->initialState;
}

TileConfig::~TileConfig() {}

TileConfig* TileConfig::create(std::string symbol) {
  if (symbol == TileConfig::SYMBOL_GOAL) {
    return new TileConfig(TileConfig::SYMBOL_GOAL, TileConfig::STATE_COVERED);
  }
      
  if (symbol == TileConfig::SYMBOL_PLAYER) {
    return new TileConfig(TileConfig::SYMBOL_PLAYER, TileConfig::STATE_NEUTRAL);
  }
      
  return new TileConfig(TileConfig::SYMBOL_DEFAULT, TileConfig::STATE_COVERED);
}

std::string TileConfig::getSymbol() {
  return this->symbol;
}