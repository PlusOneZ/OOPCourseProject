/**
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
	*@return 技能是否释放成功(暂定)
	*/
	//TODO:完成
	bool skill() override;
};
#endif // !_Knight_H__
