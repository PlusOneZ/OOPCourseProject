/**
*@file Spear.cpp
*@author 翟晨昊
*@date 6/19/2020
*/

#include "Spear.h"
#include "SpearBullet.h"

bool Spear::init()
{
	log("Trying to create spear");
	Sprite* pSprite = Sprite::create("item/spear.png");
	m_weaponSprite = pSprite;
	bindSprite(pSprite);
	generatePhysicalBody(kSpearMessage, sk::tag::kSpearWeapon);
	setInterval(.4f);
	setBulletCount(0);
	setDamage(5);
	return true;
}

Bullet* Spear::createBullet()
{
	auto begin = CallFunc::create([&]() {
		m_pSprite->setVisible(false);
		});
	auto delay = DelayTime::create(1.5);
	auto end = CallFunc::create([&]() {
		m_pSprite->setVisible(true);
		});
	auto seq = Sequence::create(begin, delay, end, nullptr);
	Bullet* pBullet = SpearBullet::create();
	m_pSprite->runAction(seq);
    if (gIsEffectPlaying)
    	AudioEngine::play2d(sk::files::kSwordAttack);
	return pBullet;
}