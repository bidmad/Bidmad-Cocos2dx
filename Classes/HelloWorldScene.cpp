#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

Label* callbackLabel;

void onInterstitialLoad(char* zoneId)
{
    callbackLabel->setString("onInterstitialLoad");
}
void onInterstitialShow(char* zoneId)
{
    callbackLabel->setString("onInterstitialShow");
}
void InterstitialClose(char* zoneId)
{
    callbackLabel->setString("InterstitialClose");
}
void InterstitialFail(char* zoneId)
{
    callbackLabel->setString("InterstitialFail");
}

void onRewardLoad(char* zoneId)
{
    callbackLabel->setString("onRewardLoad");
}
void onRewardShow(char* zoneId)
{
    callbackLabel->setString("onRewardShow");
}
void onRewardComplete(char* zoneId)
{
    callbackLabel->setString("onRewardComplete");
}
void onRewardSkip(char* zoneId)
{
    callbackLabel->setString("onRewardSkip");
}
void onRewardClose(char* zoneId)
{
    callbackLabel->setString("onRewardClose");
}
void onRewardFail(char* zoneId)
{
    callbackLabel->setString("onRewardFail");
}

void onAdTrackingAuthorizationResponse (int response){
    CCLOG("BidmadPlugin onAdTrackingAuthorizationResponse : %d", response);

    if(response == 3){
        CCLOG("IDFA  수집 동의 ");
    }else if(response == 2) {
        CCLOG("IDFA  수집 거부 ");
    }else if(response == 0) {
        CCLOG("IDFA  수집 미결정 ");
    }else if(response == 1) {
        CCLOG("IDFA  수집 제한 ");
    }else if(response == 4) {
        CCLOG("IDFA  iOS 14 이하 버전 ");
    }
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    CCLOG("BidmadPlugin Version : %s", CommonInterface::pluginVersion);
    CommonInterface::setDebugMode(true); //print Debug Log
    CommonInterface::reqAdTrackingAuthorization(onAdTrackingAuthorizationResponse); //iOS 14 ATT Call
    CommonInterface::setAdvertiserTrackingEnabled(true);
    initInterstitial(); //Bidmad Interstitial Init
    initReward(); //Bidmad Reward Init
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF("BidmadPlugin Sample", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    this->addChild(label, 1);

    callbackLabel = Label::createWithTTF("Callback Print", "fonts/Marker Felt.ttf", 20);
    callbackLabel->setPosition(Vec2(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2));
    callbackLabel->setColor(Color3B(71, 200, 62));
    this->addChild(callbackLabel, 1);
    
    int font_size = 15;
    auto interstitial_load_btn = MenuItemFont::create("Interstitial Load", CC_CALLBACK_0(HelloWorld::loadInterstitial, this));
    interstitial_load_btn->setFontSizeObj(font_size);
    auto interstitial_show_btn = MenuItemFont::create("Interstitial Show", CC_CALLBACK_0(HelloWorld::showInterstitial, this));
    interstitial_show_btn->setFontSizeObj(font_size);

    auto interstitialMenus = Menu::create(interstitial_load_btn, interstitial_show_btn, NULL);
    interstitialMenus->alignItemsVertically();
    interstitialMenus->alignItemsVerticallyWithPadding(50);
    interstitialMenus->setPositionX(80);
    interstitialMenus->setColor(Color3B(67, 116, 217));
    this->addChild(interstitialMenus);
    
    auto reward_load_btn = MenuItemFont::create("Reward Load", CC_CALLBACK_0(HelloWorld::loadReward, this));
    reward_load_btn->setFontSizeObj(font_size);
    auto reward_show_btn = MenuItemFont::create("Reward Show", CC_CALLBACK_0(HelloWorld::showReward, this));
    reward_show_btn->setFontSizeObj(font_size);
    
    auto rewardMenus = Menu::create(reward_load_btn, reward_show_btn, NULL);
    rewardMenus->alignItemsVertically();
    rewardMenus->alignItemsVerticallyWithPadding(50);
    rewardMenus->setPositionX(visibleSize.width-80);
    rewardMenus->setColor(Color3B(204, 61, 61));
    this->addChild(rewardMenus);

    return true;
}

void HelloWorld::initInterstitial()
{
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    char *interstitial = (char*)"228b95a9-6f42-46d8-a40d-60f17f751eb1";
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    char *interstitial = (char*)"e9acd7fc-a962-40e4-aaad-9feab1b4f821";
    #endif
    
    //Interstitial Create
    ii = new InterstitialInterface(interstitial);
    
    //Callback Setting
    ii->setOnLoadCallback(onInterstitialLoad);
    ii->setOnShowCallback(onInterstitialShow);
    ii->setOnFailCallback(InterstitialFail);
    ii->setOnCloseCallback(InterstitialClose);
}
void HelloWorld::loadInterstitial()
{
    ii->load();
}
void HelloWorld::showInterstitial()
{
    if(ii->isLoaded()){
        ii->show();
    }
}

void HelloWorld::initReward()
{
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    char* reward = (char*)"29e1ef67-98d2-47b3-9fa2-9192327dd75d";
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    char *reward = (char*)"7d9a2c9e-5755-4022-85f1-6d4fc79e4418";
    #endif
    
    //Reward Create
    ri = new RewardInterface(reward);
    
    //Callback Setting
    ri->setOnLoadCallback(onRewardLoad);
    ri->setOnShowCallback(onRewardShow);
    ri->setOnCompleteCallback(onRewardComplete);
    ri->setOnCloseCallback(onRewardClose);
    ri->setOnFailCallback(onRewardFail);
    ri->setOnSkipCallback(onRewardSkip);
}
void HelloWorld::loadReward()
{
    ri->load();
}
void HelloWorld::showReward()
{
    if(ri->isLoaded()){
        ri->show();
    }
}
