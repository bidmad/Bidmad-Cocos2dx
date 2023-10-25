#include "RewardSampleScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* RewardSampleScene::createScene()
{
    return RewardSampleScene::create();
}

Label* rewardCallbackLabel;

void onRewardLoad(char* zoneId)
{
    rewardCallbackLabel->setString("onRewardLoad");
}
void onRewardShow(char* zoneId)
{
    rewardCallbackLabel->setString("onRewardShow");
}
void onRewardComplete(char* zoneId)
{
    rewardCallbackLabel->setString("onRewardComplete");
}
void onRewardSkip(char* zoneId)
{
    rewardCallbackLabel->setString("onRewardSkip");
}
void onRewardClose(char* zoneId)
{
    rewardCallbackLabel->setString("onRewardClose");
}
void onRewardFail(char* zoneId, char* errorInfo)
{
    rewardCallbackLabel->setString("onRewardFail");
}

bool RewardSampleScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    initReward(); //Bidmad Reward Init
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF("BidmadPlugin Sample", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    this->addChild(label, 1);

    rewardCallbackLabel = Label::createWithTTF("Callback Print", "fonts/Marker Felt.ttf", 20);
    rewardCallbackLabel->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    rewardCallbackLabel->setColor(Color3B(71, 200, 62));
    this->addChild(rewardCallbackLabel, 1);

    int font_size = 15;

    auto back_btn = MenuItemFont::create("Back", CC_CALLBACK_0(RewardSampleScene::backScene, this));
    back_btn->setFontSizeObj(font_size);
    auto back_btn_menu = Menu::create(back_btn, NULL);
    back_btn_menu->alignItemsVertically();
    back_btn_menu->setPositionX(visibleSize.width-60);
    back_btn_menu->setPositionY(origin.y + visibleSize.height - label->getContentSize().height);
    back_btn_menu->setColor(Color3B(67, 116, 217));
    this->addChild(back_btn_menu);

    auto reward_load_btn = MenuItemFont::create("Reward Load", CC_CALLBACK_0(RewardSampleScene::loadReward, this));
    reward_load_btn->setFontSizeObj(font_size);
    auto reward_show_btn = MenuItemFont::create("Reward Show", CC_CALLBACK_0(RewardSampleScene::showReward, this));
    reward_show_btn->setFontSizeObj(font_size);
    
    auto rewardMenus = Menu::create(reward_load_btn, reward_show_btn, NULL);
    rewardMenus->alignItemsVertically();
    rewardMenus->alignItemsVerticallyWithPadding(50);
    rewardMenus->setPositionX(80);
    rewardMenus->setColor(Color3B(67, 116, 217));
    this->addChild(rewardMenus);

    return true;
}

void RewardSampleScene::initReward()
{
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    char* reward = (char*)"29e1ef67-98d2-47b3-9fa2-9192327dd75d";
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    char *reward = (char*)"7d9a2c9e-5755-4022-85f1-6d4fc79e4418";
    #endif
    
    //Reward Create
    ri = new RewardInterface(reward);

    
    // Bidmad Reward Ads auto-reload after the reward ad is shown to the user.
    // You can disable the auto-reload feature by giving "false" for setAutoReload method.
    // ri->setAutoReload(false); //Default true
    
    // CommonInterface can be set with Custom Unique ID with the following method.
    // CommonInterface::setCUID((char *)"SET CUID TEST");

    //Callback Setting
    ri->setOnLoadCallback(onRewardLoad);
    ri->setOnShowCallback(onRewardShow);
    ri->setOnCompleteCallback(onRewardComplete);
    ri->setOnCloseCallback(onRewardClose);
    ri->setOnFailCallback(onRewardFail);
    ri->setOnSkipCallback(onRewardSkip);
}
void RewardSampleScene::loadReward()
{
    ri->load();
}
void RewardSampleScene::showReward()
{
    if(ri->isLoaded()){
        ri->show();
    }
}

void RewardSampleScene::backScene()
{
    auto pScene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(pScene);
}
