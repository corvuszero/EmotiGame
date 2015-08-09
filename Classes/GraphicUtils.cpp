//
//  GraphicUtils.cpp
//  GoobGame
//
//  Created by Alan Morales on 8/8/15.
//
//

#include "GraphicUtils.h"

USING_NS_CC;

Vec2 GraphicUtils::screenCenter() {
  Size visibleSize = Director::getInstance()->getVisibleSize();

  return Vec2(visibleSize.width / 2, visibleSize.height / 2);
}