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
    m_pHero = pNowHero;
}

void BulletLayer::update(float dt)
{
	auto mouseListener = cocos2d::EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(BulletLayer::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);
}

bool BulletLayer::onMouseDown(Event* event)
{
    auto curTime = std::clock();
    if (static_cast<double>(curTime - m_lastShotTime) / CLOCKS_PER_SEC
            < m_pHero->getMainWeapon()->getInterval())
    {
        return true;
    }
    m_lastShotTime = curTime;
    auto e = dynamic_cast<EventMouse* >(event);
	Bullet* pBullet = m_pHero->getMainWeapon()->createBullet();
    log("Cursor at: %f, %f", e->getCursorX(), e->getCursorY());
    log("  Hero at: %f, %f", m_pHero->getPosition().x, m_pHero->getPosition().y);
	m_pWeaponBullet.pushBack(pBullet);
	pBullet->attack(e->getCursorX(), e->getCursorY(), m_pHero->getPosition());
	this->addChild(pBullet);
	return true;
}