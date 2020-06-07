//
// Created by Zhengyi on 2020/6/3.
//

#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "Actor.h"
#include "../Item/Weapon.h"
#include "../Const/Const.h"
#include <string>

class Monster : Actor
{
    typedef const std::string& cStr;
    bool init() override;

    void wander();

    void follow();

    virtual void playMoveAnimation() = 0;

    virtual void attack() = 0;

    void die();

    void reduceHealth(int amount);

    static Animate *creatMonsterAnimate(const std::string &textureName, int num);

    static bool loadAllAnimate();

protected:
    Weapon *m_pWeapon = nullptr;
    float   m_wanderSpeed = 150.;

    int  m_curHealth;
    int  m_fullHealth = 10;

    Animate* m_pMoveAnimate = nullptr;
    Animate* m_pDieAnimate  = nullptr;

    Vec2 m_OldSpeed;

};


#endif // MONSTER_H
