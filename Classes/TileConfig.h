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

enum class TileClass {
  PRIZE,
  PLAYER,
  BOARD,
};

enum class TileState {
  NEUTRAL,
  COVERED,
  UNCOVERED
};

class TileConfig {
private:
  TileClass tileClass;
  TileState state;
  
public:
  static const std::string SYMBOL_DEFAULT;
  static const std::string SYMBOL_GOAL;
  static const std::string SYMBOL_PLAYER;
  
  TileConfig(TileClass tileClass, TileState state);
  ~TileConfig();
  
  std::string getSymbol();
  
  static TileConfig* create(TileClass tileClass);
};

#endif /* defined(__GoobGame__TileConfig__) */
