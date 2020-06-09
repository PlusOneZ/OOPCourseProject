/**
*@file   Assassin.h
*@author 肖杨
*@date   6/9/2020
*/

#ifndef _ASSASSIN_H_
#define _ASSASSIN_H_

#include "Hero.h"

/**
*@brief 刺客类
*@author 肖杨
*/
class Assassin :public Hero
{
public:
	CREATE_FUNC(Assassin)

	/**
	*@brief 生成刺客
	*@author 肖杨
	*/
	bool init() override;

	/**
	*@brief 技能接口
	*@author 肖杨
	*@return 技能是否释放成功(暂定)
	*/
	//TODO:完成
	double skill() override;

	/**
	*@brief 技能结束回调
	*@author 肖杨
	*/
	void skillEnd() override;
protected:
	Animate* m_pSkillAnimate = nullptr;
	Animate* m_pSkillTempA = nullptr;
	Animate* m_pSkillTempB = nullptr;
};

#endif // !_ASSASSIN_H_
