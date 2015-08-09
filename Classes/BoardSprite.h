//
//  BoardSprite.h
//  GoobGame
//
//  Created by Alan Morales on 8/2/15.
//
//

#ifndef __GoobGame__BoardSprite__
#define __GoobGame__BoardSprite__

#include "cocos2d.h"

class TileSprite;

class BoardSprite : public cocos2d::Sprite {
private:
  int sizeX;
  int sizeY;
  cocos2d::Vector<TileSprite*> board;
  
public:
  BoardSprite();
  BoardSprite(int sizeX, int sizeY);
  ~BoardSprite();
  static BoardSprite* create();
  static BoardSprite* create(int sizeX, int sizeY);
  
  void initOptions();
};

#endif /* defined(__GoobGame__BoardSprite__) */
