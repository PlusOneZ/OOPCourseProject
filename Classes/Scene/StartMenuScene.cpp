//
// Created by Zhengyi on 2020/5/8.
//

#include "StartMenuScene.h"
#include "ui/CocosGUI.h"
#include "PauseMenu.h"

USING_NS_CC;
using namespace cocos2d::ui;

Scene* StartMenu::createScene()
{
    return StartMenu::create();
}

/**
 @author Cocos
 @brief  print file loading error
 */
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
}


bool StartMenu::init()
{
    // Check if successfully initialized.
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


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
        btnSetting->setContentSize(Size(150, 120));
        btnSetting->setPosition(Vec2(80, 60));
        settingImg->setPosition(Vec2(80, 60));
        btnSetting->addClickEventListener([&](Ref *) {
            log("Setting Pressed!");
            auto menu = PauseMenu::create();
            menu->setTag(88);
            Director::getInstance()->pause();
            Director::getInstance()->pushScene(menu);
        }
        );
    }

    this->addChild(btnSetting, 2);
    this->addChild(settingImg, 3);


    auto startBackground = Sprite::create("interface/start.png");
    if (startBackground == nullptr)
    {
        problemLoading("'start.png'");
    }
    else
    {
        auto spriteSize = startBackground->getContentSize();
        startBackground->setScale(visibleSize.width / spriteSize.width,
                         visibleSize.height / spriteSize.height);
        log("Pic size: %f, %f", spriteSize.width, spriteSize.height);
        log("Vis size: %f, %f", visibleSize.width, visibleSize.height);
        log("Proportion: %f, %f", visibleSize.width / spriteSize.width,
            visibleSize.height / spriteSize.height);
        // position the sprite on the center of the screen
        startBackground->setPosition(Vec2(visibleSize.width / 2 + origin.x,
                                 visibleSize.height / 2 + origin.y));
    }

    this->addChild(startBackground, 1);

    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(StartMenu::onKeyPressed, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    return true;
}



void StartMenu::onKeyPressed(EventKeyboard::KeyCode keyCode, Event *event) {
    log("Key with keyCode %d pressed", keyCode);
    if (event->getType() == Event::Type::KEYBOARD) {
        if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SPACE)
        {
            Director::getInstance()->replaceScene(SafeMap::create());
        }
        else if (keyCode == cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE)
        {
            Director::getInstance()->end();
        }
    }
}

/*
void StartMenu::popSettingMenu(const Size &viSize) {
    std::unique_ptr<Scale9Sprite> menuBoard(Scale9Sprite::create("interface/ui_pause_board.png"));
    menuBoard->setCapInsets(Rect(6, 6, 79, 61));
    menuBoard->setContentSize(Size(400, 300));
    menuBoard->setPosition(viSize.width / 2, viSize.height / 2);

    this->addChild(menuBoard.get(), 3);
}
*/
