//
//  TitleScene.h
//  GoobGame
//
//  Created by Alan Morales on 7/12/15.
//
//

#ifndef __GoobGame__TitleScene__
#define __GoobGame__TitleScene__

#include "cocos2d.h"

class TitleScene : public cocos2d::Layer {

public:
  static cocos2d::Scene* createScene();
    
  virtual bool init();

  CREATE_FUNC(TitleScene);
};

#endif // __GoobGame__TitleScene__