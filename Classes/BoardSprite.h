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
  static const int BOARD_WIDTH = 11;
  static const int BOARD_HEIGHT = 5;
  
  BoardSprite();
  BoardSprite(int sizeX, int sizeY);
  ~BoardSprite();
  static BoardSprite* create();
  static BoardSprite* create(int sizeX, int sizeY);
  
  void initOptions();
};

#endif /* defined(__GoobGame__BoardSprite__) */
