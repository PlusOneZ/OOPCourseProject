/**
*@file Actor.h
*@author 肖杨
*/
#ifndef _ACTOR_H_
#define _ACTOR_H_
#include "cocos2d.h"

using namespace cocos2d;
/**
*@brief 可移动类
*@author 肖杨
*/
class Actor :public Node
{
public:

    bool generatePhysics();
    /**
    *@brief 绑定精灵
    *@author 肖杨
    */
    void bindSprite(Sprite* pSprite);
protected:
    Sprite* m_sprite;
};
#endif