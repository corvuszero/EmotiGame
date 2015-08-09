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

enum class TileClass {
  BOARD,
  GOAL,
  PLAYER
};

class TileSprite : public cocos2d::Sprite {
private:
  std::string symbol;
  cocos2d::Label* emoji;
  cocos2d::Vec2 boardPosition;
  TileClass tileClass;
  
  void updateLabel();
  void initOptions();
  static std::string getSymbolForClass(TileClass tileClass);
  
public:
  static const std::string DEFAULT_EMOJI;
  static const std::string GOAL_EMOJI;

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
