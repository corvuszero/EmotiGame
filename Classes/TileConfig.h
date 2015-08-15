//
//  TileConfig.h
//  GoobGame
//
//  Created by Alan Morales on 8/14/15.
//
//

#ifndef __GoobGame__TileConfig__
#define __GoobGame__TileConfig__

#include "cocos2d.h"

class TileConfig {
private:
  std::string initialState;
  std::string symbol;
  std::string state;
  
public:
  static const std::string SYMBOL_DEFAULT;
  static const std::string SYMBOL_GOAL;
  static const std::string SYMBOL_PLAYER;
  
  static const std::string STATE_COVERED;
  static const std::string STATE_NEUTRAL;
  static const std::string STATE_UNCOVERED;
  
  TileConfig(std::string symbol, std::string state);
  ~TileConfig();
  
  std::string getSymbol();
  
  static TileConfig* create(std::string symbol);
};

#endif /* defined(__GoobGame__TileConfig__) */
