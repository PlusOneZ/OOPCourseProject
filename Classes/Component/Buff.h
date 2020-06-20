/**
*@file   Buff.h
*@author 肖杨
*@date   6/10/2020
*/

#ifndef _BUFF_H_
#define _BUFF_H_

#include "Actor/Hero.h"

/**
*@brief buff类
*@author 肖杨
*@details 里面的所有buff都对应：一个实现函数，一个终止函数和一个判断buff是否还持续的成员
*/
class Buff
{
private:
	int m_immortal = 0;

	int m_speedUp = 0;

	double m_rootedTime = 0;

	int m_increaseDamage = 0;

	int m_flaming = 0;

	Animate* m_pFlaming;
public:
	Buff()
	{
		m_pFlaming = creatBuffAnimate("item/flame_effect");
	}

	Buff &operator=(Buff& ) = default;

	Animate* creatBuffAnimate(const char * pAnimateName)
	{
		log("Trying to create buff effect");
		int moveFrameNum = 6;
		SpriteFrame*frame = nullptr;
		Vector<SpriteFrame*> frameVec;
		for (int i = 1; i <= moveFrameNum; i++)
		{
			frame = SpriteFrame::create(StringUtils::format("%s%d.png", pAnimateName, i),
				Rect(0, 0, 46, 48));
			if (frame == nullptr)
			{
				log("animate %s%d.png lost", pAnimateName, i);
			}
			else
			{
				frame->setAnchorPoint(Vec2(0.5f, 0.f));
				frameVec.pushBack(frame);
			}
		}
		Animation*animation = Animation::createWithSpriteFrames(frameVec);
		animation->setLoops(-1);
		animation->setDelayPerUnit(0.1f);
		Animate*action = Animate::create(animation);
		action->retain();
		return action;
	}

	void immortal()
	{
		Hero::m_pPresentHero->m_ifMortal = false;
		log("immortal");
		m_immortal++;
	}

	void immortalEnd()
	{
		if (m_immortal > 0)
		{
			Hero::m_pPresentHero->m_ifMortal = true;
			m_immortal--;
		}
	}

	void speedUp(float up)
	{
		Hero::m_pPresentHero->m_speed *= up;
		Hero::m_pPresentHero->m_ifStateChanged = true;
		log("speedup");
		m_speedUp++;
	}

	void speedUpEnd(float up)
	{
		if (m_speedUp > 1)
		{
			Hero::m_pPresentHero->m_speed /=up;
		}
		else if (m_speedUp == 1)
		{
			Hero::m_pPresentHero->m_speed = gHeroSpeed;
		}
		if (m_speedUp > 0)
		{
			Hero::m_pPresentHero->m_ifStateChanged = true;
			log("speedup end");
			m_speedUp--;
		}
	}

	void rooted(double rootedTime)
	{
		Hero::m_pPresentHero->m_speed = 0;
		Hero::m_pPresentHero->m_ifStateChanged = true;
		if (m_rootedTime == 0)
		{
			auto freeze = Sprite::create("item/freeze_effect.png");
			freeze->setTag(sk::tag::kFreezeTrap);
			freeze->setPosition(10., 0.);
			Hero::m_pPresentHero->addChild(freeze);
		}
		log("rooted");
		m_rootedTime = m_rootedTime > rootedTime ? m_rootedTime : rootedTime;
	}

	void rootedEnd(double rootedTime)
	{
		if (m_rootedTime - rootedTime <= 0.1)
		{
			Hero::m_pPresentHero->m_speed = gHeroSpeed;
			m_rootedTime = 0;
			log("rooted end");
			auto ice = Hero::m_pPresentHero->getChildByTag(sk::tag::kFreezeTrap);
			if (ice != nullptr)
			{
				ice->removeFromParentAndCleanup(true);
			}
		}
		else
		{
			m_rootedTime -= rootedTime;
		}
	}

	void increaseATK(int amount)
	{
		Hero::m_pPresentHero->m_baseDamage += amount;
		log("atk up");
		if (m_increaseDamage == 0)
		{
			auto angry = Sprite::create("Actor/atk_up.png");
			angry->setTag(sk::tag::kIncreaseDamage);
			angry->setPosition(0., 60.);
			Hero::m_pPresentHero->addChild(angry, 3);
		}
		m_increaseDamage++;
	}

	void increaseATKEnd(int amount)
	{
		if (m_increaseDamage > 0)
		{
			Hero::m_pPresentHero->m_baseDamage -= amount;
			log("atk up end");
			if (m_increaseDamage == 1)
			{
				auto atkup = Hero::m_pPresentHero->getChildByTag(sk::tag::kIncreaseDamage);
				if (atkup != nullptr)
				{
					atkup->removeFromParentAndCleanup(true);
				}
			}
			m_increaseDamage--;
		}
	}

	void flaming()
	{
		if (m_flaming == 0)
		{
			auto flame = Sprite::create("item/flame_effect1.png");
			flame->runAction(m_pFlaming);
			flame->setPosition(0., 10.);
			flame->setTag(sk::tag::kFlameTrap);
			Hero::m_pPresentHero->addChild(flame, 3);
			log("flaming");
		}
		m_flaming++;
	}

	void flamingEnd()
	{
		if (m_flaming > 0)
		{
			if (m_flaming == 1)
			{
				auto flame=Hero::m_pPresentHero->getChildByTag(sk::tag::kFlameTrap);
				if (flame != nullptr)
				{
					flame->removeFromParentAndCleanup(true);
				}
				log("flaming end");
			}
			m_flaming--;
		}
	}

}static HeroBuff;



#endif // !_BUFF_H_

