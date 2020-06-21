/**
*@file Coin.h
*@author 肖杨
*@date 6/10/2020
*/
#ifndef _COIN_H_
#define _COIN_H_

#include "Actor/Hero.h"

/**
*@brief 金币类
*@author 肖杨
*/
class Coin :public Node
{
public:
	CREATE_FUNC(Coin)

	/**
	*@brief 生成金币
	*@author 肖杨
	*/
	bool init() override;

	/**
	*@brief 设置金币数额
	*/
	void setCoinAmount(int amount);

	/**
	*@brief 判断有没有和英雄碰撞
	*@author 肖杨
	*/
	bool onContactBegin(PhysicsContact& contact);

	/**
	 * @author 卓正一
	 * @param  tag
	 */
	void setTag(int tag) override ;

protected:
    Animate* m_pCoinAnimate;
	Sprite* m_pSprite;
	int m_coinAmount = 1;
};


#endif // !_COIN_H_

