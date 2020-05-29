#ifndef _PAUSE_MENU_H
#define _PAUSE_MENU_H

#include <utility>
#include "Const/Const.h"

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "AudioEngine.h"
#include "StartScene.h"

USING_NS_CC;

// 控制音乐的全局变量
extern int  gBackgroundMusicID;
extern bool gIsMusicPlaying;
extern bool gIsEffectPlaying;

class PauseMenu : public cocos2d::Scene{
public:

    PauseMenu(sk::HeroID id);

    /**
     * @brief  初始化目录
     * @return true
     * @author 卓正一
     */
    bool init() override ;

    /**
     * @brief  自定义的创建函数
     * @param  auState, id 引用的参数
     * @return 一个 PauseMenu 的实例
     * @author 卓正一
     */
    static PauseMenu* create(sk::HeroID id);

private:
    sk::HeroID m_heroID = sk::kKnight;

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
    static void playClickEffect();
};



#endif // _PAUSE_MENU_H
