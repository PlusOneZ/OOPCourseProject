/**
*@file Hero.h
*@author 肖杨
*@date 2020.5.24
*/
#ifndef _HERO_H_
#define _HERO_H_

#include "Actor.h"
#include "../Item/Weapon.h"
#include "../Const/Const.h"
#include <vector>

class BulletLayer;
/**
*@brief 主角类
*@author 肖杨
*/
class Hero : public Actor
{
public:
	/**
	*@brief 生成主角
	*@author 肖杨
	*/
	bool init() override;

	void update(float dt) override;

	/**
	*@brief 主角移动
	*@author 肖杨
	*/
	virtual void move() = 0;

	/**
	*@brief 主角停止移动
	*@author 肖杨
	*/
	virtual void stopMove() = 0;

	/**
	*@brief 主角静止
	*@author 肖杨
	*/
	virtual void rest() = 0;

	/**
	*@brief 生成动画
	*@author 肖杨
	*@return 对应动画
	@param arg1 要生成的动画对应文件名称
	*/
	static Animate* creatHeroAnimate(const char* pAnimateName);

	/**
	 * @note   Modified : 卓正一
	 * @return 主武器
	 */
	Weapon* getMainWeapon();


	/**
	*@brief 技能接口
	*@author 肖杨
	*@return 技能是否释放成功(暂定)
	*/
	virtual bool skill() = 0;

	/**
	*@brief 切换武器
	*@author 肖杨
	*/
	void shiftWeapon();


	/**
	* @brief  监听按钮按下
	* @param  keyCode 哪个按钮
	* @author 卓正一
	*/
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);

	/**
	 * @brief  监听按钮松开
	 * @param  keyCode 哪个按钮
	 * @author 卓正一
	 */
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);


	static Hero* m_pPresentHero;


protected:

	Weapon* m_pMainWeapon = nullptr;
	Weapon* m_pSecWeapon = nullptr;

	Animate* m_pRestAnimate = nullptr;
	Animate* m_pMoveAnimate = nullptr;

	sk::HeroID m_ID;

	float m_speed = 150.;

	bool m_ifMoved = false;
	bool m_ifStateChanged = false;

	int m_curFacing = sk::kRight;

	std::vector<bool> m_isKeyDown = std::vector<bool>(6, false);
};
#endif