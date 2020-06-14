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

static float kHeroSpeed = 150.;

/**
*@brief 主角类
*@author 肖杨
*/
class Hero : public Actor
{
    friend class Buff;
    friend class HeroUI;
public:

	void update(float dt) override ;

	/**
	*@brief 主角移动
	*@author 肖杨
	*/
	void move();

	/**
	*@brief 主角停止移动
	*@author 肖杨
	*/
	void stopMove();

	/**
	*@brief 主角静止
	*@author 肖杨
	*/
	void rest();

	/**
	 * @note   Modified : 卓正一
	 * @return 主武器
	 */
	Weapon* getMainWeapon();

	/**
	*@brief 设置主副武器
	*@author 肖杨
	*/
	void setMainWeapon(Weapon* pNewWeapon);
	void setSecondWeapon(Weapon* pNewWeapon);

	/**
	*@brief 获取英雄朝向
	*@author 翟晨昊
	*@return 隐含朝向信息的整数
	*/
	int getFacing();

	/**
	*@brief 技能接口
	*@author 肖杨
	*@return 技能持续时间
	*/
	virtual float skill() = 0;

	/**
	*@brief 技能结束回调
	*@author 肖杨
	*/
	virtual void skillEnd() = 0;

	/**
	*@brief 切换武器
	*@author 翟晨昊
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

	/**
	* @brief 受伤
	* @param 伤害数值
	* @author 肖杨
	* @return 是否还活着
	*/
	bool reduceHealth(int damage = 1);

	/**
	* @brief 恢复生命
	* @param 恢复数值
	* @author 肖杨
	*/
	void recoverHealth(int healAmount = 1);

	/**
	*@brief 是否受伤
	*@author 肖杨
	*@return 是否受伤
	*/
	bool ifInjured();

	/**
	*@brief 消耗金币
	*@param 消耗数量
	*@author 肖杨
	*@return 是否消耗成功
	*/
	bool costCoins(int coin);

	/**
	*@brief 获取金币
	*@param 获得数量
	*@author 肖杨
	*/
	void gainCoins(int coin);

	/**
	*@brief 获取英雄攻击力
	*@author 肖杨
	*@return 攻击力
	*/
	int getBaseDamage();

	static Hero* m_pPresentHero;
	static Item* m_pPresentContactItem;

protected:
    /// 武器
    Weapon* m_pMainWeapon = nullptr;
    Weapon* m_pSecWeapon  = nullptr;

    /// 基本动画
	Animate* m_pRestAnimate = nullptr;
	Animate* m_pMoveAnimate = nullptr;

	sk::HeroID m_ID;

	bool m_alive    = true;
	float m_speed   = kHeroSpeed;
	int m_health    = 5;
	int m_maxHealth = 5;

    /// 基本属性
	//int m_magicPoint;
	int m_armor              = 5;
	int m_maxArmor           = 5;
    float m_recoverArmorTime = 0;
	bool m_ifMortal          = true;
	int m_baseDamage         = 5;

    /// 技能属性
	float m_skillCD         = 8.f;       // 技能冷却时间
    float m_skillTime       = m_skillCD; // 当前技能冷却
    float m_skillLastTime   = 1.;        // 技能持续时间
    float m_skillRemainTime = 0;         // 技能剩余时间

	int m_coinNumber = 0;

    /// 移动状态
	bool m_ifMoved        = false;
	bool m_ifStateChanged = false;

	int m_curFacing = sk::kRight;        // 面向位置

    /// 控制监测
	std::vector<bool> m_isKeyDown = std::vector<bool>(7, false);

};
#endif
