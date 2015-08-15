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

class TileSprite : public cocos2d::Sprite {
private:
  TileConfig* config;
  cocos2d::Label* emoji;
  
  void calculateValue();
  void updateLabel();
  void initOptions();

public:
  cocos2d::Vec2 boardPosition;
  TileState currentState;
  TileValues value;
  
  ~TileSprite();
  TileSprite();
  TileSprite(TileClass tileClass);
  
  void setSymbol(std::string emoji);
  void setBoardPosition(float row, float column);
  cocos2d::Vec2 getBoardPosition();
  const cocos2d::Size& getContentSize();

  static TileSprite* create();
  static TileSprite* create(TileClass tileClass);

};

#endif /* defined(__GoobGame__TileSprite__) */
