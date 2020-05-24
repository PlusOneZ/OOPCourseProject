#ifndef _PAUSE_MENU_H
#define _PAUSE_MENU_H

#include <utility>

#include "cocos2d.h"

USING_NS_CC;

class PauseMenu : public cocos2d::Scene{
public:

    /**
     * @brief  初始化目录
     * @return true
     * @author 卓正一
     */
    bool init() override ;

    /**
     * @brief  自定义的创建函数
     * @todo   还缺两个参数，决定是否播放音乐音效以及头像用哪个英雄
     * @param
     * @return 一个 PauseMenu 的实例
     * @author 卓正一
     */
    static PauseMenu* create();

private:
    bool m_playEffect = true;
    bool m_playMusic  = true;
    // sk::HERO_TYPE m_heroType = sk::KNIGHT;

    /**
     * @brief  改变音效播放状态
     * @author 卓正一
     */
    void changEffectPlayEvent();

    /**
     * @brief  改变音乐播放状态
     * @author 卓正一
     */
    void changMusicPlayEvent();

    /**
     * @brief  按按钮的时候当然要放音效
     * @author 卓正一
     */
    void playClickEffect();
};



#endif // _PAUSE_MENU_H
