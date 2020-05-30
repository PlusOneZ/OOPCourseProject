/**
 * @file   PauseMenuLayer.cpp
 * @brief  Create a menu on top when "pause" button pressed.
 * @author 卓正一
 */

#include "PauseMenu.h"

using namespace cocos2d;
int  gBackgroundMusicID;
bool gIsMusicPlaying = true;
bool gIsEffectPlaying = true;

PauseMenu::PauseMenu(sk::HeroID id)
    : m_heroID(id)
{
    // Empty
}

PauseMenu* PauseMenu::create(sk::HeroID id)
{
    auto *pRet = new(std::nothrow) PauseMenu(id);
    if (pRet)
    {
        if (pRet->init())
        {
            pRet->autorelease();
            return pRet;
        }
    }
    delete pRet;
    pRet = nullptr;
    return nullptr;
}

/**
 @brief  print file loading error
 @author Cocos
 */
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
}

/**
 * @brief  调整按钮尺寸的辅助函数
 * @param  pBtn 按钮指针
 * @author 卓正一
 */
void normalizeButton(ui::Button *pBtn) {
    static const Size kBtnContSize(30, 18);;
    if (pBtn == nullptr)
    {
        problemLoading("InNormalize");
        return;
    }
    pBtn->setScale9Enabled(true);
    // 设置素材内容部分贴图大小
    pBtn->setCapInsets(Rect(12, 12, kBtnContSize.width, kBtnContSize.height));
    pBtn->setContentSize(Size(100, 90));
}


