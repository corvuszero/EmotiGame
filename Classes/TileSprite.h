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
  
  void updateLabel();
  void initOptions();
  
public:
  TileSprite();
  TileSprite(std::string symbol);
  ~TileSprite();
  static TileSprite* create();
  static TileSprite* create(std::string symbol);
  
  
  void setSymbol(std::string emoji);
  void setBoardPosition(float row, float column);
};

#endif /* defined(__GoobGame__TileSprite__) */
