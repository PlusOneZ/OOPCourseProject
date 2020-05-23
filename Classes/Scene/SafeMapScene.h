/**
*@file
*SafeMapScene.h
*@author �Գ��
*/

#ifndef SOULKNIGHT_SAFEMAPSCENE_H
#define SOULKNIGHT_SAFEMAPSCENE_H

#include "cocos2d.h"
USING_NS_CC;

/**
*@brief A saferoom scene
*@fn CREATE_FUNC contains the definition of the create function
*@author �Գ��
*/
class SafeMap : public cocos2d::Scene
{
public:
    static Scene* createScene();
    bool init() override ;
    CREATE_FUNC(SafeMap);
};
#endif
