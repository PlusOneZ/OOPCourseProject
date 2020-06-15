/**
*@file Board.h
*@author 翟晨昊
*@date 6/14/2020
*/

#ifndef _BOARD_H_
#define _BOARD_H_

#include "Item.h"

/**
*@brief 信息板类
*@author 翟晨昊
*/
class Board :public Item
{
public:
	CREATE_FUNC(Board)

	/**
	*@brief 生成一个信息板
	*@author 翟晨昊
	*/
	bool init() override;

	/**
	*@brief 交互时更改控制器
	*@author 翟晨昊
	*/
	void interact() override;

	/**
	*@brief 控制控制器的开关
	*@author 翟晨昊
	*/
	void controlListener();
	
	/**
	*@brief 键盘控制器
	*@author 翟晨昊
	*/
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	
protected:
	unsigned int curNumber = 0;
	Vector<ui::Scale9Sprite*> m_message;
};

/**
*@brief 辅助函数，用于显示信息
*@author 翟晨昊
*/
ui::Scale9Sprite* putMessage(const std::string& message);
#endif