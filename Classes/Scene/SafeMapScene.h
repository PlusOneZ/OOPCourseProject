/**
*@file
*SafeMapScene.h
*@author µÔ³¿ê»
*/

#ifndef SOULKNIGHT_SAFEMAPSCENE_H
#define SOULKNIGHT_SAFEMAPSCENE_H

#include "cocos2d.h"
USING_NS_CC;

/**
*@brief A saferoom scene
*@fn CREATE_FUNC contains the definition of the create function
*@author µÔ³¿ê»
*/
class SafeMap : public cocos2d::Scene
{
public:
    static Scene* createScene();
    bool init() override ;
    CREATE_FUNC(SafeMap);
};
#endif