bool PauseMenu::init() {
    playClickEffect();

    this->setOpacity(128u);
    const auto kVisibleSize = Director::getInstance()->getVisibleSize();

    // 设置背景框
    auto pauseBoardImg = ui::Scale9Sprite::create("interface/ui_pause_board.png");
    if(pauseBoardImg == nullptr)
    {
        problemLoading("'interface/ui_pause_board.png'");
    }
    else
    {
        pauseBoardImg->setCapInsets(Rect(6, 6, 79, 61));
        pauseBoardImg->setContentSize(Size(500, 400));
        pauseBoardImg->setPosition(kVisibleSize.width / 2, kVisibleSize.height / 2);

        this->addChild(pauseBoardImg, 0);
    }

    // 放置小部件
    auto garnish = ui::Scale9Sprite::create("interface/ui_garnish.png");
    auto hint    = Label::createWithTTF("Paused", "Font/IRANYekanBold.ttf", 65.);
    if (garnish == nullptr || hint == nullptr)
    {
        problemLoading("'interface/ui_garnish.png' / 'Font/IRANYekanBold.ttf'");
    }
    else
    {
        const Vec2 kGarnishPos = {kVisibleSize.width / 2 + 65, kVisibleSize.height / 2 + 120};
        garnish->setContentSize(Size(270, 100));
        garnish->setPosition(kGarnishPos);
        hint->setPosition(kGarnishPos);
        this->addChild(garnish, 1);
        this->addChild(hint, 2);
    }

    // 放置头像框
    auto avatarPot = ui::Scale9Sprite::create("interface/ui_pot.png");
    auto avatar    = Sprite::create(sk::files::kHeroAvatar[m_heroID],
            Rect(0, 0, 112, 100));
    if (avatar == nullptr || avatarPot == nullptr)
    {
        problemLoading("'interface/ui_pot.png' / 'interface/ui2_knight.png'");
    }
    else
    {
        const Vec2 kAvatarPos = {kVisibleSize.width / 2 - 150, kVisibleSize.height / 2 + 120};
        avatarPot->setContentSize(Size(112, 110));
        avatarPot->setPosition(kAvatarPos);
        avatar->setPosition(kAvatarPos);
        this->addChild(avatarPot, 1);
        this->addChild(avatar, 2);
    }


    auto resumeBtn = ui::Button::create("interface/ui_btn_default.png",
                                         "interface/ui_btn_default_pressed.png");
    auto resumeImg = Sprite::create("interface/ui_resume.png");
    auto homeBtn   = ui::Button::create("interface/ui_btn_default.png",
                                         "interface/ui_btn_default_pressed.png");
    auto homeImg   = Sprite::create("interface/ui_home.png");
    auto effectBtn = ui::Button::create("interface/ui_btn_default.png",
                                       "interface/ui_btn_default_pressed.png");
    auto effectImg = Sprite::create("interface/ui_aueffect.png");
    auto musicBtn  = ui::Button::create("interface/ui_btn_default.png",
                                        "interface/ui_btn_default_pressed.png");
    auto musicImg  = Sprite::create("interface/ui_music.png");
    if (resumeBtn == nullptr || resumeImg == nullptr || homeBtn == nullptr
        || homeImg == nullptr || effectBtn == nullptr || effectImg == nullptr
        || musicBtn == nullptr || musicImg == nullptr)
    {
        problemLoading("Button things");
    }
    else
    {
        // TODO: 重新布局或者加入技能栏（大概是重新布局）
        const float kYCenter = kVisibleSize.height / 2 - 130;
        const float kXCenter = kVisibleSize.width / 2;
        normalizeButton(resumeBtn);
        normalizeButton(homeBtn);
        normalizeButton(effectBtn);
        normalizeButton(musicBtn);

        resumeBtn->setPosition(Vec2(kXCenter - 190, kYCenter));
        resumeImg->setPosition(Vec2(kXCenter - 190, kYCenter));

        homeBtn->setPosition(Vec2(kXCenter - 65, kYCenter));
        homeImg->setPosition(Vec2(kXCenter - 65, kYCenter));

        if (!gIsEffectPlaying)
            effectImg->setColor(Color3B(20, 20, 20));
        effectBtn->setPosition(Vec2(kXCenter + 65, kYCenter));
        effectImg->setPosition(Vec2(kXCenter + 65, kYCenter));

        if (!gIsMusicPlaying)
            musicImg->setColor(Color3B(20, 20, 20));
        musicBtn->setPosition(Vec2(kXCenter + 190, kYCenter));
        musicImg->setPosition(Vec2(kXCenter + 190, kYCenter));

        resumeBtn->addClickEventListener([&](Ref*){
            playClickEffect();
            // 恢复游戏就是退出设置界面
            log("Clicked");
            Director::getInstance()->resume();
            Director::getInstance()->popScene();
        });

        homeBtn->addClickEventListener([&](Ref* ){
            playClickEffect();
            // TODO: 如果有存档功能的话，在这里存档并退出（或是每过一个房间就存一次档）
            AudioEngine::pauseAll();
            Director::getInstance()->replaceScene(Start::create());
        });

        effectBtn->addClickEventListener([&](Ref*){ changEffectPlayEvent(); });

        musicBtn->addClickEventListener([&](Ref*) { changMusicPlayEvent(); });

        this->addChild(resumeBtn, 1); this->addChild(resumeImg, 2);
        this->addChild(homeBtn, 1);   this->addChild(homeImg, 2);
        this->addChild(effectBtn, 1); this->addChild(effectImg, 2, 88);
        this->addChild(musicBtn, 1);  this->addChild(musicImg, 2, 77);
    }

    return true;
}

void PauseMenu::changEffectPlayEvent() {
    // 在这里开关音效
    if (gIsEffectPlaying)
    {
        gIsEffectPlaying = false;
        this->getChildByTag(88)->setColor(Color3B(20, 20, 20));
    }
    else
    {
        gIsEffectPlaying = true;
        this->getChildByTag(88)->setColor(Color3B(240, 240, 240));
    }
    playClickEffect();
}

void PauseMenu::changMusicPlayEvent() {
    playClickEffect();
    // TODO: 在这里开关音乐
    if (gIsMusicPlaying) {
        gIsMusicPlaying = false;
        this->getChildByTag(77)->setColor(Color3B(20, 20, 20));
        AudioEngine::pause(gBackgroundMusicID);
    }
    else
    {
        gIsMusicPlaying = true;
        this->getChildByTag(77)->setColor(Color3B(240, 240, 240));
        AudioEngine::resume(gBackgroundMusicID);
    }
}

void PauseMenu::playClickEffect() {
    if (gIsEffectPlaying) {
        AudioEngine::play2d(sk::files::kBtnPressed);
    }
}
