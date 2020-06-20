/**
*@file Hero.cpp
*@author 肖杨
*@date 2020.5.24
*/
#include "Hero.h"
#include "../Scene/PauseMenu.h"
#include "Item/Gun.h"

Hero* Hero::m_pPresentHero = nullptr;
Item* Hero::m_pPresentContactItem = nullptr;

Weapon* Hero::getMainWeapon()
{
	return this->m_pMainWeapon;
}

void Hero::setMainWeapon(Weapon* pNewWeapon)
{
	pNewWeapon->setState(true);
	pNewWeapon->setPosition(Point(20.0, 20.0));
	m_pMainWeapon = pNewWeapon;
	this->addChild(pNewWeapon, 2);
}

void Hero::setSecondWeapon(Weapon* pNewWeapon)
{
	pNewWeapon->setState(true);
	pNewWeapon->setPosition(Point(20.0, 20.0));
	m_pSecWeapon = pNewWeapon;
	this->addChild(pNewWeapon, 2);
}


int Hero::getFacing()
{
    return m_curFacing;
}


void Hero::shiftWeapon()
{
	if (m_pSecWeapon != nullptr)
	{
        m_pMainWeapon->setVisible(false);
        m_pSecWeapon->setVisible(true);
		Weapon* pTemp = m_pSecWeapon;
		m_pSecWeapon = m_pMainWeapon;
		m_pMainWeapon = pTemp;
		AudioEngine::play2d(sk::files::kWeaponSwitch);
	}
}

void Hero::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    log("Key %d pressed.", keyCode);
    m_ifStateChanged = true;
	using namespace cocos2d;
	if (keyCode == EventKeyboard::KeyCode::KEY_D ||
		keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		m_isKeyDown[sk::kRight] = true;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_W ||
		keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		m_isKeyDown[sk::kUp] = true;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_A ||
		keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		m_isKeyDown[sk::kLeft] = true;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_S ||
		keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		m_isKeyDown[sk::kDown] = true;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_Q)
	{
		if (m_skillTime >= m_skillCD)
		{
			m_skillRemainTime=this->skill();
			m_skillTime = -m_skillRemainTime;
		}
		else
		{
			log("skill CDing");
		}
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_E)
	{
		// TODO: Shift weapon here.
		this->shiftWeapon();
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_F)
	{
		if (m_pPresentContactItem != nullptr)
		{
				m_pPresentContactItem->interact();
		}
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		Director::getInstance()->pushScene(PauseMenu::create(m_ID));
	}
}

void Hero::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    m_ifStateChanged = true;
	using namespace cocos2d;
	if (keyCode == EventKeyboard::KeyCode::KEY_D ||
		keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		m_isKeyDown[sk::kRight] = false;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_W ||
		keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		m_isKeyDown[sk::kUp] = false;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_A ||
		keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		m_isKeyDown[sk::kLeft] = false;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_S ||
		keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		m_isKeyDown[sk::kDown] = false;
	}
}

void Hero::update(float dt)
{
    auto v = Vec2(0, 0);
    if (m_ifStateChanged) 
	{
        if (m_isKeyDown[sk::kUp])
            v.y += m_speed;
        if (m_isKeyDown[sk::kDown])
            v.y -= m_speed;
        if (m_isKeyDown[sk::kLeft])
            v.x -= m_speed;
        if (m_isKeyDown[sk::kRight])
            v.x += m_speed;

        v = v.getNormalized() * m_speed;

        getPhysicsBody()->setVelocity(v);
    }
    m_ifStateChanged = false;
    getPhysicsBody()->setAngularVelocity(0);

    if (v.x < 0 && m_curFacing == sk::kRight)
    {
        m_sprite->setFlippedX(true);
        m_pMainWeapon->getSprite()->setFlippedX(true);
        m_pMainWeapon->setPosition(Point(-20.0, 20.0));
        m_pSecWeapon->getSprite()->setFlippedX(true);
        m_pSecWeapon->setPosition(Point(-20.0, 20.0));
        if (m_pMainWeapon->getSprite()->getTag() == sk::tag::kSwordWeapon)
        {
            m_pMainWeapon->getSprite()->setRotation(60.f);
        }
        m_curFacing = sk::kLeft;
    }
    else if (v.x > 0 && m_curFacing == sk::kLeft)
    {
        m_sprite->setFlippedX(false);
        m_pMainWeapon->getSprite()->setFlippedX(false);
        m_pMainWeapon->setPosition(Point(20.0, 20.0));
        m_pSecWeapon->getSprite()->setFlippedX(false);
        m_pSecWeapon->setPosition(Point(20.0, 20.0));
        if (m_pMainWeapon->getSprite()->getTag() == sk::tag::kSwordWeapon)
        {
            m_pMainWeapon->getSprite()->setRotation(-60.f);
        }
        m_curFacing = sk::kRight;
    }

    if (getPhysicsBody()->getVelocity() != Vec2::ZERO)
    {
        if (!m_ifMoved)
        {
            m_ifMoved = true;
            move();
        }
    }
    else
    {
        if (m_ifMoved)
        {
            m_ifMoved = false;
            stopMove();
            rest();
        }
    }

	if (m_skillTime < m_skillCD)
	{
		m_skillTime += dt;
	}
	if (m_skillRemainTime > 0)
	{
		m_skillRemainTime -= dt;
		if (m_skillRemainTime <= 0)
		{
			skillEnd();
		}
	}

	if (m_recoverArmorTime < 1)
	{
		m_recoverArmorTime += dt;
	}
	else if (m_armor < m_maxArmor)
	{
		m_armor += 1;
		log("armor regain");
		m_recoverArmorTime = 0;
	}
	
	
}

