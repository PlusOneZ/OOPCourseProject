/**
*@file ArmorPotion.h
*@author 翟晨昊
*@date 6/20/2020
*/

#ifndef _ARMOR_POTION_H_
#define _ARMOR_POTION_H_

#include "Item.h"

/**
*@brief 护甲药水类
*@author 翟晨昊
*/
class ArmorPotion :public Item
{
public:
	CREATE_FUNC(ArmorPotion)

		/**
		*@brief 生成一个护甲药水
		*@author 翟晨昊
		*/
		bool init() override;

	/**
	*@brief 交互时消耗并增加护甲
	*@author 翟晨昊
	*/
	void interact() override;

};
#endif // !_ARMOR_POTION_H_

