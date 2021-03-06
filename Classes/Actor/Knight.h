﻿/**
*@file Knight.h
*@author 肖杨
*@date 5/24/2020
*/
#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include "Hero.h"

/**
*@brief 骑士类
*@author 肖杨
*/
class Knight : public Hero
{
public:

    CREATE_FUNC(Knight)

	/**
	*@brief 生成骑士
	*@author 肖杨
	*/
	bool init() override ;

	/**
	*@brief 技能接口
	*@author 肖杨
	*@return 技能持续时间
	*/
	//TODO:完成
	float skill() override;

	/**
	*@brief 技能结束回调
	*@author 肖杨
	*/
	void skillEnd() override;
protected:
	int m_increaseAmount = 5;
};
#endif // !_Knight_H__
