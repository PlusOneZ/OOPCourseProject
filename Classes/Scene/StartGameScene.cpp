/**
 * @file   StartGameScene.cpp
 * @date   05/24/2020 [modified ZZY]
 * @author �Գ�� ZZY
*/

#include "StartGameScene.h"
#include "SafeMapScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

extern int  gBackgroundMusicID;
extern bool gIsMusicPlaying;
extern bool gIsEffectPlaying;


/**
*@brief Error adding resource
*@author �Գ��
*/
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartGameScene.cpp\n");
}

/**
*@brief Initialize the scene
*@details Add images, buttons, and label to the scene
*@return true
*@author �Գ��
*/
bool TitleScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    // 播放音乐
    static bool recorded = false;
    if (!recorded)
    {
        gBackgroundMusicID = AudioEngine::play2d(sk::files::kBgm1, true, .5);
        AudioEngine::preload(sk::files::kBtnPressed);
        recorded = true;
        gIsMusicPlaying  = true;
        gIsEffectPlaying = true;
    }
    else
    {
        AudioEngine::resume(gBackgroundMusicID);
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    auto startMenu = MenuItemImage::create(
                                           "startNormal.png",
                                           "startSelected.png",
                                           CC_CALLBACK_1(TitleScene::menuStartCallback, this));
    if (startMenu == nullptr ||
        startMenu->getContentSize().width <= 0 ||
        startMenu->getContentSize().height <= 0)
    {
        problemLoading("'startNormal.png' and 'startSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width / 2 - startMenu->getContentSize().width/2;
        float y = origin.y + startMenu->getContentSize().height/2 + 90.0;
        startMenu->setPosition(Vec2(x,y));
    }

    auto endMenu = MenuItemImage::create(
        "interface/ui_close.png",
        "interface/ui_close_pressed.png",
        CC_CALLBACK_1(TitleScene::menuEndCallback, this));
    if (endMenu == nullptr ||
        endMenu->getContentSize().width <= 0 ||
        endMenu->getContentSize().height <= 0)
    {
        problemLoading("'endNormal.png' and 'endSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - endMenu->getContentSize().width / 2;
        float y = origin.y + visibleSize.height - endMenu->getContentSize().height / 2;
        endMenu->setPosition(Vec2(x, y));
    }

    auto menu = Menu::create(startMenu, endMenu, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    auto startLabel = Label::createWithTTF("Start Game", "Font/pixel_bold.ttf", 28);
    if (startLabel == nullptr)
    {
        problemLoading("'Font/pixel_bold.ttf'");
    }
    else
    {
        startLabel->setPosition(Vec2(origin.x + visibleSize.width / 2 -110.0,
                                     origin.y + startLabel->getContentSize().height / 2 + 140.0));
        this->addChild(startLabel, 1);
    }

    //��������
    auto gameCover = Sprite::create("interface/start.png");
    auto coverElement = Sprite::create("interface/start_2.png");
    if (gameCover == nullptr || coverElement == nullptr)
    {
        problemLoading("'interface/start.png' / 'interface/start_2.png'");
    }
    else
    {
        auto rate = visibleSize.width / gameCover->getContentSize().width;
        gameCover->setScale(rate);
        gameCover->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
        this->addChild(gameCover, 0);
        coverElement->setPosition(Vec2(visibleSize.width / 2 + origin.x + 290.0,
                                       visibleSize.height / 2 + origin.y + 30.0));
        coverElement->setScale(rate);
        this->addChild(coverElement, 0);
    }

    auto gameName = Sprite::create("interface/title_zh.png");
    if (gameName == nullptr ||
        gameName->getContentSize().width <= 0 ||
        gameName->getContentSize().height <= 0)
    {
        problemLoading("'interface/title_zh.png'");
    }
    else
    {
        gameName->setPosition(Vec2(origin.x + gameName->getContentSize().width / 2 + 50, 
                                   visibleSize.height + origin.y - gameName->getContentSize().height));
        this->addChild(gameName, 0);
    }

    buildSettingBtn();

    return true;
}

/**
*@brief Go to the next scene
*@author �Գ��
*/
void TitleScene::menuStartCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(SafeMap::createScene());
}

/**
*@brief Exit the game
*@author �Գ��
*/
void TitleScene::menuEndCallback(Ref* pSender)
{
    Director::getInstance()->end();
}



void TitleScene::buildSettingBtn() {

    auto btnSetting = Button::create("interface/ui_btn_default.png",
                                     "interface/ui_btn_default_pressed.png");
    auto settingImg = Sprite::create("interface/ui_settings.png");
    const Size kBtnContSize(30, 18);

    if (btnSetting == nullptr || settingImg == nullptr)
    {
        problemLoading("'interface/ui_btn_default.png'");
        problemLoading("'interface/ui_settings.png'");
    }
    else
    {
        btnSetting->setScale9Enabled(true);
        // 设置素材内容部分贴图大小
        btnSetting->setCapInsets(Rect(12, 12, kBtnContSize.width, kBtnContSize.height));
        btnSetting->setContentSize(Size(100, 80));
        btnSetting->setPosition(Vec2(60, 40));
        settingImg->setPosition(Vec2(60, 40));
        btnSetting->addClickEventListener([&](Ref *) {
            log("Setting Pressed!");
            auto menu = PauseMenu::create(sk::kKnight);
            Director::getInstance()->pause();
            Director::getInstance()->pushScene(menu);
        }
        );
    }

    this->addChild(btnSetting, 2);
    this->addChild(settingImg, 3);
}


