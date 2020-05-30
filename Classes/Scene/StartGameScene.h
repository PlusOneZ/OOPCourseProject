/**
*@file
*StartGameScene.h
*@author 翟晨昊
*/

#ifndef __STARTGAME_SCENE_H__
#define __STARTGAME_SCENE_H__

#include "cocos2d.h"
#include "PauseMenu.h"
#include "Const/Const.h"

/**
*@brief Scene at the beginning of the game
*@fn CREATE_FUNC contains the definition of the create function
*@author 翟晨昊
*/
class TitleScene : public cocos2d::Scene
{
public:

    virtual bool init();
    void menuStartCallback(cocos2d::Ref* pSender);
    void menuEndCallback(cocos2d::Ref* pSender);
    CREATE_FUNC(TitleScene);

    /**
     * @brief  Build a setting button on left bottom corner
     * @author ZZY
     * @note   please change this documentation to Chinese when encoding fixed.
     */
    void buildSettingBtn();

};

#endif