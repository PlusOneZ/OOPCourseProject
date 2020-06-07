/**
*@file Hero.cpp
*@author 肖杨
*@date 2020.5.24
*/
#include "Hero.h"
#include "../Scene/PauseMenu.h"

bool Hero::init()
{
    scheduleUpdate();
	m_pPresentHero = nullptr;
	m_pPresentContactItem = nullptr;
	return true;
}

Weapon* Hero::getMainWeapon()
{
	return this->m_pMainWeapon;
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
		this->skill();
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
			m_pPresentContactItem = nullptr;
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

        getPhysicsBody()->setVelocity(v);
    }
    m_ifStateChanged = false;
    getPhysicsBody()->setAngularVelocity(0);

    if (v.x < 0 && m_curFacing == sk::kRight)
    {
        m_sprite->setFlippedX(true);
        m_pMainWeapon->getSprite()->setFlippedX(true);
        m_pMainWeapon->setPosition(Point(-20.0, 20.0));
        m_curFacing = sk::kLeft;
    }
    else if (v.x > 0 && m_curFacing == sk::kLeft)
    {
        m_sprite->setFlippedX(false);
        m_pMainWeapon->getSprite()->setFlippedX(false);
        m_pMainWeapon->setPosition(Point(20.0, 20.0));
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

bool Hero::reduceHP(int damage)
{
	if (m_armor != 0)
	{
		if (damage > m_armor)
		{
			damage -= m_armor;
			m_armor = 0;
		}
		else
		{
			m_alive -= damage;
			return true;
		}
	}
	if (damage >= m_HP)
	{
		m_alive = false;
		return false;
	}
	else
	{
		m_HP -= damage;
		return true;
	}
}

void Hero::recoverHP(int healAmount)
{
	if (m_HP + healAmount <= m_maxHP)
	{
		m_HP += healAmount;
	}
	else
	{
		m_HP = m_maxHP;
	}
}

/*

void AttackController::update(float dt)
{
	if (m_controllerListener == nullptr)
	{
		return;
	}

	Hero* myHero = Hero::m_pPresentHero;

	/if (KEY_DOWN(VK_LBUTTON))
	{
		myHero->m_pMainWeapon->attack();
	}

	if (KEY_DOWN(VK_RBUTTON))
	{
		myHero->shiftWeapon();
	}

	if (KEY_DOWN('Q'))
	{
		myHero->skill();
	}/
}
/
左键调用主武器的攻击函数
右键调用切换武器
q键调用技能
请务必完善相应函数
/

/
*@bug 动画调用有问题，本周内修复，暂时注释掉
*@date 05/29/2020[bug fixed:肖杨]
*@date 05/29/2020 [modified: 卓正一]
*@note 取消了 Windows API 的使用
/
void MoveController::update(float dt)
{
    if (m_controllerListener == nullptr)
    {
        return;
    }

    Hero* myHero = Hero::m_pPresentHero;
    auto& keyState = myHero->m_isKeyDown;
    bool checkMove = myHero->m_ifMove;
    auto v = Vec2(0, 0);

    if (keyState[sk::kUp])
    {
        pos.y += m_speed;
    }
    if (keyState[sk::kDown])
    {
        pos.y -= m_speed;
    }
    if (keyState[sk::kRight])
    {
        pos.x += m_speed;
    }
    if (keyState[sk::kLeft])
    {
        pos.x -= m_speed;
    }

    if (pos.x <= 20 || pos.x >= 1260
        || pos.y <= 0 || pos.y >= 670)
    {
        return;
    }

    /*
    int aimX = (pos.x - 10) / 28;
    int aimY = (720 - pos.y - 10) / 28;
    auto objectLayer = map->getLayer("Object1");
    int gid = objectLayer->getTileGIDAt(Vec2(aimX, aimY));
    if (gid)
    {
        return;
    }
    /
    //没想好怎么传参先注释掉

    myHero->m_ifMove = (pos != m_controllerListener->getTargetPosition());

    if (checkMove != myHero->m_ifMove)
    {
        if (myHero->m_ifMove)//说明在开始移动
        {
            myHero->move();
        }
        else
        {
            myHero->stopMove();
            myHero->rest();
        }
    }
    m_controllerListener->setTargetPosition(pos.x, pos.y);

}//TODO:改变方向，播放动画

 void Hero::setMoveController(ControllerBase* controllerbase)
{
	m_pMoveController = controllerbase;
	m_pMoveController->setControllerListener(this);
}

void Hero::setAttackController(ControllerBase* controllerbase)
{
	m_pAttackController = controllerbase;
	m_pAttackController->setControllerListener(this);
}

 */