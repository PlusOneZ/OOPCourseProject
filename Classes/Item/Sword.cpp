/**
*@file Sword.cpp
*@author 翟晨昊
*@date 6/6/2020
*/

#include "Sword.h"
#include "SwordBullet.h"

bool Sword::init()
{
	log("Trying to create sword");
	Sprite* pSprite = Sprite::create("item/sword.png");
	m_weaponSprite = pSprite;
	bindSprite(pSprite);
	generatePhysicalBody(kSwordMessage, sk::tag::kSwordWeapon);
	pSprite->setRotation(-60.f);
	setInterval(.2f);
	setBulletCount(0);
    setDamage(4);
	return true;
}

Bullet* Sword::createBullet()
{
    auto begin = CallFunc::create([&]() {
        m_pSprite->setVisible(false);
    });
    auto delay = DelayTime::create(0.9);
    auto end   = CallFunc::create([&]() {
        m_pSprite->setVisible(true);
    });
    auto seq   = Sequence::create(begin, delay, end, nullptr);
	Bullet* pBullet = SwordBullet::create();
    m_pSprite->runAction(seq);
    AudioEngine::play2d(sk::files::kSwordAttack);
	return pBullet;
}