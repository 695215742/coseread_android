#include "MainScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 255) ))
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto BookItem = MenuItemImage::create(
                                           "reading_btn.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainScene::menuCloseCallback, this));
    
	BookItem->setPosition(Vec2(origin.x +BookItem->getContentSize().width/2,
		origin.y +visibleSize.height- BookItem->getContentSize().height/2));
	auto ListItem = MenuItemImage::create(
                                           "list_btn.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainScene::menuStartCallback, this));
    
	ListItem->setPosition(Vec2(origin.x +BookItem->getContentSize().width/2 ,
		origin.y +visibleSize.height- 3*BookItem->getContentSize().height/2));
	auto SearchItem = MenuItemImage::create(
                                           "search_btn.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainScene::menuStartCallback, this));
    
	SearchItem->setPosition(Vec2(origin.x +BookItem->getContentSize().width/2 ,
		origin.y +visibleSize.height- 5*BookItem->getContentSize().height/2));
 
    // create menu, it's an autorelease object
	auto menu = Menu::create(BookItem, ListItem,SearchItem,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width,
                            origin.y + visibleSize.height - label->getContentSize().height));
    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "MainScene" splash screen"
    MainScene::isprite = Sprite::create("title.png");

    // position the sprite on the center of the screen
    MainScene::isprite->setPosition(Vec2(visibleSize.width/2 + origin.x, 2*visibleSize.height/3 + origin.y));
    // add the sprite as a child to this layer
    //this->addChild(MainScene::isprite, 0);
    
    return true;
}


void MainScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
void MainScene::menuStartCallback(Ref* pSender)
{
	 RotateBy * titlerote = RotateBy::create (1, 180);
	 MainScene::isprite->runAction(titlerote);

}
