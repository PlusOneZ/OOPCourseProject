/**
 * @file   Const.h
 * @brief  需要用的常量
 * @author 大家按需要自己添加
 */

#ifndef __CONST_H__
#define __CONST_H__

#include <string>

namespace sk
{
    /// State Structures



    /// Constants, Classify them before adding!

    enum HeroID
    {
        kKnight,
        kAssassin,
    };

    enum KeyResponse
    {
        kRight,
        kLeft,
        kUp,
        kDown,
        kSkill,
        kShiftWeapon
    };

    // File names
    namespace files
    {
        // Audio
        const char kBgm1[]       = "Audio/bgm_1Low.mp3";
        const char kBtnPressed[] = "Audio/fx_btn1.mp3";

        // Heroes
        const char kKnightRest[] = "Actor/knight_rest";
        const char kKnightMove[] = "Actor/knight_move";

        const std::string kYellowCrawPlist = "Actor/Monster/yellowCraw.plist";
        const std::string kYellowCrawPng   = "Actor/Monster/yellowCraw.png";
        const std::string kYellowCrawName  = "Y_craw_monster";

        const char kHeroAvatar[2][40] = {
                "interface/ui2_knight.png",
                "interface/ui2_assassin.png",
        };
    }
}

#endif // CONST_H
