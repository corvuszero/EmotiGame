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

class TileSprite : public cocos2d::Sprite {
private:
  std::string symbol;
  cocos2d::Label* emoji;
  cocos2d::Vec2 boardPosition;
  
  void updateLabel();
  void initOptions();
  
public:
  TileSprite();
  TileSprite(std::string symbol);
  ~TileSprite();
  
  
  void setSymbol(std::string emoji);
  void setBoardPosition(float row, float column);
  cocos2d::Vec2 getBoardPosition();
  const cocos2d::Size& getContentSize();

  static TileSprite* create();
  static TileSprite* create(std::string symbol);

};

#endif /* defined(__GoobGame__TileSprite__) */