void Hero::rest()
{
	m_sprite->runAction(m_pRestAnimate);
}

void Hero::move()
{
	m_sprite->stopAction(m_pRestAnimate);
	m_sprite->runAction(m_pMoveAnimate);
}

void Hero::stopMove()
{
	m_sprite->stopAction(m_pMoveAnimate);
}

bool Hero::reduceHealth(int damage)
{
	if (m_ifMortal)
	{
		m_recoverArmorTime = -4;
		if (m_armor != 0)
		{
			if (damage > m_armor)
			{
				damage -= m_armor;
				m_armor = 0;
			}
			else
			{
				m_armor -= damage;
				AudioEngine::play2d(sk::files::kHeroHurt);
				return true;
			}
		}
		if (damage >= m_health)
		{
			m_health = 0;
			m_alive = false;
			return false;
		}
		else
		{
            m_health -= damage;
            AudioEngine::play2d(sk::files::kHeroHurt);
			return true;
		}
	}
	return true;
}

void Hero::recoverHealth(int healAmount)
{
	if (m_health + healAmount <= m_maxHealth)
	{
        m_health += healAmount;
	}
	else
	{
        m_health = m_maxHealth;
	}
}

void Hero::addArmor(int addAmount)
{
	m_maxArmor += addAmount;
}

bool Hero::ifInjured()
{
	return m_health < m_maxHealth;
}

bool Hero::costCoins(int coin)
{
	if (m_coinNumber >= coin)
	{
		m_coinNumber -= coin;
		return true;
	}
	else
	{
		return false;
	}
}

void Hero::gainCoins(int coin)
{
	m_coinNumber += coin;
}

int Hero::getBaseDamage()
{
	return m_baseDamage;
}

void Hero::setSpeed(float speed)
{
	m_speed = speed;
}

void Hero::clearKeyPress()
{
	for (auto key : m_isKeyDown)
	{
		key = false;
	}
}

sk::HeroID Hero::getHeroID()
{
	return m_ID;
}

Hero *Hero::getInstance()
{
    return m_pPresentHero;
}

void Hero::clearPresentHero()
{
    m_pPresentHero = nullptr;
}

Item *Hero::getPresentContactItem()
{
    return m_pPresentContactItem;
}

void Hero::setPresentContactItem(Item *pItem)
{
    m_pPresentContactItem = pItem;
}

//Item中函数的实现
bool Item::onContactSeparate(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();
	if (nodeA != nullptr && nodeB != nullptr)
	{
		if ((nodeA->getTag() == sk::tag::kHero || nodeB->getTag() == sk::tag::kHero)
			&& (nodeA->getTag() == this->getTag() || nodeB->getTag() == this->getTag()))
		{
			if (Hero::getPresentContactItem() == this)
			{
				log("item seperate");
				Hero::setPresentContactItem(nullptr);
				m_pMessage->setVisible(false);
			}
		}
	}
	return true;
}

bool Item::onContactBegin(PhysicsContact& contact)
{
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();
	if (nodeA != nullptr && nodeB != nullptr)
	{
		if ((nodeA->getTag() == sk::tag::kHero || nodeB->getTag() == sk::tag::kHero)
			&& (nodeA->getTag() == this->getTag() || nodeB->getTag() == this->getTag()))
		{
			if (Hero::getPresentContactItem() == nullptr)
			{
				log("near item");
				Hero::setPresentContactItem(this);
				m_pMessage->setVisible(true);
			}
		}
	}
	return false;
}

bool Item::buyItem()
{
	if (m_ifShopItem)
	{
		if (Hero::getInstance()->costCoins(m_price))//购买成功
		{
			log("buy item");
            AudioEngine::play2d(sk::files::kBuy);
			m_ifShopItem = false;
			m_price = 0;
			m_pShopMessage->removeFromParentAndCleanup(true);
			m_pShopMessage = nullptr;
		}
		else
		{
            AudioEngine::play2d(sk::files::kHeroNoMoney);
			log("no enough money");
		}
	}
	return !m_ifShopItem;
}



void Weapon::interact()
{
	if (buyItem())
	{
		auto myHero = Hero::getInstance();
		const int Tag = myHero->getMainWeapon()->m_pSprite->getTag();
		auto floorWeapon = myHero->getMainWeapon();
		floorWeapon->retain();
		floorWeapon->removeFromParent();
		floorWeapon->setPosition(Point(this->getPosition()));
		floorWeapon->setState(false);
		myHero->getParent()->addChild(floorWeapon, 3, Tag);
		this->retain();
		this->removeFromParent();
		this->m_pMessage->setVisible(false);
		myHero->setMainWeapon(this);
		log("weapon changed");
		AudioEngine::play2d(sk::files::kWeaponPickup);
		Hero::setPresentContactItem(nullptr);
	}
}

