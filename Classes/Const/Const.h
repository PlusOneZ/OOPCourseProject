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

    enum class Kind
    {
        kSelf,
        kMonster
    };

    // File names
    namespace files
    {
        // Audio
        static const char kBgm1[]         = "Audio/bgm_1Low.mp3";
        static const char kBtnPressed[]   = "Audio/fx_btn1.mp3";
        static const char kBgm2[]         = "Audio/bgm_room.mp3";
        static const char kWeaponPickup[] = "Audio/fx_pickup.mp3";
        static const char kWeaponSwitch[] = "Audio/fx_switch.mp3";
        static const char kSwordAttack[]  = "Audio/fx_sword.mp3";
        static const char kGunShot[]      = "Audio/fx_normal_gun.mp3";
        static const char kShotGunShot[]  = "Audio/fx_shotgun.mp3";
        static const char kTakePotion[]   = "Audio/fx_health_potion.mp3";
        static const char kBuy[]          = "Audio/fx_buy.mp3";
        static const char kMonThorn[]     = "Audio/fx_mon_atk1.mp3";
        static const char kCoin[]         = "Audio/fx_coin.mp3";
        static const char kIceTrap[]      = "Audio/fx_ice.mp3";
        static const char kFireTrap[]     = "Audio/fx_fire.mp3";
        static const char kHeroHurt[]     = "Audio/fx_hurt.mp3";
        static const char kHeroNoMoney[]  = "Audio/fx_ero_hurt.mp3";


        // Heroes
        static const char kKnightRest[] = "Actor/knight_rest";
        static const char kKnightMove[] = "Actor/knight_move";

        static const std::string kYellowCrawPlist = "Actor/Monster/yellowCraw.plist";
        static const std::string kYellowCrawPng   = "Actor/Monster/yellowCraw.png";
        static const std::string kYellowCrawName  = "Y_craw_monster";
        static const std::string kYellowCrawDie   = "Y_craw_monster_dead";

        static const char kHeroAvatar[2][40] = {
                "interface/ui2_knight.png",
                "interface/ui2_assassin.png",
        };
    }

    namespace bitMask {
        static const int kHeroCategory  = 0x4;
        static const int kHeroCollision = 0x1;
        static const int kHeroContact   = 0x63;

        static const int kMonsterCategory  = 0x8;
        static const int kMonsterContact   = 0x13;
        static const int kMonsterCollision = 0x1b;

        static const int kItemCategory  = 0x40;
        static const int kItemCollision = 0x00;
        static const int kItemContact   = 0x4;

        static const int kMapCategory  = 0x1;
        static const int kMapCollision = 0x0;
        static const int kMapContact   = 0x3c;

        static const int kDoorCategory  = 0x2;
        static const int kDoorCollision = 0x0;
        static const int kDoorContact   = 0x34;

        static const int kSelfBulletCategory  = 0x10;
        static const int kSelfBulletCollision = 0xb;
        static const int kSelfBulletContact   = 0xb;

        static const int kMonsterBulletCategory  = 0x20;
        static const int kMonsterBulletCollision = 0x3;
        static const int kMonsterBulletContact   = 0x7;
    }

    namespace tag {

        static const int kHero           = 500;
        static const int kMonster        = 300;
        static const int kBullet         = 200;
        static const int kCloseDamage    = 201;
		static const int kFreezeTrap     = 51;
		static const int kFlameTrap      = 52;
		static const int kCoin           = 40;
		static const int kHealthPotion   = 10;
        static const int kGunWeapon      = 1;
        static const int kShotgunWeapon  = 2;
        static const int kSwordWeapon    = 3;
		static const int kIncreaseDamage = 101;
        static const int kHeroUI         = 600;
    }
}

#endif // CONST_H
