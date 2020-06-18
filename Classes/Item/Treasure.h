/**
*@file Treasure.h
*@author 肖杨
*@date 6/16/2020
*/
#ifndef _TREASURE_H_
#define _TREASURE_H_

#include "Item.h"

/**
*@brief 宝箱类
*@author 肖杨
*/
class Treasure :public Item
{
public:
	CREATE_FUNC(Treasure)
	/**
	*@brief 生成一个内容未知的宝箱
	*@author 肖杨
	*/
	bool init()override;

	/**
	*@brief 打开宝箱
	*@author 肖杨
	*/
	void interact()override;
protected:
	Item* m_pUnknownItem;
};


#endif // !_TREASURE_H_