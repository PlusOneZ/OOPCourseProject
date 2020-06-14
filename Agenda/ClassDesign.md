# 类设计
* PauseMenu
    * Scene 两个成员
        * 音效 m_playEffect
        * 音乐 m_playMisuic
    * PauseMenu::create(bool, bool);

## SafeMap

## GameMap : cocos2d::Scene
* 瓦片地图
* 层地图
* ~~迷你地图~~
* 编排
    * 小地图
        * 类成员
            * 音效 m_playEffect
            * 音乐 m_playMisuic
            * 角色 m_player
            * 敌人（可能不是类成员）
            * 地形参数 ……
            * 障碍物
            * 破坏箱
            * 门
        * 类函数
            * 开门 openDoors
            * 关门 closeDoors
            * 进出门 
            
## Store :: Scene

 
## Actor 
* 成员 Sprite 
* 加载动画
* 攻击 virtual attack
* 生死状态 成员 m_alive
* 死掉 函数 die() 

## Hero : Actor
* 武器 成员 m_mainWeapon
* 武器 成员 m_secWeapon
* 使用技能 virtual
* 移动 
* 状态（速度、血量、蓝、甲）
* 拾取 / 交互
* Buff （暂定）
* attack override
* 回甲

## Enemy : Actor
* 状态（血量、速度）
* 攻击范围
* AI
* attack override
* 掉落物品
* Bullet

## Boss : Enemy（暂定）

## Pet : Actor / Employee（暂定）


## Item
* 成员 Sprite
* 靠近互动 virtual 
* 被“拾取”互动 virtual

## Weapon : Item
* 被“拾取”互动 【放下旧武器】virtual
* 发射 【hero attack 里调用】/ 攻击 shoot
* 子弹 / 近战没子弹
* 射击时间间隔
* 近战范围

## Bullet
* 成员 Sprite
* 速度
* 类型：角色子弹 / 敌人子弹
* 打到东西 / 消失

## Prop : Item
* 被拾取 / 互动  interact
* 成员 m_isValid


## Coin
* 金币被拾取的响应函数

## Buff (暂定)

## Components
* 金币
* 三条
* 迷你地图

## Consts
sk::
