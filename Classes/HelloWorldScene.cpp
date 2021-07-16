#include "HelloWorldScene.h"
#include "BannerSampleScene.h"
#include "InterstitialSampleScene.h"
#include "RewardSampleScene.h"
#include "bidmad/CommonInterface.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
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
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto label = Label::createWithTTF("BidmadPlugin Sample", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    this->addChild(label, 1);
    
    int font_size = 15;

    auto banner_sample_btn = MenuItemFont::create("BannerSample", CC_CALLBACK_0(HelloWorld::MoveBannerSample, this));
    banner_sample_btn->setFontSizeObj(font_size);
    auto interstitial_sample_btn = MenuItemFont::create("InterstitialSample", CC_CALLBACK_0(HelloWorld::MoveInterstitialSample, this));
    interstitial_sample_btn->setFontSizeObj(font_size);
    auto reward_sample_btn = MenuItemFont::create("RewardSample", CC_CALLBACK_0(HelloWorld::MoveRewardSample, this));
    reward_sample_btn->setFontSizeObj(font_size);

    auto sample_menus = Menu::create(banner_sample_btn, interstitial_sample_btn, reward_sample_btn, NULL);
    sample_menus->alignItemsVertically();
    sample_menus->alignItemsVerticallyWithPadding(40);
    sample_menus->setColor(Color3B(67, 116, 217));
    this->addChild(sample_menus);
    return true;
}

void HelloWorld::MoveBannerSample()
{
    auto pScene = BannerSampleScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}

void HelloWorld::MoveInterstitialSample()
{
    auto pScene = InterstitialSampleScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}

void HelloWorld::MoveRewardSample()
{
    auto pScene = RewardSampleScene::createScene();
    Director::getInstance()->replaceScene(pScene);
}
