/**
*@file
*SafeMapScene.h
*@author 翟晨昊
*/

#ifndef SOULKNIGHT_SAFEMAPSCENE_H
#define SOULKNIGHT_SAFEMAPSCENE_H

#include "cocos2d.h"
#include"Actor/Knight.h"
USING_NS_CC;

/**
*@brief A saferoom scene
*@fn CREATE_FUNC contains the definition of the create function
*@author 翟晨昊
*/
class SafeMap : public cocos2d::Scene
{
public:
    static Scene* createScene();
    bool init() override ;
    CREATE_FUNC(SafeMap);
	/**
	*@brief 添加骑士
	*@author 肖杨
	*/
	void SafeMap::addPlayerKnight(SafeMap* pMap);
};
#endif
