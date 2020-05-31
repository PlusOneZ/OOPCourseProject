/**
*@brief 创建
*@details 射击时间间隔没有实装 没有设置子弹击中后消失
*@bug 无法正确获取获取鼠标位置
*@date 2020.5.30
*@author 翟晨昊
*/
#include "Actor/Hero.h"
#include "BulletLayer.h"

bool BulletLayer::init()
{
	scheduleUpdate();
	return true;
}

void BulletLayer::bindHero(Hero* pNowHero)
{
	pHero = pNowHero;
}

void BulletLayer::update(float dt)
{
	auto mouseListener = cocos2d::EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(BulletLayer::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
}

bool BulletLayer::onMouseDown(Event* event)
{
	auto e = dynamic_cast<EventMouse* >(event);
	Bullet* pBullet = pHero->getWeapon()->createBullet();
    log("Cursor at: %f, %f", e->getCursorX(), e->getCursorY());
    log("  Hero at: %f, %f", pHero->getPosition().x, pHero->getPosition().y);
	m_pWeaponBullet.pushBack(pBullet);
	pBullet->attack(e->getCursorX(), e->getCursorY(), pHero->getPosition());
	this->addChild(pBullet);
	return true;
}