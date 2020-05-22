//
// Created by Zhengyi on 2020/5/8.
//

#include "StartMenuScene.h"
#include "ui/UIScale9Sprite.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

Scene* StartMenu::createScene()
{
    return StartMenu::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' "
           "in front of filenames in StartMenuScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StartMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
            "interface/ui_btn_default.png",
            "interface/ui_btn_default_pressed.png",
            CC_CALLBACK_1(StartMenu::menuCloseCallback, this));
    
    auto pic = Scale9Sprite::create("interface/ui_btn_default.png");
    
    auto btn1 = Button::create("interface/ui_btn_default.png",
                               "interface/ui_btn_default_pressed.png");
    
    // Check if resource loaded correctly
    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'interface/ui_btn_default.png'");
    }
    else
    {
//        closeItem->setScale(10, 10);
        float x = origin.x + closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x,y));
    }
    
    if (btn1 == nullptr)
    {
        problemLoading("'interface/ui_btn_default.png'");
    }
    else
    {
        btn1->setContentSize(Size(150, 120));
        btn1->setPosition(Vec2(200, 200));
    }
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    this->addChild(btn1, 1);
    
    /////////////////////////////
    // 3. add your codes below...

    // add "StartMenu" splash screen"
    auto sprite = Sprite::create("interface/start.png");
    if (sprite == nullptr)
    {
        problemLoading("'start.png'");
    }
    else
    {
        auto spriteSize = sprite->getContentSize();
        sprite->setScale(visibleSize.width / spriteSize.width,
                         visibleSize.height / spriteSize.height);
        log("Pic size: %f, %f", spriteSize.width, spriteSize.height);
        log("Vis size: %f, %f", visibleSize.width, visibleSize.height);
        log("Proportion: %f, %f", visibleSize.width / spriteSize.width,
            visibleSize.height / spriteSize.height);
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x,
                visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }

    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(StartMenu::onSpacePressed, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}


void StartMenu::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application
     * ,do not use Director::getInstance()->end() as given above,instead trigger a custom
     * event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}


void StartMenu::onSpacePressed(EventKeyboard::KeyCode keyCode, Event *event) {
    log("Key with keyCode %d pressed", keyCode);
    if (event->getType() == Event::Type::KEYBOARD &&
        keyCode == cocos2d::EventKeyboard::KeyCode::KEY_SPACE) {
        Director::getInstance()->replaceScene(SafeMap::create());
    }
}

