/**
*@file Item.h
*@author 肖杨
*@date 5/28/2020
*/

#ifndef _ITEM_H_
#define _ITEM_H_

#include"cocos2d.h"
#include "Const/Const.h"
#include "ui/CocosGUI.h"

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
	virtual void interact()=0;


	/**
	*@brief 设置商店物品属性
	*@author 肖杨
	*/
	void setShopItem(int price);

	/**
	*@brief 购买后回调商品
	*@author 肖杨
	*@return 是否可使用
	*/
	bool buyItem();

	/**
	*@brief 修改m_pPresentContactItem
	*@author 肖杨
	*/
	virtual bool onContactBegin(PhysicsContact& contact)=0;
	virtual bool onContactSeparate(PhysicsContact& contact);

protected:
	Sprite* m_pSprite;
	ui::Scale9Sprite* m_pMessage;
	ui::Scale9Sprite* m_pShopMessage;

	bool m_ifShopItem=false;
	int m_price;
};

/**
*@brief 辅助函数，用于显示信息
*@author 肖杨
*/
ui::Scale9Sprite* showMessage(const std::string& message);
#endif // !_ITEM_H_
