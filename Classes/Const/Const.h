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
        kShiftWeapon,
		kInteract
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
        const std::string kYellowCrawDie   = "Y_craw_monster_dead";

        const char kHeroAvatar[2][40] = {
                "interface/ui2_knight.png",
                "interface/ui2_assassin.png",
        };
    }

    namespace bitMask {

        static const int kMonsterCategory  = 0xff;
        static const int kMonsterContact   = 0xff;
        static const int kMonsterCollision = 0xff;

        static const int kItemCategory  = 0x01;
        static const int kItemCollision = 0x00;
        static const int kItemContact   = 0x01;

        static const int kMapCategory  = 0x0010;
        static const int kMapCollision = 0x1100;
        static const int kMapContact   = 0x1100;

        static const int kHeroCategory  = 0x01;
        static const int kHeroCollision = 0x01;
        static const int kHeroContact   = 0x01;

        static const int kBulletCategory = 0x1100;
        static const int kBulletCollision = 0x0010;
        static const int kBulletContact = 0x0010;
    }

    namespace tag {

        static const int kHero   = 500;
        static const int kBullet = 200;
    }
}

#endif // CONST_H
