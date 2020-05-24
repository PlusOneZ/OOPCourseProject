/**
 * @file   Const.h
 * @brief  需要用的常量
 * @author 大家按需要自己添加
 */

#ifndef __CONST_H__
#define __CONST_H__


namespace sk {
    /// Warning: Below are file scope global variables
    static int gBackgroundMusicID;


    /**
     * @brief  用于类之间传递音频播放状态
     * @author 卓正一
     */
    struct AudioState {
        bool musicPlaying    = true;
        bool auEffectPlaying = true;
    };

    enum HeroID {
        kKnight,
        kAssassin,
    };
}


#endif // CONST_H
