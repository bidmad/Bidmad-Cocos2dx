#include "BannerInterface.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "ios/BannerBridgeCpp.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#endif

BannerInterface::BannerInterface(char* zoneId){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CCLOG("BidmadSDK, Banner Instance Creation");
    localZoneId = zoneId;
    banner = new BannerBridgeCpp(zoneId);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner = new BannerController(zoneId);
    banner->setActivity();
    banner->makeAdView();
    banner->setAdInfo(zoneId);
#endif
}

void BannerInterface::setInterval(int interval){
    CCLOG("BidmadSDK, setInterval");
    banner->setInterval(interval);
}
void BannerInterface::load(int y){
    CCLOG("BidmadSDK, load");
    banner->load(y);
}
void BannerInterface::load(int x, int y){
    CCLOG("BidmadSDK, load");
    banner->load(x,y);
}
void BannerInterface::removeBanner(){
    CCLOG("BidmadSDK, removeBanner");
    banner->removeBanner();
}
void BannerInterface::hideBannerView(){
    CCLOG("BidmadSDK, hideBannerView");
    banner->hideBannerView();
}
void BannerInterface::showBannerView(){
    CCLOG("BidmadSDK, showBannerView");
    banner->showBannerView();
}
void BannerInterface::setCUID(char* cuid) {
    CCLOG("BidmadSDK, setCUID");
    banner->setCUID(cuid);
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
void BannerInterface::onPause(){
    banner->onPause();
}

void BannerInterface::onResume(){
    banner->onResume();
}
#endif

void BannerInterface::setOnLoadCallback(void (*_onLoadCallback) (char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    banner->setOnLoadCallback(_onLoadCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner->callback->setOnLoadCallback(_onLoadCallback);
#endif
}
void BannerInterface::setOnFailCallback(void (*_onFailCallback) (char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    banner->setOnFailCallback(_onFailCallback);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner->callback->setOnFailCallback(_onFailCallback);
#endif
}
