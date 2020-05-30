/**
*@file Actor.cpp
*@author 肖杨
*/

#include "Actor.h"

void Actor::bindSprite(Sprite *pSprite)
{
    m_sprite = pSprite;
    this->addChild(m_sprite);
}