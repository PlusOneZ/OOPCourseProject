/**
*@file Actor.cpp
*@author 肖杨
*/

#include "Actor.h"

void Actor::bindSprite(Sprite *pSprite){
    m_sprite = pSprite;
    this->addChild(m_sprite);
}

bool Actor::generatePhysics()
{
    auto body = PhysicsBody::createBox(m_sprite->getContentSize());
    body->setMass(1e10);
    body->setGravityEnable(false);
    this->setPhysicsBody(body);

    return true;
}

