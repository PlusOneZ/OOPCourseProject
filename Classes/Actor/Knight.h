/**
*@file Knight.h
*@author 肖杨
*@date 2020.5.24
*/
#ifndef _Knight_H_
#define _Knight_H_

#include "Hero.h"
#include <string>
/**
*@brief 骑士类
*@author 肖杨
*/
class Knight :public Hero
{
public:
	CREATE_FUNC(Knight);
	/**
	*@brief 生成骑士
	*@author 肖杨
	*/
	virtual bool init();
	
	/**
	*@brief 生成移动动画
	*@author 肖杨
	*@return 移动动作
	*/
	Animate* creatMoveAnimate();
	/**
	*@brief 生成静止动画
	*@author 肖杨
	*@return 静止动作
	*/
	Animate* creatRestAnimate();
	/**
	*@brief 主角静止
	*@author 肖杨
	*/
	void rest();
	/**
	*@brief 主角移动
	*@author 肖杨
	*/
	void move();
};
#endif // !_Knight_H__
