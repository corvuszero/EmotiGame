//
//  TileNode.h
//  GoobGame
//
//  Created by Alan Morales on 7/20/15.
//
//

#ifndef __GoobGame__TileSprite__
#define __GoobGame__TileSprite__

#include "cocos2d.h"
#include "TileConfig.h"

enum class TileValues {
  NEUTRAL,
  ROCK,
  PAPER,
  SCISSORS
};

class TileSprite : public cocos2d::Label {
private:
  TileConfig* config;
  
  void calculateValue();
  void initOptions(TileClass tileClass);
  void setEvents();
  void touchEvent(cocos2d::Touch* touch);
  void updateLabel();

public:
  typedef std::function<void(int, int)> ggOnTileTapCallback;
  
  cocos2d::Vec2 boardPosition;
  ggOnTileTapCallback onTap;
  TileState currentState;
  TileValues value;
  
  ~TileSprite();
  TileSprite();
  
  void setBoardPosition(int row, int column);
  static TileSprite* create(TileClass tileClass);
};

#endif /* defined(__GoobGame__TileSprite__) */
