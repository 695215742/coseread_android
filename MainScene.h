#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"

class MainScene : public cocos2d::CCLayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuReadingCallback(cocos2d::Ref* pSender);
	void menuListCallback(cocos2d::Ref* pSender);
	void menuSearchCallback(cocos2d::Ref* pSender);
	void menuSettingCallback(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
private:
	cocos2d::Sprite * isprite;
	cocos2d::CCLayerGradient* searchlayer;
	cocos2d::CCLayerGradient* settinglayer;
	cocos2d::CCLayerGradient* readinglayer;
	cocos2d::CCLayerGradient* listlayer;
	//state 1:reading,2:list,3:search,4:setting
	int state;
};

#endif // __HELLOWORLD_SCENE_H__
