/**
*@file   HeroUI.h
*@author 肖杨
*@date   6/14/2020
*/
#ifndef _HERO_UI_H_
#define _HERO_UI_H_

#include "Actor/Hero.h"

/**
*@brief 英雄属性UI
*@author 肖杨
*/
class HeroUI:public Node
{
public:
	CREATE_FUNC(HeroUI)

	/**
	*@brief 生成ui基本组件
	*@author 肖杨
	*/
	bool init()override;

	/**
	*@brief 0.1s更新状态
	*@author 肖杨
	*/
	void scheduleUI(float dt);

protected:
	Sprite* m_pSprite;
	ProgressTimer* m_pHealth;
	ProgressTimer* m_pArmor;

	Label* m_pHealthMessage;
	Label* m_pArmorMessage;
	Label* m_pCoinMessage;

	Hero* m_pHero;
	int m_presentHP;
	int m_presentArmor;
	int m_presntCoin;
};

#endif // !_HERO_UI_H_

