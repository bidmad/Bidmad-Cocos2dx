#include "HelloWorldScene.h"
#include "BannerSampleScene.h"
#include "InterstitialSampleScene.h"
#include "RewardSampleScene.h"
#include "bidmad/CommonInterface.h"
#include "bidmad/GoogleGDPRInterface.h"

USING_NS_CC;

GoogleGDPRInterface* gdpri;

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

void onConsentInfoUpdateSuccessCallback (){
    CCLOG("BidmadPlugin onConsentInfoUpdateSuccessCallback : %d", gdpri->isConsentFormAvailable());

    if (gdpri->getConsentStatus() == 1) {
        gdpri->showForm();
        CCLOG("ConsentStatusRequired");
    } else if (gdpri->getConsentStatus() == 0) {
        CCLOG("ConsentStatusUnknown");
    } else if (gdpri->getConsentStatus() == 2) {
        CCLOG("ConsentStatusNotRequired");
    } else if (gdpri->getConsentStatus() == 3) {
        CCLOG("ConsentStatusObtained");
    }
}

void onConsentInfoUpdateFailureCallback (char* msg){
    CCLOG("BidmadPlugin onConsentInfoUpdateFailureCallback : %s",msg);
}

void onConsentFormLoadSuccessCallback (){
    CCLOG("BidmadPlugin onConsentFormLoadSuccessCallback : %d", gdpri->getConsentStatus());
    if(gdpri->getConsentStatus() == 1)
        gdpri->showForm();
}

void onConsentFormLoadFailureCallback (char* msg){
    CCLOG("BidmadPlugin onConsentFormLoadFailureCallback : %s",msg);
}

void onConsentFormDismissedCallback (char* msg){
    CCLOG("BidmadPlugin onConsentFormDismissedCallback : %s",msg);
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


    //GDPR interface provided by Google UMP.
    gdpri = new GoogleGDPRInterface();
    // gdpri->setDebug("GOOGLE_TEST_ID", true);

    gdpri->setOnConsentInfoUpdateSuccessCallback(onConsentInfoUpdateSuccessCallback);
    gdpri->setOnConsentInfoUpdateFailureCallback(onConsentInfoUpdateFailureCallback);
    gdpri->setOnConsentFormLoadSuccessCallback(onConsentFormLoadSuccessCallback);
    gdpri->setOnConsentFormLoadFailureCallback(onConsentFormLoadFailureCallback);
    gdpri->setOnConsentFormDismissedCallback(onConsentFormDismissedCallback);

    // gdpri->reset(); //Reset previous decisions
    gdpri->requestConsentInfoUpdate();

    // Use of that Interface when Google GDPR is not available.
    // CCLOG("BidmadPlugin getGdprConsent : %d", CommonInterface::getGdprConsent(false));
    // CommonInterface::setGdprConsent(true, false);

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
