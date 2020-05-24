/**
*@file
*StartGameScene.h
*@author �Գ��
*/

#ifndef __STARTGAME_SCENE_H__
#define __STARTGAME_SCENE_H__

#include "cocos2d.h"
#include "PauseMenu.h"
#include "Const/Const.h"

/**
*@brief Scene at the beginning of the game
*@fn CREATE_FUNC contains the definition of the create function
*@author �Գ��
*/
class TitleScene : public cocos2d::Scene
{
public:

    /**
     * @note  Added by ZZY
     */
    TitleScene(sk::AudioState &auState);
    virtual bool init();
    void menuStartCallback(cocos2d::Ref* pSender);
    void menuEndCallback(cocos2d::Ref* pSender);

    /**
     * @note Added by ZZY
     */
    static TitleScene* create(sk::AudioState &auState);

    /**
     * @brief  Build a setting button on left bottom corner
     * @author ZZY
     * @note   please change this documentation to Chinese when encoding fixed.
     */
    void buildSettingBtn();

private:
    sk::AudioState &m_audioState;
};

#endif