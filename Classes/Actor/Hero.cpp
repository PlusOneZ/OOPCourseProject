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
	return true;
}

/**
 * @brief  创建
 * @bug    传参错误导致无法正常生成动
 * @date   05/25/2020 [bug fixed: 卓正一]
 * @param  pAnimateName 动画文件名（字符串）
 * @author 肖杨
*/
Animate* Hero::creatHeroAnimate(const char * pAnimateName)
{
    log("Trying to create hero");
	int moveFrameNum = 4;
	SpriteFrame*frame = nullptr;
	Vector<SpriteFrame*> frameVec;
	for (int i = 1; i <= moveFrameNum; i++)
	{
		frame = SpriteFrame::create(StringUtils::format("%s%d.png", pAnimateName, i),
		                            Rect(0, 0, 64, 60));
		if (frame == nullptr)
		{
            log("animate %s%d.png lost", pAnimateName, i);
		}
		else
		{
		    frame->setAnchorPoint(Vec2(0.5, 0.));
			frameVec.pushBack(frame);
		}
	}
	Animation*animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.2f);
	Animate*action = Animate::create(animation);
	action->retain();
	return action;
}

Weapon* Hero::getMainWeapon()
{
	return this->m_pMainWeapon;
}

void Hero::shiftWeapon()
{
	if (m_pSecWeapon != nullptr)
	{
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
    if (m_ifStateChanged) {
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
        m_curFacing = sk::kLeft;
    }
    else if (v.x > 0 && m_curFacing == sk::kLeft)
    {
        m_sprite->setFlippedX(false);
        m_curFacing = sk::kRight;
    }

    if (v != Vec2::ZERO)
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