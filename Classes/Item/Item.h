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
*@author 肖杨(仅创建)
*/
class Item:public Node
{
public:
	void bindSprite(Sprite* pSprite);
private:
	Sprite* m_pSprite;
};

#endif // !_ITEM_H_
