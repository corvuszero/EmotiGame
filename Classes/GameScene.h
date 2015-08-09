//
//  GameScene.h
//  GoobGame
//
//  Created by Alan Morales on 7/12/15.
//
//

#ifndef __GoobGame__GameScene__
#define __GoobGame__GameScene__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer {
  
public:
  static cocos2d::Scene* createScene();
  
  virtual bool init();
  
  CREATE_FUNC(GameScene);
};

#endif // __GoobGame__GameScene__