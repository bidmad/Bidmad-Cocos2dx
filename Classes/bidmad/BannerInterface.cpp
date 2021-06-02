#include "BannerInterface.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define LOG_TAG "bidmad"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#endif

BannerInterface::BannerInterface(char* zoneId){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner = new BannerController(zoneId);
    banner->setActivity();
    banner->makeAdView();
    banner->setAdInfo(zoneId);
#endif
}

void BannerInterface::setInterval(int interval){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner->setInterval(interval);
#endif
}
void BannerInterface::load(int y){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner->load(y);
#endif
}
void BannerInterface::load(int x, int y){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner->load(x,y);
#endif
}
void BannerInterface::removeBanner(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner->removeBanner();
#endif
}
void BannerInterface::hideBannerView(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner->hideBannerView();
#endif
}
void BannerInterface::showBannerView(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner->showBannerView();
#endif
}
void BannerInterface::onPause(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner->onPause();
#endif
}
void BannerInterface::onResume(){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner->onResume();
#endif
}

void BannerInterface::setOnLoadCallback(void (*_onLoadCallback) (char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner->callback->setOnLoadCallback(_onLoadCallback);
#endif
}
void BannerInterface::setOnFailCallback(void (*_onFailCallback) (char *)){
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    banner->callback->setOnFailCallback(_onFailCallback);
#endif
}
