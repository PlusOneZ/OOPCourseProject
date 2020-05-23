/**
*@file
*StartGameScene.h
*@author µÔ³¿ê»
*/

#ifndef __STARTGAME_SCENE_H__
#define __STARTGAME_SCENE_H__

#include "cocos2d.h"

/**
*@brief Scene at the beginning of the game
*@fn CREATE_FUNC contains the definition of the create function
*@author µÔ³¿ê»
*/
class TitleScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuStartCallback(cocos2d::Ref* pSender);
    void menuEndCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(TitleScene);
};

#endif