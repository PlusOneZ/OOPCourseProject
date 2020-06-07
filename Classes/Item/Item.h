/**
*@file Item.h
*@author 肖杨
*@date 5/28/2020
*/

#ifndef _ITEM_H_
#define _ITEM_H_

#include"cocos2d.h"
using namespace cocos2d;

/**
*@brief 物品类
*@author 肖杨
*/
class Item:public Node
{
public:
	/**
	*@brief 绑定精灵
	*/
	void bindSprite(Sprite* pSprite);

	/**
	*@brief 获取精灵
	*@author 翟晨昊
	*/
	Sprite* getSprite();

	/**
	*@brief 交互函数
	*@author 肖杨
	*/
	virtual void interact();

	/**
	*@brief 空的碰撞函数，用于忽略碰撞体积
	*@author 肖杨
	*/
	bool voidOnContactPreSolve(PhysicsContact& contact);
protected:
	Sprite* m_pSprite;
};

#endif // !_ITEM_H_
