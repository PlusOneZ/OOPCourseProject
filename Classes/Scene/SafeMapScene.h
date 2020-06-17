/**
*@file
*SafeMapScene.h
*@author 翟晨昊
*/

#ifndef SOULKNIGHT_SAFEMAPSCENE_H
#define SOULKNIGHT_SAFEMAPSCENE_H

#include "cocos2d.h"
#include "Actor/Knight.h"
#include "Actor/Assassin.h"
#include "Item/HealthPotion.h"
#include "Component/Coin.h"
#include "Actor/DistantMonster.h"
#include "Component/Trap.h"
#include "Item/Weapon.h"
#include "Item/Board.h"

USING_NS_CC;

/**
*@brief A saferoom scene
*@fn CREATE_FUNC contains the definition of the create function
*@author 翟晨昊
*/
class SafeMap : public cocos2d::Scene
{
public:

    /**
     *@brief Call the create function
     *@return A Scene instance
     *@author 翟晨昊
     */
    static Scene *createScene();

    /**
     *@brief Initialize the scene
     *@details Add images to the saferoom
     *@return true
     *@author 翟晨昊
     */
    bool init() override;

    CREATE_FUNC(SafeMap);

	/**
	 *@brief 添加骑士 子弹层 键盘监控
	*@author 肖杨  翟晨昊 卓正一
	 */
	void addPlayer(sk::HeroID id);


	/**
	*@brief 去除多余的键盘监控
	*@author 肖杨
	*/
	void removeKeyboard(Node* node);

    static EventListenerKeyboard* keyBoardListenerOne;
    static EventListenerKeyboard* keyBoardListenerTwo;
};

#endif
