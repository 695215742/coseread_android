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

    if ( !CCLayerColor::initWithColor(ccc4(255, 255, 255, 255) ))
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //left menu with four buttons and a label (reading,search,setting,list&system information)
    auto BookItem = MenuItemImage::create(
                                           "reading_btn.png",
                                           "reading_btn_pu.png",
                                           CC_CALLBACK_1(MainScene::menuCloseCallback, this));
    
	BookItem->setPosition(Vec2(origin.x +BookItem->getContentSize().width/2,
		origin.y +visibleSize.height- BookItem->getContentSize().height/2));
	auto ListItem = MenuItemImage::create(
                                           "list_btn.png",
                                           "list_btn_pu.png",
                                           CC_CALLBACK_1(MainScene::menuStartCallback, this));
    
	ListItem->setPosition(Vec2(origin.x +BookItem->getContentSize().width/2 ,
		origin.y +visibleSize.height- 3*BookItem->getContentSize().height/2));
	auto SearchItem = MenuItemImage::create(
                                           "search_btn.png",
                                           "search_btn_pu.png",
                                           CC_CALLBACK_1(MainScene::menuStartCallback, this));
    
	SearchItem->setPosition(Vec2(origin.x +BookItem->getContentSize().width/2 ,
		origin.y +visibleSize.height- 5*BookItem->getContentSize().height/2));
	auto SettingItem = MenuItemImage::create(
                                           "setting_btn.png",
                                           "setting_btn_pu.png",
                                           CC_CALLBACK_1(MainScene::menuStartCallback, this));
    
	SettingItem->setPosition(Vec2(origin.x +BookItem->getContentSize().width/2 ,
		origin.y +visibleSize.height- 7*BookItem->getContentSize().height/2));
    // create menu, it's an autorelease object
	auto menu = Menu::create(BookItem, ListItem,SearchItem,SettingItem,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	//four layers,control by tuttons
	CCLayerGradient* layer1 = CCLayerGradient::create(ccc4(255, 0, 0, 255), ccc4(255, 0, 255, 255));
	layer1->setContentSize(CCSizeMake(80, 80));
	layer1->setPosition(ccp(50,50));
	

    MainScene::isprite = Sprite::create("title.png");

    // position the sprite on the center of the screen
    MainScene::isprite->setPosition(Vec2(visibleSize.width/2 + origin.x, 2*visibleSize.height/3 + origin.y));
    // add the sprite as a child to this layer
    //this->addChild(MainScene::isprite, 0);
	layer1->addChild(isprite);
    addChild(layer1);
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
void MainScene::menuReadingCallback(Ref* pSender)
{
	 RotateBy * titlerote = RotateBy::create (1, 180);
	 MainScene::isprite->runAction(titlerote);
}
void MainScene::menuSearchCallback(Ref* pSender)
{
	 RotateBy * titlerote = RotateBy::create (1, 180);
	 MainScene::isprite->runAction(titlerote);
}
void MainScene::menuListCallback(Ref* pSender)
{
	 RotateBy * titlerote = RotateBy::create (1, 180);
	 MainScene::isprite->runAction(titlerote);
}
void MainScene::menuSettingCallback(Ref* pSender)
{
	 RotateBy * titlerote = RotateBy::create (1, 180);
	 MainScene::isprite->runAction(titlerote);
}
